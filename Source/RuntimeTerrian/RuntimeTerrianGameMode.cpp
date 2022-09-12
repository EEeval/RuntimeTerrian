// Copyright Epic Games, Inc. All Rights Reserved.

#include "RuntimeTerrianGameMode.h"
#include "RuntimeTerrianCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARuntimeTerrianGameMode::ARuntimeTerrianGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
