// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerProfile.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

APlayerProfile::APlayerProfile()
{
	if (!BudgetController)
	{
		BudgetController = CreateDefaultSubobject<UBudgetController>("Budget Manager");
	}
	BudgetController->SetPlayerProfile(this);

	if (!ConstructionController)
	{
		ConstructionController = CreateDefaultSubobject<UConstructionManager>("Construction Manager");
	}
	ConstructionController->SetPlayerProfile(this);

	if (!HorsesController)
	{
		HorsesController = CreateDefaultSubobject<UHorsesManager>("Horses Manager");
	}
	HorsesController->SetPlayerProfile(this);
}

TArray<AConstructableBuilding*> APlayerProfile::GetAllBuildings() const
{
	TArray<AConstructableBuilding*> result;
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AConstructableBuilding::StaticClass(), FoundActors);
	for (auto&& buildingActor : FoundActors)
	{
		auto Building = Cast<AConstructableBuilding>(buildingActor);
		if (Building->IsReady())
		{
			result.AddUnique(Building);
		}
		
	}
	return result;
}

void APlayerProfile::Tick_Implementation(float DeltaTime)
{
	ConstructionController->Tick(DeltaTime);
	BudgetController->Tick(DeltaTime);
}

