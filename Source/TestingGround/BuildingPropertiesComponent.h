// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Components/ActorComponent.h"
#include "BuildingPropertiesComponent.generated.h"


UCLASS(ClassGroup=(BuildingSettings), Blueprintable)
class TESTINGGROUND_API UBuildingPropertiesComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UBuildingPropertiesComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	float GetBuildingIncome() const;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	float GetBuildingExpenses() const;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Upgrade();
	
	UFUNCTION(BlueprintCallable)
	virtual TMap<FString, FString> GetVisualInfo() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float		BuildingIncome = 100;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float		BuildingExpenses = 75;
};

UCLASS(ClassGroup = (BuildingSettings), Blueprintable)
class TESTINGGROUND_API UStablePropertiesComponent : public UBuildingPropertiesComponent
{
	GENERATED_BODY()

public:
	UStablePropertiesComponent() : UBuildingPropertiesComponent()
	{
		BuildingIncome = 150;
		BuildingExpenses = 100;
	}

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	int		GetStablesCount() const { return StablesAmount; }
	
	TMap<FString, FString> GetVisualInfo() const override;
private:
	int			StablesAmount = 0;
};
