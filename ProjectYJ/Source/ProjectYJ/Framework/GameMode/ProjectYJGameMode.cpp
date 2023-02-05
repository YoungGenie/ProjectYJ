// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectYJGameMode.h"
#include "Framework/Actor/ProjectYJCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProjectYJGameMode::AProjectYJGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
