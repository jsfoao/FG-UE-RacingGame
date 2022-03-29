#include "RaceCar.h"
#include "Components/BoxComponent.h"
#include "RaceCarMovementComponent.h"

ARaceCar::ARaceCar()
{
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	RootComponent = BoxCollision;

	MoveComp = CreateDefaultSubobject<URaceCarMovementComponent>(TEXT("Movement Component"));
}

void ARaceCar::SetupPlayerInputComponent(UInputComponent* InputComp)
{
	InputComp->BindAxis(TEXT("Accelerate"), this, &ARaceCar::HandleAccelerateInput);
	InputComp->BindAxis(TEXT("TurnRight"), this, &ARaceCar::HandleTurnRightInput);
}

void ARaceCar::HandleAccelerateInput(float Value) 
{
	GEngine->AddOnScreenDebugMessage(
		INDEX_NONE,
		0.f,
		FColor::White,
		FString::Printf(TEXT("Accelerate: %f"), Value)
	);
}

void ARaceCar::HandleTurnRightInput(float Value)
{
	GEngine->AddOnScreenDebugMessage(
		INDEX_NONE,
		0.f,
		FColor::White,
		FString::Printf(TEXT("Turn Right: %f"), Value)
	);
}

