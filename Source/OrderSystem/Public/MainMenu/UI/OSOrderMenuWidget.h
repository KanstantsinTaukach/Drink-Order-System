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
    TObjectPtr<UComboBoxString> SelectedDrinkComboBox;

    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UCheckBox> AddSugarCheckBox;

    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UCheckBox> AddMilkCheckBox;

    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UButton> OrderButton;

    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UButton> BackToMenuButton;

    virtual void NativeOnInitialized() override;

private:
    TObjectPtr<UWidgetSwitcher> ParentSwitcher;

    UFUNCTION()
    void OnOrder();

    UFUNCTION()
    void OnBackToMenu();
};
