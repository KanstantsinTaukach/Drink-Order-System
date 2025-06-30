// Quick Drink Order System

#include "MainMenu/UI/OSMainMenuHUD.h"
#include "Blueprint/UserWidget.h"

void AOSMainMenuHUD::BeginPlay()
{
    Super::BeginPlay();

    if (MenuWidgetClass)
    {
        const auto MenuWidget = CreateWidget<UUserWidget>(GetWorld(), MenuWidgetClass);
        if (MenuWidget)
        {
            MenuWidget->AddToViewport();
        }
    }
}