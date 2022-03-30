#include "RaceCarMovementComponent.h"

#include "DrawDebugHelpers.h"

void DebugScreenMessage(FString str)
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE,0.f,FColor::White, str);
}

URaceCarMovementComponent::URaceCarMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	Acceleration = 100.f;
	TurnSpeed = 10.f;
}

void URaceCarMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Accelerate(DeltaTime);
	Turn(DeltaTime);
}

void URaceCarMovementComponent::Accelerate(float DeltaTime)
{
	AActor* Owner = GetOwner();
	FVector ForwardVec = Owner->GetActorForwardVector();
	FVector Location = Owner->GetActorLocation();
	
	// Apply acceleration
	Velocity += ForwardVec * Acceleration * AccelInput * DeltaTime;

	// Apply friction (Acceleration friction)
	FVector RollingVelocity = Velocity.ProjectOnTo(ForwardVec);
	FVector GripVelocity = Velocity - RollingVelocity;

	RollingVelocity -= RollingVelocity * RollFriction * DeltaTime;
	GripVelocity -= GripVelocity * GripFriction * DeltaTime;

	Velocity = RollingVelocity + GripVelocity;

	// Apply movement
	// Collision handling big 3
	//		Iterative Collision Solving
	//		Redirection
	//		Depenetration
	float RemainingTime = DeltaTime;
	while (RemainingTime > 0.f)
	{
		FHitResult Hit;
		Owner->AddActorWorldOffset(Velocity * RemainingTime, true, &Hit);
		
		// Hit something
		if (Hit.bBlockingHit)
		{
			// Depenetration
			if (Hit.bStartPenetrating)
			{
				Owner->AddActorWorldOffset(Hit.Normal * (Hit.PenetrationDepth + 32.f));
			}
			// Otherwise, just redirect and keep going
			else
			{
				Velocity = FVector::VectorPlaneProject(Velocity, Hit.Normal);
				RemainingTime -= RemainingTime * Hit.Time;	
			}
		}
		else
		{
			break;
		}
	}
	float Speed = Velocity.Size();

	UE_LOG(LogTemp, Display, TEXT("Hello"));
	DebugScreenMessage(FString::Printf(TEXT("Rolling Vel: %f"), RollingVelocity.Size()));
	DebugScreenMessage(FString::Printf(TEXT("Velocity: %f"), RollingVelocity.Size()));
	DrawDebugLine(GetWorld(), Location, Location + RollingVelocity, FColor::Red);
	DrawDebugLine(GetWorld(), Location, Location + GripVelocity, FColor::Blue);
}

void URaceCarMovementComponent::Turn(float DeltaTime)
{
	AActor* Owner = GetOwner();
	Owner->AddActorWorldRotation(FRotator(0.f, TurnSpeed * TurnInput * DeltaTime, 0.f));
}