// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "IWeaponConstructable.h"
#include "WeaponConstructor.generated.h"

/**
 * 
 */
UCLASS()
class GOLDENEGG_API UWeaponConstructor : public UUserWidget
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Weapon Property")
	TScriptInterface<IIWeaponConstructable> ConstructingWeapon = TScriptInterface<IIWeaponConstructable>();
	TScriptInterface<IIModule>* CustomizedSlot;
public:
	void SetWeapon(UObject* Weapon);
	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void AssembleWeapon(TMap<TEnumAsByte<ESlotType>, UObject*> Map);
	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void GetModule(ESlotType SlotType);
	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void SetModule(UObject* Module);
	~UWeaponConstructor();
};
