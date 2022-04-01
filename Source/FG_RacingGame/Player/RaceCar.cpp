#include "RaceCar.h"
#include "Components/BoxComponent.h"
#include "RaceCarMovementComponent.h"

ARaceCar::ARaceCar()
{
	PrimaryActorTick.bCanEverTick = true;
	
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	BoxCollision->SetCollisionProfileName("BlockAllDynamic");
	RootComponent = BoxCollision;

	MoveComp = CreateDefaultSubobject<URaceCarMovementComponent>(TEXT("Movement Component"));
}

void ARaceCar::Tick(float DeltaTime)
{
	if (Powerup != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(
			INDEX_NONE,
			.0f,
			FColor::Emerald,
			Powerup->GetClass()->GetName()
			);
	}
}


void ARaceCar::BeginPlay()
{
	Super::BeginPlay();

	// kinda like new keyword but for UObjects
	Powerup = NewObject<URacePowerup>(this, PowerupClass);
}

void ARaceCar::SetupPlayerInputComponent(UInputComponent* InputComp)
{
	InputComp->BindAxis(TEXT("Accelerate"), this, &ARaceCar::HandleAccelerateInput);
	InputComp->BindAxis(TEXT("TurnRight"), this, &ARaceCar::HandleTurnRightInput);
	InputComp->BindAction(TEXT("ActivatePowerup"), IE_Pressed, this, &ARaceCar::HandleActivatePowerup);
}

void ARaceCar::HandleActivatePowerup()
{
	Powerup->OnPowerupActivated();
}


void ARaceCar::HandleAccelerateInput(float Value) 
{
	GEngine->AddOnScreenDebugMessage(
		INDEX_NONE,
		0.f,
		FColor::White,
		FString::Printf(TEXT("Accelerate: %f"), Value)
	);

	MoveComp->AccelInput = Value;
}

void ARaceCar::HandleTurnRightInput(float Value)
{
	GEngine->AddOnScreenDebugMessage(
		INDEX_NONE,
		0.f,
		FColor::White,
		FString::Printf(TEXT("Turn Right: %f"), Value)
	);

	MoveComp->TurnInput = Value;
}

