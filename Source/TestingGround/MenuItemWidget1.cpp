// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuItemWidget1.h"

void UMenuItemWidget1::Init(const FBuildingSettings& info)
{
	SetInfo(info);
	SetText(info.name, info.base_price);
}
