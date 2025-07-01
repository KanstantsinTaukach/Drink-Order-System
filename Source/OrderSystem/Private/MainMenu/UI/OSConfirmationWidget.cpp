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

    if (OrderSummaryText && !OrderSummary.IsEmpty())
    {
        OrderSummaryText->SetText(FText::FromString(OrderSummary));
    }
}

void UOSConfirmationWidget::OnBackToMenu()
{
    if (ParentSwitcher)
    {
        ParentSwitcher->SetActiveWidgetIndex(1);
    }
}

void UOSConfirmationWidget::SetOrderDetails(const FString& Summary)
{
    OrderSummary = Summary;

    if (OrderSummaryText)
    {
        OrderSummaryText->SetText(FText::FromString(Summary));
    }
}