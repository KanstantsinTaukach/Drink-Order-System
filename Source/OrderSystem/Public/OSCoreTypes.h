// Quick Drink Order System

#pragma once

UENUM(BlueprintType)
enum class EDrinkType : uint8
{
    Tea UMETA(DisplayName = "Tea"),
    Coffee UMETA(DisplayName = "Coffee"),
    Juice UMETA(DisplayName = "Juice")
};