// Quick Drink Order System

#include "MainMenu/UI/OSOrderMenuWidget.h"
#include "Components/CheckBox.h"
#include "Components/ComboBoxString.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"

void UOSOrderMenuWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (OrderButton)
    {
        OrderButton->OnClicked.AddDynamic(this, &UOSOrderMenuWidget::OnOrder);
    }

    if (BackToMenuButton)
    {
        BackToMenuButton->OnClicked.AddDynamic(this, &UOSOrderMenuWidget::OnBackToMenu);
    }

    if (UWidgetSwitcher* Switcher = Cast<UWidgetSwitcher>(GetParent()))
    {
        ParentSwitcher = Switcher;
    }
}

void UOSOrderMenuWidget::OnOrder() 
{

}

void UOSOrderMenuWidget::OnBackToMenu()
{
    if (ParentSwitcher)
    {
        ParentSwitcher->SetActiveWidgetIndex(1);
    }
}