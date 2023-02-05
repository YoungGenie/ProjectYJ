// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SignificanceManager.h"
#include "YJSignificanceManager.generated.h"

/*
 * SignificanceManagerSetting에 세팅된 우선 순위에 따른 오브젝트 개체 수를 기반으로 등록된 오브젝트를 관리합니다.
 * 매 프레임 등록된 오브젝트의 중요도(Significance)를 카메라의 절두체, 거리에 따라 계산됩니다.
 * 우선 순위와 중요도로 오브젝트를 정렬하여 활성화 오브젝트 목록을 구성합니다. (구성 기준 : 우선 순위 -> 중요도)
 *
 * 만약 월드에 존재하는 오브젝트 개체 수가 세팅 값보다 많을 때, 활성화 오브젝트 목록의 상태에 따라 추가적으로 활성화합니다.
 * 
 * 시그니피컨스 매니저로 관리할 클래스의 'BeginPlay'에서 'RegisterObject_YJ'를, 'EndPlay'에서 'UnregisterObject_YJ'를 호출시켜줘야 합니다.
 */

class USignificanceManagerSetting;

UCLASS()
class PROJECTYJ_API UYJSignificanceManager : public USignificanceManager
{
	GENERATED_BODY()
	
public:
	// 등록된 오브젝트를 관리하기 위한 구조체
	struct FYJManagedObjectInfo
	{
		FYJManagedObjectInfo(UYJSignificanceManager* InSignificanceManager, UObject* InObject, uint32 InPriority)
			: SignificanceManager(InSignificanceManager)
			, Object(InObject)
			, Priority(InPriority)
			, Significance(1.0f)
			, OldSignificance(1.0f)
			, bMustActive(false)
		{}

		virtual ~FYJManagedObjectInfo() { }

	public:
		UObject* GetObject() const
		{
			if (Object.IsValid() == false || Object->IsValidLowLevel() == false)
			{
				return nullptr;
			}
			return Object.Get();
		}
		
		FORCEINLINE uint32 GetPriority() const { return Priority; }
		FORCEINLINE void SetPriority(uint32 InPriority) { Priority = InPriority; }

		FORCEINLINE float GetSignificance() const { return Significance; }
		FORCEINLINE void SetSignificance(float InSignificance) { Significance = InSignificance; }

		FORCEINLINE float GetOldSignificance () const { return OldSignificance; }
		FORCEINLINE void SetOldSignificance(float InOldSignificance) { OldSignificance = InOldSignificance; }

		FORCEINLINE bool GetMustActive() const { return bMustActive; }
		FORCEINLINE void SetMustActive(bool InMustActive) { bMustActive = InMustActive; }

	private:
		void UpdateSignificance(const TArray<FTransform>& InViewpoints);

	private:
		TWeakObjectPtr<UYJSignificanceManager> SignificanceManager;
		TWeakObjectPtr<UObject> Object;
		uint32 Priority;
		float Significance;
		float OldSignificance;
		bool bMustActive;

		friend UYJSignificanceManager;
	};

	FORCEINLINE void SetActive(bool InIsActive) { m_IsActive = InIsActive; }
	FORCEINLINE bool GetActive() { return m_IsActive; }

	virtual void Update(TArrayView<const FTransform> InViewpoints) override;

	FORCEINLINE int32 GetManagedObjectsNumber() { return m_ManagedObjects.Num(); }

	void RegisterObject_YJ(UObject* InObject, uint32 InPriority);
	void UnregisterObject_YJ(UObject* InObject);
	void UnregisterAll();
	void ChangePriority(UObject* InObject, uint32 InPriority);
	void ResetObjects();

	void ChangeSignificanceManagerSetting(USignificanceManagerSetting* InSetting);
	USignificanceManagerSetting* GetSignificanceManagerSetting();

	template<class T>
	void GetActiveObjArray(TArray<T*>& OutActiveObjArray)
	{
		OutActiveObjArray.Empty();
		for (FYJManagedObjectInfo* ObjectInfo : m_ActiveObjArray)
		{
			if (ObjectInfo == nullptr)
			{
				continue;
			}

			UObject* Object = ObjectInfo->GetObject();
			if (Object == nullptr || Object->IsValidLowLevel() == false)
			{
				continue;
			}

			if (Object->IsA(T::StaticClass()))
			{
				OutActiveObjArray.Emplace(Cast<T>(Object));
			}
		}
	}

private:
	void GetFrustum(FConvexVolume& OutFrustum);
	float CalcSignificance(const FYJManagedObjectInfo* InObjectInfo, const FTransform& InViewpoint);
	void ApplySignificance(const FYJManagedObjectInfo* InObjectInfo, float InOldSignificance, float InNewSignificance);
	void ActiveObject(FYJManagedObjectInfo* InObjectInfo);
	void InactiveObject(FYJManagedObjectInfo* InObjectInfo);
	void InitActiveObjArray();
	void FillActiveObjArray();

private:
	bool m_IsActive = true;

	TMap<UObject*, FYJManagedObjectInfo*> m_ManagedObjects;
	TArray<FYJManagedObjectInfo*> m_ObjArray;
	TArray<FYJManagedObjectInfo*> m_ActiveObjArray;

	// 활성화 오브젝트 목록을 구성할 때 사용되는 인덱스 변수 (추가로 활성화하는 경우를 위해 캐싱) 
	int32 m_HeadActiveObjectIndex;
	int32 m_TailActiveObjectIndex;

	FConvexVolume m_Frustum;

	UPROPERTY()
		USignificanceManagerSetting* m_SignificanceManagerSetting;
};
