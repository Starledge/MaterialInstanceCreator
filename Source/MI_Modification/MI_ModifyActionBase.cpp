// Fill out your copyright notice in the Description page of Project Settings.


#include "MI_ModifyActionBase.h"
#include "MaterialEditingLibrary.h"
#include "FileHelpers.h"
#include "Materials/MaterialInstanceConstant.h"
#include "AssetToolsModule.h"
#include "Factories/MaterialInstanceConstantFactoryNew.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "UObject/Package.h"
#include "UObject/SavePackage.h"
#include "ContentBrowserModule.h"
//#include "PackageHelperFunctions.h"


UMI_ModifyActionBase* UMI_ModifyActionBase::MarkPackageToSave(UMaterialInstanceConstant* _Child)
{
    UMI_ModifyActionBase* Current = NewObject<UMI_ModifyActionBase>();
    Current->Child = _Child;
    Current->toSave = _Child;
    return Current;
}

UMI_ModifyActionBase* UMI_ModifyActionBase::CreateMaterialInstances(UMaterial* _Parent, FString _Path, FName _InstanceName)
{
    UMI_ModifyActionBase* Current = NewObject<UMI_ModifyActionBase>();
    Current->Parent = _Parent;
    Current->toSave = _Parent;
    Current->Path = _Path;
    Current->InstanceName = _InstanceName;
    return Current;
}

void UMI_ModifyActionBase::Activate() 
{
    CreateInstances();
    SaveAsset();
}

void UMI_ModifyActionBase::SaveAsset()
{
    toSave->MarkPackageDirty();
}

void UMI_ModifyActionBase::CreateInstances()
{
    if (Parent)
    {
        FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
        FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));
        IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();
        FAssetToolsModule& AssetToolsModule = FModuleManager::Get().LoadModuleChecked<FAssetToolsModule>("AssetTools");

        UMaterialInstanceConstantFactoryNew* Factory = NewObject<UMaterialInstanceConstantFactoryNew>();
        Factory->InitialParent = Parent;
        FString Name = InstanceName.ToString();

        UMaterialInstanceConstant* M_Instance = CastChecked<UMaterialInstanceConstant>(AssetToolsModule.Get().CreateAsset(Name, FPackageName::GetLongPackagePath(Path), UMaterialInstanceConstant::StaticClass(), Factory));
        AssetRegistry.AssetCreated(M_Instance);
        toSave = M_Instance;
    }
}