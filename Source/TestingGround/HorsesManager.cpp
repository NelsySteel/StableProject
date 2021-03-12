// Fill out your copyright notice in the Description page of Project Settings.


#include "HorsesManager.h"
#include "PlayerProfile.h"


void UHorsesManager::SetPlayerProfile(UPlayerProfile* profile)
{
	PlayerProfile = profile ;
}

bool UHorsesManager::BuyHorse(UHorseObject* horse)
{
	if (!horse)
	{
		return false;
	}
	
	const auto& price = horse->GetPrice(PlayerProfile);
	if (PlayerProfile->BudgetController->CanBuy(price))
	{
		if (AddHorse(horse))
		{
			PlayerProfile->BudgetController->RemoveCurrency(price);
			return true;
		}
	}
	
	return false;
}

bool UHorsesManager::AddHorse(UHorseObject* horse)
{
	if (!horse)
	{
		return false;
	}
	Horses.AddUnique(horse);
	return true;
}

bool UHorsesManager::SellHorse(UHorseObject* horse)
{
	if (horse == nullptr)
	{
		return false;
	}
	const auto& price = horse->GetPrice(PlayerProfile);
	PlayerProfile->BudgetController->AddCurrency(price);
	return RemoveHorse(horse);
}

bool UHorsesManager::RemoveHorse(UHorseObject* horse)
{
	if (horse == nullptr)
	{
		return false;
	}
	if (Horses.Find(horse) != INDEX_NONE)
	{
		Horses.Remove(horse);
		return true;
	}
	return false;
}


void UHorseObject::SetInfo(FString name, FHorseTypeInfo type, TEnumAsByte<HorseColor> color, int speed, int jump,
	int handling)
{
	Name = name;
	Type = type;
	Color = color;
	Characteristics.Speed = speed;
	Characteristics.Jump = jump;
	Characteristics.Handling = handling;
}

void UHorseObject::SetRandomParameters(FString name, UDataTable* HorsesInfo)
{
	const FString ContextString;
	
	const auto& color_index = FMath::RandRange(0, HorseColor::Empty);
	const auto& breed_names = HorsesInfo->GetRowNames();
	const auto& breed_index = FMath::RandRange(0, breed_names.Num() - 1);
	const auto& type = HorsesInfo->FindRow<FHorseTypeInfo>(breed_names[breed_index], ContextString);
	const auto& speed = FMath::RandRange(MIN_HORSE_SPEED, MAX_HORSE_SPEED);
	const auto& jump = FMath::RandRange(MIN_HORSE_JUMP, MAX_HORSE_JUMP);
	const auto& handling = FMath::RandRange(MIN_HORSE_HANDLING, MAX_HORSE_HANDLING);
	
	SetInfo(name, *type, TEnumAsByte<HorseColor>(color_index), speed, jump, handling);
}

int UHorseObject::GetPrice(UPlayerProfile* profile) const
{
	return Type.BasePrice;
}
