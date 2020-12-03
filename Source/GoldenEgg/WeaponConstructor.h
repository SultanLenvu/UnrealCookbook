// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WidgetBlueprint.h"
#include "IWeaponConstructable.h"
#include "IModule.h"
#include "WeaponConstructor.generated.h"

/**
 * 
 */
UCLASS()
class GOLDENEGG_API UWeaponConstructor : public UWidgetBlueprint
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Weapon Property")
	TScriptInterface<IIWeaponConstructable> ConstructingWeapon;
	TScriptInterface<IIModule>* CustomizedSlot;
public:
	UWeaponConstructor();
	explicit UWeaponConstructor(UObject* Weapon);
	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	void AssembleWeapon(TMap<TEnumAsByte<ESlotType>, UObject*> Map);
	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	void GetModule(ESlotType Slot);
	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	void SetModule(UObject* Module);
	~UWeaponConstructor();
};
