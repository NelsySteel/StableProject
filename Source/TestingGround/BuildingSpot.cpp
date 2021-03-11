#include "BuildingSpot.h"

ABuildingSpot::ABuildingSpot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ABuildingSpot::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABuildingSpot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

