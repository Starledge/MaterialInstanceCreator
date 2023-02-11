// Fill out your copyright notice in the Description page of Project Settings.


#include "BPL_MaterialEditor.h"
#include "FileHelpers.h"
#include "Materials/MaterialInstanceConstant.h"
#include "AssetToolsModule.h"
#include "Factories/MaterialInstanceConstantFactoryNew.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "UObject/Package.h"
#include "UObject/SavePackage.h"
#include "ContentBrowserModule.h"
#include "Misc/PackageName.h"
#include "MaterialEditingLibrary.h"

#if WITH_EDITOR
void UBPL_MaterialEditor::SaveInstance(UMaterialInstanceConstant* Instance)
{
	Instance->GetPackage()->MarkPackageDirty();
}


void UBPL_MaterialEditor::CreateInstancesConstant(UMaterialInterface* Parent,FString InstanceName,FString Path)
{
    FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
    FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));
    IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();
    FAssetToolsModule& AssetToolsModule = FModuleManager::Get().LoadModuleChecked<FAssetToolsModule>("AssetTools");
    UMaterialInstanceConstantFactoryNew* Factory = NewObject<UMaterialInstanceConstantFactoryNew>();
    if (Parent)
    {
        Factory->InitialParent = Parent;
        FString Name = InstanceName;
        UMaterialInstanceConstant* M_Instance = CastChecked<UMaterialInstanceConstant>(AssetToolsModule.Get().CreateAsset(Name, FPackageName::GetLongPackagePath(Path), UMaterialInstanceConstant::StaticClass(), Factory));
        AssetRegistry.AssetCreated(M_Instance);
    }
}
#endif
