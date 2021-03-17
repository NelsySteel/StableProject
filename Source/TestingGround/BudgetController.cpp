// Fill out your copyright notice in the Description page of Project Settings.


#include "BudgetController.h"
#include <algorithm>
#include "PlayerProfile.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

UBudgetController::UBudgetController()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATime::StaticClass(), FoundActors);
	if (FoundActors.Num() >0)
	{
		Cast<ATime>(FoundActors[0])->OnMonthChange.AddUniqueDynamic(this, &UBudgetController::OnMonthChange);
	}
}

void UBudgetController::SetPlayerProfile(APlayerProfile* profile)
{
	PlayerProfile = profile;
}

void UBudgetController::RegisterTransaction(int money)
{
	CurrentBudget += money;
}

float UBudgetController::GetTotalExpenses() const
{
	float result = 0.f;
	const auto& Buildings = PlayerProfile->GetAllBuildings();
	for (const auto* Building : Buildings)
	{
		if (const auto& component = Building->FindComponentByClass(UBuildingPropertiesComponent::StaticClass()))
		{
			result += Cast<UBuildingPropertiesComponent>(component)->GetBuildingExpenses();
		}
	}
	return result;
}

float UBudgetController::GetTotalIncome() const
{
	float result = 0.f;
	const auto& Buildings = PlayerProfile->GetAllBuildings();
	for (const auto* Building : Buildings)
	{
		if (const auto& component = Building->FindComponentByClass(UBuildingPropertiesComponent::StaticClass()))
		{
			result += Cast<UBuildingPropertiesComponent>(component)->GetBuildingIncome();
		}
	}
	return result;
}

float UBudgetController::GetTotalBalanceChange() const
{
	float result = 0.f;
	const auto& Buildings = PlayerProfile->GetAllBuildings();
	for (const auto* Building : Buildings)
	{
		if (const auto& component = Building->FindComponentByClass(UBuildingPropertiesComponent::StaticClass()))
		{
			const auto& BuildingSettingsComponent = Cast<UBuildingPropertiesComponent>(component);
			result += BuildingSettingsComponent->GetBuildingIncome();
			result -= BuildingSettingsComponent->GetBuildingExpenses();
		}
	}
	return result;
}

void UBudgetController::OnMonthChange()
{
	RegisterTransaction(GetTotalBalanceChange());
}
