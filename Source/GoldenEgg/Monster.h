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
	//скорость передвижения
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCMessage)
		float Speed;
	//здоровье
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		float HitPoints;
	//Наносимый урон
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		float BaseAttackDamage;
	//время между атаками 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProperties)
		float AttackTimeout;
	// Время с последнего удара монстра, читаемое в blueprint
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = MonsterProperties)
		float TimeSinceLastStrike;
	//дистанция обзора
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Collision)
		USphereComponent* SightSphere;
	//дальность атаки
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Collision)
		USphereComponent* AttackRangeSphere;
	
	//конструктор
	AMonster(const class FObjectInitializer& );
	//передвижение моба
	virtual void Tick(float DeltaSeconds) override;
};
