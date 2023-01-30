// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectYJ/Framework/Viewport/CustomGameViewportClient.h"
#include "Engine/Classes/Engine/Engine.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCustomGameViewportClient() {}
// Cross Module References
	PROJECTYJ_API UClass* Z_Construct_UClass_UCustomGameViewportClient_NoRegister();
	PROJECTYJ_API UClass* Z_Construct_UClass_UCustomGameViewportClient();
	ENGINE_API UClass* Z_Construct_UClass_UGameViewportClient();
	UPackage* Z_Construct_UPackage__Script_ProjectYJ();
// End Cross Module References
	void UCustomGameViewportClient::StaticRegisterNativesUCustomGameViewportClient()
	{
	}
	UClass* Z_Construct_UClass_UCustomGameViewportClient_NoRegister()
	{
		return UCustomGameViewportClient::StaticClass();
	}
	struct Z_Construct_UClass_UCustomGameViewportClient_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCustomGameViewportClient_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameViewportClient,
		(UObject* (*)())Z_Construct_UPackage__Script_ProjectYJ,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomGameViewportClient_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Framework/Viewport/CustomGameViewportClient.h" },
		{ "ModuleRelativePath", "Framework/Viewport/CustomGameViewportClient.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCustomGameViewportClient_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCustomGameViewportClient>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCustomGameViewportClient_Statics::ClassParams = {
		&UCustomGameViewportClient::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UCustomGameViewportClient_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomGameViewportClient_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCustomGameViewportClient()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCustomGameViewportClient_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCustomGameViewportClient, 593658782);
	template<> PROJECTYJ_API UClass* StaticClass<UCustomGameViewportClient>()
	{
		return UCustomGameViewportClient::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCustomGameViewportClient(Z_Construct_UClass_UCustomGameViewportClient, &UCustomGameViewportClient::StaticClass, TEXT("/Script/ProjectYJ"), TEXT("UCustomGameViewportClient"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCustomGameViewportClient);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
