// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Time.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMonthChange);

/**
 * 
 */
UCLASS()
class TESTINGGROUND_API ATime : public AActor
{
	GENERATED_BODY()
public:
	ATime();
	void TickActor(float DeltaTime, ELevelTick TickType, FActorTickFunction& ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time Settings")
	float		m_secondsPerMonth = 300;


	UFUNCTION(BlueprintCallable)
		int GetCurrentMonth() const;

	UPROPERTY(BlueprintAssignable)
	FOnMonthChange	OnMonthChange;
protected:
	void BeginPlay() override;

private:
	float		m_currentTime = 0;

	
	int			m_currentMonth = 0;
	int			m_currentYear = 0;
	
};
