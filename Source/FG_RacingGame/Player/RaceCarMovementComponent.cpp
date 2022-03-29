#include "RaceCarMovementComponent.h"

URaceCarMovementComponent::URaceCarMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void URaceCarMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	AActor* Owner = GetOwner();
	Owner->AddActorWorldOffset(FVector::ForwardVector * 100.f * DeltaTime);
}