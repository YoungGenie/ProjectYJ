// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectYJ/Framework/GameMode/ProjectYJGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProjectYJGameMode() {}
// Cross Module References
	PROJECTYJ_API UClass* Z_Construct_UClass_AProjectYJGameMode_NoRegister();
	PROJECTYJ_API UClass* Z_Construct_UClass_AProjectYJGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_ProjectYJ();
// End Cross Module References
	void AProjectYJGameMode::StaticRegisterNativesAProjectYJGameMode()
	{
	}
	UClass* Z_Construct_UClass_AProjectYJGameMode_NoRegister()
	{
		return AProjectYJGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AProjectYJGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AProjectYJGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_ProjectYJ,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProjectYJGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Framework/GameMode/ProjectYJGameMode.h" },
		{ "ModuleRelativePath", "Framework/GameMode/ProjectYJGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AProjectYJGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AProjectYJGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AProjectYJGameMode_Statics::ClassParams = {
		&AProjectYJGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AProjectYJGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AProjectYJGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AProjectYJGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AProjectYJGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AProjectYJGameMode, 2681851402);
	template<> PROJECTYJ_API UClass* StaticClass<AProjectYJGameMode>()
	{
		return AProjectYJGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AProjectYJGameMode(Z_Construct_UClass_AProjectYJGameMode, &AProjectYJGameMode::StaticClass, TEXT("/Script/ProjectYJ"), TEXT("AProjectYJGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AProjectYJGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
