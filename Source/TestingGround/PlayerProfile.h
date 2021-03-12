// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BudgetController.h"
#include "HorsesManager.h"
#include "ConstructionManager.h"
#include "Time.h"
#include "PlayerProfile.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class TESTINGGROUND_API UPlayerProfile : public UObject
{
	GENERATED_BODY()
public:
	UPlayerProfile();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Tick(float DeltaTime);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
	ATime* timeController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category = "Game Start")
	int InitialBudget = 250;;

	UPROPERTY(BlueprintReadOnly, Category = "Controllers")
	UBudgetController*			BudgetController;
	
	UPROPERTY(BlueprintReadOnly, Category = "Controllers")
	UConstructionManager*		ConstructionController;

	UPROPERTY(BlueprintReadOnly, Category = "Controllers")
	UHorsesManager*				HorsesController;
};
