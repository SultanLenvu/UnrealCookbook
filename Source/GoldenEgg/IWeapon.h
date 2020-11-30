// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IWeapon.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIWeapon : public UInterface
{
	GENERATED_BODY()
};

/**
* 
*/
class GOLDENEGG_API IIWeapon
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	public:
	virtual void ShootStart(FVector GunPointLocation, FVector ForwardVector) = 0;

	virtual void ReloadStart() = 0;

	virtual void MeleeHitStart() = 0;
	
	virtual void ShootEnd() = 0;

	virtual void ReloadEnd() = 0;

	virtual void MeleeHitEnd() = 0;
};
