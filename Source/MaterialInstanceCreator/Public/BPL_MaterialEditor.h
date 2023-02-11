// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Materials/MaterialInstanceConstant.h"
#include "BPL_MaterialEditor.generated.h"

/**
 * 
 */
UCLASS()
class MATERIALINSTANCECREATOR_API UBPL_MaterialEditor : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable,Category="MaterialInstanceCreator")
	static void SaveInstance(UMaterialInstanceConstant* Instance);

	UFUNCTION(BlueprintCallable, Category = "MaterialInstanceCreator")
	static void CreateInstancesConstant(UMaterialInterface* Parent,FString InstanceName, FString Path);
	
};
