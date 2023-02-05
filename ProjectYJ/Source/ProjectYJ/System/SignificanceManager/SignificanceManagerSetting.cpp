// Fill out your copyright notice in the Description page of Project Settings.


#include "SignificanceManagerSetting.h"

#if WITH_EDITOR

#include "ISettingsModule.h"

#endif

#define LOCTEXT_NAMESPACE "USignificanceManager"

USignificanceManagerSetting::USignificanceManagerSetting()
{
#if WITH_EDITOR
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("settings"))
	{
		SettingsModule->RegisterSettings("Project", "YJ", "SignificanceManager",
			LOCTEXT("RuntimeSettingsName", "SignificanceManager"),
			LOCTEXT("RuntimeSettingsDescription", "Setting SignificanceManager"),
			GetMutableDefault<USignificanceManagerSetting>());
	}
#endif

	bUseSignificanceManager = true;
	m_ActiveCountMap = { {0, 30}, {1, 30}, {2, 40} };
	m_MaxDistance = 10000.0f;
	m_DistanceSection = 5;
	m_MaxTickInterval = 0.25f;
}

uint32 USignificanceManagerSetting::GetTotalActiveCount()
{
	uint32 TotalActiveCount = 0;
	for (TPair<uint32, uint32> ActiveCount : m_ActiveCountMap)
	{
		TotalActiveCount += ActiveCount.Value;
	}
	return TotalActiveCount;
}

uint32 USignificanceManagerSetting::GetActiveCountByPriority(uint32 InPriority)
{
	return m_ActiveCountMap.FindRef(InPriority);
}

uint32 USignificanceManagerSetting::GetMaxPriority()
{
	TArray<uint32> PriorityArray;
	m_ActiveCountMap.GenerateKeyArray(PriorityArray);

	uint32 MaxPriority = 0;
	for (uint32 Priority : PriorityArray)
	{
		if (MaxPriority < Priority)
		{
			MaxPriority = Priority;
		}
	}
	return MaxPriority;
}

void USignificanceManagerSetting::SetActiveCount(uint32 InPriority, uint32 InActiveCount)
{
	uint32* ActiveCountPtr = m_ActiveCountMap.Find(InPriority);

	if (ActiveCountPtr == nullptr)
	{
		m_ActiveCountMap.Add(InPriority, InActiveCount);
	}
	else
	{
		*ActiveCountPtr = InActiveCount;
	}
}

void USignificanceManagerSetting::SetActiveCount(TArray<uint32>& InPriorityArray, uint32 InActiveCount)
{
	for (uint32 Priority : InPriorityArray)
	{
		SetActiveCount(Priority, InActiveCount);
	}
}

void USignificanceManagerSetting::RemovePriority(uint32 InPriority)
{
	m_ActiveCountMap.Remove(InPriority);
}

#undef LOCTEXT_NAMESPACE