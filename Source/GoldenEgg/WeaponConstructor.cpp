// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponConstructor.h"

// Fill out your copyright notice in the Description page of Project Settings.

UWeaponConstructor::UWeaponConstructor()
{
	ConstructingWeapon = nullptr;
	CustomizedSlot = nullptr;
}

UWeaponConstructor::UWeaponConstructor(UObject* Weapon)
{
	bool bIsNesting = Weapon->GetClass()->ImplementsInterface(UIWeaponConstructable::StaticClass());
	if (bIsNesting)
	{
		ConstructingWeapon.SetObject(Weapon);
		ConstructingWeapon.SetInterface(Cast<IIWeaponConstructable>(Weapon));
	}
	CustomizedSlot = nullptr;
}

/*void UWeaponConstructor::AssembleWeapon(TMap<ESlotType, UObject*> Map)
{
	for (auto It = Map.CreateConstIterator(); It; ++It)
	{
		GetModule(It.Key());
		SetModule(It.Value());
	}
}*/

void UWeaponConstructor::GetModule(const ESlotType Slot)
{
	switch (Slot)
	{
	case Muzzle:
		CustomizedSlot = ConstructingWeapon->GetMuzzel();
		break;
	case ForeGrip:
		CustomizedSlot = ConstructingWeapon->GetForeGrip();
		break;
	case Magazine:
		CustomizedSlot = ConstructingWeapon->GetMagazine();
		break;
	case Grip:
		CustomizedSlot = ConstructingWeapon->GetGrip();
		break;
	case Frame:
		CustomizedSlot = ConstructingWeapon->GetFrame();
		break;
	case Stock:
		CustomizedSlot = ConstructingWeapon->GetStock();
		break;
	case Bullet:
		CustomizedSlot = ConstructingWeapon->GetBullet();
		break;
	case Kit:
		CustomizedSlot = ConstructingWeapon->GetKit();
		break;
	case GunPoint:
		CustomizedSlot = ConstructingWeapon->GetGunPoint();
		break;
	default:
		break;
	}
}

void UWeaponConstructor::SetModule(UObject* Module)
{
	bool bIsNesting = Module->GetClass()->ImplementsInterface(UIModule::StaticClass());
	if (bIsNesting)
	{
		if (CustomizedSlot)
		{
			CustomizedSlot->operator->()->Execute_ResetVisual(CustomizedSlot->GetObject());	
			CustomizedSlot->operator->()->Execute_ResetStats(CustomizedSlot->GetObject(),
				ConstructingWeapon->GetWeaponStats());
		}
		ConstructingWeapon->SetModule(Module);
		CustomizedSlot->SetObject(Module);
		CustomizedSlot->SetInterface(Cast<IIModule>(Module));
	}
	
}

UWeaponConstructor::~UWeaponConstructor()
{
	ConstructingWeapon = nullptr;
	CustomizedSlot = nullptr;
}
