// Fill out your copyright notice in the Description page of Project Settings.


#include "FunctionLibrary/VertexAnimFunctionLibrary.h"
#include "VertexAnimUtils.h"
#include "VertexAnimProfile.h"

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

void UVertexAnimFunctionLibrary::DoBake(UVertexAnimProfile* InVertexAnimProfile, USkeletalMesh* InSkeletalMesh)
{

}
