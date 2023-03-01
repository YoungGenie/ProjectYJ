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
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_bEnableUpdateRateOptimizations_MetaData[];
#endif
		static void NewProp_m_bEnableUpdateRateOptimizations_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_m_bEnableUpdateRateOptimizations;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_bInterpolateSkippedFrames_MetaData[];
#endif
		static void NewProp_m_bInterpolateSkippedFrames_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_m_bInterpolateSkippedFrames;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_m_SkippedFramesByLOD_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_SkippedFramesByLOD_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_m_SkippedFramesByLOD;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
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
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYJCharacter_Statics::NewProp_m_bEnableUpdateRateOptimizations_MetaData[] = {
		{ "Category", "URO" },
		{ "Comment", "// Animation URO ???? ????\n" },
		{ "ModuleRelativePath", "Character/YJCharacter.h" },
		{ "ToolTip", "Animation URO ???? ????" },
	};
#endif
	void Z_Construct_UClass_AYJCharacter_Statics::NewProp_m_bEnableUpdateRateOptimizations_SetBit(void* Obj)
	{
		((AYJCharacter*)Obj)->m_bEnableUpdateRateOptimizations = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AYJCharacter_Statics::NewProp_m_bEnableUpdateRateOptimizations = { "m_bEnableUpdateRateOptimizations", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AYJCharacter), &Z_Construct_UClass_AYJCharacter_Statics::NewProp_m_bEnableUpdateRateOptimizations_SetBit, METADATA_PARAMS(Z_Construct_UClass_AYJCharacter_Statics::NewProp_m_bEnableUpdateRateOptimizations_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AYJCharacter_Statics::NewProp_m_bEnableUpdateRateOptimizations_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYJCharacter_Statics::NewProp_m_bInterpolateSkippedFrames_MetaData[] = {
		{ "Category", "URO" },
		{ "Comment", "// ??\xc5\xb5?? ?????? ?????? ???? ????\n" },
		{ "ModuleRelativePath", "Character/YJCharacter.h" },
		{ "ToolTip", "??\xc5\xb5?? ?????? ?????? ???? ????" },
	};
#endif
	void Z_Construct_UClass_AYJCharacter_Statics::NewProp_m_bInterpolateSkippedFrames_SetBit(void* Obj)
	{
		((AYJCharacter*)Obj)->m_bInterpolateSkippedFrames = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AYJCharacter_Statics::NewProp_m_bInterpolateSkippedFrames = { "m_bInterpolateSkippedFrames", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AYJCharacter), &Z_Construct_UClass_AYJCharacter_Statics::NewProp_m_bInterpolateSkippedFrames_SetBit, METADATA_PARAMS(Z_Construct_UClass_AYJCharacter_Statics::NewProp_m_bInterpolateSkippedFrames_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AYJCharacter_Statics::NewProp_m_bInterpolateSkippedFrames_MetaData)) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AYJCharacter_Statics::NewProp_m_SkippedFramesByLOD_Inner = { "m_SkippedFramesByLOD", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYJCharacter_Statics::NewProp_m_SkippedFramesByLOD_MetaData[] = {
		{ "Category", "URO" },
		{ "Comment", "// LOD?? ???? ??\xc5\xb5?? ?????? ??\n" },
		{ "ModuleRelativePath", "Character/YJCharacter.h" },
		{ "ToolTip", "LOD?? ???? ??\xc5\xb5?? ?????? ??" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AYJCharacter_Statics::NewProp_m_SkippedFramesByLOD = { "m_SkippedFramesByLOD", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AYJCharacter, m_SkippedFramesByLOD), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AYJCharacter_Statics::NewProp_m_SkippedFramesByLOD_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AYJCharacter_Statics::NewProp_m_SkippedFramesByLOD_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AYJCharacter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYJCharacter_Statics::NewProp_m_bEnableUpdateRateOptimizations,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYJCharacter_Statics::NewProp_m_bInterpolateSkippedFrames,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYJCharacter_Statics::NewProp_m_SkippedFramesByLOD_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYJCharacter_Statics::NewProp_m_SkippedFramesByLOD,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AYJCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AYJCharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AYJCharacter_Statics::ClassParams = {
		&AYJCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AYJCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AYJCharacter_Statics::PropPointers),
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
	IMPLEMENT_CLASS(AYJCharacter, 3659521768);
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
