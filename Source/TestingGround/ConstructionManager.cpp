#include "ConstructionManager.h"
#include "BuildingSpot.h"
#include "ConstructableBuilding.h"
#include "PlayerProfile.h"

void UConstructionManager::Tick(float DeltaTime)
{
	if (BuiltObject != nullptr)
	{
		TArray<TEnumAsByte<EObjectTypeQuery> > objTypes;
		objTypes.Add(UEngineTypes::ConvertToObjectType(ECC_GameTraceChannel3));
		FHitResult hitResult;
		GetWorld()->GetFirstPlayerController()->GetHitResultUnderCursorForObjects(objTypes, true, hitResult);
		if (hitResult.IsValidBlockingHit())
		{
			if (const auto hitSpot = dynamic_cast<ABuildingSpot*>(hitResult.GetActor()))
			{
				BuiltObject->SetPosition(hitSpot->GetBuildingPosition(), hitSpot->GetType() == BuiltObject->GetInfo().type && !hitSpot->IsBusy(), hitSpot);
			}
		}
		else
		{
			GetWorld()->GetFirstPlayerController()->GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_GameTraceChannel1), true, hitResult);
			if (hitResult.IsValidBlockingHit())
			{
				BuiltObject->SetPosition(hitResult.Location, false);
			}
		}
		
	}
}

AConstructableBuilding* UConstructionManager::BuildObject(AConstructableBuilding*  building, FBuildingSettings info)
{
	MoveBuilding(building);
	BuiltObject->SetInfo(info);
	return BuiltObject;
}

TArray<FBuildingSettings> UConstructionManager::GetBuildingWidgets(UDataTable* buildingsInfo, UPlayerProfile* profile, TEnumAsByte<BuildingType> type)
{
	TArray<FBuildingSettings> widgets;
	TArray<FBuildingSettings*> rows;
	const FString ContextString;
	for (const auto& rowName : buildingsInfo->GetRowNames())
	{
		const auto& info = buildingsInfo->FindRow<FBuildingSettings>(rowName, ContextString);
		if (info->type == type && info->ChildActorClass != nullptr)
		{
			widgets.Add(*info);
		}
	}
	return widgets;
}

void UConstructionManager::MoveBuilding(AConstructableBuilding* building)
{
	if (BuiltObject)
	{
		BuiltObject->StopMoving();
	}
	BuiltObject = building;
	BuiltObject->Move();
	BuiltObject->OnFinishMoving.AddUniqueDynamic(this, &UConstructionManager::OnStopMoving);
}


void UConstructionManager::OnStopMoving()
{
	BuiltObject = nullptr;
}

