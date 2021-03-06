// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Structures.h"
#include "ConstructableBuilding.h"
#include "ConstructionManager.generated.h"

class APlayerProfile;
using namespace std;

class UMenuItemWidget1;

UCLASS(Blueprintable, BlueprintType, EditInlineNew)
class TESTINGGROUND_API UConstructionManager : public UObject
{
	GENERATED_BODY()

public:
	UConstructionManager() {}

	void SetPlayerProfile(APlayerProfile* profile);
	
	UFUNCTION(BlueprintCallable)
	void Tick(float DeltaTime);
	
	UFUNCTION(BlueprintCallable)
	AConstructableBuilding* BuildObject(AConstructableBuilding* object, FBuildingSettings info);

	UFUNCTION(BlueprintCallable)
	TArray<FBuildingSettings> GetBuildingWidgets(UDataTable* buildingsInfo, APlayerProfile* profile, TEnumAsByte<BuildingType> type);

	UFUNCTION(BlueprintCallable)
	void MoveBuilding(AConstructableBuilding* building);
	
	UFUNCTION()
	void OnStopMoving();
private:
	UPROPERTY()
	UWorld*						World = nullptr;

	UPROPERTY()
	AConstructableBuilding*		BuiltObject = nullptr;
	APlayerProfile*				PlayerProfile;
};
