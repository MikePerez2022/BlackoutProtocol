// Fill out your copyright notice in the Description page of Project Settings.

#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "BlackoutProtocolCameraManager.h"
#include "HorrorCharacter.h"
#include "HorrorUI.h"
#include "HorrorShooter.h"
#include "HorrorShooterPlayerController.h"

AHorrorShooterPlayerController::AHorrorShooterPlayerController()
{
	PlayerCameraManagerClass = ABlackoutProtocolCameraManager::StaticClass();
}

void AHorrorShooterPlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	AHorrorShooter* HSCharacter = Cast<AHorrorShooter>(aPawn);

	// set up the UI for the character
	if (!HorrorUI)
	{
		HorrorUI = CreateWidget<UHorrorShooterHUD>(this, HorrorUIClass);
		HorrorUI->AddToViewport(0);
	}

	HorrorUI->SetupCharacter(HSCharacter);
}

void AHorrorShooterPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add Input Mapping Contexts
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
		{
			Subsystem->AddMappingContext(CurrentContext, 0);
		}
	}
}
