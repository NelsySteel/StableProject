// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "HorsesManager.generated.h"

class UHorseObject;

UENUM(Blueprintable)
enum HorseColor
{
	Black                                   UMETA(DisplayName = "Black"),
	Gray                                    UMETA(DisplayName = "Gray"),
	Iron_Gray                               UMETA(DisplayName = "Iron Gray"),
	Liver                                   UMETA(DisplayName = "Liver"),
	Flaxen                                  UMETA(DisplayName = "Flaxen"),
	Dun                                     UMETA(DisplayName = "Dun"),
	Bay                                     UMETA(DisplayName = "Bay"),
	Chestnut                                UMETA(DisplayName = "Chestnut"),
	Palomino                                UMETA(DisplayName = "Palomino"),
	Cremello                                UMETA(DisplayName = "Cremello"),
	White                                   UMETA(DisplayName = "White"),

    Empty                                   UMETA(DisplayName = "Empty color")
	
};


USTRUCT(BlueprintType, Blueprintable)
struct FHorseTypeInfo : public FTableRowBase
{
    GENERATED_USTRUCT_BODY()
        FHorseTypeInfo() {}

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString TypeName = "Plain horse";

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int BasePrice = 100;
};

USTRUCT(BlueprintType, Blueprintable)
struct FHorseCharacteristics : public FTableRowBase
{
    GENERATED_USTRUCT_BODY()
        FHorseCharacteristics() {}

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int Speed = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int Jump = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int Handling = 0;
};

UCLASS(BlueprintType)
class TESTINGGROUND_API UHorseObject : public UObject
{
    GENERATED_BODY()
public:
    UHorseObject() {}
	
    UFUNCTION(BlueprintCallable)
    void SetInfo(FString name, FHorseTypeInfo type, TEnumAsByte<HorseColor> color, int speed, int jump, int handling);

    UFUNCTION(BlueprintCallable)
    void SetRandomParameters(FString name, UDataTable* HorsesInfo);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString Name = "Adele";

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FHorseTypeInfo Type = {};
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int Age = 2;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FHorseCharacteristics Characteristics = {};

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TEnumAsByte<HorseColor> Color = Empty;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        UHorseObject* mother = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        UHorseObject* father = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray<UHorseObject*> foalings = {};
};
/**
 * 
 */
UCLASS(BlueprintType)
class TESTINGGROUND_API UHorsesManager : public UObject
{
	GENERATED_BODY()
public:
	UHorsesManager() {}

    
};
