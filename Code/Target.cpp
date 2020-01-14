#include "Target.h"
#include "Engine/Engine.h"
#include<time.h>

// Sets default values
ATarget::ATarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATarget::BeginPlay()
{
	Super::BeginPlay();
	RandX = GetActorLocation().X;
	RandY = GetActorLocation().Y;
	RandZ = GetActorLocation().Z;
	//GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &ATimeActor::RepeatingFunc , 2.0f ,	true , 2.0f);
	srand(time(0));
}

// Called every frame
void ATarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	newLocation = FVector(RandX, RandY, RandZ);
	SetActorLocation(newLocation, false, 0, ETeleportType::None);
}

void ATarget::ChangePos()
{
	RandX = FMath::FRandRange(-850, 1560);
	RandZ = FMath::FRandRange(220, 720);
	RandY = FMath::FRandRange(-630, 1800);
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("RandZ: %f"), RandZ));
}
