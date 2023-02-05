// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/YJCharacter.h"

#include "System/SignificanceManager/YJSignificanceManager.h"

void AYJCharacter::BeginPlay()
{
	RegisterAtSignificanceManager();

	Super::BeginPlay();
}

void AYJCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	UnregisterAtSignificanceManager();

	Super::EndPlay(EndPlayReason);
}

void AYJCharacter::RegisterAtSignificanceManager()
{
	UYJSignificanceManager* SignificanceManager = Cast<UYJSignificanceManager>(FSignificanceManagerModule::Get(GetWorld()));
	SignificanceManager->RegisterObject_YJ(this, 1);
}

void AYJCharacter::UnregisterAtSignificanceManager()
{
	UYJSignificanceManager* SignificanceManager = Cast<UYJSignificanceManager>(FSignificanceManagerModule::Get(GetWorld()));
	SignificanceManager->UnregisterObject_YJ(this);
}
