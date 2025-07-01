// Quick Drink Order System

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OSMainMenuWidget.generated.h"

class UButton;
class UWidgetSwitcher;

UCLASS()
class ORDERSYSTEM_API UOSMainMenuWidget : public UUserWidget
{
    GENERATED_BODY()

protected:
    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UButton> OpenOrderMenuButton;

    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UButton> QuitMenuButton;

    virtual void NativeOnInitialized() override;

private:
    TObjectPtr<UWidgetSwitcher> ParentSwitcher;

    UFUNCTION()
    void OnOpenOrderMenu();

    UFUNCTION()
    void OnQuitMenu();
};
