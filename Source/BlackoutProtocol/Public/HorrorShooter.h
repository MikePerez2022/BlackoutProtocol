// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShooterCharacter.h"
#include "BlackoutProtocolCharacter.h"
#include "HorrorShooter.generated.h"

//class USpotLightComponent;
class UInputAction;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUpdateSprintMeterD, float, Percentage);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSprintStateChangedD, bool, bSprinting);

UCLASS()
class BLACKOUTPROTOCOL_API AHorrorShooter : public AShooterCharacter
{
	GENERATED_BODY()

	/** Player light source */
	/*UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USpotLightComponent* SpotLight;*/

protected:
	/** Fire weapon input action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* SprintAction;

	/** If true, we're sprinting */
	bool bSprinting = false;

	/** If true, we're recovering stamina */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battery")
	bool bRecovering = false;

	/** Default walk speed when not sprinting or recovering */
	UPROPERTY(EditAnywhere, Category = "Walk")
	float WalkSpeed = 250.0f;

	/** Time interval for sprinting stamina ticks */
	UPROPERTY(EditAnywhere, Category = "Sprint")
	float SprintFixedTickTime = 0.03333f;

	/** Sprint stamina amount. Maxes at SprintTime */
	float SprintMeter = 0.0f;

	/** How long we can sprint for, in seconds */
	UPROPERTY(EditAnywhere, Category = "Sprint", meta = (ClampMin = 0, ClampMax = 10, Units = "s"))
	float SprintTime = 3.0f;

	/** Walk speed while sprinting */
	UPROPERTY(EditAnywhere, Category = "Sprint", meta = (ClampMin = 0, ClampMax = 10, Units = "cm/s"))
	float SprintSpeed = 600.0f;

	/** Walk speed while recovering stamina */
	UPROPERTY(EditAnywhere, Category = "Recovery")
	float RecoveringWalkSpeed = 150.0f;

	/** Time it takes for the sprint meter to recover */
	UPROPERTY(EditAnywhere, Category = "Recovery", meta = (ClampMin = 0, ClampMax = 10, Units = "s"))
	float RecoveryTime = 0.0f;

	/** Sprint tick timer */
	FTimerHandle SprintTimer;

public:

	/** Delegate called when the sprint meter should be updated */
	FUpdateSprintMeterD OnSprintMeterUpdated;

	///** Delegate called when we start and stop sprinting */
	FSprintStateChangedD OnSprintStateChanged;

public:
	// Sets default values for this character's properties
	AHorrorShooter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Gameplay cleanup */
	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

public:

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	/** Starts sprinting behavior */
	UFUNCTION(BlueprintCallable, Category = "Input")
	void DoStartSprint();

	/** Stops sprinting behavior */
	UFUNCTION(BlueprintCallable, Category = "Input")
	void DoEndSprint();

	/** Called while sprinting at a fixed time interval */
	void SprintFixedTick();

};
