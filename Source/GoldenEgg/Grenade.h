// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"

#include "Grenade.generated.h"

USTRUCT(BlueprintType)
struct FDamageDebuffStats
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float DamagePerSecond;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float Duration;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<UDamageType> DamageType;
	FDamageDebuffStats()
	{
		DamagePerSecond = 0.0f;
		Duration = 0.0f;
		DamageType = UDamageType::StaticClass();
	}
};

USTRUCT(BlueprintType)
struct FGrenadeStats
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float Damage;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float ExplosionTime;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float Radius;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FDamageDebuffStats DebuffStats;
	FGrenadeStats()
	{
		Damage = 100.0f;
		Radius = 1500.0f;
		ExplosionTime = 5.0f;
		DebuffStats = {};
	}
};

UENUM()
enum EGrenadeType
{
	Striking UMETA(DisplayName = "Striking"),
	Tactical  UMETA(DisplayName = "Tactical")
};

struct FGrenadeStats;
struct FDamageDebuffStats;
enum EGrenadeType;

UCLASS()
class GOLDENEGG_API AGrenade : public AActor
{
	GENERATED_BODY()
	FTimerHandle ExplosionTimer;

	void Explode();
	void CauseDamage();
	
public:	
	// Sets default values for this actor's properties
	AGrenade();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	USkeletalMeshComponent* MeshComponent;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UProjectileMovementComponent* MovementComponent;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UParticleSystem* ExplosionSystem;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TEnumAsByte<EGrenadeType> GrenadeType;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<UDamageType> DamageType;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FGrenadeStats GrenadeStats;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	bool bCanDebuff = false;
	
	UFUNCTION(BlueprintNativeEvent)
	void PerformExplosionEffect();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetExplosionTimer();
};
