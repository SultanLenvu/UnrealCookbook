// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IModule.h"
#include "IWeaponConstructable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIWeaponConstructable : public UInterface
{
	GENERATED_BODY()
};

/**
* 
*/
class GOLDENEGG_API IIWeaponConstructable
{
	GENERATED_BODY()
	
	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	public:
	virtual void SetModule(UObject* module) = 0;

	virtual TScriptInterface<IIModule>* GetMuzzel() = 0;

	virtual TScriptInterface<IIModule>* GetForeGrip() = 0;

	virtual TScriptInterface<IIModule>* GetMagazine() = 0;

	virtual TScriptInterface<IIModule>* GetGrip() = 0;

	virtual TScriptInterface<IIModule>* GetStock() = 0;

	virtual TScriptInterface<IIModule>* GetFrame() = 0;

	virtual TScriptInterface<IIModule>* GetBullet() = 0;

	virtual TScriptInterface<IIModule>* GetKit() = 0;

	virtual TScriptInterface<IIModule>* GetGunPoint() = 0;

	virtual TScriptInterface<IIModule>* GetHandle() = 0;
	
	virtual FWeaponStats& GetWeaponStats() =0;
};
