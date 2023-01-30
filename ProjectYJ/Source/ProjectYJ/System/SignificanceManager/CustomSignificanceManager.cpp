// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomSignificanceManager.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/Actor.h"

#include "SignificanceManagerSetting.h"


bool CompareObjectInfo(const UCustomSignificanceManager::FCustomManagedObjectInfo& A, const UCustomSignificanceManager::FCustomManagedObjectInfo& B)
{
	if (A.GetPriority() == B.GetPriority())
	{
		return A.GetSignificance() > B.GetSignificance();
	}
	else
	{
		return A.GetPriority() < B.GetPriority();
	}
}

typedef bool CompareFunctionType(const UCustomSignificanceManager::FCustomManagedObjectInfo&, const UCustomSignificanceManager::FCustomManagedObjectInfo&);
CompareFunctionType& CompareFunc_ObjectInfo()
{
	return CompareObjectInfo;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------

void UCustomSignificanceManager::FCustomManagedObjectInfo::UpdateSignificance(const TArray<FTransform>& InViewpoints)
{
	OldSignificance = GetSignificance();
	if (InViewpoints.Num() == 0)
	{
		Significance = -1.0f;
	}
	else
	{
		Significance = TNumericLimits<float>::Max();
		for (const FTransform& Viewpoint : InViewpoints)
		{
			const float NewSignificance = SignificanceManager.Get()->CalcSignificance(this, Viewpoint);
			if (NewSignificance < Significance)
			{
				Significance = NewSignificance;
			}
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------

void UCustomSignificanceManager::Update(TArrayView<const FTransform> InViewpoints)
{
	if (m_SignificanceManagerSetting == nullptr)
	{
		m_SignificanceManagerSetting = GetSignificanceManagerSetting();
	}

	if (m_SignificanceManagerSetting->bUseSignificanceManager == true)
	{
		if (m_ActiveObjArray.Num() != m_SignificanceManagerSetting->GetTotalActiveCount())
		{
			InitActiveObjArray();
		}

		// 중요도 계산
		GetFrustum(m_Frustum);
		Viewpoints.Reset(InViewpoints.Num());
		Viewpoints.Append(InViewpoints.GetData(), InViewpoints.Num());

		uint32 ObjArrayIndex = 0;
		for (const TPair<UObject*, FCustomManagedObjectInfo*>& ManagedObjectPair : m_ManagedObjects)
		{
			FCustomManagedObjectInfo* ObjectInfo = ManagedObjectPair.Value;
			ObjectInfo->UpdateSignificance(Viewpoints);
			ObjectInfo->SetMustActive(false);

			if (m_ObjArray.Num() < m_ManagedObjects.Num())
			{
				m_ObjArray.AddUnique(ObjectInfo);
			}
		}

		// 정렬 (우선순위 + 중요도)
		m_ObjArray.StableSort(CompareFunc_ObjectInfo());

		// 활성화 오브젝트 배열 초기화
		for (int i = 0; i < m_ActiveObjArray.Num(); i++)
		{
			m_ActiveObjArray[i] = nullptr;
		}

		// 활성화 오브젝트 선별 & 중요도 처리
		FillActiveObjArray();
	}
	else
	{
		for (const TPair<UObject*, FCustomManagedObjectInfo*>& ManagedObjectPair : m_ManagedObjects)
		{
			FCustomManagedObjectInfo* ObjectInfo = ManagedObjectPair.Value;
			ObjectInfo->SetSignificance(1.0f);
			ActiveObject(ObjectInfo);

			if (m_ObjArray.Num() < m_ManagedObjects.Num())
			{
				m_ObjArray.AddUnique(ObjectInfo);
			}
		}
	}
}

void UCustomSignificanceManager::RegisterObject_Custom(UObject* InObject, uint32 InPriority)
{
	FCustomManagedObjectInfo* ObjectInfo = new FCustomManagedObjectInfo(this, InObject, InPriority);
	ObjectInfo->UpdateSignificance(Viewpoints);
	m_ManagedObjects.Add(InObject, ObjectInfo);
}

void UCustomSignificanceManager::UnregisterObject_Custom(UObject* InObject)
{
	FCustomManagedObjectInfo* ObjectInfo = nullptr;
	if (m_ManagedObjects.RemoveAndCopyValue(InObject, ObjectInfo) == true)
	{
		m_ObjArray.Remove(ObjectInfo);
		m_ActiveObjArray.Remove(ObjectInfo);
		delete ObjectInfo;
	}
}

void UCustomSignificanceManager::UnregisterAll()
{
	for (const TPair<UObject*, FCustomManagedObjectInfo*>& ManagedObjectPair : m_ManagedObjects)
	{
		FCustomManagedObjectInfo* ObjectInfo = ManagedObjectPair.Value;
		delete ObjectInfo;
	}
	m_ManagedObjects.Empty();
	m_ObjArray.Empty();
	m_ActiveObjArray.Empty();
}

void UCustomSignificanceManager::ChangePriority(UObject* InObject, uint32 InPriority)
{
	FCustomManagedObjectInfo* ObjectInfo = m_ManagedObjects.FindRef(InObject);
	if (ObjectInfo != nullptr)
	{
		ObjectInfo->SetPriority(InPriority);
	}
}

void UCustomSignificanceManager::ResetObjects()
{
	for (FCustomManagedObjectInfo* ObjectInfo : m_ObjArray)
	{
		UObject* Object = ObjectInfo->GetObject();
		if (Object == nullptr || Object->IsValidLowLevel() == false)
		{
			continue;
		}

		AActor* Actor = Cast<AActor>(Object);
		if (Actor == nullptr)
		{
			return;
		}

		Actor->SetActorTickEnabled(true);
		Actor->SetActorTickInterval(0);
		Actor->SetActorHiddenInGame(false);
	}
}

void UCustomSignificanceManager::ChangeSignificanceManagerSetting(USignificanceManagerSetting* InSetting)
{
	if (m_SignificanceManagerSetting != nullptr)
	{
		m_SignificanceManagerSetting->MarkPendingKill();
	}

	if (InSetting == nullptr)
	{
		m_SignificanceManagerSetting = NewObject<USignificanceManagerSetting>();
	}
	else
	{
		m_SignificanceManagerSetting = InSetting;
	}
	InitActiveObjArray();
}

USignificanceManagerSetting* UCustomSignificanceManager::GetSignificanceManagerSetting()
{
	if (m_SignificanceManagerSetting == nullptr)
	{
		m_SignificanceManagerSetting = NewObject<USignificanceManagerSetting>();
		InitActiveObjArray();
	}
	return m_SignificanceManagerSetting;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------

void UCustomSignificanceManager::GetFrustum(FConvexVolume& OutFrustum)
{
	ULocalPlayer* LocalPlayer = GetWorld()->GetFirstLocalPlayerFromController();
	if (LocalPlayer != nullptr &&
		LocalPlayer->ViewportClient != nullptr &&
		LocalPlayer->ViewportClient->Viewport != nullptr)
	{
		FSceneViewFamilyContext ViewFamily(
			FSceneViewFamily::ConstructionValues(
				LocalPlayer->ViewportClient->Viewport,
				GetWorld()->Scene,
				LocalPlayer->ViewportClient->EngineShowFlags).SetRealtimeUpdate(true));

		FVector ViewLocation;
		FRotator ViewRotation;
		FSceneView* SceneView = LocalPlayer->CalcSceneView(&ViewFamily, ViewLocation, ViewRotation, LocalPlayer->ViewportClient->Viewport);

		if (SceneView != nullptr)
		{
			OutFrustum = SceneView->ViewFrustum;
			OutFrustum.Init();
		}
	}
}

float UCustomSignificanceManager::CalcSignificance(const FCustomManagedObjectInfo* InObjectInfo, const FTransform& InViewpoint)
{
	UObject* Object = InObjectInfo->GetObject();
	if (Object == nullptr || Object->IsValidLowLevel() == false)
	{
		return -1.0f;
	}

	AActor* Actor = Cast<AActor>(Object);
	if (Actor == nullptr)
	{
		return -1.0f;
	}

	// 절두체 밖에 존재하는 경우
	if (m_Frustum.IntersectSphere(Actor->GetActorLocation(), Actor->GetSimpleCollisionRadius()) == false)
	{
		return -1.0f;
	}

	FVector Distance = InViewpoint.GetLocation() - Actor->GetActorLocation();
	float SettingDistance = m_SignificanceManagerSetting->m_MaxDistance;
	if (SettingDistance <= 0.0f)
	{
		return -1.0f;
	}

	if (Distance.Size() < SettingDistance)
	{
		float Significance = 1.0f - (Distance.Size() / SettingDistance);
		return Significance;
	}
	return 0.0f;
}

void UCustomSignificanceManager::ApplySignificance(const FCustomManagedObjectInfo* InObjectInfo, float InOldSignificance, float InNewSignificance)
{
	UObject* Object = InObjectInfo->GetObject();
	if (Object == nullptr || Object->IsValidLowLevel() == false)
	{
		return;
	}

	AActor* Actor = Cast<AActor>(Object);
	if (Actor == nullptr)
	{
		return;
	}

	Actor->SetActorTickEnabled(true);

	float UnitSignificance = 1.0f / m_SignificanceManagerSetting->m_DistanceSection;
	float UnitTickInterval = m_SignificanceManagerSetting->m_MaxTickInterval / (m_SignificanceManagerSetting->m_DistanceSection - 1);
	float SectionSignificance = 0.0f;
	float SectionTickInterval = 0.0f;
	for (int i = m_SignificanceManagerSetting->m_DistanceSection; i > 0; i--)
	{
		SectionSignificance = (i - 1) * UnitSignificance;
		SectionTickInterval = (m_SignificanceManagerSetting->m_DistanceSection - 1) * UnitTickInterval;

		if (InNewSignificance > SectionSignificance)
		{
			Actor->SetActorTickInterval(SectionTickInterval);
			Actor->SetActorHiddenInGame(false);
			Actor->NetUpdateFrequency = 1.0f;
			break;
		}
	}
}

void UCustomSignificanceManager::ActiveObject(FCustomManagedObjectInfo* InObjectInfo)
{
	InObjectInfo->SetMustActive(true);
	ApplySignificance(InObjectInfo, InObjectInfo->OldSignificance, InObjectInfo->Significance);
}

void UCustomSignificanceManager::InactiveObject(FCustomManagedObjectInfo* InObjectInfo)
{
	UObject* Object = InObjectInfo->GetObject();
	if (Object == nullptr || Object->IsValidLowLevel() == false)
	{
		return;
	}

	AActor* Actor = Cast<AActor>(Object);
	if (Actor == nullptr)
	{
		return;
	}
	Actor->SetActorHiddenInGame(true);
	Actor->SetActorTickEnabled(false);
}

void UCustomSignificanceManager::InitActiveObjArray()
{
	m_ActiveObjArray.Init(nullptr, m_SignificanceManagerSetting->GetTotalActiveCount());
	m_HeadActiveObjectIndex = 0;
	m_TailActiveObjectIndex = m_SignificanceManagerSetting->GetTotalActiveCount() - 1;
}

void UCustomSignificanceManager::FillActiveObjArray()
{
	if (m_SignificanceManagerSetting == nullptr)
	{
		m_SignificanceManagerSetting = GetSignificanceManagerSetting();
	}

	m_HeadActiveObjectIndex = 0;
	m_TailActiveObjectIndex = m_SignificanceManagerSetting->GetTotalActiveCount() - 1;

	uint32 LastPriority = 0;
	uint32 ActiveCount = m_SignificanceManagerSetting->GetActiveCountByPriority(LastPriority);
	bool ValidActiveCount = ActiveCount > 0 ? true : false;
	for (FCustomManagedObjectInfo* ObjectInfo : m_ObjArray)
	{
		if (ObjectInfo->GetPriority() > m_SignificanceManagerSetting->GetMaxPriority())
		{
			// 우선 순위가 세팅에 설정된 최대 우선 순위보다 높음
			InactiveObject(ObjectInfo);
			continue;
		}

		if (ObjectInfo->GetPriority() > LastPriority)
		{
			LastPriority = ObjectInfo->GetPriority();
			ActiveCount = m_SignificanceManagerSetting->GetActiveCountByPriority(LastPriority);
			ValidActiveCount = ActiveCount > 0 ? true : false;
		}

		if (ValidActiveCount == true && ObjectInfo->GetSignificance() >= 0)
		{
			if (ActiveCount > 0 && m_HeadActiveObjectIndex < m_ActiveObjArray.Num())
			{
				// 반드시 활성화
				ActiveObject(ObjectInfo);
				m_ActiveObjArray[m_HeadActiveObjectIndex] = ObjectInfo;
				m_HeadActiveObjectIndex++;
				ActiveCount--;
			}
			else
			{
				// 빈 자리를 채우고 나중에 활성화
				InactiveObject(ObjectInfo);
				if (m_HeadActiveObjectIndex <= m_TailActiveObjectIndex)
				{
					m_ActiveObjArray[m_TailActiveObjectIndex] = ObjectInfo;
					m_TailActiveObjectIndex--;
				}
			}
		}
		else
		{
			InactiveObject(ObjectInfo);
		}
	}

	// 빈 자리를 채운 오브젝트들을 활성화
	for (int i = m_ActiveObjArray.Num() - 1; i > 0; i--)
	{
		if (m_ActiveObjArray[i] != nullptr && m_ActiveObjArray[i]->GetMustActive() == false)
		{
			ActiveObject(m_ActiveObjArray[i]);
		}
		else
		{
			break;
		}
	}
}