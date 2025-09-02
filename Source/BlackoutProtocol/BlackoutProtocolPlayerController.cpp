// Copyright Epic Games, Inc. All Rights Reserved.


#include "BlackoutProtocolPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "BlackoutProtocolCameraManager.h"

ABlackoutProtocolPlayerController::ABlackoutProtocolPlayerController()
{
	// set the player camera manager class
	PlayerCameraManagerClass = ABlackoutProtocolCameraManager::StaticClass();
}

void ABlackoutProtocolPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
		{
			Subsystem->AddMappingContext(CurrentContext, 0);
		}
	}
}
