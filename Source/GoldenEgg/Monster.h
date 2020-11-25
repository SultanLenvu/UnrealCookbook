// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/SphereComponent.h"
#include "UObject/Object.h"
#include "Kismet/GameplayStatics.h"
#include "Avatar.h"
#include "Monster.generated.h"

UCLASS()
class GOLDENEGG_API AMonster : public ACharacter
{
	GENERATED_BODY()

public:
	//�������� ������������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCMessage)
		float Speed;
	//��������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		float HitPoints;
	//��������� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		float BaseAttackDamage;
	//����� ����� ������� 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		float AttackTimeout;
	// ����� � ���������� ����� �������, �������� � blueprint
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = MonsterProperties)
		float TimeSinceLastStrike;
	//��������� ������
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Collision)
		USphereComponent* SightSphere;
	//��������� �����
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Collision)
		USphereComponent* AttackRangeSphere;
	
	//�����������
	AMonster(const class FObjectInitializer& );
	//������������ ����
	virtual void Tick(float DeltaSeconds) override;
};
