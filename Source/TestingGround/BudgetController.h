// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ConstructionManager.h"
#include "BudgetController.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class TESTINGGROUND_API UBudgetController : public UObject
{
	GENERATED_BODY()
public:
	UBudgetController();

	UFUNCTION(BlueprintCallable)
	void Tick(float DeltaTime);
	
	UFUNCTION(BlueprintCallable, Category="Budget Info")
	int GetCurrentBudget() const { return m_budget; }

	void SetPlayerProfile(UPlayerProfile* profile);
	UFUNCTION(BlueprintCallable)
	void RegisterTransaction(int money);

	UFUNCTION(BlueprintCallable)
	bool CanBuy(int money) { return GetCurrentBudget() >= money; }

	UFUNCTION(BlueprintCallable, Category = "Budget Info")
	float GetTotalExpenses() const;

	UFUNCTION(BlueprintCallable, Category = "Budget Info")
	float GetTotalIncome() const;

	UFUNCTION(BlueprintCallable, Category = "Budget Info")
	float GetTotalBalanceChange() const;

	UFUNCTION(BlueprintCallable, Category = "Budget Info")
	void OnMonthChange();
	
private:
	UPROPERTY(BlueprintGetter=GetCurrentBudget)
	int		m_budget = 0;
	UPlayerProfile* PlayerProfile;
};
