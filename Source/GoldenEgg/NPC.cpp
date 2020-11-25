// Fill out your copyright notice in the Description page of Project Settings.

#include "NPC.h"
#include "Avatar.h"
#include "MyHUD.h"

//����������� �� ���������
ANPC::ANPC()
{
	message = "Hi, I'm ";

	ProxSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Proximity Sphere"));
	ProxSphere->SetupAttachment(RootComponent);
	ProxSphere->InitSphereRadius(200.f);

	// ��� ��� ������� ANPC::Prox(), ����� ��� ����� ������������ ������ �������
	ProxSphere->OnComponentBeginOverlap.AddDynamic(this, &ANPC::Prox);
}

//������� �������� ������ ���������� ��������
void ANPC::Prox_Implementation(UPrimitiveComponent*  OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFormSweep, const FHitResult & SweepResult)
{
	//���� �����, � ������� ��������� ����������� �� �����, �� �� ������ ������� �� �������
	if (Cast<AAvatar>(OtherActor) == nullptr)
	{
		return;
	}
	APlayerController* PController = GetWorld()->GetFirstPlayerController();
	if (PController)
	{
		//������ � ���� ������
		AMyHUD * hud = Cast<AMyHUD>(PController->GetHUD());
		//����� ��������� �� ��� ������
		hud->addMessage(Message(name+FString(": ")+message + name, 5.f, FColor::Black));
	}
}