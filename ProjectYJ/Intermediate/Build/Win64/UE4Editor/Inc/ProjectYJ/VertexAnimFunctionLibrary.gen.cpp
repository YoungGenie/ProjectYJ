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
	PROJECTYJ_API UScriptStruct* Z_Construct_UScriptStruct_FVertexAnimProfileData();
	UPackage* Z_Construct_UPackage__Script_ProjectYJ();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	PROJECTYJ_API UClass* Z_Construct_UClass_UVertexAnimFunctionLibrary_NoRegister();
	PROJECTYJ_API UClass* Z_Construct_UClass_UVertexAnimFunctionLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	VERTEXANIMTOOLSET_API UClass* Z_Construct_UClass_UVertexAnimProfile_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
// End Cross Module References
class UScriptStruct* FVertexAnimProfileData::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern PROJECTYJ_API uint32 Get_Z_Construct_UScriptStruct_FVertexAnimProfileData_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FVertexAnimProfileData, Z_Construct_UPackage__Script_ProjectYJ(), TEXT("VertexAnimProfileData"), sizeof(FVertexAnimProfileData), Get_Z_Construct_UScriptStruct_FVertexAnimProfileData_Hash());
	}
	return Singleton;
}
template<> PROJECTYJ_API UScriptStruct* StaticStruct<FVertexAnimProfileData>()
{
	return FVertexAnimProfileData::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FVertexAnimProfileData(FVertexAnimProfileData::StaticStruct, TEXT("/Script/ProjectYJ"), TEXT("VertexAnimProfileData"), false, nullptr, nullptr);
static struct FScriptStruct_ProjectYJ_StaticRegisterNativesFVertexAnimProfileData
{
	FScriptStruct_ProjectYJ_StaticRegisterNativesFVertexAnimProfileData()
	{
		UScriptStruct::DeferCppStructOps<FVertexAnimProfileData>(FName(TEXT("VertexAnimProfileData")));
	}
} ScriptStruct_ProjectYJ_StaticRegisterNativesFVertexAnimProfileData;
	struct Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NumFrames_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_NumFrames;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AnimStart_Generated_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_AnimStart_Generated;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Speed_Generated_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Speed_Generated;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RowsPerFrame_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_RowsPerFrame;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxValueOffset_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MaxValueOffset;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OffsetsTexture_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OffsetsTexture;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NormalsTexture_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_NormalsTexture;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "FunctionLibrary/VertexAnimFunctionLibrary.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVertexAnimProfileData>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_NumFrames_MetaData[] = {
		{ "Category", "VertexAnimProfileData" },
		{ "ModuleRelativePath", "FunctionLibrary/VertexAnimFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_NumFrames = { "NumFrames", nullptr, (EPropertyFlags)0x0010000000000004, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FVertexAnimProfileData, NumFrames), METADATA_PARAMS(Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_NumFrames_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_NumFrames_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_AnimStart_Generated_MetaData[] = {
		{ "Category", "VertexAnimProfileData" },
		{ "ModuleRelativePath", "FunctionLibrary/VertexAnimFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_AnimStart_Generated = { "AnimStart_Generated", nullptr, (EPropertyFlags)0x0010000000000004, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FVertexAnimProfileData, AnimStart_Generated), METADATA_PARAMS(Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_AnimStart_Generated_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_AnimStart_Generated_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_Speed_Generated_MetaData[] = {
		{ "Category", "VertexAnimProfileData" },
		{ "ModuleRelativePath", "FunctionLibrary/VertexAnimFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_Speed_Generated = { "Speed_Generated", nullptr, (EPropertyFlags)0x0010000000000004, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FVertexAnimProfileData, Speed_Generated), METADATA_PARAMS(Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_Speed_Generated_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_Speed_Generated_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_RowsPerFrame_MetaData[] = {
		{ "Category", "VertexAnimProfileData" },
		{ "ModuleRelativePath", "FunctionLibrary/VertexAnimFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_RowsPerFrame = { "RowsPerFrame", nullptr, (EPropertyFlags)0x0010000000000004, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FVertexAnimProfileData, RowsPerFrame), METADATA_PARAMS(Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_RowsPerFrame_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_RowsPerFrame_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_MaxValueOffset_MetaData[] = {
		{ "Category", "VertexAnimProfileData" },
		{ "ModuleRelativePath", "FunctionLibrary/VertexAnimFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_MaxValueOffset = { "MaxValueOffset", nullptr, (EPropertyFlags)0x0010000000000004, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FVertexAnimProfileData, MaxValueOffset), METADATA_PARAMS(Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_MaxValueOffset_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_MaxValueOffset_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_OffsetsTexture_MetaData[] = {
		{ "Category", "VertexAnimProfileData" },
		{ "ModuleRelativePath", "FunctionLibrary/VertexAnimFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_OffsetsTexture = { "OffsetsTexture", nullptr, (EPropertyFlags)0x0010000000000004, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FVertexAnimProfileData, OffsetsTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_OffsetsTexture_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_OffsetsTexture_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_NormalsTexture_MetaData[] = {
		{ "Category", "VertexAnimProfileData" },
		{ "ModuleRelativePath", "FunctionLibrary/VertexAnimFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_NormalsTexture = { "NormalsTexture", nullptr, (EPropertyFlags)0x0010000000000004, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FVertexAnimProfileData, NormalsTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_NormalsTexture_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_NormalsTexture_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_NumFrames,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_AnimStart_Generated,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_Speed_Generated,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_RowsPerFrame,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_MaxValueOffset,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_OffsetsTexture,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::NewProp_NormalsTexture,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_ProjectYJ,
		nullptr,
		&NewStructOps,
		"VertexAnimProfileData",
		sizeof(FVertexAnimProfileData),
		alignof(FVertexAnimProfileData),
		Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVertexAnimProfileData()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FVertexAnimProfileData_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_ProjectYJ();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("VertexAnimProfileData"), sizeof(FVertexAnimProfileData), Get_Z_Construct_UScriptStruct_FVertexAnimProfileData_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FVertexAnimProfileData_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FVertexAnimProfileData_Hash() { return 3269657121U; }
	DEFINE_FUNCTION(UVertexAnimFunctionLibrary::execGetVertexAnimProfileData)
	{
		P_GET_OBJECT(UVertexAnimProfile,Z_Param_InVertexAnimProfile);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVertexAnimProfileData*)Z_Param__Result=UVertexAnimFunctionLibrary::GetVertexAnimProfileData(Z_Param_InVertexAnimProfile);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVertexAnimFunctionLibrary::execDoBake)
	{
		P_GET_OBJECT(UVertexAnimProfile,Z_Param_InVertexAnimProfile);
		P_GET_OBJECT(UObject,Z_Param_InSkeletalMeshComponent);
		P_GET_PROPERTY(FStrProperty,Z_Param_InAssetSavePath);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UStaticMesh**)Z_Param__Result=UVertexAnimFunctionLibrary::DoBake(Z_Param_InVertexAnimProfile,Z_Param_InSkeletalMeshComponent,Z_Param_InAssetSavePath);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVertexAnimFunctionLibrary::execSetDataAtProfile)
	{
		P_GET_OBJECT(UVertexAnimProfile,Z_Param_InVertexAnimProfile);
		P_GET_OBJECT(UObject,Z_Param_InAnimationAsset);
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
			{ "GetVertexAnimProfileData", &UVertexAnimFunctionLibrary::execGetVertexAnimProfileData },
			{ "SetDataAtProfile", &UVertexAnimFunctionLibrary::execSetDataAtProfile },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVertexAnimFunctionLibrary_DoBake_Statics
	{
		struct VertexAnimFunctionLibrary_eventDoBake_Parms
		{
			UVertexAnimProfile* InVertexAnimProfile;
			UObject* InSkeletalMeshComponent;
			FString InAssetSavePath;
			UStaticMesh* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InVertexAnimProfile;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InSkeletalMeshComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InAssetSavePath_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_InAssetSavePath;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVertexAnimFunctionLibrary_DoBake_Statics::NewProp_InVertexAnimProfile = { "InVertexAnimProfile", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(VertexAnimFunctionLibrary_eventDoBake_Parms, InVertexAnimProfile), Z_Construct_UClass_UVertexAnimProfile_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVertexAnimFunctionLibrary_DoBake_Statics::NewProp_InSkeletalMeshComponent = { "InSkeletalMeshComponent", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(VertexAnimFunctionLibrary_eventDoBake_Parms, InSkeletalMeshComponent), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVertexAnimFunctionLibrary_DoBake_Statics::NewProp_InAssetSavePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVertexAnimFunctionLibrary_DoBake_Statics::NewProp_InAssetSavePath = { "InAssetSavePath", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(VertexAnimFunctionLibrary_eventDoBake_Parms, InAssetSavePath), METADATA_PARAMS(Z_Construct_UFunction_UVertexAnimFunctionLibrary_DoBake_Statics::NewProp_InAssetSavePath_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UVertexAnimFunctionLibrary_DoBake_Statics::NewProp_InAssetSavePath_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVertexAnimFunctionLibrary_DoBake_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(VertexAnimFunctionLibrary_eventDoBake_Parms, ReturnValue), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVertexAnimFunctionLibrary_DoBake_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVertexAnimFunctionLibrary_DoBake_Statics::NewProp_InVertexAnimProfile,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVertexAnimFunctionLibrary_DoBake_Statics::NewProp_InSkeletalMeshComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVertexAnimFunctionLibrary_DoBake_Statics::NewProp_InAssetSavePath,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVertexAnimFunctionLibrary_DoBake_Statics::NewProp_ReturnValue,
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
	struct Z_Construct_UFunction_UVertexAnimFunctionLibrary_GetVertexAnimProfileData_Statics
	{
		struct VertexAnimFunctionLibrary_eventGetVertexAnimProfileData_Parms
		{
			UVertexAnimProfile* InVertexAnimProfile;
			FVertexAnimProfileData ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InVertexAnimProfile;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVertexAnimFunctionLibrary_GetVertexAnimProfileData_Statics::NewProp_InVertexAnimProfile = { "InVertexAnimProfile", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(VertexAnimFunctionLibrary_eventGetVertexAnimProfileData_Parms, InVertexAnimProfile), Z_Construct_UClass_UVertexAnimProfile_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVertexAnimFunctionLibrary_GetVertexAnimProfileData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(VertexAnimFunctionLibrary_eventGetVertexAnimProfileData_Parms, ReturnValue), Z_Construct_UScriptStruct_FVertexAnimProfileData, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVertexAnimFunctionLibrary_GetVertexAnimProfileData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVertexAnimFunctionLibrary_GetVertexAnimProfileData_Statics::NewProp_InVertexAnimProfile,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVertexAnimFunctionLibrary_GetVertexAnimProfileData_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVertexAnimFunctionLibrary_GetVertexAnimProfileData_Statics::Function_MetaDataParams[] = {
		{ "Category", "Vertex Animation Tool" },
		{ "ModuleRelativePath", "FunctionLibrary/VertexAnimFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVertexAnimFunctionLibrary_GetVertexAnimProfileData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVertexAnimFunctionLibrary, nullptr, "GetVertexAnimProfileData", nullptr, nullptr, sizeof(VertexAnimFunctionLibrary_eventGetVertexAnimProfileData_Parms), Z_Construct_UFunction_UVertexAnimFunctionLibrary_GetVertexAnimProfileData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVertexAnimFunctionLibrary_GetVertexAnimProfileData_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVertexAnimFunctionLibrary_GetVertexAnimProfileData_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UVertexAnimFunctionLibrary_GetVertexAnimProfileData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVertexAnimFunctionLibrary_GetVertexAnimProfileData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVertexAnimFunctionLibrary_GetVertexAnimProfileData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVertexAnimFunctionLibrary_SetDataAtProfile_Statics
	{
		struct VertexAnimFunctionLibrary_eventSetDataAtProfile_Parms
		{
			UVertexAnimProfile* InVertexAnimProfile;
			UObject* InAnimationAsset;
			int32 InNumFrames;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InVertexAnimProfile;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InAnimationAsset;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_InNumFrames;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVertexAnimFunctionLibrary_SetDataAtProfile_Statics::NewProp_InVertexAnimProfile = { "InVertexAnimProfile", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(VertexAnimFunctionLibrary_eventSetDataAtProfile_Parms, InVertexAnimProfile), Z_Construct_UClass_UVertexAnimProfile_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVertexAnimFunctionLibrary_SetDataAtProfile_Statics::NewProp_InAnimationAsset = { "InAnimationAsset", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(VertexAnimFunctionLibrary_eventSetDataAtProfile_Parms, InAnimationAsset), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
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
		{ &Z_Construct_UFunction_UVertexAnimFunctionLibrary_DoBake, "DoBake" }, // 3174255658
		{ &Z_Construct_UFunction_UVertexAnimFunctionLibrary_GetVertexAnimProfileData, "GetVertexAnimProfileData" }, // 4050254707
		{ &Z_Construct_UFunction_UVertexAnimFunctionLibrary_SetDataAtProfile, "SetDataAtProfile" }, // 1634707194
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
	IMPLEMENT_CLASS(UVertexAnimFunctionLibrary, 2477062061);
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
