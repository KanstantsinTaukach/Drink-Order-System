// Quick Drink Order System

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OSConfirmationWidget.generated.h"

class UTextBlock;
class UButton;
class UWidgetSwitcher;

UCLASS()
class ORDERSYSTEM_API UOSConfirmationWidget : public UUserWidget
{
    GENERATED_BODY()

protected:
    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UTextBlock> OrderSummaryText;

    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UButton> BackToMenuButton;

    virtual void NativeOnInitialized() override;

private:
    FString OrderSummary;

    UPROPERTY()
    TObjectPtr<UWidgetSwitcher> ParentSwitcher;

    UFUNCTION()
    void OnBackToMenu();

public:
    void SetOrderDetails(const FString& Summary);
};
