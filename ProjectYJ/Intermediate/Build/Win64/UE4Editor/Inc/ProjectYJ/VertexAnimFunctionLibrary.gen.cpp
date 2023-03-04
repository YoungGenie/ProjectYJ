// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectYJ/FunctionLibrary/VertexAnimFunctionLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVertexAnimFunctionLibrary() {}
// Cross Module References
	PROJECTYJ_API UClass* Z_Construct_UClass_UVertexAnimFunctionLibrary_NoRegister();
	PROJECTYJ_API UClass* Z_Construct_UClass_UVertexAnimFunctionLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_ProjectYJ();
	VERTEXANIMTOOLSET_API UClass* Z_Construct_UClass_UVertexAnimProfile_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMesh_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_UAnimationAsset_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UVertexAnimFunctionLibrary::execDoBake)
	{
		P_GET_OBJECT(UVertexAnimProfile,Z_Param_InVertexAnimProfile);
		P_GET_OBJECT(USkeletalMesh,Z_Param_InSkeletalMesh);
		P_GET_PROPERTY(FStrProperty,Z_Param_InResultPath);
		P_FINISH;
		P_NATIVE_BEGIN;
		UVertexAnimFunctionLibrary::DoBake(Z_Param_InVertexAnimProfile,Z_Param_InSkeletalMesh,Z_Param_InResultPath);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVertexAnimFunctionLibrary::execSetDataAtProfile)
	{
		P_GET_OBJECT(UVertexAnimProfile,Z_Param_InVertexAnimProfile);
		P_GET_OBJECT(UClass,Z_Param_InAnimationAsset);
		P_GET_PROPERTY(FIntProperty,Z_Param_InNumFrames);
		P_FINISH;
		P_NATIVE_BEGIN;
		UVertexAnimFunctionLibrary::SetDataAtProfile(Z_Param_InVertexAnimProfile,Z_Param_InAnimationAsset,Z_Param_InNumFrames);
		P_NATIVE_END;
	}
	void UVertexAnimFunctionLibrary::StaticRegisterNativesUVertexAnimFunctionLibrary()
	{
		UClass* Class = UVertexAnimFunctionLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "DoBake", &UVertexAnimFunctionLibrary::execDoBake },
			{ "SetDataAtProfile", &UVertexAnimFunctionLibrary::execSetDataAtProfile },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVertexAnimFunctionLibrary_DoBake_Statics
	{
		struct VertexAnimFunctionLibrary_eventDoBake_Parms
		{
			UVertexAnimProfile* InVertexAnimProfile;
			USkeletalMesh* InSkeletalMesh;
			FString InResultPath;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InVertexAnimProfile;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InSkeletalMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InResultPath_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_InResultPath;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVertexAnimFunctionLibrary_DoBake_Statics::NewProp_InVertexAnimProfile = { "InVertexAnimProfile", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(VertexAnimFunctionLibrary_eventDoBake_Parms, InVertexAnimProfile), Z_Construct_UClass_UVertexAnimProfile_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVertexAnimFunctionLibrary_DoBake_Statics::NewProp_InSkeletalMesh = { "InSkeletalMesh", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(VertexAnimFunctionLibrary_eventDoBake_Parms, InSkeletalMesh), Z_Construct_UClass_USkeletalMesh_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVertexAnimFunctionLibrary_DoBake_Statics::NewProp_InResultPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVertexAnimFunctionLibrary_DoBake_Statics::NewProp_InResultPath = { "InResultPath", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(VertexAnimFunctionLibrary_eventDoBake_Parms, InResultPath), METADATA_PARAMS(Z_Construct_UFunction_UVertexAnimFunctionLibrary_DoBake_Statics::NewProp_InResultPath_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UVertexAnimFunctionLibrary_DoBake_Statics::NewProp_InResultPath_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVertexAnimFunctionLibrary_DoBake_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVertexAnimFunctionLibrary_DoBake_Statics::NewProp_InVertexAnimProfile,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVertexAnimFunctionLibrary_DoBake_Statics::NewProp_InSkeletalMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVertexAnimFunctionLibrary_DoBake_Statics::NewProp_InResultPath,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVertexAnimFunctionLibrary_DoBake_Statics::Function_MetaDataParams[] = {
		{ "Category", "Vertex Animation Tool" },
		{ "ModuleRelativePath", "FunctionLibrary/VertexAnimFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVertexAnimFunctionLibrary_DoBake_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVertexAnimFunctionLibrary, nullptr, "DoBake", nullptr, nullptr, sizeof(VertexAnimFunctionLibrary_eventDoBake_Parms), Z_Construct_UFunction_UVertexAnimFunctionLibrary_DoBake_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVertexAnimFunctionLibrary_DoBake_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVertexAnimFunctionLibrary_DoBake_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UVertexAnimFunctionLibrary_DoBake_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVertexAnimFunctionLibrary_DoBake()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVertexAnimFunctionLibrary_DoBake_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVertexAnimFunctionLibrary_SetDataAtProfile_Statics
	{
		struct VertexAnimFunctionLibrary_eventSetDataAtProfile_Parms
		{
			UVertexAnimProfile* InVertexAnimProfile;
			TSubclassOf<UAnimationAsset>  InAnimationAsset;
			int32 InNumFrames;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InVertexAnimProfile;
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_InAnimationAsset;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_InNumFrames;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVertexAnimFunctionLibrary_SetDataAtProfile_Statics::NewProp_InVertexAnimProfile = { "InVertexAnimProfile", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(VertexAnimFunctionLibrary_eventSetDataAtProfile_Parms, InVertexAnimProfile), Z_Construct_UClass_UVertexAnimProfile_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UVertexAnimFunctionLibrary_SetDataAtProfile_Statics::NewProp_InAnimationAsset = { "InAnimationAsset", nullptr, (EPropertyFlags)0x0014000000000080, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(VertexAnimFunctionLibrary_eventSetDataAtProfile_Parms, InAnimationAsset), Z_Construct_UClass_UAnimationAsset_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UVertexAnimFunctionLibrary_SetDataAtProfile_Statics::NewProp_InNumFrames = { "InNumFrames", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(VertexAnimFunctionLibrary_eventSetDataAtProfile_Parms, InNumFrames), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVertexAnimFunctionLibrary_SetDataAtProfile_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVertexAnimFunctionLibrary_SetDataAtProfile_Statics::NewProp_InVertexAnimProfile,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVertexAnimFunctionLibrary_SetDataAtProfile_Statics::NewProp_InAnimationAsset,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVertexAnimFunctionLibrary_SetDataAtProfile_Statics::NewProp_InNumFrames,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVertexAnimFunctionLibrary_SetDataAtProfile_Statics::Function_MetaDataParams[] = {
		{ "Category", "Vertex Animation Tool" },
		{ "ModuleRelativePath", "FunctionLibrary/VertexAnimFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVertexAnimFunctionLibrary_SetDataAtProfile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVertexAnimFunctionLibrary, nullptr, "SetDataAtProfile", nullptr, nullptr, sizeof(VertexAnimFunctionLibrary_eventSetDataAtProfile_Parms), Z_Construct_UFunction_UVertexAnimFunctionLibrary_SetDataAtProfile_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVertexAnimFunctionLibrary_SetDataAtProfile_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVertexAnimFunctionLibrary_SetDataAtProfile_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UVertexAnimFunctionLibrary_SetDataAtProfile_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVertexAnimFunctionLibrary_SetDataAtProfile()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVertexAnimFunctionLibrary_SetDataAtProfile_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UVertexAnimFunctionLibrary_NoRegister()
	{
		return UVertexAnimFunctionLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UVertexAnimFunctionLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVertexAnimFunctionLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_ProjectYJ,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UVertexAnimFunctionLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVertexAnimFunctionLibrary_DoBake, "DoBake" }, // 3683604238
		{ &Z_Construct_UFunction_UVertexAnimFunctionLibrary_SetDataAtProfile, "SetDataAtProfile" }, // 1107211818
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVertexAnimFunctionLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "FunctionLibrary/VertexAnimFunctionLibrary.h" },
		{ "ModuleRelativePath", "FunctionLibrary/VertexAnimFunctionLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVertexAnimFunctionLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVertexAnimFunctionLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVertexAnimFunctionLibrary_Statics::ClassParams = {
		&UVertexAnimFunctionLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UVertexAnimFunctionLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UVertexAnimFunctionLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVertexAnimFunctionLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVertexAnimFunctionLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVertexAnimFunctionLibrary, 3357614312);
	template<> PROJECTYJ_API UClass* StaticClass<UVertexAnimFunctionLibrary>()
	{
		return UVertexAnimFunctionLibrary::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVertexAnimFunctionLibrary(Z_Construct_UClass_UVertexAnimFunctionLibrary, &UVertexAnimFunctionLibrary::StaticClass, TEXT("/Script/ProjectYJ"), TEXT("UVertexAnimFunctionLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVertexAnimFunctionLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
