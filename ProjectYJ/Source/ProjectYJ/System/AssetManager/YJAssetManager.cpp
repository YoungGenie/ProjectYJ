// Fill out your copyright notice in the Description page of Project Settings.


#include "YJAssetManager.h"
#include "UObject/ConstructorHelpers.h"

DEFINE_LOG_CATEGORY(YJAssetManager);

//---------------------------------------------------------------------------------------------------------------------------------------------------------
// FAsyncLoadRequest - Public (외부)

void UYJAssetManager::FAsyncLoadRequest::PrintLog(EAsyncLoadLogType Type)
{
	switch (Type)
	{
	case EAsyncLoadLogType::Info:
		UE_LOG(YJAssetManager, Display, TEXT("FAsyncLoadRequest - Info (Requestor : %s, RequestKey : %d, RequestedAsset : %s)"), *GetRequestorName(), Key, *GetRequestedAssetName());
		break;
	case EAsyncLoadLogType::Complete:
		CompleteLog();
		break;
	case EAsyncLoadLogType::Cancel:
		UE_LOG(YJAssetManager, Display, TEXT("FAsyncLoadRequest - Cancel (Requestor : %s, RequestKey : %d, RequestedAsset : %s)"), *GetRequestorName(), Key, *GetRequestedAssetName());
		break;
	}
}

// Key 관련
uint32 UYJAssetManager::FAsyncLoadRequest::GetKey()
{
	return Key;
}

// Handle 관련
bool UYJAssetManager::FAsyncLoadRequest::HasLoadCompleted()
{
	if (Handle == nullptr)
	{
		UE_LOG(YJAssetManager, Warning, TEXT("FAsyncLoadRequest::HasLoadCompleted - Handle is nullptr."));
		return false;
	}

	return Handle->HasLoadCompleted();
}

bool UYJAssetManager::FAsyncLoadRequest::WasCanceled()
{
	if (Handle == nullptr)
	{
		UE_LOG(YJAssetManager, Warning, TEXT("FAsyncLoadRequest::WasCanceled - Handle is nullptr."));
		return false;
	}

	return Handle->WasCanceled();
}

void UYJAssetManager::FAsyncLoadRequest::CancelHandle()
{
	if (Handle == nullptr)
	{
		UE_LOG(YJAssetManager, Warning, TEXT("FAsyncLoadRequest::CancelHandle - Handle is nullptr."));
		return;
	}

	Handle->CancelHandle();
}

// Event 관련
FString UYJAssetManager::FAsyncLoadRequest::GetRequestorName()
{
	if (Event.IsBound() == false)
	{
		UE_LOG(YJAssetManager, Warning, TEXT("FAsyncLoadRequest::GetRequestorName - Event is not bounded."));
		return "";
	}

	if (Event.GetUObject() == nullptr)
	{
		UE_LOG(YJAssetManager, Warning, TEXT("FAsyncLoadRequest::CancelHandle - Owner Object is nullptr."));
		return "";
	}

	return Event.GetUObject()->GetFName().ToString();
}

void UYJAssetManager::FAsyncLoadRequest::ExecuteEvent()
{
	if (Handle == nullptr)
	{
		UE_LOG(YJAssetManager, Warning, TEXT("FAsyncLoadRequest::CancelHandle - Handle is nullptr."));
		return;
	}

	if (Event.IsBound() == false)
	{
		UE_LOG(YJAssetManager, Warning, TEXT("FAsyncLoadRequest::GetRequestorName - Event is not bounded."));
		return;
	}

	TArray<UObject*> AssetList;
	Handle->GetLoadedAssets(AssetList);
	Event.ExecuteIfBound(Key, AssetList);
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------
// FAsyncLoadRequest - Private (내부)

FString UYJAssetManager::FAsyncLoadRequest::GetRequestedAssetName()
{
	if (Handle == nullptr)
	{
		UE_LOG(YJAssetManager, Warning, TEXT("FAsyncLoadRequest::GetRequestedAssetName - Handle is nullptr."));
		return "";
	}

	TArray<FSoftObjectPath> AssetList;
	Handle->GetRequestedAssets(AssetList);

	if (AssetList.Num() <= 0)
	{
		UE_LOG(YJAssetManager, Warning, TEXT("FAsyncLoadRequest::GetRequestedAssetName - There is not Requested Assets."));
		return "";
	}

	return AssetList[0].ToString();
}

void UYJAssetManager::FAsyncLoadRequest::CompleteLog()
{
	if (Handle == nullptr)
	{
		UE_LOG(YJAssetManager, Warning, TEXT("FAsyncLoadRequest::CompleteLog - Handle is nullptr."));
		return;
	}

	TArray<UObject*> AssetList;
	Handle->GetLoadedAssets(AssetList);

	FString RequestorName = GetRequestorName();

	if (AssetList.Num() <= 0)
	{
		UE_LOG(YJAssetManager, Warning, TEXT("FAsyncLoadRequest::CompleteLog - There is not Loaded Assets."));
		return;
	}

	for (const UObject* Asset : AssetList)
	{
		UE_LOG(YJAssetManager, Display, TEXT("FAsyncLoadRequest - Complete (Requestor : %s, RequestKey : %d, LoadedAsset : %s)"), *RequestorName, Key, *Asset->GetFullName());
	}
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------
// UYJAssetManager - Public (외부)

UYJAssetManager* UYJAssetManager::Get()
{
	UYJAssetManager* Singleton = Cast<UYJAssetManager>(GEngine->AssetManager);

	if (Singleton)
	{
		return Singleton;
	}
	else
	{
		UE_LOG(YJAssetManager, Fatal, TEXT("Cannot use AssetManager if no AssetManagerClassName is defined!"));
		return NewObject<UYJAssetManager>();
	}
}


// Primary Data Asset - Return Value : Request Key ( 0 : Failure, 1~ : Success )
uint32 UYJAssetManager::RequestAsyncLoadByPrimaryAsset(const FPrimaryAssetId& AssetID, FOnLoadAsset DelegateToGetAsset, TAsyncLoadPriority Priority)
{
	UYJAssetManager* AssetManager = UYJAssetManager::Get();
	uint32 RequestKey = AssetManager->AsyncLoadByPrimaryAsset(AssetID, DelegateToGetAsset, Priority);
	if (RequestKey == false)
	{
		UE_LOG(YJAssetManager, Warning, TEXT("UYJAssetManager::RequestAsyncLoadByPrimaryAsset - Failure (%s)"), *AssetID.PrimaryAssetName.ToString());
	}
	else
	{
		UE_LOG(YJAssetManager, Display, TEXT("UYJAssetManager::RequestAsyncLoadByPrimaryAsset - Success (%s)"), *AssetID.PrimaryAssetName.ToString());
	}
	return RequestKey;
}

// Primary Data Asset - Return Value : Request Key ( 0 : Failure, 1~ : Success )
uint32 UYJAssetManager::RequestAsyncLoadByPrimaryAsset(const TArray<FPrimaryAssetId>& AssetID, FOnLoadAsset DelegateToGetAsset, TAsyncLoadPriority Priority)
{
	UYJAssetManager* AssetManager = UYJAssetManager::Get();
	uint32 RequestKey = AssetManager->AsyncLoadByPrimaryAsset(AssetID, DelegateToGetAsset, Priority);
	if (RequestKey == false)
	{
		UE_LOG(YJAssetManager, Warning, TEXT("UYJAssetManager::RequestAsyncLoadByPrimaryAsset - Failure (%s)"), *AssetID[0].PrimaryAssetName.ToString());
	}
	else
	{
		UE_LOG(YJAssetManager, Display, TEXT("UYJAssetManager::RequestAsyncLoadByPrimaryAsset - Success (%s)"), *AssetID[0].PrimaryAssetName.ToString());
	}
	return RequestKey;
}

void UYJAssetManager::UnloadByPrimaryAsset(const FPrimaryAssetId& AssetID)
{
	UAssetManager::Get().UnloadPrimaryAsset(AssetID);
}

void UYJAssetManager::UnloadByPrimaryAsset(const TArray<FPrimaryAssetId>& AssetIDList)
{
	UAssetManager::Get().UnloadPrimaryAssets(AssetIDList);
}


// Path (SoftObjectPath) - Return Value : Request Key ( 0 : Failure, 1~ : Success )
uint32 UYJAssetManager::RequestAsyncLoadByPath(const FSoftObjectPath& Path, FOnLoadAsset DelegateToGetAsset, TAsyncLoadPriority Priority, bool bManualRelease)
{
	UYJAssetManager* AssetManager = UYJAssetManager::Get();
	uint32 RequestKey = AssetManager->AsyncLoadByPath(Path, DelegateToGetAsset, Priority, bManualRelease);
	if (RequestKey == false)
	{
		UE_LOG(YJAssetManager, Warning, TEXT("UYJAssetManager::RequestAsyncLoadByPath - Failure (%s)"), *Path.GetAssetName());
	}
	else
	{
		UE_LOG(YJAssetManager, Display, TEXT("UYJAssetManager::RequestAsyncLoadByPath - Success (%s)"), *Path.GetAssetName());
	}
	return RequestKey;
}

// Path (SoftObjectPath) - Return Value : Request Key ( 0 : Failure, 1~ : Success )
uint32 UYJAssetManager::RequestAsyncLoadByPath(const TArray<FSoftObjectPath>& Path, FOnLoadAsset DelegateToGetAsset, TAsyncLoadPriority Priority, bool bManualRelease)
{
	UYJAssetManager* AssetManager = UYJAssetManager::Get();
	uint32 RequestKey = AssetManager->AsyncLoadByPath(Path, DelegateToGetAsset, Priority, bManualRelease);
	if (RequestKey == false)
	{
		UE_LOG(YJAssetManager, Warning, TEXT("UYJAssetManager::RequestAsyncLoadByPath - Failure (%s)"), *Path[0].GetAssetName());
	}
	else
	{
		UE_LOG(YJAssetManager, Display, TEXT("UYJAssetManager::RequestAsyncLoadByPath - Success (%s)"), *Path[0].GetAssetName());
	}
	return RequestKey;
}

void UYJAssetManager::UnloadByPath(const FSoftObjectPath& Path)
{
	UAssetManager::GetStreamableManager().Unload(Path);
}

void UYJAssetManager::UnloadByPath(const TArray<FSoftObjectPath>& PathList)
{
	for (const FSoftObjectPath& Path : PathList)
	{
		UnloadByPath(Path);
	}
}


// Path (FString) - Return : Return Value : Request Key ( 0 : Failure, 1~ : Success )
uint32 UYJAssetManager::RequestAsyncLoadByPath(const FString& Path, FOnLoadAsset DelegateToGetAsset, TAsyncLoadPriority Priority, bool bManualRelease)
{
	UYJAssetManager* AssetManager = UYJAssetManager::Get();
	TArray<FSoftObjectPath> ParsedPath;
	if (AssetManager->ParsePath(TArray<FString>{Path}, ParsedPath))
	{
		uint32 RequestKey = AssetManager->AsyncLoadByPath(ParsedPath, DelegateToGetAsset, Priority, bManualRelease);
		if (RequestKey == false)
		{
			UE_LOG(YJAssetManager, Warning, TEXT("UYJAssetManager::RequestAsyncLoadByPath - Failure (%s)"), *ParsedPath[0].GetAssetName());
		}
		else
		{
			UE_LOG(YJAssetManager, Display, TEXT("UYJAssetManager::RequestAsyncLoadByPath - Success (%s)"), *ParsedPath[0].GetAssetName());
		}
		return RequestKey;
	}
	UE_LOG(YJAssetManager, Warning, TEXT("UYJAssetManager::RequestAsyncLoadByPath - Parsing Failure"));
	return 0;
}

// Path (FString) - Return : Return Value : Request Key ( 0 : Failure, 1~ : Success )
uint32 UYJAssetManager::RequestAsyncLoadByPath(const TArray<FString>& Path, FOnLoadAsset DelegateToGetAsset, TAsyncLoadPriority Priority, bool bManualRelease)
{
	UYJAssetManager* AssetManager = UYJAssetManager::Get();
	TArray<FSoftObjectPath> ParsedPath;
	if (AssetManager->ParsePath(TArray<FString>{Path}, ParsedPath))
	{
		uint32 RequestKey = AssetManager->AsyncLoadByPath(ParsedPath, DelegateToGetAsset, Priority, bManualRelease);
		if (RequestKey == false)
		{
			UE_LOG(YJAssetManager, Warning, TEXT("UYJAssetManager::RequestAsyncLoadByPath - Failure (%s)"), *ParsedPath[0].GetAssetName());
		}
		else
		{
			UE_LOG(YJAssetManager, Display, TEXT("UYJAssetManager::RequestAsyncLoadByPath - Success (%s)"), *ParsedPath[0].GetAssetName());
		}
		return RequestKey;
	}
	UE_LOG(YJAssetManager, Warning, TEXT("UYJAssetManager::RequestAsyncLoadByPath - Parsing Failure"));
	return 0;
}

void UYJAssetManager::UnloadByPath(const FString& Path)
{
	UYJAssetManager* AssetManager = UYJAssetManager::Get();

	TArray<FSoftObjectPath> ParsedPathList;
	if (AssetManager->ParsePath(TArray<FString>{Path}, ParsedPathList))
	{
		for (const FSoftObjectPath& ParsedPath : ParsedPathList)
		{
			UnloadByPath(ParsedPath);
		}
	}
}

void UYJAssetManager::UnloadByPath(const TArray<FString>& PathList)
{
	UYJAssetManager* AssetManager = UYJAssetManager::Get();

	TArray<FSoftObjectPath> ParsedPathList;
	if (AssetManager->ParsePath(TArray<FString>{PathList}, ParsedPathList))
	{
		for (const FSoftObjectPath& ParsedPath : ParsedPathList)
		{
			UnloadByPath(ParsedPath);
		}
	}
}

// 비동기 로드 취소
void UYJAssetManager::CancelAsyncLoading()
{
	TLinkedList<FAsyncLoadRequest>* CurrentNode = UYJAssetManager::Get()->GetHeadNode();

	while (CurrentNode != nullptr && (*CurrentNode)->HasLoadCompleted() == false)
	{
		(*CurrentNode)->CancelHandle();
		UE_LOG(YJAssetManager, Display, TEXT("UYJAssetManager::CancelAsyncLoading - Requestor : %s, RequestKey : %d"), *(*CurrentNode)->GetRequestorName(), (*CurrentNode)->GetKey());
		CurrentNode = CurrentNode->Next();
	}
	::CancelAsyncLoading();
}

void UYJAssetManager::CancelAsyncLoading(const uint32 Key)
{
	TLinkedList<FAsyncLoadRequest>* CurrentNode = UYJAssetManager::Get()->GetHeadNode();
	TLinkedList<FAsyncLoadRequest>* PrevNode = CurrentNode;
	while (CurrentNode != nullptr && (*CurrentNode)->HasLoadCompleted() == false)
	{
		if ((*CurrentNode)->GetKey() == Key)
		{
			(*CurrentNode)->CancelHandle();
			UE_LOG(YJAssetManager, Display, TEXT("UYJAssetManager::CancelAsyncLoading - Requestor : %s, RequestKey : %d"), *(*CurrentNode)->GetRequestorName(), (*CurrentNode)->GetKey());
			UYJAssetManager::Get()->DeleteRequest(CurrentNode, PrevNode);
			break;
		}
		PrevNode = CurrentNode;
		CurrentNode = CurrentNode->Next();
	}
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------
// UYJAssetManager - Private (내부)

// FString -> SoftObjectPath 변환
bool UYJAssetManager::ParsePath(const TArray<FString>& InPath, TArray<FSoftObjectPath>& OutPath)
{
	for (const FString& Path : InPath)
	{
		FString ResultPath = Path;
		int32 FindIndex = 0;

		// 문자열 변환
		if (ResultPath.Contains(TEXT("."), ESearchCase::CaseSensitive))
		{
			if (ResultPath.Contains(TEXT("'"), ESearchCase::CaseSensitive))
			{
				// "'" 문자가 있으면 ReferencePath		(Blueprint'/Game/char/pc/argos/data/CBP_10001_argos.CBP_10001_argos')
				ConstructorHelpers::StripObjectClass(ResultPath);
			}
			else if (ResultPath.Contains(TEXT(":"), ESearchCase::CaseSensitive))
			{
				// ":" 문자가 있으면 FilePath			(E:/0. SVN/RiseO/Client/Content/char/pc/argos/data/CBP_10001_argos.uasset)
				FindIndex = ResultPath.Find(TEXT("/Content"), ESearchCase::CaseSensitive, ESearchDir::FromStart);
				ResultPath.RemoveAt(0, FindIndex + 8);

				FindIndex = ResultPath.Find(TEXT("."), ESearchCase::CaseSensitive, ESearchDir::FromEnd);
				ResultPath.RemoveAt(FindIndex, ResultPath.Len());

				FindIndex = ResultPath.Find(TEXT("/"), ESearchCase::CaseSensitive, ESearchDir::FromEnd);
				FString AssetName = ResultPath.RightChop(FindIndex + 1);

				ResultPath.InsertAt(0, TEXT("/Game"));
				ResultPath.Append(TEXT("." + AssetName));
			}
		}
		else
		{
			UE_LOG(YJAssetManager, Warning, TEXT("UYJAssetManager::ParsePath - Path is not valid (%s)"), *ResultPath);
			return false;
		}

		// 변환 결과에 대한 검사
		if (FPaths::ValidatePath(ResultPath) == false)
		{
			UE_LOG(YJAssetManager, Warning, TEXT("UYJAssetManager::ParsePath - Parsed Path is not valid (%s)"), *ResultPath);
			return false;
		}

		UE_LOG(YJAssetManager, Display, TEXT("UYJAssetManager::ParsePath - Parsed Path is %s"), *ResultPath);
		OutPath.Add(FSoftObjectPath(ResultPath));
	}
	return true;
}

uint32 UYJAssetManager::AddRequest(TSharedPtr<FStreamableHandle> Handle, FOnLoadAsset DelegateToGetAsset)
{
	KeyCount++;
	TLinkedList<FAsyncLoadRequest>* NewRequestNode = new TLinkedList<FAsyncLoadRequest>(FAsyncLoadRequest(KeyCount, Handle, DelegateToGetAsset));

	if (m_RequestListHead == nullptr)
	{
		NewRequestNode->LinkHead(m_RequestListHead);
	}
	else
	{
		NewRequestNode->LinkAfter(m_RequestListTail);
	}
	m_RequestListTail = NewRequestNode;
	(*NewRequestNode)->PrintLog(EAsyncLoadLogType::Info);

	return (*NewRequestNode)->GetKey();
}

void UYJAssetManager::DeleteRequest(TLinkedList<FAsyncLoadRequest>* CurrentNode, TLinkedList<FAsyncLoadRequest>* PrevNode)
{
	if (m_RequestListHead == CurrentNode && m_RequestListTail == CurrentNode)
	{
		m_RequestListHead = m_RequestListTail = nullptr;
		KeyCount = 0;
	}
	else if (m_RequestListHead == CurrentNode)
	{
		m_RequestListHead = CurrentNode->Next();
	}
	else if (m_RequestListTail == CurrentNode)
	{
		m_RequestListTail = PrevNode;
	}
	else
	{
		PrevNode->LinkBefore(CurrentNode->Next());
	}
	delete CurrentNode;
}

void UYJAssetManager::LoadComplete()
{
	if (m_RequestListHead != nullptr)
	{
		TLinkedList<FAsyncLoadRequest>* CurrentNode = m_RequestListHead;
		TLinkedList<FAsyncLoadRequest>* PrevNode = nullptr;
		while ((*CurrentNode)->HasLoadCompleted() == false)
		{
			PrevNode = CurrentNode;
			CurrentNode = CurrentNode->Next();

			if (CurrentNode == nullptr)
			{
				UE_LOG(YJAssetManager, Error, TEXT("UYJAssetManager::LoadComplete - Can't find a completed handle"));
				return;
			}
		}
		(*CurrentNode)->PrintLog(EAsyncLoadLogType::Complete);
		(*CurrentNode)->ExecuteEvent();

		DeleteRequest(CurrentNode, PrevNode);
	}
}

void UYJAssetManager::LoadCancel()
{
	if (m_RequestListHead != nullptr)
	{
		TLinkedList<FAsyncLoadRequest>* CurrentNode = m_RequestListHead;
		TLinkedList<FAsyncLoadRequest>* PrevNode = nullptr;
		while ((*CurrentNode)->WasCanceled() == false)
		{
			PrevNode = CurrentNode;
			CurrentNode = CurrentNode->Next();

			if (CurrentNode == nullptr)
			{
				UE_LOG(YJAssetManager, Error, TEXT("UYJAssetManager::LoadCancel - Can't find a canceled handle"));
				return;
			}
		}
		(*CurrentNode)->PrintLog(EAsyncLoadLogType::Cancel);

		DeleteRequest(CurrentNode, PrevNode);
	}
}

uint32 UYJAssetManager::AsyncLoadByPrimaryAsset(const FPrimaryAssetId& AssetID, FOnLoadAsset DelegateToGetAsset, TAsyncLoadPriority Priority)
{
	TSharedPtr<FStreamableHandle> Handle = UAssetManager::Get().LoadPrimaryAsset(AssetID, TArray<FName>(), FStreamableDelegate::CreateUObject(this, &UYJAssetManager::LoadComplete), Priority);
	if (Handle.IsValid() == false)
	{
		FString PrimaryAssetName = AssetID.IsValid() == true ? AssetID.PrimaryAssetName.ToString() : TEXT("AssetID is invalid");
		UE_LOG(YJAssetManager, Warning, TEXT("UYJAssetManager::AsyncLoadByPrimaryAsset - Handle is not valid (%s)"), *PrimaryAssetName);
		return 0;
	}
	UE_LOG(YJAssetManager, Display, TEXT("UYJAssetManager::AsyncLoadByPrimaryAsset - Handle is valid (%s)"), *AssetID.PrimaryAssetName.ToString());
	Handle->BindCancelDelegate(FStreamableDelegate::CreateUObject(this, &UYJAssetManager::LoadCancel));
	return AddRequest(Handle, DelegateToGetAsset);
}

uint32 UYJAssetManager::AsyncLoadByPrimaryAsset(const TArray<FPrimaryAssetId>& AssetID, FOnLoadAsset DelegateToGetAsset, TAsyncLoadPriority Priority)
{
	TSharedPtr<FStreamableHandle> Handle = UAssetManager::Get().LoadPrimaryAssets(AssetID, TArray<FName>(), FStreamableDelegate::CreateUObject(this, &UYJAssetManager::LoadComplete), Priority);
	if (Handle.IsValid() == false)
	{
		FString PrimaryAssetName = AssetID.Num() != 0 ? AssetID[0].PrimaryAssetName.ToString() : TEXT("AssetID is invalid");
		UE_LOG(YJAssetManager, Warning, TEXT("UYJAssetManager::AsyncLoadByPrimaryAsset - Handle is not valid (%s)"), *PrimaryAssetName);
		return 0;
	}
	UE_LOG(YJAssetManager, Display, TEXT("UYJAssetManager::AsyncLoadByPrimaryAsset - Handle is valid (%s)"), *AssetID[0].PrimaryAssetName.ToString());
	Handle->BindCancelDelegate(FStreamableDelegate::CreateUObject(this, &UYJAssetManager::LoadCancel));
	return AddRequest(Handle, DelegateToGetAsset);
}

uint32 UYJAssetManager::AsyncLoadByPath(const FSoftObjectPath& Path, FOnLoadAsset DelegateToGetAsset, TAsyncLoadPriority Priority, bool bManualRelease)
{
	TSharedPtr<FStreamableHandle> Handle = UAssetManager::GetStreamableManager().RequestAsyncLoad(Path, FStreamableDelegate::CreateUObject(this, &UYJAssetManager::LoadComplete), Priority, bManualRelease);
	if (Handle.IsValid() == false)
	{
		FString AssetName = Path.IsValid() == true ? Path.GetAssetName() : TEXT("Path is invalid");
		UE_LOG(YJAssetManager, Warning, TEXT("UYJAssetManager::AsyncLoadByPath - Handle is not valid (%s)"), *AssetName);
		return 0;
	}
	UE_LOG(YJAssetManager, Display, TEXT("UYJAssetManager::AsyncLoadByPath - Handle is valid (%s)"), *Path.GetAssetName());
	Handle->BindCancelDelegate(FStreamableDelegate::CreateUObject(this, &UYJAssetManager::LoadCancel));
	return AddRequest(Handle, DelegateToGetAsset);
}

uint32 UYJAssetManager::AsyncLoadByPath(const TArray<FSoftObjectPath>& Path, FOnLoadAsset DelegateToGetAsset, TAsyncLoadPriority Priority, bool bManualRelease)
{
	TSharedPtr<FStreamableHandle> Handle = UAssetManager::GetStreamableManager().RequestAsyncLoad(Path, FStreamableDelegate::CreateUObject(this, &UYJAssetManager::LoadComplete), Priority, bManualRelease);
	if (Handle.IsValid() == false)
	{
		FString AssetName = Path.Num() != 0 ? Path[0].GetAssetName() : TEXT("Path is invalid");
		UE_LOG(YJAssetManager, Warning, TEXT("UYJAssetManager::AsyncLoadByPath - Handle is not valid (%s)"), *AssetName);
		return 0;
	}
	UE_LOG(YJAssetManager, Display, TEXT("UYJAssetManager::AsyncLoadByPath - Handle is valid (%s)"), *Path[0].GetAssetName());
	Handle->BindCancelDelegate(FStreamableDelegate::CreateUObject(this, &UYJAssetManager::LoadCancel));
	return AddRequest(Handle, DelegateToGetAsset);
}