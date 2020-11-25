// Fill out your copyright notice in the Description page of Project Settings.

#include "NPC.h"
#include "Avatar.h"
#include "MyHUD.h"

//Конструктор по умолчанию
ANPC::ANPC()
{
	message = "Hi, I'm ";

	ProxSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Proximity Sphere"));
	ProxSphere->SetupAttachment(RootComponent);
	ProxSphere->InitSphereRadius(200.f);

	// Код для запуска ANPC::Prox(), когда эта сфера пересекается другим актором
	ProxSphere->OnComponentBeginOverlap.AddDynamic(this, &ANPC::Prox);
}

//Функция задающая собтие перекрытия коллизий
void ANPC::Prox_Implementation(UPrimitiveComponent*  OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFormSweep, const FHitResult & SweepResult)
{
	//если актор, с которым произошло пересечение не игрок, то мы просто выходим из функции
	if (Cast<AAvatar>(OtherActor) == nullptr)
	{
		return;
	}
	APlayerController* PController = GetWorld()->GetFirstPlayerController();
	if (PController)
	{
		//доступ к худу игрока
		AMyHUD * hud = Cast<AMyHUD>(PController->GetHUD());
		//вывод сообщения на худ игрока
		hud->addMessage(Message(name+FString(": ")+message + name, 5.f, FColor::Black));
	}
}