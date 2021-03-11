// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Structures.h"
#include "MenuItemWidget1.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class TESTINGGROUND_API UMenuItemWidget1 : public UUserWidget
{
	GENERATED_BODY()
public:
	void SetInfo(const FBuildingSettings& info) { BuildingInfo = info; }
	UFUNCTION(BlueprintCallable)
		FBuildingSettings GetInfo() const { return BuildingInfo; }
	
	UFUNCTION(BlueprintImplementableEvent)
	void SetText(const FString& name, const int& price);

	
	UFUNCTION(BlueprintCallable)
	void Init(const FBuildingSettings& info);
private:
	FBuildingSettings BuildingInfo;
};
