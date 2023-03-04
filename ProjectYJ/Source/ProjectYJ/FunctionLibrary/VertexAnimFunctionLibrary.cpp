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


void UVertexAnimFunctionLibrary::SetDataAtProfile(UVertexAnimProfile* InVertexAnimProfile, TSubclassOf<UAnimationAsset> InAnimationAsset, int32 InNumFrames)
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

void UVertexAnimFunctionLibrary::DoBake(UVertexAnimProfile* InVertexAnimProfile, USkeletalMesh* InSkeletalMesh, const FString& InAssetSavePath)
{
	USkeletalMeshComponent* PreviewComponent = NewObject<USkeletalMeshComponent>();
	PreviewComponent->GlobalAnimRateScale = 0.f;
	PreviewComponent->SetSkeletalMesh(InSkeletalMesh);

	UVertexAnimProfile* Profile = InVertexAnimProfile;

	FString MeshName;
	FString PackageName;
	bool bOnlyCreateStaticMesh = false;

	/*
	{
		FString NewNameSuggestion = FString(TEXT("VertexAnimStaticMesh"));
		FString PackageNameSuggestion = FString(TEXT("/Game/Meshes/")) + NewNameSuggestion;
		FString Name;
		FAssetToolsModule& AssetToolsModule = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools");
		AssetToolsModule.Get().CreateUniqueAssetName(PackageNameSuggestion, TEXT(""), PackageNameSuggestion, Name);

		//TSharedPtr<SDlgPickAssetPath> PickAssetPathWidget =
		TSharedPtr<SPickAssetDialog> PickAssetPathWidget =
			SNew(SPickAssetDialog)
			.Title(LOCTEXT("BakeAnimDialog", "Bake Anim Dialog"))
			.DefaultAssetPath(FText::FromString(PackageNameSuggestion));

		if (PickAssetPathWidget->ShowModal() == EAppReturnType::Ok)
		{
			// Get the full name of where we want to create the mesh asset.
			Profile = PickAssetPathWidget->GetSelectedProfile();
			bOnlyCreateStaticMesh = PickAssetPathWidget->GetOnlyCreateStaticMesh();

			PackageName = PickAssetPathWidget->GetFullAssetPath().ToString();
			MeshName = FPackageName::GetLongPackageAssetName(PackageName);

			// Check if the user inputed a valid asset name, if they did not, give it the generated default name
			if (MeshName.IsEmpty())
			{
				// Use the defaults that were already generated.
				PackageName = PackageNameSuggestion;
				MeshName = *Name;
			}
		}
	}
	*/

	bool DoAnimBake = (Profile != NULL) && !bOnlyCreateStaticMesh;
	bool DoStaticMesh = (Profile != NULL);

	if ((!DoAnimBake) && (!DoStaticMesh)) return;

	TArray<int32> UniqueSourceIDs;
	TArray<TArray<FVector2D>> UVs_VertAnim;
	TArray<TArray<FVector2D>> UVs_BoneAnim1;
	TArray<TArray<FVector2D>> UVs_BoneAnim2;
	TArray<TArray<FColor>> Colors_BoneAnim;

	/*
	{
		{
			SkinnedMeshVATData(
				PreviewComponent,
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
			FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("SelectedProfileRequiresMoreHeight", "Selected Profile Requires More Texture Height"));
			return;
		}

		if ((Profile->OverrideSize_Vert.GetMax() > 4096) ||
			(Profile->OverrideSize_Bone.GetMax() > 4096))
		{
			FMessageDialog::Open(EAppMsgType::Ok,
				LOCTEXT("TooMuch", "Warning: required texture size exceeds UE texture resolution limit, Mesh has too many vertices and/or Profile has too many animation frames"));
			return;
		}
	}
	*/

	if (DoStaticMesh)
	{
		if (Profile->StaticMesh && (!bOnlyCreateStaticMesh))
		{
			PackageName = Profile->StaticMesh->GetOutermost()->GetName();
		}
		else
		{
			FString AssetName = Profile->GetOutermost()->GetName();
			//FString Name = Profile->GetName();
			FString Name = PreviewComponent->SkeletalMesh->GetName();
			//FString AssetName = PreviewComponent->SkeletalMesh->GetOutermost()->GetName();
			const FString SanitizedBasePackageName = InAssetSavePath;
			const FString PackagePath = FPackageName::GetLongPackagePath(SanitizedBasePackageName) + TEXT("/") + Name + TEXT("_VAT");
			PackageName = PackagePath;
		}

		UStaticMesh* StaticMesh = UVertexAnimFunctionLibrary::ConvertMeshesToStaticMesh({ PreviewComponent }, FTransform::Identity, PackageName);

		if (Profile->UVChannel_VertAnim != -1) UVertexAnimFunctionLibrary::VATUVsToStaticMeshLODs(StaticMesh, Profile->UVChannel_VertAnim, UVs_VertAnim);
		if (Profile->UVChannel_BoneAnim != -1) UVertexAnimFunctionLibrary::VATUVsToStaticMeshLODs(StaticMesh, Profile->UVChannel_BoneAnim, UVs_BoneAnim1);
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
		GatherAndBakeAllAnimVertData(Profile, PreviewComponent, UniqueSourceIDs, VertPos, VertNormal);

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

				Profile->NormalsTexture = SetTexture2(PreviewComponent->GetWorld(), PackagePath,
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

				Profile->OffsetsTexture = SetTexture2(PreviewComponent->GetWorld(), PackagePath,
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
				OverallMaxLODs = FMath::Max(SkinnedMeshComponent->MeshObject->GetSkeletalMeshRenderData().LODRenderData.Num(), OverallMaxLODs);
			}
			else if (false)//(IsValidStaticMeshComponent(StaticMeshComponent))
			{
				OverallMaxLODs = FMath::Max(StaticMeshComponent->GetStaticMesh()->RenderData->LODResources.Num(), OverallMaxLODs);
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
			else if (false)//(IsValidStaticMeshComponent(StaticMeshComponent))
			{
				//StaticMeshToRawMeshes(StaticMeshComponent, OverallMaxLODs, ComponentToWorld, PackageName, RawMeshTrackers, RawMeshes, Materials);
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
