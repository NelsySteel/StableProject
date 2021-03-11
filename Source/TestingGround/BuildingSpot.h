// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Structures.h"
#include "BuildingSpot.generated.h"

UCLASS(BlueprintType, Blueprintable)
class TESTINGGROUND_API ABuildingSpot : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuildingSpot();
	
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	FTransform GetBuildingPosition() const;

	bool		IsBusy() const { return m_isBusy; }
	void		BuildOnSpot() { m_isBusy = true; }
	
	TEnumAsByte<BuildingType> GetType() const { return type; }
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<BuildingType>	type;

	bool						m_isBusy;

};
