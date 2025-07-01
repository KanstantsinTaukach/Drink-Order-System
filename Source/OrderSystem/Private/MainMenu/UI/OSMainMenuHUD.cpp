// Quick Drink Order System

#include "MainMenu/UI/OSMainMenuHUD.h"
#include "MainMenu/UI/OSStoreWidget.h"

void AOSMainMenuHUD::BeginPlay()
{
    Super::BeginPlay();

    if (StoreWidgetClass)
    {
        StoreWidget = CreateWidget<UOSStoreWidget>(GetWorld(), StoreWidgetClass);
        if (StoreWidget)
        {
            StoreWidget->AddToViewport();
        }
    }
}