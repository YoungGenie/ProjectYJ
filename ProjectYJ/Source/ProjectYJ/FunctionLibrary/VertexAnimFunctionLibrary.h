// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "VertexAnimFunctionLibrary.generated.h"

/**
 * 
 */

class UVertexAnimProfile;
class UMaterialInstanceConstant;

USTRUCT(BlueprintType)
struct FVertexAnimProfileData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
		int32 NumFrames = 0;

	UPROPERTY(BlueprintReadWrite)
		int32 AnimStart_Generated = 0;

	UPROPERTY(BlueprintReadWrite)
		float Speed_Generated = 0.f;

	UPROPERTY(BlueprintReadWrite)
		int32 RowsPerFrame = 0;

	UPROPERTY(BlueprintReadWrite)
		float MaxValueOffset = 0;

	UPROPERTY(BlueprintReadWrite)
		UTexture2D* OffsetsTexture = nullptr;

	UPROPERTY(BlueprintReadWrite)
		UTexture2D* NormalsTexture = nullptr;
};

UCLASS()
class PROJECTYJ_API UVertexAnimFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Vertex Animation Tool")
		static void SetDataAtProfile(UVertexAnimProfile* InVertexAnimProfile, UObject* InAnimationAsset, int32 InNumFrames);

	UFUNCTION(BlueprintCallable, Category = "Vertex Animation Tool")
		static UStaticMesh* DoBake(UVertexAnimProfile* InVertexAnimProfile, UObject* InSkeletalMeshComponent, const FString& InAssetSavePath);

	UFUNCTION(BlueprintCallable, Category = "Vertex Animation Tool")
		static FVertexAnimProfileData GetVertexAnimProfileData(UVertexAnimProfile* InVertexAnimProfile);

public:
	static float EncodeFloat(const float& T, const float& Bound);
	static UStaticMesh* ConvertMeshesToStaticMesh(const TArray<UMeshComponent*>& InMeshComponents, const FTransform& InRootTransform = FTransform::Identity, const FString& InPackageName = FString());
	static void VATUVsToStaticMeshLODs(UStaticMesh* StaticMesh, const int32 UVChannel, const TArray <TArray <FVector2D>>& UVs);
	static void VATColorsToStaticMeshLODs(UStaticMesh* StaticMesh, const TArray <TArray <FColor>>& Colors);
};
