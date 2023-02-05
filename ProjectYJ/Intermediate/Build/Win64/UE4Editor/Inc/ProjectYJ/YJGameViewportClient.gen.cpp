// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectYJ/Framework/Viewport/YJGameViewportClient.h"
#include "Engine/Classes/Engine/Engine.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeYJGameViewportClient() {}
// Cross Module References
	PROJECTYJ_API UClass* Z_Construct_UClass_UYJGameViewportClient_NoRegister();
	PROJECTYJ_API UClass* Z_Construct_UClass_UYJGameViewportClient();
	ENGINE_API UClass* Z_Construct_UClass_UGameViewportClient();
	UPackage* Z_Construct_UPackage__Script_ProjectYJ();
// End Cross Module References
	void UYJGameViewportClient::StaticRegisterNativesUYJGameViewportClient()
	{
	}
	UClass* Z_Construct_UClass_UYJGameViewportClient_NoRegister()
	{
		return UYJGameViewportClient::StaticClass();
	}
	struct Z_Construct_UClass_UYJGameViewportClient_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UYJGameViewportClient_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameViewportClient,
		(UObject* (*)())Z_Construct_UPackage__Script_ProjectYJ,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UYJGameViewportClient_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Framework/Viewport/YJGameViewportClient.h" },
		{ "ModuleRelativePath", "Framework/Viewport/YJGameViewportClient.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UYJGameViewportClient_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UYJGameViewportClient>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UYJGameViewportClient_Statics::ClassParams = {
		&UYJGameViewportClient::StaticClass,
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
		0x001000ACu,
		METADATA_PARAMS(Z_Construct_UClass_UYJGameViewportClient_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UYJGameViewportClient_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UYJGameViewportClient()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UYJGameViewportClient_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UYJGameViewportClient, 1397508912);
	template<> PROJECTYJ_API UClass* StaticClass<UYJGameViewportClient>()
	{
		return UYJGameViewportClient::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UYJGameViewportClient(Z_Construct_UClass_UYJGameViewportClient, &UYJGameViewportClient::StaticClass, TEXT("/Script/ProjectYJ"), TEXT("UYJGameViewportClient"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UYJGameViewportClient);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
