// Fill out your copyright notice in the Description page of Project Settings.


#include "FunctionLibrary/VertexAnimFunctionLibrary.h"

#include "Components/SkeletalMeshComponent.h"
#include "PackageTools.h"
#include "SkeletalRenderPublic.h"
#include "Runtime/Engine/Private/SkeletalRenderCPUSkin.h"
#include "AssetRegistryModule.h"
#include "Animation/AnimSingleNodeInstance.h"
// --------------------------------------------------------------
#include "RawMesh.h"
#include "AssetToolsModule.h"
#include "Rendering/SkeletalMeshModel.h"
#include "Rendering/SkeletalMeshLODRenderData.h"
#include "Materials/MaterialInstanceDynamic.h"

#include "VertexAnimProfile.h"

static void QuatSave(FQuat& Q)
{
	// Make sure we have a non null SquareSum. It shouldn't happen with a quaternion, but better be safe.
	if (Q.SizeSquared() <= SMALL_NUMBER)
	{
		Q = FQuat::Identity;
	}
	else
	{
		// All transmitted quaternions *MUST BE* unit quaternions, in which case we can deduce the value of W.
		if (!ensure(Q.IsNormalized()))
		{
			Q.Normalize();
		}
	}
}

static void MapSkinVerts(
	UVertexAnimProfile* InProfile, const TArray <FFinalSkinVertex>& SkinVerts,
	TArray <int32>& UniqueVertsSourceID, TArray <FVector2D>& OutUVSet_Vert)
{
	TArray <FVector> UniqueVerts;
	TArray <int32> UniqueID;
	UniqueID.SetNumZeroed(SkinVerts.Num());

	for (int32 i = 0; i < SkinVerts.Num(); i++)
	{
		int32 ID = INDEX_NONE;

		if (InProfile->UVMergeDuplicateVerts)
		{
			if (UniqueVerts.Find(SkinVerts[i].Position, ID))
			{
				UniqueID[i] = ID;
			}
			else
			{
				UniqueID[i] = UniqueVerts.Num();
				UniqueVerts.Add(SkinVerts[i].Position);
				UniqueVertsSourceID.Add(i);
			}
		}
		else
		{
			UniqueID[i] = UniqueVerts.Num();
			UniqueVerts.Add(SkinVerts[i].Position);
			UniqueVertsSourceID.Add(i);
		}
	}



	if (InProfile->AutoSize)
	{
		int32 XSize = FMath::Min(InProfile->MaxWidth, (int32)FMath::RoundUpToPowerOfTwo(UniqueVerts.Num()));
		InProfile->RowsPerFrame_Vert = FMath::CeilToInt((float)(UniqueVerts.Num()) / (float)(XSize));
		InProfile->OverrideSize_Vert = FIntPoint(
			XSize,
			FMath::RoundUpToPowerOfTwo(InProfile->CalcTotalRequiredHeight_Vert()));
	}
	else
	{
		InProfile->RowsPerFrame_Vert = //FMath::CeilToInt((float)(UniqueVerts.Num()) / (float)(InProfile->OverrideSize.X));
			FMath::RoundUpToPowerOfTwo((float)(UniqueVerts.Num()) / (float)(InProfile->OverrideSize_Vert.X));
	}

	const float XStep = 1.f / InProfile->OverrideSize_Vert.X;
	const float YStep = 1.f / InProfile->OverrideSize_Vert.Y;
	const FVector2D HalfStep = FVector2D(XStep, YStep) / 2;
	TArray <FVector2D> UniqueMappedUVs;
	UniqueMappedUVs.SetNum(UniqueVerts.Num());

	for (int32 i = 0; i < UniqueVerts.Num(); i++)
	{
		// I SWITCHED THESE to have the UVs lined horizontally.
		const int32 GridX = i % InProfile->OverrideSize_Vert.X;
		const int32 GridY = i / InProfile->OverrideSize_Vert.X;
		const FVector2D GridUV = FVector2D(GridX * XStep, GridY * YStep);
		UniqueMappedUVs[i] = GridUV;
	}

	TArray <FVector2D> NewUVSet_Vert;
	NewUVSet_Vert.SetNum(SkinVerts.Num());
	for (int32 i = 0; i < SkinVerts.Num(); i++)
	{
		NewUVSet_Vert[i] = UniqueMappedUVs[UniqueID[i]];
	}
	OutUVSet_Vert = NewUVSet_Vert;
};

static void MapActiveBones(
	UVertexAnimProfile* InProfile, const int32 NumBones, TArray <FVector2D>& OutUVSet_Bone)
{
	if (InProfile->AutoSize)
	{
		int32 XSize = FMath::Clamp((int32)FMath::RoundUpToPowerOfTwo(NumBones), 8, InProfile->MaxWidth);

		InProfile->OverrideSize_Bone = FIntPoint(
			XSize,
			FMath::RoundUpToPowerOfTwo(InProfile->CalcTotalRequiredHeight_Bone() + 1));
	}

	const float XStep = 1.f / InProfile->OverrideSize_Bone.X;
	const float YStep = 1.f / InProfile->OverrideSize_Bone.Y;
	TArray <FVector2D> UniqueMappedUVs;
	UniqueMappedUVs.SetNum(NumBones);

	for (int32 i = 0; i < NumBones; i++)
	{
		if (true)
		{
			// I SWITCHED THESE to have the UVs lined horizontally.
			const int32 GridX = i % InProfile->OverrideSize_Bone.X;
			const int32 GridY = i / InProfile->OverrideSize_Bone.X;
			const FVector2D GridUV = FVector2D(GridX * XStep, GridY * YStep);
			UniqueMappedUVs[i] = GridUV;
		}
		else
		{
			UniqueMappedUVs[i] = FVector2D();
		}
	}

	OutUVSet_Bone = UniqueMappedUVs;
};

static void SkinnedMeshVATData(
	USkinnedMeshComponent* InSkinnedMeshComponent,
	UVertexAnimProfile* InProfile,
	TArray <int32>& UniqueSourceID,
	TArray <TArray <FVector2D>>& UVs_VertAnim,
	TArray <TArray <FVector2D>>& UVs_BoneAnim1,
	TArray <TArray <FVector2D>>& UVs_BoneAnim2,
	TArray <TArray <FColor>>& Colors_BoneAnim)
{
	UniqueSourceID.Empty();
	UVs_VertAnim.Empty();
	UVs_BoneAnim1.Empty();
	UVs_BoneAnim2.Empty();
	Colors_BoneAnim.Empty();

	const int32 NumLODs = InSkinnedMeshComponent->GetNumLODs();

	const auto& RefSkeleton = InSkinnedMeshComponent->SkeletalMesh->RefSkeleton;
	const auto& GlobalRefSkeleton = InSkinnedMeshComponent->SkeletalMesh->Skeleton->GetReferenceSkeleton();

	TArray <FVector2D> GridUVs_Vert;
	TArray <FVector2D> GridUVs_Bone;

	TArray<FFinalSkinVertex> AnimMeshFinalVertices;
	int32 AnimMeshLOD = 0;


	int32 UVVertStart = -1;
	int32 UVBoneStart = -2;

	FSkeletalMeshRenderData& SkeletalMeshRenderData = InSkinnedMeshComponent->MeshObject->GetSkeletalMeshRenderData();

	{
		FSkeletalMeshLODRenderData& LODData = SkeletalMeshRenderData.LODRenderData[0];
		MapActiveBones(InProfile, GlobalRefSkeleton.GetNum(), GridUVs_Bone);

		InSkinnedMeshComponent->GetCPUSkinnedVertices(AnimMeshFinalVertices, AnimMeshLOD);
		MapSkinVerts(InProfile, AnimMeshFinalVertices, UniqueSourceID, GridUVs_Vert);

		int32 UVChannelStart = LODData.StaticVertexBuffers.StaticMeshVertexBuffer.GetNumTexCoords();
		UVVertStart = InProfile->Anims_Vert.Num() ? UVChannelStart : -1;
		InProfile->UVChannel_VertAnim = UVVertStart;
		UVBoneStart =
			InProfile->Anims_Bone.Num() ? (InProfile->Anims_Vert.Num() ? UVChannelStart + 1 : UVChannelStart) : -2;
		InProfile->UVChannel_BoneAnim = UVBoneStart;
		InProfile->UVChannel_BoneAnim_Full = ((UVBoneStart >= 0) && InProfile->FullBoneSkinning) ? UVBoneStart + 1 : -1;
	}


	for (int32 OverallLODIndex = 0; OverallLODIndex < NumLODs; OverallLODIndex++)
	{
		int32 LODIndexRead = FMath::Min(OverallLODIndex, NumLODs - 1);

		FSkeletalMeshLODInfo& SrcLODInfo = *(InSkinnedMeshComponent->SkeletalMesh->GetLODInfo(LODIndexRead));

		// Get the CPU skinned verts for this LOD, WAIT, if it changes LOD on each loop, does that not mean it changes??
		TArray<FFinalSkinVertex> FinalVertices;
		InSkinnedMeshComponent->GetCPUSkinnedVertices(FinalVertices, LODIndexRead);


		TArray <FColor> thisLODSkinWeightColor;
		// Here is where we find the correct grid UVs for this LOD
		TArray <FVector2D> thisLODGridUVs_Vert, thisLODGridUVs_Bone1, thisLODGridUVs_Bone2;

		thisLODGridUVs_Bone1.SetNum(FinalVertices.Num());
		thisLODGridUVs_Bone2.SetNum(FinalVertices.Num());
		thisLODSkinWeightColor.SetNum(FinalVertices.Num());

		if (OverallLODIndex == AnimMeshLOD)
		{
			thisLODGridUVs_Vert = GridUVs_Vert;
		}
		else
		{
			// Here we search
			thisLODGridUVs_Vert.SetNum(FinalVertices.Num());

			for (int32 o = 0; o < FinalVertices.Num(); o++)
			{
				const FVector Pos = FinalVertices[o].Position;
				float Lowest = MAX_FLT;
				int32 WinnerID = INDEX_NONE;

				for (int32 u = 0; u < UniqueSourceID.Num(); u++)
				{
					const FVector TargetPos = AnimMeshFinalVertices[UniqueSourceID[u]].Position;

					const float Dist = FVector::Dist(Pos, TargetPos);
					if (Dist < Lowest)
					{
						Lowest = Dist;
						WinnerID = UniqueSourceID[u];
					}
				}

				check(WinnerID != INDEX_NONE);

				thisLODGridUVs_Vert[o] = GridUVs_Vert[WinnerID];
			}
		}


		FSkeletalMeshModel* Resource = InSkinnedMeshComponent->SkeletalMesh->GetImportedModel();
		FSkeletalMeshLODRenderData& LODData = SkeletalMeshRenderData.LODRenderData[LODIndexRead];

		{
			const FSkinWeightVertexBuffer& SkinWeightVertexBuffer = *LODData.GetSkinWeightVertexBuffer();

			auto SkinData = LODData.GetSkinWeightVertexBuffer();
			check(SkinData->GetNumVertices() == FinalVertices.Num());

			for (int32 s = 0; s < (int32)SkinData->GetNumVertices(); s++)
			{
				int32 SectionIndex;
				int32 VertIndex;
				LODData.GetSectionFromVertexIndex(s, SectionIndex, VertIndex);
				check(SectionIndex < LODData.RenderSections.Num());
				const FSkelMeshRenderSection& Section = LODData.RenderSections[SectionIndex];
				const auto& SoftVert = Resource->LODModels[LODIndexRead].Sections[SectionIndex].SoftVertices[VertIndex];

				uint32 InfluenceBones[4] = {
						SoftVert.InfluenceBones[0],
						SoftVert.InfluenceBones[1],
						SoftVert.InfluenceBones[2],
						SoftVert.InfluenceBones[3]
				};

				uint8 InfluenceWeights[4] = {
						SoftVert.InfluenceWeights[0],
						SoftVert.InfluenceWeights[1],
						SoftVert.InfluenceWeights[2],
						SoftVert.InfluenceWeights[3]
				};

				const float Sum =
					((float)InfluenceWeights[0] / 255.f) + ((float)InfluenceWeights[1] / 255.f)
					+ ((float)InfluenceWeights[2] / 255.f) + ((float)InfluenceWeights[3] / 255.f);
				const float Rest = 1.f - Sum;

				FLinearColor W = FLinearColor(
					((float)InfluenceWeights[0] / 255.f) + Rest,
					((float)InfluenceWeights[1] / 255.f),
					((float)InfluenceWeights[2] / 255.f),
					((float)InfluenceWeights[3] / 255.f));


				thisLODSkinWeightColor[s] = W.ToFColor(false);

				{
					check(Section.BoneMap.IsValidIndex(InfluenceBones[0]));
					check(Section.BoneMap.IsValidIndex(InfluenceBones[1]));
					check(Section.BoneMap.IsValidIndex(InfluenceBones[2]));
					check(Section.BoneMap.IsValidIndex(InfluenceBones[3]));

					const int32
						Bone0 = GlobalRefSkeleton.FindBoneIndex(RefSkeleton.GetBoneName(Section.BoneMap[InfluenceBones[0]])),
						Bone1 = GlobalRefSkeleton.FindBoneIndex(RefSkeleton.GetBoneName(Section.BoneMap[InfluenceBones[1]])),
						Bone2 = GlobalRefSkeleton.FindBoneIndex(RefSkeleton.GetBoneName(Section.BoneMap[InfluenceBones[2]])),
						Bone3 = GlobalRefSkeleton.FindBoneIndex(RefSkeleton.GetBoneName(Section.BoneMap[InfluenceBones[3]]));


					checkf(GridUVs_Bone.IsValidIndex(Bone0), TEXT("NUMY %i || %i"),
						GridUVs_Bone.Num(), LODData.ActiveBoneIndices.Num());
					checkf(GridUVs_Bone.IsValidIndex(Bone1), TEXT("NUMY %i || %i"),
						GridUVs_Bone.Num(), LODData.ActiveBoneIndices.Num());
					checkf(GridUVs_Bone.IsValidIndex(Bone2), TEXT("NUMY %i || %i"),
						GridUVs_Bone.Num(), LODData.ActiveBoneIndices.Num());
					checkf(GridUVs_Bone.IsValidIndex(Bone3), TEXT("NUMY %i || %i"),
						GridUVs_Bone.Num(), LODData.ActiveBoneIndices.Num());


					thisLODGridUVs_Bone1[s] = FVector2D(
						GridUVs_Bone[Bone0].X,
						GridUVs_Bone[Bone1].X);
					thisLODGridUVs_Bone2[s] = FVector2D(
						GridUVs_Bone[Bone2].X,
						GridUVs_Bone[Bone3].X);
				}
			}
		}

		UVs_VertAnim.Add(thisLODGridUVs_Vert);
		UVs_BoneAnim1.Add(thisLODGridUVs_Bone1);
		UVs_BoneAnim2.Add(thisLODGridUVs_Bone2);
		Colors_BoneAnim.Add(thisLODSkinWeightColor);
	}
}

void GatherAndBakeAllAnimVertData(UVertexAnimProfile* Profile, USkeletalMeshComponent* PreviewComponent, const TArray<int32>& UniqueSourceIDs, TArray<FVector4>& OutGridVertPos, TArray<FVector4>& OutGridVertNormal)
{
	bool bCachedCPUSkinning = false;
	constexpr bool bRecreateRenderStateImmediately = true;
	// 1?switch to CPU skinning
	{
		const int32 InLODIndex = 0;
		{
			if (USkinnedMeshComponent* MasterPoseComponentPtr = PreviewComponent->MasterPoseComponent.Get())
			{
				MasterPoseComponentPtr->SetForcedLOD(InLODIndex + 1);
				MasterPoseComponentPtr->UpdateLODStatus();
				MasterPoseComponentPtr->RefreshBoneTransforms(nullptr);
			}
			else
			{
				PreviewComponent->SetForcedLOD(InLODIndex + 1);
				PreviewComponent->UpdateLODStatus();
				PreviewComponent->RefreshBoneTransforms(nullptr);
			}

			// switch to CPU skinning
			bCachedCPUSkinning = PreviewComponent->GetCPUSkinningEnabled();

			PreviewComponent->SetCPUSkinningEnabled(true, bRecreateRenderStateImmediately);

			check(PreviewComponent->MeshObject);
			check(PreviewComponent->MeshObject->IsCPUSkinned());
		}
	}

	// 2?Make Sure it in ref pose
	PreviewComponent->RefreshBoneTransforms(nullptr);
	PreviewComponent->ClearMotionVector();
	FlushRenderingCommands();


	TArray<FFinalSkinVertex> RefPoseFinalVerts = static_cast<FSkeletalMeshObjectCPUSkin*>(PreviewComponent->MeshObject)->GetCachedFinalVertices();

	TArray<FVector4> GridVertPos;
	TArray<FVector4> GridVertNormal;

	float MaxValueOffset = 0.f;

	float MaxValuePosBone = 0.f;

	const int32 PerFrameArrayNum_Vert = Profile->OverrideSize_Vert.X * Profile->RowsPerFrame_Vert;
	const int32 PerFrameArrayNum_Bone = Profile->OverrideSize_Bone.X;



	TArray <FVector4> ZeroedPos;
	ZeroedPos.SetNumZeroed(PerFrameArrayNum_Vert);
	TArray <FVector4> ZeroedNorm;
	ZeroedNorm.SetNumZeroed(PerFrameArrayNum_Vert);

	// YOW, need different sizes for vert and bone textures.
	TArray <FVector4> ZeroedBonePos;
	ZeroedBonePos.SetNumZeroed(PerFrameArrayNum_Bone);
	TArray <FVector4> ZeroedBoneRot;
	ZeroedBoneRot.SetNumZeroed(PerFrameArrayNum_Bone);

	FSkeletalMeshRenderData& SkeletalMeshRenderData = PreviewComponent->MeshObject->GetSkeletalMeshRenderData();
	FSkeletalMeshLODRenderData& LODData = SkeletalMeshRenderData.LODRenderData[0];
	const auto& ActiveBoneIndices = LODData.ActiveBoneIndices;
	TArray <FMatrix> RefToLocal;

	// 3?Store Values
	// Vert Anim
	if (Profile->Anims_Vert.Num())
	{
		for (int32 i = 0; i < Profile->Anims_Vert.Num(); i++)
		{
			UAnimSingleNodeInstance* SingleNodeInstance = PreviewComponent->GetSingleNodeInstance();

			const float Length = SingleNodeInstance->GetLength();
			const float Step_Vert = Length / Profile->Anims_Vert[i].NumFrames;

			Profile->Anims_Vert[i].Speed_Generated = 1.f / Length;
			Profile->Anims_Vert[i].AnimStart_Generated = Profile->CalcStartHeightOfAnim_Vert(i);

			{
				for (int32 j = 0; j < Profile->Anims_Vert[i].NumFrames; j++)
				{
					const float AnimTime = Step_Vert * j;

					PreviewComponent->SetPosition(AnimTime, false);
					PreviewComponent->RefreshBoneTransforms(nullptr);
					PreviewComponent->RecreateClothingActors();
					// Cloth Ticking
					for (int32 P = 0; P < 8; P++) PreviewComponent->GetWorld()->Tick(ELevelTick::LEVELTICK_All, Step_Vert);

					PreviewComponent->ClearMotionVector();

					FlushRenderingCommands();

					TArray<FFinalSkinVertex> FinalVerts;
					FinalVerts = static_cast<FSkeletalMeshObjectCPUSkin*>(PreviewComponent->MeshObject)->GetCachedFinalVertices();

					for (int32 k = 0; k < UniqueSourceIDs.Num(); k++)
					{
						const int32 IndexInZeroed = k;
						const int32 VertID = UniqueSourceIDs[k];
						const FVector Delta = FinalVerts[VertID].Position - RefPoseFinalVerts[VertID].Position;
						MaxValueOffset = FMath::Max(Delta.GetAbsMax(), MaxValueOffset);
						ZeroedPos[IndexInZeroed] = Delta;

						const FVector DeltaNormal = FinalVerts[VertID].TangentZ.ToFVector() - RefPoseFinalVerts[VertID].TangentZ.ToFVector();
						ZeroedNorm[IndexInZeroed] = DeltaNormal;
					}

					GridVertPos.Append(ZeroedPos);
					GridVertNormal.Append(ZeroedNorm);
				}
			}
		}
	}


	// 4?Put Mesh back into ref pose
	{
		PreviewComponent->RefreshBoneTransforms(nullptr);

		PreviewComponent->ClearMotionVector();

		// switch back to non CPU skinning
		{
			// switch skinning mode, LOD etc. back
			PreviewComponent->SetForcedLOD(0);
			PreviewComponent->SetCPUSkinningEnabled(bCachedCPUSkinning, bRecreateRenderStateImmediately);
		}

		FlushRenderingCommands();
	}

	Profile->MaxValueOffset_Vert = MaxValueOffset;
	Profile->MaxValuePosition_Bone = MaxValuePosBone;

	Profile->MarkPackageDirty();

	OutGridVertPos = GridVertPos;
	OutGridVertNormal = GridVertNormal;
}

static void EncodeData_Vec(const TArray <FVector4>& VectorData, const float MaxValue, const bool HDR, TArray <FFloat16Color>& Data)
{
	for (int32 i = 0; i < VectorData.Num(); i++)
	{
		FVector VectorValue = VectorData[i];
		const float MaxDim = VectorValue.GetAbsMax();

		if (MaxDim > 0.f)
		{
			float Mag;
			if (HDR)
			{
				VectorValue.X = VectorValue.X / MaxDim;
				VectorValue.Y = VectorValue.Y / MaxDim;
				VectorValue.Z = VectorValue.Z / MaxDim;
				Mag = -1.0 + ((MaxDim / MaxValue) * 2.0);

				Data[i] = FLinearColor(VectorValue.X, VectorValue.Y, VectorValue.Z, Mag);
			}
			else
			{
				VectorValue.X = UVertexAnimFunctionLibrary::EncodeFloat(VectorValue.X, MaxDim);
				VectorValue.Y = UVertexAnimFunctionLibrary::EncodeFloat(VectorValue.Y, MaxDim);
				VectorValue.Z = UVertexAnimFunctionLibrary::EncodeFloat(VectorValue.Z, MaxDim);
				Mag = MaxDim / MaxValue;

				Data[i] = FLinearColor(VectorValue.X, VectorValue.Y, VectorValue.Z, Mag);
			}
		}
	}
}

static UTexture2D* SetTexture2(
	UWorld* World, const FString PackagePath, const FString Name,
	UTexture2D* Texture,
	const int32 InSizeX, const int32 InSizeY,
	const TArray <FFloat16Color>& Data, //const TArray <FVector>& VectorData,
	EObjectFlags InObjectFlags)
{
	UTexture2D* NewTexture;

	{

		if (Texture != NULL)
		{
			NewTexture = NewObject<UTexture2D>(Texture->GetOuter(), FName(*Texture->GetName()), InObjectFlags);

		}
		else
		{
			UPackage* Package = CreatePackage(NULL, *(PackagePath + Name));
			check(Package);
			Package->FullyLoad();

			NewTexture = NewObject<UTexture2D>(Package, *Name, InObjectFlags);

			FAssetRegistryModule::AssetCreated(NewTexture);
		}

		checkf(NewTexture, TEXT("%s"), *Name);

		NewTexture->Source.Init(InSizeX, InSizeY, /*NumSlices=*/ 1, /*NumMips=*/ 1, TSF_RGBA16F);
		uint32* TextureData = (uint32*)NewTexture->Source.LockMip(0);
		const int32 TextureDataSize = NewTexture->Source.CalcMipSize(0);

		FMemory::Memcpy(TextureData, Data.GetData(), TextureDataSize); // this did not blow up 

		NewTexture->Source.UnlockMip(0);

		NewTexture->PostEditChange();

		NewTexture->MarkPackageDirty();
	}

	return NewTexture;
}

// Helper function for ConvertMeshesToStaticMesh
static void AddOrDuplicateMaterial(UMaterialInterface* InMaterialInterface, const FString& InPackageName, TArray<UMaterialInterface*>& OutMaterials)
{
	if (InMaterialInterface && !InMaterialInterface->GetOuter()->IsA<UPackage>())
	{
		// Convert runtime material instances to new concrete material instances
		// Create new package
		FString OriginalMaterialName = InMaterialInterface->GetName();
		FString MaterialPath = FPackageName::GetLongPackagePath(InPackageName) / OriginalMaterialName;
		FString MaterialName;
		FAssetToolsModule& AssetToolsModule = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools");
		AssetToolsModule.Get().CreateUniqueAssetName(MaterialPath, TEXT(""), MaterialPath, MaterialName);
		UPackage* MaterialPackage = CreatePackage(NULL, *MaterialPath);

		// Duplicate the object into the new package
		UMaterialInterface* NewMaterialInterface = DuplicateObject<UMaterialInterface>(InMaterialInterface, MaterialPackage, *MaterialName);
		NewMaterialInterface->SetFlags(RF_Public | RF_Standalone);

		if (UMaterialInstanceDynamic* MaterialInstanceDynamic = Cast<UMaterialInstanceDynamic>(NewMaterialInterface))
		{
			UMaterialInstanceDynamic* OldMaterialInstanceDynamic = CastChecked<UMaterialInstanceDynamic>(InMaterialInterface);
			MaterialInstanceDynamic->K2_CopyMaterialInstanceParameters(OldMaterialInstanceDynamic);
		}

		NewMaterialInterface->MarkPackageDirty();

		FAssetRegistryModule::AssetCreated(NewMaterialInterface);

		InMaterialInterface = NewMaterialInterface;
	}

	OutMaterials.Add(InMaterialInterface);
}

// Helper function for ConvertMeshesToStaticMesh
template <typename ComponentType>
static void ProcessMaterials(ComponentType* InComponent, const FString& InPackageName, TArray<UMaterialInterface*>& OutMaterials)
{
	const int32 NumMaterials = InComponent->GetNumMaterials();
	for (int32 MaterialIndex = 0; MaterialIndex < NumMaterials; MaterialIndex++)
	{
		UMaterialInterface* MaterialInterface = InComponent->GetMaterial(MaterialIndex);
		AddOrDuplicateMaterial(MaterialInterface, InPackageName, OutMaterials);
	}
}

// Helper function for ConvertMeshesToStaticMesh
static bool IsValidSkinnedMeshComponent(USkinnedMeshComponent* InComponent)
{
	return InComponent && InComponent->MeshObject && InComponent->IsVisible();
}

/** Helper struct for tracking validity of optional buffers */
struct FRawMeshTracker
{
	FRawMeshTracker()
		: bValidColors(false)
	{
		FMemory::Memset(bValidTexCoords, 0);
	}

	bool bValidTexCoords[MAX_MESH_TEXTURE_COORDS];
	bool bValidColors;
};

// Helper function for ConvertMeshesToStaticMesh
static void SkinnedMeshToRawMeshes(USkinnedMeshComponent* InSkinnedMeshComponent, int32 InOverallMaxLODs, const FMatrix& InComponentToWorld, const FString& InPackageName, TArray<FRawMeshTracker>& OutRawMeshTrackers, TArray<FRawMesh>& OutRawMeshes, TArray<UMaterialInterface*>& OutMaterials)
{
	const int32 BaseMaterialIndex = OutMaterials.Num();

	// Export all LODs to raw meshes
	const int32 NumLODs = InSkinnedMeshComponent->GetNumLODs();

	for (int32 OverallLODIndex = 0; OverallLODIndex < InOverallMaxLODs; OverallLODIndex++)
	{
		int32 LODIndexRead = FMath::Min(OverallLODIndex, NumLODs - 1);

		FRawMesh& RawMesh = OutRawMeshes[OverallLODIndex];
		FRawMeshTracker& RawMeshTracker = OutRawMeshTrackers[OverallLODIndex];
		const int32 BaseVertexIndex = RawMesh.VertexPositions.Num();

		FSkeletalMeshLODInfo& SrcLODInfo = *(InSkinnedMeshComponent->SkeletalMesh->GetLODInfo(LODIndexRead));

		// Get the CPU skinned verts for this LOD
		TArray<FFinalSkinVertex> FinalVertices;
		InSkinnedMeshComponent->GetCPUSkinnedVertices(FinalVertices, LODIndexRead);

		FSkeletalMeshRenderData& SkeletalMeshRenderData = InSkinnedMeshComponent->MeshObject->GetSkeletalMeshRenderData();
		FSkeletalMeshLODRenderData& LODData = SkeletalMeshRenderData.LODRenderData[LODIndexRead];

		// Copy skinned vertex positions
		for (int32 VertIndex = 0; VertIndex < FinalVertices.Num(); ++VertIndex)
		{
			RawMesh.VertexPositions.Add(InComponentToWorld.TransformPosition(FinalVertices[VertIndex].Position));
		}

		const uint32 NumTexCoords = FMath::Min(LODData.StaticVertexBuffers.StaticMeshVertexBuffer.GetNumTexCoords(), (uint32)MAX_MESH_TEXTURE_COORDS);
		const int32 NumSections = LODData.RenderSections.Num();
		FRawStaticIndexBuffer16or32Interface& IndexBuffer = *LODData.MultiSizeIndexContainer.GetIndexBuffer();

		for (int32 SectionIndex = 0; SectionIndex < NumSections; SectionIndex++)
		{
			const FSkelMeshRenderSection& SkelMeshSection = LODData.RenderSections[SectionIndex];
			if (InSkinnedMeshComponent->IsMaterialSectionShown(SkelMeshSection.MaterialIndex, LODIndexRead))
			{
				// Build 'wedge' info
				const int32 NumWedges = SkelMeshSection.NumTriangles * 3;
				for (int32 WedgeIndex = 0; WedgeIndex < NumWedges; WedgeIndex++)
				{
					const int32 VertexIndexForWedge = IndexBuffer.Get(SkelMeshSection.BaseIndex + WedgeIndex);

					RawMesh.WedgeIndices.Add(BaseVertexIndex + VertexIndexForWedge);

					const FFinalSkinVertex& SkinnedVertex = FinalVertices[VertexIndexForWedge];
					const FVector TangentX = InComponentToWorld.TransformVector(SkinnedVertex.TangentX.ToFVector());
					const FVector TangentZ = InComponentToWorld.TransformVector(SkinnedVertex.TangentZ.ToFVector());
					const FVector4 UnpackedTangentZ = SkinnedVertex.TangentZ.ToFVector4();
					const FVector TangentY = (TangentZ ^ TangentX).GetSafeNormal() * UnpackedTangentZ.W;

					RawMesh.WedgeTangentX.Add(TangentX);
					RawMesh.WedgeTangentY.Add(TangentY);
					RawMesh.WedgeTangentZ.Add(TangentZ);

					for (uint32 TexCoordIndex = 0; TexCoordIndex < MAX_MESH_TEXTURE_COORDS; TexCoordIndex++)
					{
						if (TexCoordIndex >= NumTexCoords)
						{
							RawMesh.WedgeTexCoords[TexCoordIndex].AddDefaulted();
						}
						else
						{
							RawMesh.WedgeTexCoords[TexCoordIndex].Add(LODData.StaticVertexBuffers.StaticMeshVertexBuffer.GetVertexUV(VertexIndexForWedge, TexCoordIndex));
							RawMeshTracker.bValidTexCoords[TexCoordIndex] = true;
						}
					}

					if (LODData.StaticVertexBuffers.ColorVertexBuffer.IsInitialized())
					{
						RawMesh.WedgeColors.Add(LODData.StaticVertexBuffers.ColorVertexBuffer.VertexColor(VertexIndexForWedge));
						RawMeshTracker.bValidColors = true;
					}
					else
					{
						RawMesh.WedgeColors.Add(FColor::White);
					}
				}

				int32 MaterialIndex = SkelMeshSection.MaterialIndex;
				// use the remapping of material indices if there is a valid value
				if (SrcLODInfo.LODMaterialMap.IsValidIndex(SectionIndex) && SrcLODInfo.LODMaterialMap[SectionIndex] != INDEX_NONE)
				{
					MaterialIndex = FMath::Clamp<int32>(SrcLODInfo.LODMaterialMap[SectionIndex], 0, InSkinnedMeshComponent->SkeletalMesh->Materials.Num());
				}

				// copy face info
				for (uint32 TriIndex = 0; TriIndex < SkelMeshSection.NumTriangles; TriIndex++)
				{
					RawMesh.FaceMaterialIndices.Add(BaseMaterialIndex + MaterialIndex);
					RawMesh.FaceSmoothingMasks.Add(0); // Assume this is ignored as bRecomputeNormals is false
				}
			}
		}
	}

	ProcessMaterials<USkinnedMeshComponent>(InSkinnedMeshComponent, InPackageName, OutMaterials);
}

//
// =============================================================================================================================================================
//


void UVertexAnimFunctionLibrary::SetDataAtProfile(UVertexAnimProfile* InVertexAnimProfile, UObject* InAnimationAsset, int32 InNumFrames)
{
	if (InVertexAnimProfile == nullptr)
		return;

	if (InAnimationAsset == nullptr)
		return;

	FVASequenceData NewData;
	NewData.SequenceRef = Cast<UAnimationAsset>(InAnimationAsset);
	NewData.NumFrames = InNumFrames;

	InVertexAnimProfile->Anims_Vert.Add(NewData);
}

void UVertexAnimFunctionLibrary::DoBake(UVertexAnimProfile* InVertexAnimProfile, UObject* InSkeletalMeshComponent, const FString& InAssetSavePath)
{
	if (InVertexAnimProfile == nullptr)
		return;

	if (InSkeletalMeshComponent == nullptr)
		return;
	
	USkeletalMeshComponent* MeshComponent = Cast<USkeletalMeshComponent>(InSkeletalMeshComponent);
	UVertexAnimProfile* Profile = InVertexAnimProfile;

	bool bOnlyCreateStaticMesh = false;

	bool DoAnimBake = (Profile != NULL) && !bOnlyCreateStaticMesh;
	bool DoStaticMesh = (Profile != NULL);

	if ((!DoAnimBake) && (!DoStaticMesh)) return;

	TArray<int32> UniqueSourceIDs;
	TArray<TArray<FVector2D>> UVs_VertAnim;
	TArray<TArray<FVector2D>> UVs_BoneAnim1;
	TArray<TArray<FVector2D>> UVs_BoneAnim2;
	TArray<TArray<FColor>> Colors_BoneAnim;

	FString PackageName;// = InAssetSavePath;

	{
		{
			SkinnedMeshVATData(
				MeshComponent,
				Profile,
				UniqueSourceIDs,
				UVs_VertAnim,
				UVs_BoneAnim1,
				UVs_BoneAnim2,
				Colors_BoneAnim);
		}

		if ((Profile->CalcTotalRequiredHeight_Vert() > Profile->OverrideSize_Vert.Y) ||
			(Profile->CalcTotalRequiredHeight_Bone() > Profile->OverrideSize_Bone.Y))
		{
			return;
		}

		if ((Profile->OverrideSize_Vert.GetMax() > 4096) ||
			(Profile->OverrideSize_Bone.GetMax() > 4096))
		{
			return;
		}
	}

	// Create StaticMesh
	if (DoStaticMesh)
	{
		if (Profile->StaticMesh && (!bOnlyCreateStaticMesh))
		{
			PackageName = Profile->StaticMesh->GetOutermost()->GetName();
		}
		else
		{
			FString AssetName = Profile->GetOutermost()->GetName();
			FString Name = MeshComponent->SkeletalMesh->GetName();
			const FString PackagePath = InAssetSavePath + TEXT("/") + Name + TEXT("_VAT");
			PackageName = PackagePath;
		}

		UStaticMesh* StaticMesh = UVertexAnimFunctionLibrary::ConvertMeshesToStaticMesh({ MeshComponent }, FTransform::Identity, PackageName);

		if (Profile->UVChannel_VertAnim != -1) 
			UVertexAnimFunctionLibrary::VATUVsToStaticMeshLODs(StaticMesh, Profile->UVChannel_VertAnim, UVs_VertAnim);

		if (Profile->UVChannel_BoneAnim != -1) 
			UVertexAnimFunctionLibrary::VATUVsToStaticMeshLODs(StaticMesh, Profile->UVChannel_BoneAnim, UVs_BoneAnim1);

		if (Profile->UVChannel_BoneAnim_Full != -1)
		{
			UVertexAnimFunctionLibrary::VATUVsToStaticMeshLODs(StaticMesh, Profile->UVChannel_BoneAnim_Full, UVs_BoneAnim2);
			UVertexAnimFunctionLibrary::VATColorsToStaticMeshLODs(StaticMesh, Colors_BoneAnim);
		}

		Profile->StaticMesh = StaticMesh;
		Profile->MarkPackageDirty();
	}


	if (DoAnimBake)
	{
		int32 TextureWidth_Vert = Profile->OverrideSize_Vert.X;
		int32 TextureHeight_Vert = Profile->OverrideSize_Vert.Y;

		TArray <FVector4> VertPos, VertNormal;
		GatherAndBakeAllAnimVertData(Profile, MeshComponent, UniqueSourceIDs, VertPos, VertNormal);

		FString AssetName = Profile->GetOutermost()->GetName();
		const FString SanitizedBasePackageName = InAssetSavePath;
		const FString PackagePath = FPackageName::GetLongPackagePath(SanitizedBasePackageName) + TEXT("/");

		// Vert Textures
		if (Profile->Anims_Vert.Num())
		{
			TArray <FFloat16Color> Data;
			Data.SetNumZeroed(TextureWidth_Vert * TextureHeight_Vert);


			{
				EncodeData_Vec(VertNormal, 2.f, false, Data); // decided on fixed 2.0 for simplicity

				Profile->NormalsTexture = SetTexture2(MeshComponent->GetWorld(), PackagePath,
					Profile->GetName() + "_Normals", Profile->NormalsTexture,
					TextureWidth_Vert, TextureHeight_Vert,
					Data,
					Profile->GetMaskedFlags() | RF_Public | RF_Standalone);

				Profile->NormalsTexture->Filter = TextureFilter::TF_Nearest;
				Profile->NormalsTexture->NeverStream = true;
				Profile->NormalsTexture->CompressionSettings = TextureCompressionSettings::TC_VectorDisplacementmap;
				Profile->NormalsTexture->SRGB = false;
				Profile->NormalsTexture->Modify();
				Profile->NormalsTexture->MarkPackageDirty();
				Profile->NormalsTexture->PostEditChange();
				Profile->NormalsTexture->UpdateResource();
			}


			{
				EncodeData_Vec(VertPos, Profile->MaxValueOffset_Vert, true, Data);

				Profile->OffsetsTexture = SetTexture2(MeshComponent->GetWorld(), PackagePath,
					Profile->GetName() + "_Offsets", Profile->OffsetsTexture,
					TextureWidth_Vert, TextureHeight_Vert,
					Data,
					Profile->GetMaskedFlags() | RF_Public | RF_Standalone);

				Profile->OffsetsTexture->Filter = TextureFilter::TF_Nearest;
				Profile->OffsetsTexture->NeverStream = true;
				Profile->OffsetsTexture->CompressionSettings = TextureCompressionSettings::TC_HDR;
				Profile->OffsetsTexture->SRGB = false;
				Profile->OffsetsTexture->Modify();
				Profile->OffsetsTexture->MarkPackageDirty();
				Profile->OffsetsTexture->PostEditChange();
				Profile->OffsetsTexture->UpdateResource();
			}
		}
	}
}

// ===============================================================================================================

float UVertexAnimFunctionLibrary::EncodeFloat(const float& T, const float& Bound)
{
	// Divide to normalize, + 1 * 0.5 to account for negative Values
	return ((T / Bound) + 1.f) * 0.5f;
}

UStaticMesh* UVertexAnimFunctionLibrary::ConvertMeshesToStaticMesh(const TArray<UMeshComponent*>& InMeshComponents, const FTransform& InRootTransform, const FString& InPackageName)
{
	UStaticMesh* StaticMesh = nullptr;

	// Build a package name to use
	FString PackageName = InPackageName;
	FString MeshName = *FPackageName::GetLongPackageAssetName(PackageName);

	if (!PackageName.IsEmpty() && !MeshName.IsEmpty())
	{
		TArray<FRawMesh> RawMeshes;
		TArray<UMaterialInterface*> Materials;

		TArray<FRawMeshTracker> RawMeshTrackers;

		FMatrix WorldToRoot = InRootTransform.ToMatrixWithScale().Inverse();

		// first do a pass to determine the max LOD level we will be combining meshes into
		int32 OverallMaxLODs = 0;
		for (UMeshComponent* MeshComponent : InMeshComponents)
		{
			USkinnedMeshComponent* SkinnedMeshComponent = Cast<USkinnedMeshComponent>(MeshComponent);
			UStaticMeshComponent* StaticMeshComponent = Cast<UStaticMeshComponent>(MeshComponent);

			if (IsValidSkinnedMeshComponent(SkinnedMeshComponent))
			{
				USkeletalMesh* SkeletalMesh = SkinnedMeshComponent->SkeletalMesh;
				OverallMaxLODs = FMath::Max(SkeletalMesh->GetResourceForRendering()->LODRenderData.Num(), OverallMaxLODs);
			}
		}

		// Resize raw meshes to accommodate the number of LODs we will need
		RawMeshes.SetNum(OverallMaxLODs);
		RawMeshTrackers.SetNum(OverallMaxLODs);

		// Export all visible components
		for (UMeshComponent* MeshComponent : InMeshComponents)
		{
			FMatrix ComponentToWorld = MeshComponent->GetComponentTransform().ToMatrixWithScale() * WorldToRoot;

			USkinnedMeshComponent* SkinnedMeshComponent = Cast<USkinnedMeshComponent>(MeshComponent);
			UStaticMeshComponent* StaticMeshComponent = Cast<UStaticMeshComponent>(MeshComponent);

			if (IsValidSkinnedMeshComponent(SkinnedMeshComponent))
			{
				SkinnedMeshToRawMeshes(SkinnedMeshComponent, OverallMaxLODs, ComponentToWorld, PackageName, RawMeshTrackers, RawMeshes, Materials);
			}
		}

		uint32 MaxInUseTextureCoordinate = 0;

		// scrub invalid vert color & tex coord data
		check(RawMeshes.Num() == RawMeshTrackers.Num());
		for (int32 RawMeshIndex = 0; RawMeshIndex < RawMeshes.Num(); RawMeshIndex++)
		{
			if (!RawMeshTrackers[RawMeshIndex].bValidColors)
			{
				RawMeshes[RawMeshIndex].WedgeColors.Empty();
			}

			for (uint32 TexCoordIndex = 0; TexCoordIndex < MAX_MESH_TEXTURE_COORDS; TexCoordIndex++)
			{
				if (!RawMeshTrackers[RawMeshIndex].bValidTexCoords[TexCoordIndex])
				{
					RawMeshes[RawMeshIndex].WedgeTexCoords[TexCoordIndex].Empty();
				}
				else
				{
					// Store first texture coordinate index not in use
					MaxInUseTextureCoordinate = FMath::Max(MaxInUseTextureCoordinate, TexCoordIndex);
				}
			}
		}

		// Check if we got some valid data.
		bool bValidData = false;
		for (FRawMesh& RawMesh : RawMeshes)
		{
			if (RawMesh.IsValidOrFixable())
			{
				bValidData = true;
				break;
			}
		}

		if (bValidData)
		{
			// Then find/create it.
			UPackage* Package = CreatePackage(NULL, *PackageName);
			check(Package);

			// Create StaticMesh object
			StaticMesh = NewObject<UStaticMesh>(Package, *MeshName, RF_Public | RF_Standalone);
			StaticMesh->InitResources();

			StaticMesh->LightingGuid = FGuid::NewGuid();

			// Determine which texture coordinate map should be used for storing/generating the lightmap UVs
			const uint32 LightMapIndex = FMath::Min(MaxInUseTextureCoordinate + 1, (uint32)MAX_MESH_TEXTURE_COORDS - 1);

			// Add source to new StaticMesh
			for (FRawMesh& RawMesh : RawMeshes)
			{
				if (RawMesh.IsValidOrFixable())
				{
					FStaticMeshSourceModel& SrcModel = StaticMesh->AddSourceModel();
					SrcModel.BuildSettings.bRecomputeNormals = false;
					SrcModel.BuildSettings.bRecomputeTangents = false;
					SrcModel.BuildSettings.bRemoveDegenerates = true;
					SrcModel.BuildSettings.bUseHighPrecisionTangentBasis = false;
					SrcModel.BuildSettings.bUseFullPrecisionUVs = false;
					SrcModel.BuildSettings.bGenerateLightmapUVs = true;
					SrcModel.BuildSettings.SrcLightmapIndex = 0;
					SrcModel.BuildSettings.DstLightmapIndex = LightMapIndex;
					SrcModel.SaveRawMesh(RawMesh);
				}
			}

			// Copy materials to new mesh 
			for (UMaterialInterface* Material : Materials)
			{
				StaticMesh->StaticMaterials.Add(FStaticMaterial(Material));
			}

			//Set the Imported version before calling the build
			StaticMesh->ImportVersion = EImportStaticMeshVersion::LastVersion;

			// Set light map coordinate index to match DstLightmapIndex
			StaticMesh->LightMapCoordinateIndex = LightMapIndex;

			// setup section info map
			for (int32 RawMeshLODIndex = 0; RawMeshLODIndex < RawMeshes.Num(); RawMeshLODIndex++)
			{
				const FRawMesh& RawMesh = RawMeshes[RawMeshLODIndex];
				TArray<int32> UniqueMaterialIndices;
				for (int32 MaterialIndex : RawMesh.FaceMaterialIndices)
				{
					UniqueMaterialIndices.AddUnique(MaterialIndex);
				}

				int32 SectionIndex = 0;
				for (int32 UniqueMaterialIndex : UniqueMaterialIndices)
				{
					StaticMesh->GetSectionInfoMap().Set(RawMeshLODIndex, SectionIndex, FMeshSectionInfo(UniqueMaterialIndex));
					SectionIndex++;
				}
			}
			StaticMesh->GetOriginalSectionInfoMap().CopyFrom(StaticMesh->GetSectionInfoMap());

			// Build mesh from source
			StaticMesh->Build(false);
			StaticMesh->PostEditChange();

			StaticMesh->MarkPackageDirty();

			// Notify asset registry of new asset
			FAssetRegistryModule::AssetCreated(StaticMesh);

			//// Display notification so users can quickly access the mesh
			//if (GIsEditor)
			//{
			//	FNotificationInfo Info(FText::Format(LOCTEXT("SkeletalMeshConverted", "Successfully Converted Mesh"), FText::FromString(StaticMesh->GetName())));
			//	Info.ExpireDuration = 8.0f;
			//	Info.bUseLargeFont = false;
			//	Info.Hyperlink = FSimpleDelegate::CreateLambda([=]() { GEditor->GetEditorSubsystem<UAssetEditorSubsystem>()->OpenEditorForAssets(TArray<UObject*>({ StaticMesh })); });
			//	Info.HyperlinkText = FText::Format(LOCTEXT("OpenNewAnimationHyperlink", "Open {0}"), FText::FromString(StaticMesh->GetName()));
			//	TSharedPtr<SNotificationItem> Notification = FSlateNotificationManager::Get().AddNotification(Info);
			//	if (Notification.IsValid())
			//	{
			//		Notification->SetCompletionState(SNotificationItem::CS_Success);
			//	}
			//}
		}
	}

	return StaticMesh;
}



void UVertexAnimFunctionLibrary::VATUVsToStaticMeshLODs(UStaticMesh* StaticMesh, const int32 UVChannel, const TArray<TArray<FVector2D>>& UVs)
{
	for (int32 LOD = 0; LOD < StaticMesh->GetNumLODs(); LOD++)
	{
		const uint32 PaintingMeshLODIndex = LOD;

		if (StaticMesh->IsSourceModelValid(PaintingMeshLODIndex))
		{
			if (StaticMesh->GetSourceModel(PaintingMeshLODIndex).IsRawMeshEmpty() == false)
			{
				const uint32 NumUVChannels = StaticMesh->GetNumUVChannels(PaintingMeshLODIndex);
				// Extract the raw mesh.
				FRawMesh Mesh;
				StaticMesh->GetSourceModel(PaintingMeshLODIndex).LoadRawMesh(Mesh);

				// Build a mapping of vertex positions to vertex colors.
				for (int32 WedgeIndex = 0; WedgeIndex < Mesh.WedgeIndices.Num(); ++WedgeIndex)
				{
					int32 VertID = Mesh.WedgeIndices[WedgeIndex];
					FVector Position = Mesh.VertexPositions[VertID];

					for (uint32 TexCoordIndex = 0; TexCoordIndex < MAX_MESH_TEXTURE_COORDS; TexCoordIndex++)
					{
						if (TexCoordIndex <= NumUVChannels)//(!RawMeshTrackers[RawMeshIndex].bValidTexCoords[TexCoordIndex])
						{
							if ((TexCoordIndex == UVChannel))
							{
								// Mesh.WedgeTexCoords[TexCoordIndex].Empty();
								if (Mesh.WedgeTexCoords[TexCoordIndex].Num() != Mesh.WedgeIndices.Num())
									Mesh.WedgeTexCoords[TexCoordIndex].SetNum(Mesh.WedgeIndices.Num());

								Mesh.WedgeTexCoords[TexCoordIndex][WedgeIndex] = UVs[PaintingMeshLODIndex][VertID];
							}
							else if (TexCoordIndex >= NumUVChannels)
							{
								Mesh.WedgeTexCoords[TexCoordIndex].Empty();
							}
						}
						else
						{
							Mesh.WedgeTexCoords[TexCoordIndex].Empty();
						}
					}
				}

				// Determine which texture coordinate map should be used for storing/generating the lightmap UVs
				const uint32 LightMapIndex = FMath::Min(UVChannel == NumUVChannels ? NumUVChannels + 1 : NumUVChannels, (uint32)MAX_MESH_TEXTURE_COORDS - 1);
				StaticMesh->GetSourceModel(PaintingMeshLODIndex).BuildSettings.DstLightmapIndex = LightMapIndex;

				// Save the new raw mesh.
				StaticMesh->GetSourceModel(PaintingMeshLODIndex).SaveRawMesh(Mesh);


				StaticMesh->ImportVersion = EImportStaticMeshVersion::LastVersion;
				// Set light map coordinate index to match DstLightmapIndex
				StaticMesh->LightMapCoordinateIndex = LightMapIndex;


			}
		}
	}

	// Build mesh from source
	StaticMesh->Build(false);
	StaticMesh->PostEditChange();
	StaticMesh->MarkPackageDirty();
}

void UVertexAnimFunctionLibrary::VATColorsToStaticMeshLODs(UStaticMesh* StaticMesh, const TArray<TArray<FColor>>& Colors)
{
	for (int32 LOD = 0; LOD < StaticMesh->GetNumLODs(); LOD++)
	{
		const uint32 PaintingMeshLODIndex = LOD;

		if (StaticMesh->IsSourceModelValid(PaintingMeshLODIndex))
		{
			if (StaticMesh->GetSourceModel(PaintingMeshLODIndex).IsRawMeshEmpty() == false)
			{
				const uint32 NumUVChannels = StaticMesh->GetNumUVChannels(PaintingMeshLODIndex);
				// Extract the raw mesh.
				FRawMesh Mesh;
				StaticMesh->GetSourceModel(PaintingMeshLODIndex).LoadRawMesh(Mesh);

				// Reserve space for the new vertex colors.
				if (Mesh.WedgeColors.Num() == 0 || Mesh.WedgeColors.Num() != Mesh.WedgeIndices.Num())
				{
					Mesh.WedgeColors.Empty(Mesh.WedgeIndices.Num());
					Mesh.WedgeColors.AddUninitialized(Mesh.WedgeIndices.Num());
				}

				// Build a mapping of vertex positions to vertex colors.
				for (int32 WedgeIndex = 0; WedgeIndex < Mesh.WedgeIndices.Num(); ++WedgeIndex)
				{
					int32 VertID = Mesh.WedgeIndices[WedgeIndex];
					FVector Position = Mesh.VertexPositions[VertID];
					Mesh.WedgeColors[WedgeIndex] = Colors[PaintingMeshLODIndex][VertID];
				}

				// Save the new raw mesh.
				StaticMesh->GetSourceModel(PaintingMeshLODIndex).SaveRawMesh(Mesh);
				StaticMesh->ImportVersion = EImportStaticMeshVersion::LastVersion;
			}
		}
	}

	// Build mesh from source
	StaticMesh->Build(false);
	StaticMesh->PostEditChange();
	StaticMesh->MarkPackageDirty();
}
