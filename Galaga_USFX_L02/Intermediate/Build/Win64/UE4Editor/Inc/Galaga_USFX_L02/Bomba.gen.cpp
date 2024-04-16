// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_L02/Bomba.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBomba() {}
// Cross Module References
	GALAGA_USFX_L02_API UClass* Z_Construct_UClass_ABomba_NoRegister();
	GALAGA_USFX_L02_API UClass* Z_Construct_UClass_ABomba();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_L02();
	ENGINE_API UClass* Z_Construct_UClass_UParticleSystem_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void ABomba::StaticRegisterNativesABomba()
	{
	}
	UClass* Z_Construct_UClass_ABomba_NoRegister()
	{
		return ABomba::StaticClass();
	}
	struct Z_Construct_UClass_ABomba_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CantidadDanio_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CantidadDanio;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VelocidadBomba_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_VelocidadBomba;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ExplosionEffect_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ExplosionEffect;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BombaMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BombaMesh;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABomba_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_L02,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABomba_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Bomba.h" },
		{ "ModuleRelativePath", "Bomba.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABomba_Statics::NewProp_CantidadDanio_MetaData[] = {
		{ "Category", "Gameplay" },
		{ "ModuleRelativePath", "Bomba.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABomba_Statics::NewProp_CantidadDanio = { "CantidadDanio", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABomba, CantidadDanio), METADATA_PARAMS(Z_Construct_UClass_ABomba_Statics::NewProp_CantidadDanio_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABomba_Statics::NewProp_CantidadDanio_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABomba_Statics::NewProp_VelocidadBomba_MetaData[] = {
		{ "ModuleRelativePath", "Bomba.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABomba_Statics::NewProp_VelocidadBomba = { "VelocidadBomba", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABomba, VelocidadBomba), METADATA_PARAMS(Z_Construct_UClass_ABomba_Statics::NewProp_VelocidadBomba_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABomba_Statics::NewProp_VelocidadBomba_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABomba_Statics::NewProp_ExplosionEffect_MetaData[] = {
		{ "Category", "Effects" },
		{ "Comment", "// Malla visual de la bomba\n" },
		{ "ModuleRelativePath", "Bomba.h" },
		{ "ToolTip", "Malla visual de la bomba" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABomba_Statics::NewProp_ExplosionEffect = { "ExplosionEffect", nullptr, (EPropertyFlags)0x0040000000020001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABomba, ExplosionEffect), Z_Construct_UClass_UParticleSystem_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABomba_Statics::NewProp_ExplosionEffect_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABomba_Statics::NewProp_ExplosionEffect_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABomba_Statics::NewProp_BombaMesh_MetaData[] = {
		{ "Category", "Bomba" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Bomba.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABomba_Statics::NewProp_BombaMesh = { "BombaMesh", nullptr, (EPropertyFlags)0x00400000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABomba, BombaMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABomba_Statics::NewProp_BombaMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABomba_Statics::NewProp_BombaMesh_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABomba_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABomba_Statics::NewProp_CantidadDanio,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABomba_Statics::NewProp_VelocidadBomba,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABomba_Statics::NewProp_ExplosionEffect,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABomba_Statics::NewProp_BombaMesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABomba_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABomba>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABomba_Statics::ClassParams = {
		&ABomba::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ABomba_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ABomba_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ABomba_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABomba_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABomba()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABomba_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABomba, 2530831919);
	template<> GALAGA_USFX_L02_API UClass* StaticClass<ABomba>()
	{
		return ABomba::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABomba(Z_Construct_UClass_ABomba, &ABomba::StaticClass, TEXT("/Script/Galaga_USFX_L02"), TEXT("ABomba"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABomba);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
