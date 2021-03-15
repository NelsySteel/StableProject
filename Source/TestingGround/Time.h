// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Time.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMonthChange);

UENUM(Blueprintable)
enum Months
{
	January					UMETA(DisplayName = "January"),
	February                UMETA(DisplayName = "February"),
	March                   UMETA(DisplayName = "March"),
	April                   UMETA(DisplayName = "April"),
	May						UMETA(DisplayName = "May"),
	June					UMETA(DisplayName = "June"),
	July					UMETA(DisplayName = "July"),
	August                  UMETA(DisplayName = "August"),
	September               UMETA(DisplayName = "September"),
	October                 UMETA(DisplayName = "October"),
	November                UMETA(DisplayName = "November"),
	December                UMETA(DisplayName = "December"),
	MonthCount				
};

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
	int GetCurrentMonthTotal() const;

	UFUNCTION(BlueprintCallable)
	int GetCurrentYear() const;

	UFUNCTION(BlueprintCallable)
	TEnumAsByte<Months>	GetCurrentMonth() const;
	
	UPROPERTY(BlueprintAssignable)
	FOnMonthChange	OnMonthChange;
protected:
	void BeginPlay() override;

private:
	float		m_currentTime = 0;

	
	int			m_currentMonth = 0;
	int			m_currentYear = 0;
	
};
