// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Actor/ProjectYJCharacter.h"
#include "YJCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTYJ_API AYJCharacter : public AProjectYJCharacter
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	void RegisterAtSignificanceManager();
	void UnregisterAtSignificanceManager();

public:
	// Whether to apply Animation URO
	UPROPERTY(EditAnywhere, Category = URO)
		bool m_bEnableUpdateRateOptimizations;

	// Whether to interpolate between skipped frames
	UPROPERTY(EditAnywhere, Category = URO)
		bool m_bInterpolateSkippedFrames;

	// Number of frames to skip based on LOD
	UPROPERTY(EditAnywhere, Category = URO)
		TArray<int32> m_SkippedFramesByLOD;
};
