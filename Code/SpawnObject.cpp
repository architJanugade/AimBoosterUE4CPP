// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnObject.h"
#include"Kismet/KismetMathLibrary.h"
#include"Kismet/GameplayStatics.h"
#include"Components/BoxComponent.h"
#include "GameFramework/Character.h"
#include "Engine.h"

// Sets default values
ASpawnObject::ASpawnObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpawnVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("Spawn Volume"));
	RootComponent = SpawnVolume;
	ObjectPooler = CreateDefaultSubobject<UObjectPool>(TEXT("Object Pooler"));


}

// Called when the game starts or when spawned
void ASpawnObject::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(SpawnCooldownHandler , this , &ASpawnObject::Spawn , spawnCooldown ,  false);
}

float ASpawnObject::GetLifeSpan()
{
	return LifeSpan;
}

void ASpawnObject::Spawn()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, FString::Printf(TEXT("Spawn")));
	ATarget* poolableActor = ObjectPooler->GetPooledObject();
	if (poolableActor == nullptr) {
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, FString::Printf(TEXT("CannotSpawn")));
		GetWorldTimerManager().SetTimer(SpawnCooldownHandler, this, &ASpawnObject::Spawn, spawnCooldown, false);
		return;
	}
	
	poolableActor->SetActorLocation(GetRandomPos());
	poolableActor->SetLifeSpan(LifeSpan);
	poolableActor->SetActive(true);
	GetWorldTimerManager().SetTimer(SpawnCooldownHandler, this, &ASpawnObject::Spawn, spawnCooldown, false);

}

// Called every frame
void ASpawnObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector ASpawnObject::GetRandomPos()
{
	float RandX = FMath::FRandRange(-800, 1560);
	float RandZ = FMath::FRandRange(230, 720);
	float RandY = FMath::FRandRange(-660, 1800);
	return FVector(RandX , RandY , RandZ);
}

