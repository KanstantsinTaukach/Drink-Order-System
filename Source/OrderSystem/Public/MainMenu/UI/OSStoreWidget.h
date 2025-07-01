// Quick Drink Order System

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OSStoreWidget.generated.h"

class UButton;
class UWidgetSwitcher;

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
    UFUNCTION()
    void OnOpenMainMenu();
};
