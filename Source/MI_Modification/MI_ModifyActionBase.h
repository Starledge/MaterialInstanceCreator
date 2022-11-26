// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "MI_ModifyActionBase.generated.h"

/**
 * 
 */

UCLASS()
class MI_MODIFICATION_API UMI_ModifyActionBase : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "Modify Material Instance")
		static UMI_ModifyActionBase* MarkPackageToSave(UMaterialInstanceConstant* _Child);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "Modify Material Instance")
		static UMI_ModifyActionBase* CreateMaterialInstances(UMaterial* _Parent,FString _Path,FName _InstanceName);

	virtual void Activate() override;
	
private:
	//Variables:
	UMaterialInstanceConstant* Child;
	UMaterial* Parent;
	UMaterialInterface* toSave;
	FString Path;
	FName InstanceName;

	//Functions:
	void SaveAsset();
	void CreateInstances();
};
