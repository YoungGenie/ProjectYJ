// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECTYJ_YJAssetManager_generated_h
#error "YJAssetManager.generated.h already included, missing '#pragma once' in YJAssetManager.h"
#endif
#define PROJECTYJ_YJAssetManager_generated_h

#define ProjectYJ_Source_ProjectYJ_System_AssetManager_YJAssetManager_h_24_SPARSE_DATA
#define ProjectYJ_Source_ProjectYJ_System_AssetManager_YJAssetManager_h_24_RPC_WRAPPERS
#define ProjectYJ_Source_ProjectYJ_System_AssetManager_YJAssetManager_h_24_RPC_WRAPPERS_NO_PURE_DECLS
#define ProjectYJ_Source_ProjectYJ_System_AssetManager_YJAssetManager_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUYJAssetManager(); \
	friend struct Z_Construct_UClass_UYJAssetManager_Statics; \
public: \
	DECLARE_CLASS(UYJAssetManager, UAssetManager, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ProjectYJ"), NO_API) \
	DECLARE_SERIALIZER(UYJAssetManager)


#define ProjectYJ_Source_ProjectYJ_System_AssetManager_YJAssetManager_h_24_INCLASS \
private: \
	static void StaticRegisterNativesUYJAssetManager(); \
	friend struct Z_Construct_UClass_UYJAssetManager_Statics; \
public: \
	DECLARE_CLASS(UYJAssetManager, UAssetManager, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ProjectYJ"), NO_API) \
	DECLARE_SERIALIZER(UYJAssetManager)


#define ProjectYJ_Source_ProjectYJ_System_AssetManager_YJAssetManager_h_24_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UYJAssetManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UYJAssetManager) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UYJAssetManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UYJAssetManager); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UYJAssetManager(UYJAssetManager&&); \
	NO_API UYJAssetManager(const UYJAssetManager&); \
public:


#define ProjectYJ_Source_ProjectYJ_System_AssetManager_YJAssetManager_h_24_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UYJAssetManager() { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UYJAssetManager(UYJAssetManager&&); \
	NO_API UYJAssetManager(const UYJAssetManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UYJAssetManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UYJAssetManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UYJAssetManager)


#define ProjectYJ_Source_ProjectYJ_System_AssetManager_YJAssetManager_h_24_PRIVATE_PROPERTY_OFFSET
#define ProjectYJ_Source_ProjectYJ_System_AssetManager_YJAssetManager_h_21_PROLOG
#define ProjectYJ_Source_ProjectYJ_System_AssetManager_YJAssetManager_h_24_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ProjectYJ_Source_ProjectYJ_System_AssetManager_YJAssetManager_h_24_PRIVATE_PROPERTY_OFFSET \
	ProjectYJ_Source_ProjectYJ_System_AssetManager_YJAssetManager_h_24_SPARSE_DATA \
	ProjectYJ_Source_ProjectYJ_System_AssetManager_YJAssetManager_h_24_RPC_WRAPPERS \
	ProjectYJ_Source_ProjectYJ_System_AssetManager_YJAssetManager_h_24_INCLASS \
	ProjectYJ_Source_ProjectYJ_System_AssetManager_YJAssetManager_h_24_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ProjectYJ_Source_ProjectYJ_System_AssetManager_YJAssetManager_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ProjectYJ_Source_ProjectYJ_System_AssetManager_YJAssetManager_h_24_PRIVATE_PROPERTY_OFFSET \
	ProjectYJ_Source_ProjectYJ_System_AssetManager_YJAssetManager_h_24_SPARSE_DATA \
	ProjectYJ_Source_ProjectYJ_System_AssetManager_YJAssetManager_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	ProjectYJ_Source_ProjectYJ_System_AssetManager_YJAssetManager_h_24_INCLASS_NO_PURE_DECLS \
	ProjectYJ_Source_ProjectYJ_System_AssetManager_YJAssetManager_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTYJ_API UClass* StaticClass<class UYJAssetManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ProjectYJ_Source_ProjectYJ_System_AssetManager_YJAssetManager_h


#define FOREACH_ENUM_EASYNCLOADLOGTYPE(op) \
	op(EAsyncLoadLogType::Info) \
	op(EAsyncLoadLogType::Complete) \
	op(EAsyncLoadLogType::Cancel) 

enum class EAsyncLoadLogType : uint8;
template<> PROJECTYJ_API UEnum* StaticEnum<EAsyncLoadLogType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
