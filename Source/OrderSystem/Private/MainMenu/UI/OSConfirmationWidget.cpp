// Quick Drink Order System

#include "MainMenu/UI/OSConfirmationWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/WidgetSwitcher.h"
#include "OSCoreTypes.h"

void UOSConfirmationWidget::NativeOnInitialized() 
{
    if (BackToMenuButton)
    {
        BackToMenuButton->OnClicked.AddDynamic(this, &UOSConfirmationWidget::OnBackToMenu);
    }

    if (UWidgetSwitcher* Switcher = Cast<UWidgetSwitcher>(GetParent()))
    {
        ParentSwitcher = Switcher;
    }
}

void UOSConfirmationWidget::OnBackToMenu()
{
    if (ParentSwitcher)
    {
        ParentSwitcher->SetActiveWidgetIndex(1);
    }
}