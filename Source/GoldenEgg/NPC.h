// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/SphereComponent.h"
#include "NPC.generated.h"

UCLASS()
class GOLDENEGG_API ANPC : public ACharacter
{
	GENERATED_BODY()

public:	
	//��������� NPC, ������� �� ������ ������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCMessage)
		FString message;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCMessage)
		FString name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCMessage)
		UTexture2D *face;
	//�����, � ������� ����� ������������ �����, ����� �������� �������
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = NPCMessage)
		class USphereComponent* ProxSphere;

	//����������� �� ���������
	ANPC();

	//���������� ������� ��������� �� ���������; ��������� ������� ����������� ������� �������
	UFUNCTION(BlueprintNativeEvent, Category = Collision)
		void Prox(UPrimitiveComponent*  OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFormSweep, const FHitResult & SweepResult);
};
