#pragma once

#include <memory>

#include "Containers/EnumAsByte.h"
#include "Materials/Material.h"
#include "Engine/StaticMesh.h"
#include "Engine/DataTable.h"
#include "BuildingActor_base.h"
#include "BuildingPropertiesComponent.h"

#include "Structures.generated.h"


UENUM(Blueprintable)
enum BuildingType 
{
    Administrative          UMETA(DisplayName = "Administrative"),
    Stable                  UMETA(DisplayName = "Stable"),
    Field                   UMETA(DisplayName = "TrainingField")
};

USTRUCT(BlueprintType, Blueprintable)
struct FBuildingSettings : public FTableRowBase
{
    GENERATED_USTRUCT_BODY()
        FBuildingSettings(TEnumAsByte<BuildingType> type, const FString& name) : type(type), name(name) {}
    FBuildingSettings() {}

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TEnumAsByte<BuildingType>   type = TEnumAsByte<BuildingType>(Administrative);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString                     name = "default";

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int                         base_price = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSubclassOf<ABuildingActor_base> ChildActorClass = nullptr;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSubclassOf<UBuildingPropertiesComponent>    DetailsClass = nullptr;
};