// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerProfile.h"

UPlayerProfile::UPlayerProfile()
{
	BudgetController = CreateDefaultSubobject<UBudgetController>("Budget Manager");
	BudgetController->SetPlayerProfile(this);
	BudgetController->AddCurrency(InitialBudget);
	ConstructionController = CreateDefaultSubobject<UConstructionManager>("Construction Manager");
	ConstructionController->SetPlayerProfile(this);
	HorsesController = CreateDefaultSubobject<UHorsesManager>("Horses Manager");
	HorsesController->SetPlayerProfile(this);
}

void UPlayerProfile::Tick_Implementation(float DeltaTime)
{
	ConstructionController->Tick(DeltaTime);
	BudgetController->Tick(DeltaTime);
}

