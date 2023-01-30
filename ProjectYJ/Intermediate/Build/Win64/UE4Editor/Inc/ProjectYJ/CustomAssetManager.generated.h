// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECTYJ_CustomAssetManager_generated_h
#error "CustomAssetManager.generated.h already included, missing '#pragma once' in CustomAssetManager.h"
#endif
#define PROJECTYJ_CustomAssetManager_generated_h

#define ProjectYJ_Source_ProjectYJ_System_AssetManager_CustomAssetManager_h_24_SPARSE_DATA
#define ProjectYJ_Source_ProjectYJ_System_AssetManager_CustomAssetManager_h_24_RPC_WRAPPERS
#define ProjectYJ_Source_ProjectYJ_System_AssetManager_CustomAssetManager_h_24_RPC_WRAPPERS_NO_PURE_DECLS
#define ProjectYJ_Source_ProjectYJ_System_AssetManager_CustomAssetManager_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCustomAssetManager(); \
	friend struct Z_Construct_UClass_UCustomAssetManager_Statics; \
public: \
	DECLARE_CLASS(UCustomAssetManager, UAssetManager, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ProjectYJ"), NO_API) \
	DECLARE_SERIALIZER(UCustomAssetManager)


#define ProjectYJ_Source_ProjectYJ_System_AssetManager_CustomAssetManager_h_24_INCLASS \
private: \
	static void StaticRegisterNativesUCustomAssetManager(); \
	friend struct Z_Construct_UClass_UCustomAssetManager_Statics; \
public: \
	DECLARE_CLASS(UCustomAssetManager, UAssetManager, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ProjectYJ"), NO_API) \
	DECLARE_SERIALIZER(UCustomAssetManager)


#define ProjectYJ_Source_ProjectYJ_System_AssetManager_CustomAssetManager_h_24_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCustomAssetManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCustomAssetManager) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCustomAssetManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCustomAssetManager); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCustomAssetManager(UCustomAssetManager&&); \
	NO_API UCustomAssetManager(const UCustomAssetManager&); \
public:


#define ProjectYJ_Source_ProjectYJ_System_AssetManager_CustomAssetManager_h_24_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCustomAssetManager() { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCustomAssetManager(UCustomAssetManager&&); \
	NO_API UCustomAssetManager(const UCustomAssetManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCustomAssetManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCustomAssetManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCustomAssetManager)


#define ProjectYJ_Source_ProjectYJ_System_AssetManager_CustomAssetManager_h_24_PRIVATE_PROPERTY_OFFSET
#define ProjectYJ_Source_ProjectYJ_System_AssetManager_CustomAssetManager_h_21_PROLOG
#define ProjectYJ_Source_ProjectYJ_System_AssetManager_CustomAssetManager_h_24_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ProjectYJ_Source_ProjectYJ_System_AssetManager_CustomAssetManager_h_24_PRIVATE_PROPERTY_OFFSET \
	ProjectYJ_Source_ProjectYJ_System_AssetManager_CustomAssetManager_h_24_SPARSE_DATA \
	ProjectYJ_Source_ProjectYJ_System_AssetManager_CustomAssetManager_h_24_RPC_WRAPPERS \
	ProjectYJ_Source_ProjectYJ_System_AssetManager_CustomAssetManager_h_24_INCLASS \
	ProjectYJ_Source_ProjectYJ_System_AssetManager_CustomAssetManager_h_24_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ProjectYJ_Source_ProjectYJ_System_AssetManager_CustomAssetManager_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ProjectYJ_Source_ProjectYJ_System_AssetManager_CustomAssetManager_h_24_PRIVATE_PROPERTY_OFFSET \
	ProjectYJ_Source_ProjectYJ_System_AssetManager_CustomAssetManager_h_24_SPARSE_DATA \
	ProjectYJ_Source_ProjectYJ_System_AssetManager_CustomAssetManager_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	ProjectYJ_Source_ProjectYJ_System_AssetManager_CustomAssetManager_h_24_INCLASS_NO_PURE_DECLS \
	ProjectYJ_Source_ProjectYJ_System_AssetManager_CustomAssetManager_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTYJ_API UClass* StaticClass<class UCustomAssetManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ProjectYJ_Source_ProjectYJ_System_AssetManager_CustomAssetManager_h


#define FOREACH_ENUM_EASYNCLOADLOGTYPE(op) \
	op(EAsyncLoadLogType::Info) \
	op(EAsyncLoadLogType::Complete) \
	op(EAsyncLoadLogType::Cancel) 

enum class EAsyncLoadLogType : uint8;
template<> PROJECTYJ_API UEnum* StaticEnum<EAsyncLoadLogType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
