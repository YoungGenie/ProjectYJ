// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "YJAssetManager.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(YJAssetManager, Log, All);

DECLARE_DELEGATE_TwoParams(FOnLoadAsset, const uint32&, const TArray<UObject*>&);

UENUM()
enum class EAsyncLoadLogType : uint8
{
	Info,
	Complete,
	Cancel
};

UCLASS()
class PROJECTYJ_API UYJAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	static UYJAssetManager* Get();

	// Primary Data Asset
	static uint32 RequestAsyncLoadByPrimaryAsset(const FPrimaryAssetId& AssetID, FOnLoadAsset DelegateToGetAsset = FOnLoadAsset(), TAsyncLoadPriority Priority = FStreamableManager::DefaultAsyncLoadPriority);
	static uint32 RequestAsyncLoadByPrimaryAsset(const TArray<FPrimaryAssetId>& AssetIDList, FOnLoadAsset DelegateToGetAsset = FOnLoadAsset(), TAsyncLoadPriority Priority = FStreamableManager::DefaultAsyncLoadPriority);
	static void UnloadByPrimaryAsset(const FPrimaryAssetId& AssetID);
	static void UnloadByPrimaryAsset(const TArray<FPrimaryAssetId>& AssetIDList);

	// Path (SoftObjectPath)
	static uint32 RequestAsyncLoadByPath(const FSoftObjectPath& Path, FOnLoadAsset DelegateToGetAsset = FOnLoadAsset(), TAsyncLoadPriority Priority = FStreamableManager::DefaultAsyncLoadPriority, bool bManualRelease = false);
	static uint32 RequestAsyncLoadByPath(const TArray<FSoftObjectPath>& PathList, FOnLoadAsset DelegateToGetAsset = FOnLoadAsset(), TAsyncLoadPriority Priority = FStreamableManager::DefaultAsyncLoadPriority, bool bManualRelease = false);
	static void UnloadByPath(const FSoftObjectPath& Path);
	static void UnloadByPath(const TArray<FSoftObjectPath>& PathList);

	// Path (FString)
	static uint32 RequestAsyncLoadByPath(const FString& Path, FOnLoadAsset DelegateToGetAsset = FOnLoadAsset(), TAsyncLoadPriority Priority = FStreamableManager::DefaultAsyncLoadPriority, bool bManualRelease = false);
	static uint32 RequestAsyncLoadByPath(const TArray<FString>& PathList, FOnLoadAsset DelegateToGetAsset = FOnLoadAsset(), TAsyncLoadPriority Priority = FStreamableManager::DefaultAsyncLoadPriority, bool bManualRelease = false);
	static void UnloadByPath(const FString& Path);
	static void UnloadByPath(const TArray<FString>& PathList);

	static void CancelAsyncLoading();
	static void CancelAsyncLoading(const uint32 Key);

private:
	struct FAsyncLoadRequest
	{
		FAsyncLoadRequest(uint32 Key, TSharedPtr<FStreamableHandle> Handle, FOnLoadAsset Event)
			: Key(Key), Handle(Handle), Event(Event)
		{}

	public:
		void PrintLog(EAsyncLoadLogType Type);

		// Key
		uint32 GetKey();

		// Handle
		bool HasLoadCompleted();
		bool WasCanceled();
		void CancelHandle();

		// Event
		FString GetRequestorName();
		void ExecuteEvent();

	private:
		FString GetRequestedAssetName();
		void CompleteLog();

	private:
		uint32 Key;
		TSharedPtr<FStreamableHandle> Handle;
		FOnLoadAsset Event;
	};

	FORCEINLINE TLinkedList<FAsyncLoadRequest>* GetHeadNode() { return m_RequestListHead; }

	bool ParsePath(const TArray<FString>& InPath, TArray<FSoftObjectPath>& OutPath);

	uint32 AddRequest(TSharedPtr<FStreamableHandle> Handle, FOnLoadAsset DelegateToGetAsset);
	void DeleteRequest(TLinkedList<FAsyncLoadRequest>* CurrentNode, TLinkedList<FAsyncLoadRequest>* PrevNode);

	void LoadComplete();
	void LoadCancel();

	uint32 AsyncLoadByPrimaryAsset(const FPrimaryAssetId& AssetID, FOnLoadAsset DelegateToGetAsset, TAsyncLoadPriority Priority);
	uint32 AsyncLoadByPrimaryAsset(const TArray<FPrimaryAssetId>& AssetID, FOnLoadAsset DelegateToGetAsset, TAsyncLoadPriority Priority);
	uint32 AsyncLoadByPath(const FSoftObjectPath& Path, FOnLoadAsset DelegateToGetAsset, TAsyncLoadPriority Priority, bool bManualRelease);
	uint32 AsyncLoadByPath(const TArray<FSoftObjectPath>& Path, FOnLoadAsset DelegateToGetAsset, TAsyncLoadPriority Priority, bool bManualRelease);

private:
	TLinkedList<FAsyncLoadRequest>* m_RequestListHead;
	TLinkedList<FAsyncLoadRequest>* m_RequestListTail;
	uint32 KeyCount = 0;
};