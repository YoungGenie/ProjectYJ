// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SignificanceManagerSetting.generated.h"

/**
 * 
 */
UCLASS(config = Engine, defaultconfig)
class PROJECTYJ_API USignificanceManagerSetting : public UObject
{
	GENERATED_BODY()
	
public:
	USignificanceManagerSetting();

public:
	uint32 GetTotalActiveCount();

	uint32 GetActiveCountByPriority(uint32 InPriority);

	uint32 GetMaxPriority();

	void SetActiveCount(uint32 InPriority, uint32 InActiveCount);

	void SetActiveCount(TArray<uint32>& InPriorityArray, uint32 InActiveCount);

	void RemovePriority(uint32 InPriority);

public:
	UPROPERTY(EditAnywhere, Config, Category = "Default", meta = (DisplayName = "Use SignificanceManager"))
		bool bUseSignificanceManager;

	UPROPERTY(EditAnywhere, Config, Category = "Default", meta = (DisplayName = "Active Count By Priority"))
		TMap<uint32, uint32> m_ActiveCountMap;

	UPROPERTY(EditAnywhere, Config, Category = "Default", meta = (DisplayName = "Max Distance"))
		float m_MaxDistance;

	UPROPERTY(EditAnywhere, Config, Category = "Default", meta = (DisplayName = "Distance Section"))
		uint32 m_DistanceSection;

	UPROPERTY(EditAnywhere, Config, Category = "Default", meta = (DisplayName = "Max Tick Interval"))
		float m_MaxTickInterval;
};
