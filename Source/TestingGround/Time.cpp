// Fill out your copyright notice in the Description page of Project Settings.


#include "Time.h"
#include "math.h"

ATime::ATime()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATime::TickActor(float DeltaTime, ELevelTick TickType, FActorTickFunction& ThisTickFunction)
{
	m_currentTime += DeltaTime * GetModifier();

	if (GetCurrentMonthProgress() >= 1)
	{
		m_currentMonth++;
		OnMonthChange.Broadcast();
		m_currentTime = 0;
	}
}

int ATime::GetCurrentMonthTotal() const
{
	return m_currentMonth;
}

float ATime::GetCurrentMonthProgress() const
{
	return m_currentTime / m_secondsPerMonth;
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
