// Quick Drink Order System

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "OSMainMenuPlayerController.generated.h"

UCLASS()
class ORDERSYSTEM_API AOSMainMenuPlayerController : public APlayerController
{
    GENERATED_BODY()

protected:
    virtual void BeginPlay() override;
};
