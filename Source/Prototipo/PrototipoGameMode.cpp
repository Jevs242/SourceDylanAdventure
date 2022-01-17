// Copyright Epic Games, Inc. All Rights Reserved.

#include "PrototipoGameMode.h"
#include "PrototipoCharacter.h"
#include "UObject/ConstructorHelpers.h"

APrototipoGameMode::APrototipoGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
