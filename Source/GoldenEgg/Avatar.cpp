// Fill out your copyright notice in the Description page of Project Settings.

#include "Avatar.h"

//������� ��� ������������ ���������
void AAvatar::SetupPlayerInputComponent(class UInputComponent* InputComponent1)
{
	//������� ���� �������� ���� Forward � Strafe, ������� �� ������ ��� ������� � UnrealEditor � ����������� �� � �������-����� ������ ������� ������
	check(InputComponent1);
	InputComponent1->BindAxis("Forward", this, &AAvatar::MoveForward);
	InputComponent1->BindAxis("Strafe", this, &AAvatar::MoveRight);
	InputComponent1->BindAxis("Yaw", this, &AAvatar::Yaw);
	InputComponent1->BindAxis("Pitch", this,&AAvatar::Pitch);
}

//������ Controller � ������� AddMovementInput ���������� � ������� ������ APawn
//Avatar=>ACharacter=>APawn
void AAvatar::MoveForward(float amount)
{
	//amount - ������ �����������
	if (Controller && amount)
	{
		//��������� ������� ��� �������� � ������ �����������
		FVector fwd = GetActorForwardVector();
		//������ ����������� ������ � ����������� �������
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

//������� ��� �������� ������
void AAvatar::Yaw(float amount)
{
	AddControllerYawInput(MouseSensibility * amount * GetWorld()->GetDeltaSeconds());
}

void AAvatar::Pitch(float amount)
{
	AddControllerPitchInput(MouseSensibility * amount * GetWorld()->GetDeltaSeconds());
}