// Fill out your copyright notice in the Description page of Project Settings.


#include "Grenade.h"

#include "Kismet/GameplayStatics.h"

void AGrenade::Explode()
{
	GetWorldTimerManager().ClearTimer(ExplosionTimer);
	PerformExplosionEffect();
	if(GrenadeType==Striking) CauseDamage();
	Destroy();
}

void AGrenade::CauseDamage()
{
	bool bDamaged = UGameplayStatics::ApplyRadialDamage(GetWorld(),GrenadeStats.Damage, GetActorLocation(),
		GrenadeStats.Radius, DamageType, TArray<AActor*>(),this,
		GetNetOwner()->GetInstigatorController());
	
}
// Sets default values

AGrenade::AGrenade()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
	
	MeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	MeshComponent->SetSimulatePhysics(true);
	RootComponent = MeshComponent;
	
	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	MovementComponent->SetUpdatedComponent(MeshComponent);
	MovementComponent->MaxSpeed = 1500.0f;
	MovementComponent->bRotationFollowsVelocity = true;
}

// Called when the game starts or when spawned
void AGrenade::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGrenade::PerformExplosionEffect_Implementation()
{
	FVector spawnLocation = GetActorLocation();
	UGameplayStatics::SpawnEmitterAtLocation(this, ExplosionSystem, spawnLocation,
        FRotator::ZeroRotator, true, EPSCPoolMethod::AutoRelease);
}

// Called every frame
void AGrenade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGrenade::SetExplosionTimer()
{
	GetWorldTimerManager().SetTimer(ExplosionTimer,this,&AGrenade::Explode,GrenadeStats.ExplosionTime,
		false);
}

