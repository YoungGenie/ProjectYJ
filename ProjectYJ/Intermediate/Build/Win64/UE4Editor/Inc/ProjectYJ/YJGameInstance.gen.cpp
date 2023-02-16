// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectYJ/YJGameInstance.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeYJGameInstance() {}
// Cross Module References
	PROJECTYJ_API UClass* Z_Construct_UClass_UYJGameInstance_NoRegister();
	PROJECTYJ_API UClass* Z_Construct_UClass_UYJGameInstance();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
	UPackage* Z_Construct_UPackage__Script_ProjectYJ();
// End Cross Module References
	void UYJGameInstance::StaticRegisterNativesUYJGameInstance()
	{
	}
	UClass* Z_Construct_UClass_UYJGameInstance_NoRegister()
	{
		return UYJGameInstance::StaticClass();
	}
	struct Z_Construct_UClass_UYJGameInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UYJGameInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_ProjectYJ,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYJGameInstance_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "YJGameInstance.h" },
		{ "ModuleRelativePath", "YJGameInstance.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UYJGameInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UYJGameInstance>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UYJGameInstance_Statics::ClassParams = {
		&UYJGameInstance::StaticClass,
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
		0x009000A8u,
		METADATA_PARAMS(Z_Construct_UClass_UYJGameInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UYJGameInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UYJGameInstance()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UYJGameInstance_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UYJGameInstance, 237150180);
	template<> PROJECTYJ_API UClass* StaticClass<UYJGameInstance>()
	{
		return UYJGameInstance::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UYJGameInstance(Z_Construct_UClass_UYJGameInstance, &UYJGameInstance::StaticClass, TEXT("/Script/ProjectYJ"), TEXT("UYJGameInstance"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UYJGameInstance);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
