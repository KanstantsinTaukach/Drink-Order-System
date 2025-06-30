// Quick Drink Order System

#include "MainMenu/OSMainMenuGameModeBase.h"
#include "MainMenu/OSMainMenuPlayerController.h"
#include "MainMenu/UI/OSMainMenuHUD.h"

AOSMainMenuGameModeBase::AOSMainMenuGameModeBase() 
{
    PlayerControllerClass = AOSMainMenuPlayerController::StaticClass();
    HUDClass = AOSMainMenuHUD::StaticClass();
}
