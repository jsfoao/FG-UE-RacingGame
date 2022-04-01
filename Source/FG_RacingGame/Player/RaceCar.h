#pragma once
#include "FG_RacingGame/Powerup/RacePowerup.h"
#include "GameFramework/Pawn.h"
#include "RaceCar.generated.h"

class UBoxComponent;
class URaceCarMovementComponent;
class URacePowerup;

UCLASS()
class ARaceCar : public APawn
{
	GENERATED_BODY()

public:
	ARaceCar();

	void BeginPlay() override;
	void Tick(float DeltaTime) override;

	void SetupPlayerInputComponent(UInputComponent* InputComp) override;

	void HandleAccelerateInput(float Value);
	void HandleTurnRightInput(float Value);
	void HandleActivatePowerup();

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxCollision;

	UPROPERTY(VisibleAnywhere)
	URaceCarMovementComponent* MoveComp;

	// Pointers to UObject assumes it's an asset
	// This is why URacePowerup* won't work
	UPROPERTY(EditAnywhere)
	TSubclassOf<URacePowerup> PowerupClass;

	UPROPERTY()
	URacePowerup* Powerup;
};