#include "Monster.h"

//конструктор
AMonster::AMonster(const class FObjectInitializer & ObjectInitializer) : Super(ObjectInitializer)
{
	Speed = 20;
	HitPoints = 20;
	BaseAttackDamage = 1;
	AttackTimeout = 1.5f;
	TimeSinceLastStrike = 0;
	
	SightSphere = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("SightSphere"));
	SightSphere->AttachTo(RootComponent);

	AttackRangeSphere = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("AttackRangeSphere"));
	AttackRangeSphere->AttachTo(RootComponent);
}
//передвижение моба
void AMonster::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	//базовый интеллект, двигает моба на игрока
	AAvatar *avatar = Cast<AAvatar>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if (!avatar) return;

	FVector toPlayer = avatar->GetActorLocation() - GetActorLocation(); //вектор направления движения
	toPlayer.Normalize(); //нормализует вектор, сокращая его длину
	//двигаем моба на игрока
	AddMovementInput(toPlayer, Speed*DeltaSeconds);
	//обращение лица моба к цели
	FRotator toPlayerRotation = toPlayer.Rotation();
	toPlayerRotation.Pitch = 0; //тангаж зануляем
	RootComponent->SetWorldRotation(toPlayerRotation);
}