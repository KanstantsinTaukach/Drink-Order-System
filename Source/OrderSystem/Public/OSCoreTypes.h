// Quick Drink Order System

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "OSCoreTypes.generated.h"

UENUM(BlueprintType)
enum class EDrinkType : uint8
{
    Tea UMETA(DisplayName = "Tea"),
    Coffee UMETA(DisplayName = "Coffee"),
    Juice UMETA(DisplayName = "Juice")
};

USTRUCT(BlueprintType)
struct FDrinkProperties
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly)
    FString Name;

    UPROPERTY(BlueprintReadOnly)
    bool bAllowSugar;

    UPROPERTY(BlueprintReadOnly)
    bool bAllowMilk;
};

UCLASS()
class ORDERSYSTEM_API UOSCoreTypes : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

private:
    inline static const TMap<EDrinkType, FDrinkProperties> DrinkTypes =  //
        {
            {EDrinkType::Tea, {"Tea", true, true}},        //
            {EDrinkType::Coffee, {"Coffee", true, true}},  //
            {EDrinkType::Juice, {"Juice", false, false}}   //
        };

public:
    UFUNCTION()
    static TArray<FString> DrinkTypesOptions()
    {
        TArray<FString> Result;
        for (const auto& DrinkType : DrinkTypes)
        {
            Result.Add(DrinkType.Value.Name);
        }

        return Result;
    };

    UFUNCTION()
    static TMap<EDrinkType, FDrinkProperties> GetDrinkTypes() { return DrinkTypes; };
};
