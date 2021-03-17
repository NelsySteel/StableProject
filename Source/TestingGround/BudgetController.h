// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ConstructionManager.h"
#include "BudgetController.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, EditInlineNew)
class TESTINGGROUND_API UBudgetController : public UObject
{
	GENERATED_BODY()
public:
	UBudgetController();

	UFUNCTION(BlueprintCallable)
	void Tick(float DeltaTime) {}
	
	UFUNCTION(BlueprintCallable, Category="Budget Info")
	int GetCurrentBudget() const { return CurrentBudget; }

	void SetPlayerProfile(APlayerProfile* profile);
	UFUNCTION(BlueprintCallable)
	void RegisterTransaction(int money);

	UFUNCTION(BlueprintCallable)
	bool CanBuy(int money) const { return GetCurrentBudget() >= money; }

	UFUNCTION(BlueprintCallable, Category = "Budget Info")
	float GetTotalExpenses() const;

	UFUNCTION(BlueprintCallable, Category = "Budget Info")
	float GetTotalIncome() const;

	UFUNCTION(BlueprintCallable, Category = "Budget Info")
	float GetTotalBalanceChange() const;

	UFUNCTION(BlueprintCallable, Category = "Budget Info")
	void OnMonthChange();

	UPROPERTY(EditDefaultsOnly, Category = "Game Start")
	int				CurrentBudget = 250;
private:
	APlayerProfile* PlayerProfile;
};
