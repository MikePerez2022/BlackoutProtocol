// Fill out your copyright notice in the Description page of Project Settings.


#include "HorrorShooterHUD.h"

void UHorrorShooterHUD::SetupCharacter(AHorrorShooter* HorrorCharacter)
{
	HorrorCharacter->OnSprintMeterUpdated.AddDynamic(this, &UHorrorShooterHUD::OnSprintMeterUpdated);
	HorrorCharacter->OnSprintStateChanged.AddDynamic(this, &UHorrorShooterHUD::OnSprintStateChanged);
}

void UHorrorShooterHUD::OnSprintMeterUpdated(float Percent)
{
	// call the BP handler
	BP_SprintMeterUpdated(Percent);
}

void UHorrorShooterHUD::OnSprintStateChanged(bool bSprinting)
{
	// call the BP handler
	BP_SprintStateChanged(bSprinting);
}
