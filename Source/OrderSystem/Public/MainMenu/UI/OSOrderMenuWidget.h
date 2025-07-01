// Quick Drink Order System

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OSOrderMenuWidget.generated.h"

class UComboBoxString;
class UCheckBox;
class UButton;
class UWidgetSwitcher;

UCLASS()
class ORDERSYSTEM_API UOSOrderMenuWidget : public UUserWidget
{
    GENERATED_BODY()

protected:
    UPROPERTY(meta = (BindWidget))
    UComboBoxString* SelectedDrinkComboBox;

    UPROPERTY(meta = (BindWidget))
    UCheckBox* AddSugarCheckBox;

    UPROPERTY(meta = (BindWidget))
    UCheckBox* AddMilkCheckBox;

    UPROPERTY(meta = (BindWidget))
    UButton* OrderButton;

    UPROPERTY(meta = (BindWidget))
    UButton* BackToMenuButton;

    virtual void NativeOnInitialized() override;

private:
    UWidgetSwitcher* ParentSwitcher;

    UFUNCTION()
    void OnOrder();

    UFUNCTION()
    void OnBackToMenu();
};
