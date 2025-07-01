// Quick Drink Order System

#include "MainMenu/UI/OSStoreWidget.h"
#include "Components/WidgetSwitcher.h"
#include "Components/Button.h"

void UOSStoreWidget::NativeOnInitialized() 
{
    if (OpenMainMenuButton)
    {
        OpenMainMenuButton->OnClicked.AddDynamic(this, &UOSStoreWidget::OnOpenMainMenu);
    }
}

void UOSStoreWidget::OnOpenMainMenu() 
{
    if (MenuSwitcher)
    {
        MenuSwitcher->SetActiveWidgetIndex(1);
    }
}