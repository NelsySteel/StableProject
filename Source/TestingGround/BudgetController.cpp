// Fill out your copyright notice in the Description page of Project Settings.


#include "BudgetController.h"
#include <algorithm>

void UBudgetController::AddCurrency(int money)
{
	m_budget += money;
}

void UBudgetController::RemoveCurrency(int money)
{
	m_budget = std::max(0, m_budget - money);
}
