// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IModule.h"
#include "IWeapon.h"
#include "IWeaponConstructable.h"
#include "Weapon.generated.h"

enum EWeaponStates
{
	Shooting,
	MeleeHitting,
	Reloading,
	None
};

UCLASS()
class GOLDENEGG_API AWeapon : public AActor, public IIWeapon, public IIWeaponConstructable
{
	GENERATED_BODY()
	
	FTimerHandle ShootingTimer;
	FTimerHandle ReloadTimer;
public:	
	// Sets default values for this actor's properties
	AWeapon();

	EWeaponStates ActiveState;
	//IWeapon methods override section...
	UFUNCTION(BlueprintCallable)
	virtual void ShootStart(FVector GunPointLocation, FVector ForwardVector) override;
	UFUNCTION(BlueprintCallable)
	virtual void ReloadStart() override;
	UFUNCTION(BlueprintCallable)
	virtual void MeleeHitStart() override;
	UFUNCTION(BlueprintCallable)
	virtual void ShootEnd() override;
	UFUNCTION(BlueprintCallable)
	virtual void ReloadEnd() override;
	UFUNCTION(BlueprintCallable)
	virtual void MeleeHitEnd() override;
protected:
	//Slots properties...
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TScriptInterface<IIModule> Muzzle = TScriptInterface<IIModule>{};
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TScriptInterface<IIModule> ForeGrip;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TScriptInterface<IIModule> Magazine;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TScriptInterface<IIModule> Grip;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TScriptInterface<IIModule> Stock;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TScriptInterface<IIModule> Frame;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TScriptInterface<IIModule> Bullet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TScriptInterface<IIModule> Kit;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TScriptInterface<IIModule> GunPoint;
	//Statistics struct...
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FWeaponStats WeaponStats;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	void Tick(float DeltaTime) override;

	//IWeaponConstructable methods override section...
	virtual void SetModule(UObject* module) override;

	virtual TScriptInterface<IIModule>* GetMuzzel() override;

	virtual TScriptInterface<IIModule>* GetForeGrip() override;

	virtual TScriptInterface<IIModule>* GetMagazine() override;

	virtual TScriptInterface<IIModule>* GetGrip() override;

	virtual TScriptInterface<IIModule>* GetStock() override;

	virtual TScriptInterface<IIModule>* GetFrame() override;

	virtual TScriptInterface<IIModule>* GetBullet() override;

	virtual TScriptInterface<IIModule>* GetKit() override;

	virtual TScriptInterface<IIModule>* GetGunPoint() override;
	
	virtual FWeaponStats& GetWeaponStats() override;
};


