// Quick Drink Order System

#include "MainMenu/OSMainMenuPlayerController.h"

void AOSMainMenuPlayerController::BeginPlay() 
{
    Super::BeginPlay();

    SetInputMode(FInputModeUIOnly());
    bShowMouseCursor = true;
}
