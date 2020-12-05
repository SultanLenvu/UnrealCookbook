// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IModule.generated.h"

struct FAttachmentTransformRules;

USTRUCT(BlueprintType)
struct FDamageStats
{
	GENERATED_BODY()
public:
	//Properties... ->
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float BulletDamage;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float HitDamage;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float FallOfDistance;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float FallOfPercentageStart;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float FallOfPercentageEnd;
	FDamageStats()
	{
		BulletDamage = 10.0f;
		HitDamage = 60.0f;
		FallOfDistance = 200.0f;
		FallOfPercentageStart = 5.0f;
		FallOfPercentageEnd = 30.0f;
	}
	//Methods... ->
	float CalculateDamage(float HitDistance) const
	{
		if (HitDistance<=FallOfDistance) return BulletDamage;
		if ((HitDistance-FallOfDistance)*FallOfPercentageStart>FallOfPercentageEnd) return
            BulletDamage-BulletDamage*(FallOfPercentageEnd/100);
		else return BulletDamage-(HitDistance-FallOfDistance)*FallOfPercentageStart/100*BulletDamage;
	}
	
};

USTRUCT(BlueprintType)
struct FDispersionRow
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float Coefficient;
	FDispersionRow()
	{
		Coefficient = 1;
	}
};

USTRUCT(BlueprintType)
struct FDispersionStats
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FDispersionRow Right;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FDispersionRow Left;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FDispersionRow Up;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FDispersionRow Down ;
	//Possible future methods and constructors...
	FDispersionStats()
	{
		Right = {};
		Left = {};
		Up = {};
		Down = {};
	}
};

USTRUCT(BlueprintType)
struct FAmmoStats
{
	GENERATED_BODY();
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float MaxMagazines;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float CurrentMagazine;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float MaxAmmo;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float CurrentAmmo;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float TotalAmmoLeft;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float ReloadTime;
	FAmmoStats()
	{
		MaxAmmo = 30.0f;
		CurrentAmmo = MaxAmmo;
		MaxMagazines = 3.0f;
		CurrentMagazine = MaxMagazines;
		TotalAmmoLeft = (MaxAmmo-1)*MaxMagazines;
		ReloadTime = 2.0f;
	}
};

USTRUCT(BlueprintType)
struct FWeaponStats
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float ShootingRange;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float Mass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float ShootingRPM;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float ADSTime;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FDamageStats Damage;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FDispersionStats Dispersion;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FAmmoStats AmmoStats;
	FWeaponStats()
	{
		ShootingRange = 1500.0f;
		Mass = 1000.0f;
		ShootingRPM = 30.0f;
		ADSTime = 1.0f;
		Damage = {};
		Dispersion = {};
		AmmoStats = {};
	}
};

UENUM()
enum ESlotType
{
	Muzzle	UMETA(DisplayName = "Muzzle"),
    ForeGrip	UMETA(DisplayName = "ForeGrip"),
    Magazine	UMETA(DisplayName = "Magazine"),
    Grip	UMETA(DisplayName = "Grip"),
    Stock	UMETA(DisplayName = "Stock"),
    Frame	UMETA(DisplayName = "Frame"),
    Bullet	UMETA(DisplayName = "Bullet"),
    Kit	UMETA(DisplayName = "Kit"),
    GunPoint	UMETA(DisplayName = "GunPoint"),
	Handle	UMETA(DisplayName = "Handle")
};

enum ESlotTypes;

// This class does not need to be modified.
UINTERFACE(Blueprintable)
class UIModule : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GOLDENEGG_API IIModule
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void SetStats(UPARAM(ref) FWeaponStats& stats);
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void ResetStats(UPARAM(ref) FWeaponStats& stats);
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	ESlotType GetSlotType();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
    void SetVisual(USceneComponent* Parent, FName SocketName);
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
    void ResetVisual();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	FName GetSocketNameAttachTo();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	ESlotType GetParentSlot();
};

