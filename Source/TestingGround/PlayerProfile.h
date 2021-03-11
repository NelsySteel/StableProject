// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BudgetController.h"
#include "HorsesManager.h"
#include "ConstructionManager.h"
#include "PlayerProfile.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class TESTINGGROUND_API UPlayerProfile : public UObject
{
	GENERATED_BODY()
public:
	UPlayerProfile();

	UFUNCTION(BlueprintCallable)
	void Tick(float DeltaTime);
	
	UFUNCTION(BlueprintCallable)
	bool BuyHorse(UHorseObject* horse);
	
	UFUNCTION(BlueprintCallable)
	bool AddHorse(UHorseObject* horse);

	UFUNCTION(BlueprintCallable)
	bool SellHorse(UHorseObject* horse);

	UFUNCTION(BlueprintCallable)
		TArray<UHorseObject*> GetHorses() { return horses; };

	UFUNCTION(BlueprintCallable)
	bool RemoveHorse(UHorseObject* horse);

	UPROPERTY(BlueprintReadOnly)
	UBudgetController*		budgetCtrlr;
	
	UPROPERTY(BlueprintReadOnly)
	UConstructionManager*	constructionMngr;
private:
	TArray<UHorseObject*>	horses;
};
