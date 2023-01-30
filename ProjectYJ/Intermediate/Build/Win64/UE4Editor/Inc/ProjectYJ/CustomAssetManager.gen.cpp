// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectYJ/System/AssetManager/CustomAssetManager.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCustomAssetManager() {}
// Cross Module References
	PROJECTYJ_API UEnum* Z_Construct_UEnum_ProjectYJ_EAsyncLoadLogType();
	UPackage* Z_Construct_UPackage__Script_ProjectYJ();
	PROJECTYJ_API UClass* Z_Construct_UClass_UCustomAssetManager_NoRegister();
	PROJECTYJ_API UClass* Z_Construct_UClass_UCustomAssetManager();
	ENGINE_API UClass* Z_Construct_UClass_UAssetManager();
// End Cross Module References
	static UEnum* EAsyncLoadLogType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_ProjectYJ_EAsyncLoadLogType, Z_Construct_UPackage__Script_ProjectYJ(), TEXT("EAsyncLoadLogType"));
		}
		return Singleton;
	}
	template<> PROJECTYJ_API UEnum* StaticEnum<EAsyncLoadLogType>()
	{
		return EAsyncLoadLogType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EAsyncLoadLogType(EAsyncLoadLogType_StaticEnum, TEXT("/Script/ProjectYJ"), TEXT("EAsyncLoadLogType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_ProjectYJ_EAsyncLoadLogType_Hash() { return 3941417604U; }
	UEnum* Z_Construct_UEnum_ProjectYJ_EAsyncLoadLogType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_ProjectYJ();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EAsyncLoadLogType"), 0, Get_Z_Construct_UEnum_ProjectYJ_EAsyncLoadLogType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EAsyncLoadLogType::Info", (int64)EAsyncLoadLogType::Info },
				{ "EAsyncLoadLogType::Complete", (int64)EAsyncLoadLogType::Complete },
				{ "EAsyncLoadLogType::Cancel", (int64)EAsyncLoadLogType::Cancel },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "Cancel.Name", "EAsyncLoadLogType::Cancel" },
				{ "Complete.Name", "EAsyncLoadLogType::Complete" },
				{ "Info.Name", "EAsyncLoadLogType::Info" },
				{ "ModuleRelativePath", "System/AssetManager/CustomAssetManager.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_ProjectYJ,
				nullptr,
				"EAsyncLoadLogType",
				"EAsyncLoadLogType",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	void UCustomAssetManager::StaticRegisterNativesUCustomAssetManager()
	{
	}
	UClass* Z_Construct_UClass_UCustomAssetManager_NoRegister()
	{
		return UCustomAssetManager::StaticClass();
	}
	struct Z_Construct_UClass_UCustomAssetManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCustomAssetManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAssetManager,
		(UObject* (*)())Z_Construct_UPackage__Script_ProjectYJ,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomAssetManager_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "System/AssetManager/CustomAssetManager.h" },
		{ "ModuleRelativePath", "System/AssetManager/CustomAssetManager.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCustomAssetManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCustomAssetManager>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCustomAssetManager_Statics::ClassParams = {
		&UCustomAssetManager::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UCustomAssetManager_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomAssetManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCustomAssetManager()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCustomAssetManager_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCustomAssetManager, 491678674);
	template<> PROJECTYJ_API UClass* StaticClass<UCustomAssetManager>()
	{
		return UCustomAssetManager::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCustomAssetManager(Z_Construct_UClass_UCustomAssetManager, &UCustomAssetManager::StaticClass, TEXT("/Script/ProjectYJ"), TEXT("UCustomAssetManager"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCustomAssetManager);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
