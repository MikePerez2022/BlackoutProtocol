// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Components/SpotLightComponent.h"
#include "FlashlightComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BLACKOUTPROTOCOL_API UFlashlightComponent : public USceneComponent
{
	GENERATED_BODY()

	bool bIsOn = true;
	bool bEnabled = true;

public:	
	// Sets default values for this component's properties
	UFlashlightComponent();

	/** Player light source */
	UPROPERTY(EditAnywhere, Category = "Flashlight")
	USpotLightComponent* Flashlight;

	UFUNCTION(BlueprintCallable, Category = "Flashlight")
	void ToggleFlashlight();

	UFUNCTION(BlueprintCallable, Category = "Flashlight")
	void SetFlashlightEnabled(bool bNewEnabled);


	UFUNCTION(BlueprintCallable, Category = "Flashlight")
	void DrainLight(float val);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
