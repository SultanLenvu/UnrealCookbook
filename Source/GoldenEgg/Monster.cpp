#include "Monster.h"

//�����������
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
//������������ ����
void AMonster::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	//������� ���������, ������� ���� �� ������
	AAvatar *avatar = Cast<AAvatar>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if (!avatar) return;

	FVector toPlayer = avatar->GetActorLocation() - GetActorLocation(); //������ ����������� ��������
	toPlayer.Normalize(); //����������� ������, �������� ��� �����
	//������� ���� �� ������
	AddMovementInput(toPlayer, Speed*DeltaSeconds);
	//��������� ���� ���� � ����
	FRotator toPlayerRotation = toPlayer.Rotation();
	toPlayerRotation.Pitch = 0; //������ ��������
	RootComponent->SetWorldRotation(toPlayerRotation);
}