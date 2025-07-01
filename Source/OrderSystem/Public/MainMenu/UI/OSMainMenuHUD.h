// Quick Drink Order System

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "OSMainMenuHUD.generated.h"

class UOSStoreWidget;

UCLASS()
class ORDERSYSTEM_API AOSMainMenuHUD : public AHUD
{
    GENERATED_BODY()

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UOSStoreWidget> StoreWidgetClass;

    virtual void BeginPlay() override;

private:
    TObjectPtr<UOSStoreWidget> StoreWidget;
};
