// Quick Drink Order System

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OSCoreTypes.h"
#include "OSStoreWidget.generated.h"

class UButton;
class UWidgetSwitcher;
class UOSConfirmationWidget;
class UOSOrderMenuWidget;
class UOSMainMenuWidget;

UCLASS()
class ORDERSYSTEM_API UOSStoreWidget : public UUserWidget
{
    GENERATED_BODY()

protected:
    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UWidgetSwitcher> MenuSwitcher;

    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UButton> OpenMainMenuButton;

    virtual void NativeOnInitialized() override;

private:
    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UOSMainMenuWidget> MainMenuWidget;

    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UOSOrderMenuWidget> OrderMenuWidget;

    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UOSConfirmationWidget> ConfirmationWidget;

    UFUNCTION()
    void OnOpenMainMenu();

    UFUNCTION()
    void HandleOrderConfirmed(const FString& Summary);
};
