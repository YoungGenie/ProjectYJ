// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "VertexAnimFunctionLibrary.generated.h"

/**
 * 
 */

class UVertexAnimProfile;

UCLASS()
class PROJECTYJ_API UVertexAnimFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Vertex Animation Tool")
		static void SetDataAtProfile(UVertexAnimProfile* InVertexAnimProfile, TSubclassOf<UAnimationAsset> InAnimationAsset, int32 InNumFrames);

	UFUNCTION(BlueprintCallable, Category = "Vertex Animation Tool")
		static void DoBake(UVertexAnimProfile* InVertexAnimProfile, USkeletalMesh* InSkeletalMesh);
};
