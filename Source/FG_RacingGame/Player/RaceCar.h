#pragma once
#include "GameFramework\Pawn.h"
#include "RaceCar.generated.h"

class UBoxComponent;
class URaceCarMovementComponent;

UCLASS()
class ARaceCar : public APawn
{
	GENERATED_BODY()

public:
	ARaceCar();

	void SetupPlayerInputComponent(UInputComponent* InputComp) override;

	void HandleAccelerateInput(float Value);
	void HandleTurnRightInput(float Value);

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxCollision;

	UPROPERTY(VisibleAnywhere)
	URaceCarMovementComponent* MoveComp;
};