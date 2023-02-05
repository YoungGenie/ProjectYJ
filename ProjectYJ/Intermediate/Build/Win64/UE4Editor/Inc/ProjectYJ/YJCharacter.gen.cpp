// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectYJ/Character/YJCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeYJCharacter() {}
// Cross Module References
	PROJECTYJ_API UClass* Z_Construct_UClass_AYJCharacter_NoRegister();
	PROJECTYJ_API UClass* Z_Construct_UClass_AYJCharacter();
	PROJECTYJ_API UClass* Z_Construct_UClass_AProjectYJCharacter();
	UPackage* Z_Construct_UPackage__Script_ProjectYJ();
// End Cross Module References
	void AYJCharacter::StaticRegisterNativesAYJCharacter()
	{
	}
	UClass* Z_Construct_UClass_AYJCharacter_NoRegister()
	{
		return AYJCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AYJCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AYJCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AProjectYJCharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_ProjectYJ,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYJCharacter_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Character/YJCharacter.h" },
		{ "ModuleRelativePath", "Character/YJCharacter.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AYJCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AYJCharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AYJCharacter_Statics::ClassParams = {
		&AYJCharacter::StaticClass,
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
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AYJCharacter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AYJCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AYJCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AYJCharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AYJCharacter, 3595913411);
	template<> PROJECTYJ_API UClass* StaticClass<AYJCharacter>()
	{
		return AYJCharacter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AYJCharacter(Z_Construct_UClass_AYJCharacter, &AYJCharacter::StaticClass, TEXT("/Script/ProjectYJ"), TEXT("AYJCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AYJCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
