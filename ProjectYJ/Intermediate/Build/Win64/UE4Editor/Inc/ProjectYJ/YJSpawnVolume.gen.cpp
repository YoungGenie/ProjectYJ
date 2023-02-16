// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectYJ/YJSpawnVolume.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeYJSpawnVolume() {}
// Cross Module References
	PROJECTYJ_API UClass* Z_Construct_UClass_AYJSpawnVolume_NoRegister();
	PROJECTYJ_API UClass* Z_Construct_UClass_AYJSpawnVolume();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ProjectYJ();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	void AYJSpawnVolume::StaticRegisterNativesAYJSpawnVolume()
	{
	}
	UClass* Z_Construct_UClass_AYJSpawnVolume_NoRegister()
	{
		return AYJSpawnVolume::StaticClass();
	}
	struct Z_Construct_UClass_AYJSpawnVolume_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_m_SpawnClasses_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_SpawnClasses_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_m_SpawnClasses;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_SpawnInterval_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_m_SpawnInterval;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_SpawnRange_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_m_SpawnRange;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AYJSpawnVolume_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ProjectYJ,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYJSpawnVolume_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "YJSpawnVolume.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "YJSpawnVolume.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AYJSpawnVolume_Statics::NewProp_m_SpawnClasses_Inner = { "m_SpawnClasses", nullptr, (EPropertyFlags)0x0004000000000000, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYJSpawnVolume_Statics::NewProp_m_SpawnClasses_MetaData[] = {
		{ "Category", "YJSpawnVolume" },
		{ "Comment", "// ?????? ???\xcd\xb5??? ????\n" },
		{ "ModuleRelativePath", "YJSpawnVolume.h" },
		{ "ToolTip", "?????? ???\xcd\xb5??? ????" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AYJSpawnVolume_Statics::NewProp_m_SpawnClasses = { "m_SpawnClasses", nullptr, (EPropertyFlags)0x0044000000000001, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AYJSpawnVolume, m_SpawnClasses), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AYJSpawnVolume_Statics::NewProp_m_SpawnClasses_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AYJSpawnVolume_Statics::NewProp_m_SpawnClasses_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYJSpawnVolume_Statics::NewProp_m_SpawnInterval_MetaData[] = {
		{ "Category", "YJSpawnVolume" },
		{ "Comment", "// ???? ???? (???? : ??(s))\n" },
		{ "ModuleRelativePath", "YJSpawnVolume.h" },
		{ "ToolTip", "???? ???? (???? : ??(s))" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AYJSpawnVolume_Statics::NewProp_m_SpawnInterval = { "m_SpawnInterval", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AYJSpawnVolume, m_SpawnInterval), METADATA_PARAMS(Z_Construct_UClass_AYJSpawnVolume_Statics::NewProp_m_SpawnInterval_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AYJSpawnVolume_Statics::NewProp_m_SpawnInterval_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYJSpawnVolume_Statics::NewProp_m_SpawnRange_MetaData[] = {
		{ "Category", "YJSpawnVolume" },
		{ "Comment", "// ???? ????\n" },
		{ "ModuleRelativePath", "YJSpawnVolume.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AYJSpawnVolume_Statics::NewProp_m_SpawnRange = { "m_SpawnRange", nullptr, (EPropertyFlags)0x0040000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AYJSpawnVolume, m_SpawnRange), METADATA_PARAMS(Z_Construct_UClass_AYJSpawnVolume_Statics::NewProp_m_SpawnRange_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AYJSpawnVolume_Statics::NewProp_m_SpawnRange_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AYJSpawnVolume_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYJSpawnVolume_Statics::NewProp_m_SpawnClasses_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYJSpawnVolume_Statics::NewProp_m_SpawnClasses,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYJSpawnVolume_Statics::NewProp_m_SpawnInterval,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYJSpawnVolume_Statics::NewProp_m_SpawnRange,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AYJSpawnVolume_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AYJSpawnVolume>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AYJSpawnVolume_Statics::ClassParams = {
		&AYJSpawnVolume::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AYJSpawnVolume_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AYJSpawnVolume_Statics::PropPointers),
		0,
		0x008000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AYJSpawnVolume_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AYJSpawnVolume_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AYJSpawnVolume()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AYJSpawnVolume_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AYJSpawnVolume, 2458139673);
	template<> PROJECTYJ_API UClass* StaticClass<AYJSpawnVolume>()
	{
		return AYJSpawnVolume::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AYJSpawnVolume(Z_Construct_UClass_AYJSpawnVolume, &AYJSpawnVolume::StaticClass, TEXT("/Script/ProjectYJ"), TEXT("AYJSpawnVolume"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AYJSpawnVolume);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
