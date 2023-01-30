// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectYJ/System/SignificanceManager/CustomSignificanceManager.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCustomSignificanceManager() {}
// Cross Module References
	PROJECTYJ_API UClass* Z_Construct_UClass_UCustomSignificanceManager_NoRegister();
	PROJECTYJ_API UClass* Z_Construct_UClass_UCustomSignificanceManager();
	SIGNIFICANCEMANAGER_API UClass* Z_Construct_UClass_USignificanceManager();
	UPackage* Z_Construct_UPackage__Script_ProjectYJ();
	PROJECTYJ_API UClass* Z_Construct_UClass_USignificanceManagerSetting_NoRegister();
// End Cross Module References
	void UCustomSignificanceManager::StaticRegisterNativesUCustomSignificanceManager()
	{
	}
	UClass* Z_Construct_UClass_UCustomSignificanceManager_NoRegister()
	{
		return UCustomSignificanceManager::StaticClass();
	}
	struct Z_Construct_UClass_UCustomSignificanceManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_SignificanceManagerSetting_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_m_SignificanceManagerSetting;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCustomSignificanceManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USignificanceManager,
		(UObject* (*)())Z_Construct_UPackage__Script_ProjectYJ,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomSignificanceManager_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "System/SignificanceManager/CustomSignificanceManager.h" },
		{ "ModuleRelativePath", "System/SignificanceManager/CustomSignificanceManager.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomSignificanceManager_Statics::NewProp_m_SignificanceManagerSetting_MetaData[] = {
		{ "ModuleRelativePath", "System/SignificanceManager/CustomSignificanceManager.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCustomSignificanceManager_Statics::NewProp_m_SignificanceManagerSetting = { "m_SignificanceManagerSetting", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCustomSignificanceManager, m_SignificanceManagerSetting), Z_Construct_UClass_USignificanceManagerSetting_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCustomSignificanceManager_Statics::NewProp_m_SignificanceManagerSetting_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomSignificanceManager_Statics::NewProp_m_SignificanceManagerSetting_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCustomSignificanceManager_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCustomSignificanceManager_Statics::NewProp_m_SignificanceManagerSetting,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCustomSignificanceManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCustomSignificanceManager>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCustomSignificanceManager_Statics::ClassParams = {
		&UCustomSignificanceManager::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UCustomSignificanceManager_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UCustomSignificanceManager_Statics::PropPointers),
		0,
		0x001000A6u,
		METADATA_PARAMS(Z_Construct_UClass_UCustomSignificanceManager_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomSignificanceManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCustomSignificanceManager()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCustomSignificanceManager_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCustomSignificanceManager, 1200725408);
	template<> PROJECTYJ_API UClass* StaticClass<UCustomSignificanceManager>()
	{
		return UCustomSignificanceManager::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCustomSignificanceManager(Z_Construct_UClass_UCustomSignificanceManager, &UCustomSignificanceManager::StaticClass, TEXT("/Script/ProjectYJ"), TEXT("UCustomSignificanceManager"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCustomSignificanceManager);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
