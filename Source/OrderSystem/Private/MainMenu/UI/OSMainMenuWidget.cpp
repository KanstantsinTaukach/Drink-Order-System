// Quick Drink Order System

#include "MainMenu/UI/OSMainMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void UOSMainMenuWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (OpenOrderMenuButton)
    {
        OpenOrderMenuButton->OnClicked.AddDynamic(this, &UOSMainMenuWidget::OnOpenOrderMenu);
    }

    if (QuitGameButton)
    {
        QuitGameButton->OnClicked.AddDynamic(this, &UOSMainMenuWidget::OnQuitGame);
    }
}

void UOSMainMenuWidget::OnOpenOrderMenu() 
{

}

void UOSMainMenuWidget::OnQuitGame()
{
    UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
}