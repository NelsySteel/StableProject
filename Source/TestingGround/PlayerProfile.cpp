// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerProfile.h"

UPlayerProfile::UPlayerProfile()
{
	budgetCtrlr = CreateDefaultSubobject<UBudgetController>("Budget Manager");
	budgetCtrlr->AddCurrency(250);
	constructionMngr = CreateDefaultSubobject<UConstructionManager>("Construction Manager");
}

void UPlayerProfile::Tick(float DeltaTime)
{
	constructionMngr->Tick(DeltaTime);
}

bool UPlayerProfile::BuyHorse(UHorseObject* horse)
{
	if (!horse)
	{
		return false;
	}
	auto price = horse->Type.BasePrice;
	if (budgetCtrlr->CanBuy(price))
	{
		if (AddHorse(horse))
		{
			budgetCtrlr->RemoveCurrency(price);
			return true;
		}
	}
	return false;
}

bool UPlayerProfile::AddHorse(UHorseObject* horse)
{
	if (!horse)
	{
		return false;
	}
	horses.Add(horse);
	return true;
}

bool UPlayerProfile::SellHorse(UHorseObject* horse)
{
	if (!horse)
	{
		return false;
	}
	auto price = horse->Type.BasePrice;
	budgetCtrlr->AddCurrency(price);
	return RemoveHorse(horse);
}

bool UPlayerProfile::RemoveHorse(UHorseObject* horse)
{
	if (!horse)
	{
		return false;
	}
	if (horses.Find(horse))
	{
		horses.Remove(horse);
		return true;
	}
	return false;
}
