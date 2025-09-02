// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShooterPlayerController.h"
#include "HorrorShooterHUD.h"
#include "HorrorShooterPlayerController.generated.h"

/**
 *
 */
UCLASS()
class BLACKOUTPROTOCOL_API AHorrorShooterPlayerController : public AShooterPlayerController
{
	GENERATED_BODY()

protected:

	/** Type of UI widget to spawn */
	UPROPERTY(EditAnywhere, Category = "Horror")
	TSubclassOf<UHorrorShooterHUD> HorrorUIClass;

	/** Pointer to the UI widget */
	TObjectPtr<UHorrorShooterHUD> HorrorUI;

public:

	/** Constructor */
	AHorrorShooterPlayerController();

protected:

	/** Possessed pawn initialization */
	virtual void OnPossess(APawn* aPawn) override;

	/** Input mapping context setup */
	virtual void SetupInputComponent() override;

};
