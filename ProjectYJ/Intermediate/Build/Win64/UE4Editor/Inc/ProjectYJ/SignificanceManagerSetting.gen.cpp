// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectYJ/System/SignificanceManager/SignificanceManagerSetting.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSignificanceManagerSetting() {}
// Cross Module References
	PROJECTYJ_API UClass* Z_Construct_UClass_USignificanceManagerSetting_NoRegister();
	PROJECTYJ_API UClass* Z_Construct_UClass_USignificanceManagerSetting();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_ProjectYJ();
// End Cross Module References
	void USignificanceManagerSetting::StaticRegisterNativesUSignificanceManagerSetting()
	{
	}
	UClass* Z_Construct_UClass_USignificanceManagerSetting_NoRegister()
	{
		return USignificanceManagerSetting::StaticClass();
	}
	struct Z_Construct_UClass_USignificanceManagerSetting_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bUseSignificanceManager_MetaData[];
#endif
		static void NewProp_bUseSignificanceManager_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bUseSignificanceManager;
		static const UE4CodeGen_Private::FUInt32PropertyParams NewProp_m_ActiveCountMap_ValueProp;
		static const UE4CodeGen_Private::FUInt32PropertyParams NewProp_m_ActiveCountMap_Key_KeyProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_ActiveCountMap_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_m_ActiveCountMap;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_MaxDistance_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_m_MaxDistance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_DistanceSection_MetaData[];
#endif
		static const UE4CodeGen_Private::FUInt32PropertyParams NewProp_m_DistanceSection;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_MaxTickInterval_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_m_MaxTickInterval;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USignificanceManagerSetting_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_ProjectYJ,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USignificanceManagerSetting_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "System/SignificanceManager/SignificanceManagerSetting.h" },
		{ "ModuleRelativePath", "System/SignificanceManager/SignificanceManagerSetting.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USignificanceManagerSetting_Statics::NewProp_bUseSignificanceManager_MetaData[] = {
		{ "Category", "Default" },
		{ "DisplayName", "Use SignificanceManager" },
		{ "ModuleRelativePath", "System/SignificanceManager/SignificanceManagerSetting.h" },
	};
#endif
	void Z_Construct_UClass_USignificanceManagerSetting_Statics::NewProp_bUseSignificanceManager_SetBit(void* Obj)
	{
		((USignificanceManagerSetting*)Obj)->bUseSignificanceManager = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USignificanceManagerSetting_Statics::NewProp_bUseSignificanceManager = { "bUseSignificanceManager", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(USignificanceManagerSetting), &Z_Construct_UClass_USignificanceManagerSetting_Statics::NewProp_bUseSignificanceManager_SetBit, METADATA_PARAMS(Z_Construct_UClass_USignificanceManagerSetting_Statics::NewProp_bUseSignificanceManager_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USignificanceManagerSetting_Statics::NewProp_bUseSignificanceManager_MetaData)) };
	const UE4CodeGen_Private::FUInt32PropertyParams Z_Construct_UClass_USignificanceManagerSetting_Statics::NewProp_m_ActiveCountMap_ValueProp = { "m_ActiveCountMap", nullptr, (EPropertyFlags)0x0000000000004001, UE4CodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUInt32PropertyParams Z_Construct_UClass_USignificanceManagerSetting_Statics::NewProp_m_ActiveCountMap_Key_KeyProp = { "m_ActiveCountMap_Key", nullptr, (EPropertyFlags)0x0000000000004001, UE4CodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USignificanceManagerSetting_Statics::NewProp_m_ActiveCountMap_MetaData[] = {
		{ "Category", "Default" },
		{ "DisplayName", "Active Count By Priority" },
		{ "ModuleRelativePath", "System/SignificanceManager/SignificanceManagerSetting.h" },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UClass_USignificanceManagerSetting_Statics::NewProp_m_ActiveCountMap = { "m_ActiveCountMap", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USignificanceManagerSetting, m_ActiveCountMap), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_USignificanceManagerSetting_Statics::NewProp_m_ActiveCountMap_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USignificanceManagerSetting_Statics::NewProp_m_ActiveCountMap_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USignificanceManagerSetting_Statics::NewProp_m_MaxDistance_MetaData[] = {
		{ "Category", "Default" },
		{ "DisplayName", "Max Distance" },
		{ "ModuleRelativePath", "System/SignificanceManager/SignificanceManagerSetting.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USignificanceManagerSetting_Statics::NewProp_m_MaxDistance = { "m_MaxDistance", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USignificanceManagerSetting, m_MaxDistance), METADATA_PARAMS(Z_Construct_UClass_USignificanceManagerSetting_Statics::NewProp_m_MaxDistance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USignificanceManagerSetting_Statics::NewProp_m_MaxDistance_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USignificanceManagerSetting_Statics::NewProp_m_DistanceSection_MetaData[] = {
		{ "Category", "Default" },
		{ "DisplayName", "Distance Section" },
		{ "ModuleRelativePath", "System/SignificanceManager/SignificanceManagerSetting.h" },
	};
#endif
	const UE4CodeGen_Private::FUInt32PropertyParams Z_Construct_UClass_USignificanceManagerSetting_Statics::NewProp_m_DistanceSection = { "m_DistanceSection", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USignificanceManagerSetting, m_DistanceSection), METADATA_PARAMS(Z_Construct_UClass_USignificanceManagerSetting_Statics::NewProp_m_DistanceSection_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USignificanceManagerSetting_Statics::NewProp_m_DistanceSection_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USignificanceManagerSetting_Statics::NewProp_m_MaxTickInterval_MetaData[] = {
		{ "Category", "Default" },
		{ "DisplayName", "Max Tick Interval" },
		{ "ModuleRelativePath", "System/SignificanceManager/SignificanceManagerSetting.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USignificanceManagerSetting_Statics::NewProp_m_MaxTickInterval = { "m_MaxTickInterval", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USignificanceManagerSetting, m_MaxTickInterval), METADATA_PARAMS(Z_Construct_UClass_USignificanceManagerSetting_Statics::NewProp_m_MaxTickInterval_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USignificanceManagerSetting_Statics::NewProp_m_MaxTickInterval_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USignificanceManagerSetting_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USignificanceManagerSetting_Statics::NewProp_bUseSignificanceManager,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USignificanceManagerSetting_Statics::NewProp_m_ActiveCountMap_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USignificanceManagerSetting_Statics::NewProp_m_ActiveCountMap_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USignificanceManagerSetting_Statics::NewProp_m_ActiveCountMap,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USignificanceManagerSetting_Statics::NewProp_m_MaxDistance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USignificanceManagerSetting_Statics::NewProp_m_DistanceSection,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USignificanceManagerSetting_Statics::NewProp_m_MaxTickInterval,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USignificanceManagerSetting_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USignificanceManagerSetting>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USignificanceManagerSetting_Statics::ClassParams = {
		&USignificanceManagerSetting::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_USignificanceManagerSetting_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_USignificanceManagerSetting_Statics::PropPointers),
		0,
		0x001000A6u,
		METADATA_PARAMS(Z_Construct_UClass_USignificanceManagerSetting_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USignificanceManagerSetting_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USignificanceManagerSetting()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USignificanceManagerSetting_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USignificanceManagerSetting, 1312766929);
	template<> PROJECTYJ_API UClass* StaticClass<USignificanceManagerSetting>()
	{
		return USignificanceManagerSetting::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USignificanceManagerSetting(Z_Construct_UClass_USignificanceManagerSetting, &USignificanceManagerSetting::StaticClass, TEXT("/Script/ProjectYJ"), TEXT("USignificanceManagerSetting"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USignificanceManagerSetting);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
