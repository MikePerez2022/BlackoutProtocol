// Fill out your copyright notice in the Description page of Project Settings.


#include "FlashlightComponent.h"

// Sets default values for this component's properties
UFlashlightComponent::UFlashlightComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	Flashlight = CreateDefaultSubobject<USpotLightComponent>(TEXT("Flashlight"));
	Flashlight->SetupAttachment(this); // attach to flashlight component root

	// ...
	Flashlight->SetVisibility(true);
	Flashlight->Intensity = 10.0f;
	Flashlight->InnerConeAngle = 20.0f;
	Flashlight->OuterConeAngle = 40.0f;
	Flashlight->bUseInverseSquaredFalloff = false;
	Flashlight->SetMobility(EComponentMobility::Movable);
}

void UFlashlightComponent::ToggleFlashlight()
{
	if (!bEnabled) return;
	bIsOn = !bIsOn;
	Flashlight->SetVisibility(bIsOn);
}

void UFlashlightComponent::SetFlashlightEnabled(bool bNewEnabled)
{
	bEnabled = bNewEnabled;
	if (!bEnabled)
	{
		bIsOn = false;
		Flashlight->SetVisibility(false);
	}
}

void UFlashlightComponent::DrainLight(float val)
{
	if (!bIsOn) return;
	float intensity = 0;
	if (val > 0) intensity = 10.0f * (val/100.0f);
	Flashlight->SetIntensity(intensity);
}


// Called when the game starts
void UFlashlightComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UFlashlightComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

