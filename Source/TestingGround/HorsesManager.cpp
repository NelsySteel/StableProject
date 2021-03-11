// Fill out your copyright notice in the Description page of Project Settings.


#include "HorsesManager.h"

void UHorseObject::SetInfo(FString name, FHorseTypeInfo type, TEnumAsByte<HorseColor> color, int speed, int jump,
	int handling)
{
	Name = name;
	Type = type;
	Color = color;
	Characteristics.Speed = speed;
	Characteristics.Jump = jump;
	Characteristics.Handling = handling;
}

void UHorseObject::SetRandomParameters(FString name, UDataTable* HorsesInfo)
{
	int min_value = 5;
	int max_value = 15;
	auto color_index = FMath::RandRange(0, HorseColor::Empty);
	const FString ContextString;
	const auto& breed_names = HorsesInfo->GetRowNames();
	const auto& breed_index = FMath::RandRange(0, breed_names.Num() - 1);
	auto type = HorsesInfo->FindRow<FHorseTypeInfo>(breed_names[breed_index], ContextString);
	SetInfo(name, *type, TEnumAsByte<HorseColor>(color_index), FMath::RandRange(min_value, max_value), FMath::RandRange(min_value, max_value), FMath::RandRange(min_value, max_value));
}
