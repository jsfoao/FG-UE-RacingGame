#pragma once
#include "Components/ActorComponent.h"
#include "RaceCarMovementComponent.generated.h"

UCLASS(Meta = (BlueprintSpawnableComponent))
class URaceCarMovementComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	float AccelDirection;
	float TurnDirection;

public:
	URaceCarMovementComponent();
	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Accelerate(float DeltaTime);
	void Turn(float DeltaTime);

	void SetAccelDirection(float Value);
	void SetTurnDirection(float Value);
	
	UPROPERTY(EditAnywhere)
	float Speed;

	UPROPERTY(EditAnywhere)
	float TurnRate;
};