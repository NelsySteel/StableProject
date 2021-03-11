// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BuildingPropertiesComponent.generated.h"


UCLASS( ClassGroup=(Buildings), meta=(BlueprintSpawnableComponent) )
class TESTINGGROUND_API UBuildingPropertiesComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBuildingPropertiesComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
		int		GetBuildingPrice() const { return BuildingPrice; }

	UFUNCTION(BlueprintCallable)
	virtual TMap<FString, FString> GetVisualInfo() const;
private:
	int			BuildingPrice = 0;
};

UCLASS(ClassGroup = (Buildings), meta = (BlueprintSpawnableComponent))
class TESTINGGROUND_API UStablePropertiesComponent : public UBuildingPropertiesComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UStablePropertiesComponent() : UBuildingPropertiesComponent() {}

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	int		GetStablesCount() const { return StablesAmount; }
	TMap<FString, FString> GetVisualInfo() const override;
private:
	int			StablesAmount = 0;
};
