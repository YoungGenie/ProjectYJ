// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SignificanceManager.h"
#include "YJSignificanceManager.generated.h"

/*
 * SignificanceManagerSetting�� ���õ� �켱 ������ ���� ������Ʈ ��ü ���� ������� ��ϵ� ������Ʈ�� �����մϴ�.
 * �� ������ ��ϵ� ������Ʈ�� �߿䵵(Significance)�� ī�޶��� ����ü, �Ÿ��� ���� ���˴ϴ�.
 * �켱 ������ �߿䵵�� ������Ʈ�� �����Ͽ� Ȱ��ȭ ������Ʈ ����� �����մϴ�. (���� ���� : �켱 ���� -> �߿䵵)
 *
 * ���� ���忡 �����ϴ� ������Ʈ ��ü ���� ���� ������ ���� ��, Ȱ��ȭ ������Ʈ ����� ���¿� ���� �߰������� Ȱ��ȭ�մϴ�.
 * 
 * �ñ״������� �Ŵ����� ������ Ŭ������ 'BeginPlay'���� 'RegisterObject_YJ'��, 'EndPlay'���� 'UnregisterObject_YJ'�� ȣ�������� �մϴ�.
 */

class USignificanceManagerSetting;

UCLASS()
class PROJECTYJ_API UYJSignificanceManager : public USignificanceManager
{
	GENERATED_BODY()
	
public:
	// ��ϵ� ������Ʈ�� �����ϱ� ���� ����ü
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

	// Ȱ��ȭ ������Ʈ ����� ������ �� ���Ǵ� �ε��� ���� (�߰��� Ȱ��ȭ�ϴ� ��츦 ���� ĳ��) 
	int32 m_HeadActiveObjectIndex;
	int32 m_TailActiveObjectIndex;

	FConvexVolume m_Frustum;

	UPROPERTY()
		USignificanceManagerSetting* m_SignificanceManagerSetting;
};
