// Fill out your copyright notice in the Description page of Project Settings.

#include "Avatar.h"

//Функции для передвижения персонажа
void AAvatar::SetupPlayerInputComponent(class UInputComponent* InputComponent1)
{
	//Функция ищет привязки осей Forward и Strafe, которые мы только что создали в UnrealEditor и привязывает их к функции-члену внутри данного класса
	check(InputComponent1);
	InputComponent1->BindAxis("Forward", this, &AAvatar::MoveForward);
	InputComponent1->BindAxis("Strafe", this, &AAvatar::MoveRight);
	InputComponent1->BindAxis("Yaw", this, &AAvatar::Yaw);
	InputComponent1->BindAxis("Pitch", this,&AAvatar::Pitch);
}

//Объект Controller и функции AddMovementInput определены в базовом классе APawn
//Avatar=>ACharacter=>APawn
void AAvatar::MoveForward(float amount)
{
	//amount - размер перемещения
	if (Controller && amount)
	{
		//Получение вектора для движения в прямом направлении
		FVector fwd = GetActorForwardVector();
		//Задаем перемещение игрока в направлении вектора
		AddMovementInput(fwd, amount);
	}
}

void AAvatar::MoveRight(float amount)
{
	if (Controller && amount)
	{
		FVector right = GetActorRightVector();
		AddMovementInput(right, amount);
	}
}
//=======================================================================================================================

//Функции для вращения камеры
void AAvatar::Yaw(float amount)
{
	AddControllerYawInput(MouseSensibility * amount * GetWorld()->GetDeltaSeconds());
}

void AAvatar::Pitch(float amount)
{
	AddControllerPitchInput(MouseSensibility * amount * GetWorld()->GetDeltaSeconds());
}