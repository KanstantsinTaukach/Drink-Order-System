// Quick Drink Order System

#include "MainMenu/UI/OSMainMenuWidget.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"

void UOSMainMenuWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (OpenOrderMenuButton)
    {
        OpenOrderMenuButton->OnClicked.AddDynamic(this, &UOSMainMenuWidget::OnOpenOrderMenu);
    }

    if (QuitMenuButton)
    {
        QuitMenuButton->OnClicked.AddDynamic(this, &UOSMainMenuWidget::OnQuitMenu);
    }

    if (UWidgetSwitcher* Switcher = Cast<UWidgetSwitcher>(GetParent()))
    {
        ParentSwitcher = Switcher;
    }
}

void UOSMainMenuWidget::OnOpenOrderMenu()
{
    if (ParentSwitcher)
    {
        ParentSwitcher->SetActiveWidgetIndex(2);
    }
}

void UOSMainMenuWidget::OnQuitMenu()
{
    if (ParentSwitcher)
    {
        ParentSwitcher->SetActiveWidgetIndex(0);
    }
}