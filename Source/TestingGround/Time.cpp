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
		m_currentMonth++;
		OnMonthChange.Broadcast();
	}
}

int ATime::GetCurrentMonthTotal() const
{
	return m_currentMonth;
}

int ATime::GetCurrentYear() const
{
	return int(m_currentMonth) / int(Months::MonthCount);
}

TEnumAsByte<Months> ATime::GetCurrentMonth() const
{
	return TEnumAsByte<Months>(m_currentMonth % int(Months::MonthCount));
}


void ATime::BeginPlay()
{
	Super::BeginPlay();
}
