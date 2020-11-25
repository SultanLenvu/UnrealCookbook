#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Avatar.generated.h"

UCLASS()
class GOLDENEGG_API AAvatar : public ACharacter
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Characteristics)
		float Hp;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Characteristics)
		float MaxHp;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Characteristics)
		float MouseSensibility; //чувствительность мыши
	
	//Установка чувствительности мыши
	void SetMouseSensibility(float MS) { MouseSensibility = MS; }
	float GetMouseSensibility() { return MouseSensibility; }
		

	//Функции для передвижения персонажа
	void SetupPlayerInputComponent(class UInputComponent* InputComponent1) override;
	void MoveForward(float amount);
	void MoveRight(float amount);

	//Функции для вращения камеры
	void Yaw(float amount);
	void Pitch(float amount);
};
