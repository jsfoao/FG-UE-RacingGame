#include "RacePowerupPickup.h"
#include "FG_RacingGame/Player/RaceCar.h"


ARacePowerupPickup::ARacePowerupPickup()
{
	PrimaryActorTick.bCanEverTick = true;
	
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ARacePowerupPickup::HandleOverlap);

	Sphere->SetupAttachment(Root);
}

void ARacePowerupPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARacePowerupPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARacePowerupPickup::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	int RandomIndex = FMath::RandRange(0, PowerupClasses.Num() - 1);
	auto PowerupClass = PowerupClasses[RandomIndex];
	
	ARaceCar* Car = Cast<ARaceCar>(OtherActor);
	Car->Powerup = NewObject<URacePowerup>(Car, PowerupClass);
	Destroy();
}