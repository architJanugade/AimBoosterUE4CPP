// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Target.h"
#include "ObjectPool.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnObject.generated.h"

UCLASS()
class AIMBOOSTERPROTOTYPE_API ASpawnObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	float GetLifeSpan();
	class UBoxComponent* SpawnVolume;
		
	UPROPERTY(EditAnywhere, Category = "Spawner")
		UObjectPool* ObjectPooler;

	UPROPERTY(EditAnywhere, Category = "Trigger")
		bool trigger;

	UPROPERTY(EditAnywhere, Category = "Spawner")
		float LifeSpan = 5.0f;

	UPROPERTY(EditAnywhere, Category = "Spawner")
		float spawnCooldown = 1.2f;

	FTimerHandle SpawnCooldownHandler;
	void Spawn();


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	FVector GetRandomPos();
	
	
};
