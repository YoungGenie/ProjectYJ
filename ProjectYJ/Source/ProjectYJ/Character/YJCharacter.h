// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Actor/ProjectYJCharacter.h"
#include "YJCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTYJ_API AYJCharacter : public AProjectYJCharacter
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	void RegisterAtSignificanceManager();
	void UnregisterAtSignificanceManager();
};
