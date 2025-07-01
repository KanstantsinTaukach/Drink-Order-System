// Quick Drink Order System

#include "MainMenu/UI/OSOrderMenuWidget.h"
#include "Components/CheckBox.h"
#include "Components/ComboBoxString.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "OSCoreTypes.h"

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

    if (SelectedDrinkComboBox)
    {
        SelectedDrinkComboBox->ClearOptions();

        TArray<FString> DrinkNames = UOSCoreTypes::DrinkTypesOptions();
        for (const FString& DrinkName : DrinkNames)
        {
            SelectedDrinkComboBox->AddOption(DrinkName);
        }

        SelectedDrinkComboBox->SetSelectedOption(DrinkNames[0]);
        SelectedDrinkComboBox->OnSelectionChanged.AddDynamic(this, &UOSOrderMenuWidget::OnSelectedDrinkChanged);

        OnSelectedDrinkChanged(DrinkNames[0], ESelectInfo::Direct);
    }
}

void UOSOrderMenuWidget::OnOrder() 
{
    if (ParentSwitcher)
    {
        ParentSwitcher->SetActiveWidgetIndex(3);
    }
}

void UOSOrderMenuWidget::OnBackToMenu()
{
    if (ParentSwitcher)
    {
        ParentSwitcher->SetActiveWidgetIndex(1);
    }
}

void UOSOrderMenuWidget::OnSelectedDrinkChanged(FString SelectedItem, ESelectInfo::Type SelectionType)
{
    if (SelectionType == ESelectInfo::OnMouseClick)
    {
        EDrinkType DrinkType = EDrinkType::Tea;
        for (const auto& Pair : UOSCoreTypes::GetDrinkTypes())
        {
            if (Pair.Value.Name == SelectedItem)
            {
                if (AddSugarCheckBox)
                {
                    AddSugarCheckBox->SetCheckedState(ECheckBoxState::Unchecked);
                    AddSugarCheckBox->SetIsEnabled(Pair.Value.bAllowSugar);
                }
                if (AddMilkCheckBox)
                {
                    AddMilkCheckBox->SetCheckedState(ECheckBoxState::Unchecked);
                    AddMilkCheckBox->SetIsEnabled(Pair.Value.bAllowMilk);
                }

                DrinkType = Pair.Key;
                break;
            }
        }
    }
}