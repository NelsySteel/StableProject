// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "AssetActionUtility.h"
#include "Editor/Blutility/Classes/EditorUtilityWidget.h"
#include "Materials/MaterialExpressionVectorParameter.h"
#include "ConnectMaterials.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class EDITORUTILITIES_API UConnectMaterials : public UAssetActionUtility
{
	GENERATED_BODY()
	UConnectMaterials() {};
public:
	UFUNCTION(BlueprintCallable)
	UMaterialExpressionVectorParameter* CreateEmissionParameter(UMaterial* material);
	
	UFUNCTION(BlueprintCallable)
	void ConnectTextureToBaseColor(UMaterial* material, UMaterialExpressionTextureSample* Texture);
};
