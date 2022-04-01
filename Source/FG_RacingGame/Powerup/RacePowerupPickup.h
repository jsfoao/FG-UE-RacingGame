#pragma once

#include "CoreMinimal.h"
#include "RacePowerup.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "RacePowerupPickup.generated.h"

class USphereComponent;

UCLASS()
class FG_RACINGGAME_API ARacePowerupPickup : public AActor
{
	GENERATED_BODY()

public:
	ARacePowerupPickup();
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
protected:
	virtual void BeginPlay() override;
	
public:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;
	
	UPROPERTY(VisibleAnywhere)
	USphereComponent* Sphere;

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<URacePowerup>> PowerupClasses;
};
