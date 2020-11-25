#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Kismet/GameplayStatics.h"
#include "Avatar.h"
#include "Runtime/Engine/Classes/Engine/Texture2D.h"
#include "Runtime/Engine/Public/CanvasItem.h"
#include "Runtime/Engine/Classes/Engine/Canvas.h"
#include "MyHUD.generated.h"


struct Message //структура для вывода сообщений игроку
{
	FString message;
	float time;
	FColor color;
	UTexture2D *tex;

	Message()
	{
		time = 5.f;
		color = FColor::White;
	}
	Message(FString iMessage, float iTime, FColor iColor)
	{
		message = iMessage;
		time = iTime;
		color = iColor;
	}
};

UCLASS()
class GOLDENEGG_API AMyHUD : public AHUD
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = HUDFont)
		UTexture2D* CrosshairTexture;

public:
	//Задание шрифта испльзуемого при отображении информации 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUDFont)
		UFont* hudFont;

	TArray<Message> messages;
	//Функция отображения худа
	virtual void DrawHUD() override;
	//Функция для добавления сообщений для отображения
	void addMessage(Message msg);
	//Отображение оставшегося здоровья игрока
	void DrawHealthBar();
};
