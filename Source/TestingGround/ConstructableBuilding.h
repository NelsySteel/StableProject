// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Structures.h"
#include "ConstructableBuilding.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFinishMovingDelegate);


UENUM(Blueprintable)
enum BuildingState
{
	Idle                    UMETA(DisplayName = "Idle"),
	Moving                  UMETA(DisplayName = "Moving")
};



UENUM(Blueprintable)
enum BuildingColor
{
	Color_Normal                    UMETA(DisplayName = "Normal"),
	Color_Available                  UMETA(DisplayName = "Available"),
	Color_Inavailable                  UMETA(DisplayName = "Forbidden")
	
};


UCLASS(Blueprintable, BlueprintType)
class TESTINGGROUND_API AConstructableBuilding : public AActor
{
	GENERATED_BODY()
	
public:	
	AConstructableBuilding();

	void TickActor(float DeltaTime, ELevelTick TickType, FActorTickFunction& ThisTickFunction) override;

	UFUNCTION(BlueprintImplementableEvent)
	void SetColor(const TEnumAsByte<BuildingColor>& Material);
	
	UFUNCTION(BlueprintNativeEvent)
	void SetInfo(const FBuildingSettings& info) ;

	UFUNCTION(BlueprintCallable)
	FBuildingSettings GetInfo() const { return BuildingInfo; }

	UFUNCTION(BlueprintCallable)
	void Move();

	UFUNCTION(BlueprintCallable)
	bool PlacedCorrectly() const { return m_overlappedActors.Num() == 0; }

	UFUNCTION(BlueprintCallable)
	bool StopMoving();

	UFUNCTION(BlueprintCallable)
		AActor* CreateBuildingChild();

	UFUNCTION(BlueprintCallable)
	void ProcessActorBeginOverlap(AActor* overlappedActor);

	UFUNCTION(BlueprintCallable)
	void ProcessActorEndOverlap(AActor* overlappedActor);

	UFUNCTION(BlueprintCallable)
	TEnumAsByte<BuildingState> GetState() const { return m_currentState; }

	UFUNCTION(BlueprintCallable)
	TEnumAsByte<BuildingColor> GetMaterial() const;

	UFUNCTION(BlueprintCallable)
	bool IsReady() const { return m_isAlreadyInWorld; }
	
	UPROPERTY(BlueprintAssignable)
	FOnFinishMovingDelegate	OnFinishMoving;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBuildingSettings BuildingInfo;

protected:
	void BeginPlay() override;
	
public:	
	void Tick(float DeltaTime) override;
	void SetPosition(const FVector& position);
	void SetPosition(const FTransform& position);

private:
	UPROPERTY(BlueprintGetter = GetState)
	TEnumAsByte<BuildingState>  m_currentState = Idle;
	TEnumAsByte<BuildingColor>  m_currentColor = Color_Normal;

	TArray<AActor*>					m_overlappedActors;
	
	bool							m_isAlreadyInWorld;
	FTransform						m_originalTransform;
};
