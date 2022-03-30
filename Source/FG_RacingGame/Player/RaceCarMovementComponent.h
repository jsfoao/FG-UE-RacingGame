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

	void Accelerate(float DeltaTime);
	void Turn(float DeltaTime);
	
	UPROPERTY(EditAnywhere, Category = "Driving")
	float Acceleration = 500.f;

	UPROPERTY(EditAnywhere, Category = "Driving")
	float TurnSpeed = 180.f;

	UPROPERTY(EditAnywhere, Category = "Driving")
	float RollFriction = 1.8f;
	
	UPROPERTY(EditAnywhere, Category = "Driving")
	float GripFriction = 3.8f;

	FVector Velocity = FVector::ZeroVector;

	float AccelInput = 0.f;
	float TurnInput = 0.f;
};