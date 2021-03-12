// Fill out your copyright notice in the Description page of Project Settings.


#include "Time.h"

ATime::ATime()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATime::TickActor(float DeltaTime, ELevelTick TickType, FActorTickFunction& ThisTickFunction)
{
	m_currentTime += DeltaTime;
	if ((int(m_currentTime) / int(m_secondsPerMonth)) > m_currentMonth)
	{
		OnMonthChange.Broadcast();
	}
}

int ATime::GetCurrentMonth() const
{
	return m_currentMonth;
}

void ATime::BeginPlay()
{
	Super::BeginPlay();
}
