// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingActor_base.h"

// Sets default values
ABuildingActor_base::ABuildingActor_base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABuildingActor_base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABuildingActor_base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

