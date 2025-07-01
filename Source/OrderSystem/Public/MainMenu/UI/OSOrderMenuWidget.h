// Quick Drink Order System

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OSCoreTypes.h"
#include "OSOrderMenuWidget.generated.h"

class UComboBoxString;
class UCheckBox;
class UButton;
class UWidgetSwitcher;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnOrderConfirmedSignature, const FString&, OrderSummary);

UCLASS()
class ORDERSYSTEM_API UOSOrderMenuWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable)
    FOnOrderConfirmedSignature OnOrderConfirmed;

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
    UPROPERTY()
    TObjectPtr<UWidgetSwitcher> ParentSwitcher;

    UFUNCTION()
    void OnOrder();

    UFUNCTION()
    void OnBackToMenu();

    UFUNCTION()
    void OnSelectedDrinkChanged(FString SelectedItem, ESelectInfo::Type SelectionType);
};
