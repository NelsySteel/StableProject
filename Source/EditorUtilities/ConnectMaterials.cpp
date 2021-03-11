// Fill out your copyright notice in the Description page of Project Settings.

#include "ConnectMaterials.h"
#include "Materials/MaterialExpressionTextureSample.h"
#include "Materials/MaterialExpressionVectorParameter.h"

UMaterialExpressionVectorParameter* UConnectMaterials::CreateEmissionParameter(UMaterial* material)
{
	UMaterialExpressionVectorParameter* Expression = NewObject<UMaterialExpressionVectorParameter>(material);
	
	Expression->SetParameterName("EmissiveColor");
	material->EmissiveColor.Expression = Expression;
	return Expression;
}

void UConnectMaterials::ConnectTextureToBaseColor(UMaterial* material, UMaterialExpressionTextureSample* TextureExpression)
{
	material->BaseColor.Expression = TextureExpression;
}
