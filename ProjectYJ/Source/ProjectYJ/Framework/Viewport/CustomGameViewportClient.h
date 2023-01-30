// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameViewportClient.h"
#include "CustomGameViewportClient.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTYJ_API UCustomGameViewportClient : public UGameViewportClient
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaTime) override;

	void SetActiveSignificance(bool InActiveSignificance);
	bool GetActiveSignificance();

protected:
	TWeakObjectPtr<APlayerController> m_ClientPlayerController;

private:
	bool bActiveSignificance = true;
};
