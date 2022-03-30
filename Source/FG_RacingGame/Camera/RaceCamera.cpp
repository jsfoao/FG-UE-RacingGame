#include "RaceCamera.h"
#include "Camera/CameraComponent.h"

ARaceCamera::ARaceCamera()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(Root);
}

void ARaceCamera::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	PlayerController->SetViewTarget(this);
}

void ARaceCamera::Tick(float DeltaTime)
{
	check(FollowActor != nullptr);
	
	FVector Location = GetActorLocation();
	Location = FMath::Lerp(Location, FollowActor->GetActorLocation(), FollowSpeed * DeltaTime);

	SetActorLocation(Location);
}