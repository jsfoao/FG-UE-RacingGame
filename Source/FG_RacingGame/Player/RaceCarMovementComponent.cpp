#include "RaceCarMovementComponent.h"

URaceCarMovementComponent::URaceCarMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	Speed = 100.f;
	TurnRate = 10.f;
}

void URaceCarMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Accelerate(DeltaTime);
	Turn(DeltaTime);
}

void URaceCarMovementComponent::Accelerate(float DeltaTime)
{
	AActor* Owner = GetOwner();
	FVector Vec = Owner->GetRootComponent()->GetForwardVector();
	GetOwner()->AddActorWorldOffset(Vec * Speed * DeltaTime * AccelDirection);
}

void URaceCarMovementComponent::Turn(float DeltaTime)
{
	AActor* Owner = GetOwner();
	FRotator Rotator = Owner->GetActorRotation();
	FRotator NewRotator = FRotator(0.f, TurnRate * TurnDirection * DeltaTime, 0.f);
	Owner->SetActorRotation(Rotator + NewRotator);
}


void URaceCarMovementComponent::SetAccelDirection(float Value)
{
	AccelDirection = Value;
}

void URaceCarMovementComponent::SetTurnDirection(float Value)
{
	TurnDirection = Value;
}

//
// void URaceCarMovementComponent::Turn(float Value)
// {
// 	
// }
