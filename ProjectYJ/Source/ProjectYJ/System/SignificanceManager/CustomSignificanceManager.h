// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SignificanceManager.h"
#include "CustomSignificanceManager.generated.h"

/**
 * 
 */

class USignificanceManagerSetting;

UCLASS()
class PROJECTYJ_API UCustomSignificanceManager : public USignificanceManager
{
	GENERATED_BODY()
	
public:
	struct FCustomManagedObjectInfo
	{
		FCustomManagedObjectInfo(UCustomSignificanceManager* InSignificanceManager, UObject* InObject, uint32 InPriority)
			: SignificanceManager(InSignificanceManager)
			, Object(InObject)
			, Priority(InPriority)
			, Significance(1.0f)
			, OldSignificance(1.0f)
			, bMustActive(false)
		{}

		virtual ~FCustomManagedObjectInfo() { }

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
		TWeakObjectPtr<UCustomSignificanceManager> SignificanceManager;
		TWeakObjectPtr<UObject> Object;
		uint32 Priority;
		float Significance;
		float OldSignificance;
		bool bMustActive;

		void UpdateSignificance(const TArray<FTransform>& InViewpoints);

		friend UCustomSignificanceManager;
	};

	virtual void Update(TArrayView<const FTransform> InViewpoints) override;
	FORCEINLINE int32 GetManagedObjectsNumber() { return m_ManagedObjects.Num(); }

	void RegisterObject_Custom(UObject* InObject, uint32 InPriority);
	void UnregisterObject_Custom(UObject* InObject);
	void UnregisterAll();
	void ChangePriority(UObject* InObject, uint32 InPriority);
	void ResetObjects();

	void ChangeSignificanceManagerSetting(USignificanceManagerSetting* InSetting);
	USignificanceManagerSetting* GetSignificanceManagerSetting();

	template<class T>
	void GetActiveObjArray(TArray<T*>& OutActiveObjArray)
	{
		OutActiveObjArray.Empty();
		for (FCustomManagedObjectInfo* ObjectInfo : m_ActiveObjArray)
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
	float CalcSignificance(const FCustomManagedObjectInfo* InObjectInfo, const FTransform& InViewpoint);
	void ApplySignificance(const FCustomManagedObjectInfo* InObjectInfo, float InOldSignificance, float InNewSignificance);
	void ActiveObject(FCustomManagedObjectInfo* InObjectInfo);
	void InactiveObject(FCustomManagedObjectInfo* InObjectInfo);
	void InitActiveObjArray();
	void FillActiveObjArray();

private:
	TMap<UObject*, FCustomManagedObjectInfo*> m_ManagedObjects;
	TArray<FCustomManagedObjectInfo*> m_ObjArray;
	TArray<FCustomManagedObjectInfo*> m_ActiveObjArray;

	int32 m_HeadActiveObjectIndex;
	int32 m_TailActiveObjectIndex;

	FConvexVolume m_Frustum;

	UPROPERTY()
		USignificanceManagerSetting* m_SignificanceManagerSetting;
};
