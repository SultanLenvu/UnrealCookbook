// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "Kismet/GameplayStatics.h"

void AWeapon::ShootEnd()
{
	if (WeaponStats.AmmoStats.CurrentAmmo<=0)
	{
		ReloadStart();
		return;
	}
	if (GetWorldTimerManager().IsTimerActive(ShootingTimer)) GetWorldTimerManager().ClearTimer(ShootingTimer);
	ActiveState = None;
}

void AWeapon::ReloadEnd()
{
	WeaponStats.AmmoStats.TotalAmmoLeft-=WeaponStats.AmmoStats.MaxAmmo-WeaponStats.AmmoStats.CurrentAmmo;
	WeaponStats.AmmoStats.CurrentAmmo = WeaponStats.AmmoStats.MaxAmmo;
	if (GetWorldTimerManager().IsTimerActive(ReloadTimer)) GetWorldTimerManager().ClearTimer(ReloadTimer);
	ActiveState = None;
}

void AWeapon::MeleeHitEnd()
{
	ActiveState = None;
	if (WeaponStats.AmmoStats.CurrentAmmo<=0) ReloadStart();
}

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AWeapon::ShootStart(const FVector GunPointLocation, const FVector ForwardVector)
{
	if (ActiveState == None)
	{
		ActiveState = Shooting;
		FVector EndVector = ForwardVector*WeaponStats.ShootingRange+GunPointLocation;
		FHitResult Hit;
		FCollisionQueryParams Params;
		bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, GunPointLocation, EndVector,
			ECC_Visibility, Params);
		WeaponStats.AmmoStats.CurrentAmmo--;
		if (bHit)
		{
			UGameplayStatics::ApplyPointDamage(Hit.GetActor(),WeaponStats.Damage.CalculateDamage(Hit.Distance),
				ForwardVector*WeaponStats.ShootingRange, Hit, GetOwner()->GetInstigatorController(),
				this,UDamageType::StaticClass());
		}
		GetWorldTimerManager().SetTimer(ReloadTimer, this, &AWeapon::ShootEnd,
			1/(WeaponStats.ShootingRPM/60),false);
		
	}
}

void AWeapon::ReloadStart()
{
	if (ActiveState == None && WeaponStats.AmmoStats.TotalAmmoLeft<=0)
	{
		ActiveState = Reloading;
		GetWorldTimerManager().SetTimer(ShootingTimer, this, &AWeapon::ReloadEnd,
            WeaponStats.AmmoStats.ReloadTime,false);
	}
}

void AWeapon::MeleeHitStart()
{
	if (ActiveState == None || ActiveState==Reloading)
	{
		ActiveState = MeleeHitting;
	}
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeapon::SetModule(UObject* module)
{
	IIModule* Module = Cast<IIModule>(module);
	Module->Execute_SetStats(module, WeaponStats);
	Module->Execute_SetVisual(module,this->RootComponent, Module->Execute_GetSocketNameAttachTo(module));
}

TScriptInterface<IIModule>* AWeapon::GetMuzzel()
{
	return &Muzzle;
}

TScriptInterface<IIModule>* AWeapon::GetForeGrip()
{
	return &ForeGrip;
}

TScriptInterface<IIModule>* AWeapon::GetMagazine()
{
	return &Magazine;
}

TScriptInterface<IIModule>* AWeapon::GetGrip()
{
	return &Grip;
}

TScriptInterface<IIModule>* AWeapon::GetStock()
{
	return &Stock;
}

TScriptInterface<IIModule>* AWeapon::GetFrame()
{
	return &Frame;
}

TScriptInterface<IIModule>* AWeapon::GetBullet()
{
	return &Bullet;
}

TScriptInterface<IIModule>* AWeapon::GetKit()
{
	return &Kit;
}

TScriptInterface<IIModule>* AWeapon::GetGunPoint()
{
	return &GunPoint;
}

FWeaponStats& AWeapon::GetWeaponStats()
{
	return WeaponStats;
}

