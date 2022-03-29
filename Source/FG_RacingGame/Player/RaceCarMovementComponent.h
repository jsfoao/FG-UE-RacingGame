#pragma once
#include "Components/ActorComponent.h"
#include "RaceCarMovementComponent.generated.h"

UCLASS(Meta = (BlueprintSpawnableComponent))
class URaceCarMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	URaceCarMovementComponent();
	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};