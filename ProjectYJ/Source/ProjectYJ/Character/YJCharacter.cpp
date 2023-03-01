// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/YJCharacter.h"

#include "System/SignificanceManager/YJSignificanceManager.h"

void AYJCharacter::BeginPlay()
{
	Super::BeginPlay();

	RegisterAtSignificanceManager();

	if (m_bEnableUpdateRateOptimizations == true && m_SkippedFramesByLOD.Num() != 0)
	{
		USkeletalMeshComponent* MeshComponent = GetMesh();
		if (MeshComponent != nullptr)
		{
			MeshComponent->bEnableUpdateRateOptimizations = m_bEnableUpdateRateOptimizations;

			MeshComponent->AnimUpdateRateParams->bShouldUseLodMap = true;
			MeshComponent->AnimUpdateRateParams->bInterpolateSkippedFrames = m_bInterpolateSkippedFrames;

			for (int i = 0; i < m_SkippedFramesByLOD.Num(); i++)
			{
				MeshComponent->AnimUpdateRateParams->LODToFrameSkipMap.Add(i, m_SkippedFramesByLOD[i]);
			}
		}
	}
}

void AYJCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	UnregisterAtSignificanceManager();
}

void AYJCharacter::RegisterAtSignificanceManager()
{
	UYJSignificanceManager* SignificanceManager = Cast<UYJSignificanceManager>(FSignificanceManagerModule::Get(GetWorld()));
	SignificanceManager->RegisterObject_YJ(this, 1);
}

void AYJCharacter::UnregisterAtSignificanceManager()
{
	UYJSignificanceManager* SignificanceManager = Cast<UYJSignificanceManager>(FSignificanceManagerModule::Get(GetWorld()));
	SignificanceManager->UnregisterObject_YJ(this);
}
