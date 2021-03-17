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
class TESTINGGROUND_API APlayerProfile : public AActor
{
	GENERATED_BODY()
public:
	APlayerProfile();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	TArray<AConstructableBuilding*> GetAllBuildings() const;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Controllers")
	UBudgetController*			BudgetController = nullptr;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Controllers")
	UConstructionManager*		ConstructionController = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Controllers")
	UHorsesManager*				HorsesController = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Controllers")
	ATime*						TimeController = nullptr;
};
