// Quick Drink Order System

#include "MainMenu/UI/OSMainMenuHUD.h"
#include "Blueprint/UserWidget.h"

void AOSMainMenuHUD::BeginPlay()
{
    Super::BeginPlay();

    if (StoreWidgetClass)
    {
        const auto MenuWidget = CreateWidget<UUserWidget>(GetWorld(), StoreWidgetClass);
        if (MenuWidget)
        {
            MenuWidget->AddToViewport();
        }
    }
}