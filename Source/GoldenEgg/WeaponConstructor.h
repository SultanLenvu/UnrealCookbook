// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IWeaponConstructable.h"
#include "IModule.h"
/**
* 
*/
enum ESlotType;
class GOLDENEGG_API WeaponConstructor
{
	private:
	TScriptInterface<IIWeaponConstructable> ConstructingWeapon;
	TScriptInterface<IIModule>* CustomizedSlot;
	public:
	WeaponConstructor();
	explicit WeaponConstructor(UObject* Weapon);
	void AssembleWeapon(TMap<ESlotType, UObject*> Map);
	void GetModule(ESlotType Slot);
	void SetModule(UObject* Module);
	~WeaponConstructor();
};


