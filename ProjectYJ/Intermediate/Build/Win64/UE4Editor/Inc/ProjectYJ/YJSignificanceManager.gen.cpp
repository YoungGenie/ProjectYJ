// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectYJ/System/SignificanceManager/YJSignificanceManager.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeYJSignificanceManager() {}
// Cross Module References
	PROJECTYJ_API UClass* Z_Construct_UClass_UYJSignificanceManager_NoRegister();
	PROJECTYJ_API UClass* Z_Construct_UClass_UYJSignificanceManager();
	SIGNIFICANCEMANAGER_API UClass* Z_Construct_UClass_USignificanceManager();
	UPackage* Z_Construct_UPackage__Script_ProjectYJ();
// End Cross Module References
	void UYJSignificanceManager::StaticRegisterNativesUYJSignificanceManager()
	{
	}
	UClass* Z_Construct_UClass_UYJSignificanceManager_NoRegister()
	{
		return UYJSignificanceManager::StaticClass();
	}
	struct Z_Construct_UClass_UYJSignificanceManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UYJSignificanceManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USignificanceManager,
		(UObject* (*)())Z_Construct_UPackage__Script_ProjectYJ,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYJSignificanceManager_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "System/SignificanceManager/YJSignificanceManager.h" },
		{ "ModuleRelativePath", "System/SignificanceManager/YJSignificanceManager.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UYJSignificanceManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UYJSignificanceManager>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UYJSignificanceManager_Statics::ClassParams = {
		&UYJSignificanceManager::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A6u,
		METADATA_PARAMS(Z_Construct_UClass_UYJSignificanceManager_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UYJSignificanceManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UYJSignificanceManager()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UYJSignificanceManager_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UYJSignificanceManager, 1630945738);
	template<> PROJECTYJ_API UClass* StaticClass<UYJSignificanceManager>()
	{
		return UYJSignificanceManager::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UYJSignificanceManager(Z_Construct_UClass_UYJSignificanceManager, &UYJSignificanceManager::StaticClass, TEXT("/Script/ProjectYJ"), TEXT("UYJSignificanceManager"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UYJSignificanceManager);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
