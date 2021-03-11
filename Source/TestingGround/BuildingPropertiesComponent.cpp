// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingPropertiesComponent.h"
#include <string>

// Sets default values for this component's properties
UBuildingPropertiesComponent::UBuildingPropertiesComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UBuildingPropertiesComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBuildingPropertiesComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

TMap<FString, FString> UBuildingPropertiesComponent::GetVisualInfo() const
{
	TMap<FString, FString> info = TMap<FString, FString>();
	info.Add("Price", FString::FromInt(GetBuildingPrice()));
	return info;
}

void UStablePropertiesComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UStablePropertiesComponent::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

TMap<FString, FString> UStablePropertiesComponent::GetVisualInfo() const
{
	auto info = UBuildingPropertiesComponent::GetVisualInfo();
	info.Add("Horses", FString::FromInt(GetStablesCount()));
	return info;
}

