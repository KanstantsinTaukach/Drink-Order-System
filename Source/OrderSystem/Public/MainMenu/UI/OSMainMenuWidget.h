// Quick Drink Order System

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OSMainMenuWidget.generated.h"

class UButton;

UCLASS()
class ORDERSYSTEM_API UOSMainMenuWidget : public UUserWidget
{
    GENERATED_BODY()

    protected:
    UPROPERTY(meta = (BindWidget))
    UButton* OpenOrderMenuButton;

    UPROPERTY(meta = (BindWidget))
    UButton* QuitGameButton;

    virtual void NativeOnInitialized() override;

private:
    UFUNCTION()
    void OnOpenOrderMenu();

    UFUNCTION()
    void OnQuitGame();
};
