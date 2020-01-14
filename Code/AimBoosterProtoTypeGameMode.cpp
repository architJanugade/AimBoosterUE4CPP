// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "AimBoosterProtoTypeGameMode.h"
#include "AimBoosterProtoTypeHUD.h"
#include "AimBoosterProtoTypeCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAimBoosterProtoTypeGameMode::AAimBoosterProtoTypeGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AAimBoosterProtoTypeHUD::StaticClass();
}
