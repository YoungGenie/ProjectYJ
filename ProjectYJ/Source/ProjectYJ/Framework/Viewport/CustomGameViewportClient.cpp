// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomGameViewportClient.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

#include "System/SignificanceManager/CustomSignificanceManager.h"

void UCustomGameViewportClient::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UWorld* CurrentWorld = GetWorld();
	if (CurrentWorld != nullptr)
	{
		const bool bHasValidData = m_ClientPlayerController.IsValid();
		if (bHasValidData == false)
		{
			APlayerController* PlayerController = UGameplayStatics::GetPlayerController(CurrentWorld, 0);
			m_ClientPlayerController = TWeakObjectPtr<APlayerController>(PlayerController);
		}
		
		if (bHasValidData == true)
		{
			if (bActiveSignificance == true)
			{
				UCustomSignificanceManager* SignificanceManager = Cast<UCustomSignificanceManager>(FSignificanceManagerModule::Get(CurrentWorld));
				if (SignificanceManager != nullptr &&
					SignificanceManager->GetManagedObjectsNumber() > 0)
				{
					FVector ViewLocation;
					FRotator ViewRotation;
					m_ClientPlayerController.Get()->GetPlayerViewPoint(ViewLocation, ViewRotation);

					TArray<FTransform> Viewpoints;
					Viewpoints.Emplace(ViewRotation, ViewLocation, FVector::OneVector);

					SignificanceManager->Update(Viewpoints);
				}
			}
		}
	}
}

void UCustomGameViewportClient::SetActiveSignificance(bool InActiveSignificance)
{
	if (InActiveSignificance == false)
	{
		UWorld* CurrentWorld = GetWorld();
		if (CurrentWorld != nullptr)
		{
			const bool bHasValidData = m_ClientPlayerController.IsValid();
			if (bHasValidData == false)
			{
				APlayerController* PlayerController = UGameplayStatics::GetPlayerController(CurrentWorld, 0);
				m_ClientPlayerController = TWeakObjectPtr<APlayerController>(PlayerController);
			}

			if (bHasValidData == true)
			{
				if (bActiveSignificance == true)
				{
					UCustomSignificanceManager* SignificanceManager = Cast<UCustomSignificanceManager>(FSignificanceManagerModule::Get(CurrentWorld));
					if (SignificanceManager != nullptr &&
						SignificanceManager->GetManagedObjectsNumber() > 0)
					{
						SignificanceManager->ResetObjects();
					}
				}
			}
		}
	}
	bActiveSignificance = InActiveSignificance;
}

bool UCustomGameViewportClient::GetActiveSignificance()
{
	return bActiveSignificance;
}
