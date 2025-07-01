// Quick Drink Order System

#include "MainMenu/UI/OSStoreWidget.h"
#include "Components/WidgetSwitcher.h"
#include "Components/Button.h"
#include "MainMenu/UI/OSConfirmationWidget.h"
#include "MainMenu/UI/OSOrderMenuWidget.h"
#include "MainMenu/UI/OSMainMenuWidget.h"


void UOSStoreWidget::NativeOnInitialized() 
{
    Super::NativeOnInitialized();

    if (OpenMainMenuButton)
    {
        OpenMainMenuButton->OnClicked.AddDynamic(this, &UOSStoreWidget::OnOpenMainMenu);
    }

    if (OrderMenuWidget)
    {
        OrderMenuWidget->OnOrderConfirmed.AddDynamic(this, &UOSStoreWidget::HandleOrderConfirmed);
    }
}

void UOSStoreWidget::OnOpenMainMenu() 
{
    if (MenuSwitcher)
    {
        MenuSwitcher->SetActiveWidgetIndex(1);
    }
}

void UOSStoreWidget::HandleOrderConfirmed(const FString& Summary)
{
    if (ConfirmationWidget)
    {
        ConfirmationWidget->SetOrderDetails(Summary);
        MenuSwitcher->SetActiveWidgetIndex(3);
    }
}
