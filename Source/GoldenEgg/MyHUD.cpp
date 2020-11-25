// Fill out your copyright notice in the Description page of Project Settings.

#include "MyHUD.h"


void AMyHUD::DrawHUD()
{
	Super::DrawHUD();
	//итерацию выполняем задом наперед, так что, если мы удаляем пункт во время итерации,
	//то не возникает проблем
	for (int c = messages.Num() - 1; c >= 0; c--)
	{
		//изображаем новое окно для сообщения нужного размера
		float outputWidth, outputHeight, pad = 10.f;
		GetTextSize(messages[c].message, outputWidth, outputHeight, hudFont, 1.f);
		float messageH = outputHeight + 2.f * pad;
		float messageW = outputWidth + 2.f * pad;
		float x = 0.f, y = c * messageH;

		//черный фон
		DrawRect(FLinearColor::Yellow, x, y, Canvas->SizeX, messageH);
		//Отображаем сообщение используя hudFont
		DrawText(messages[c].message, messages[c].color, x + pad, y + pad, hudFont);
		//сокращаем время отображения на время прошедшее с последнего кадра
		messages[c].time -= GetWorld()->GetDeltaSeconds();
		//если время сообщения вышло, то удаляем его
		if (messages[c].time < 0)
		{
			messages.RemoveAt(c);
		}
	}
	//отрисовка прицела
	if (CrosshairTexture)
	{
		FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);
		FVector2D CrossHairDrawPosition(Center.X - (CrosshairTexture->GetSurfaceWidth() * 0.5f), Center.Y - (CrosshairTexture->GetSurfaceHeight()*0.5f));

		FCanvasTileItem TileItem(CrossHairDrawPosition, CrosshairTexture->Resource, FLinearColor::White);
		TileItem.BlendMode = SE_BLEND_Translucent;
		Canvas->DrawItem(TileItem);
	}
	//отрисовываем полоску здоровья
	DrawHealthBar();
}

//добавление сообщений на худ
void AMyHUD::addMessage(Message msg)
{
	messages.Add(msg);
}

void AMyHUD::DrawHealthBar()
{
	//изображаем полосу здоровья
	AAvatar *avatar = Cast<AAvatar>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	float barWidth = 200, barHeight = 50, barPad = 12, barMargin = 50;
	float percHp = avatar->Hp / avatar->MaxHp;
	DrawRect(FLinearColor(0, 0, 0, 1), Canvas->SizeX - barWidth - barPad - barMargin, 
		Canvas->SizeY - barHeight - barPad - barMargin, barWidth + 2 * barWidth, barHeight + 2 * barPad);
	DrawRect(FLinearColor(1 - percHp, percHp, 0, 1), Canvas->SizeX - barWidth - barMargin,
		Canvas->SizeY - barHeight - barMargin, barWidth * percHp, barHeight);
}