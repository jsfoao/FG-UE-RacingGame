#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RacePowerup.generated.h"

UCLASS(Blueprintable)
class FG_RACINGGAME_API URacePowerup : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPowerupActivated();
};
