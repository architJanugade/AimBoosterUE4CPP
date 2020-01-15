// Fill out your copyright notice in the Description page of Project Settings.

#include "ObjectPool.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/Actor.h"
#include "Engine/Engine.h"

// Sets default values for this component's properties
UObjectPool::UObjectPool()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


ATarget* UObjectPool::GetPooledObject()
{
	for (ATarget* poolableActor : Targets)
	{
		if (!poolableActor->isActive())
			return poolableActor;
		
	}
	return nullptr;
}

// Called when the game starts
void UObjectPool::BeginPlay()
{
	Super::BeginPlay();
	if (PooledObjectSubclass != NULL)
	{
		UWorld* const world = GetWorld();
		if (world)
		{
			for (int i = 0; i < 100; i++)
			{
				ATarget* poolableActor= GetWorld()->SpawnActor<ATarget>(PooledObjectSubclass, FVector().ZeroVector, FRotator().ZeroRotator);
				poolableActor->SetActive(false);
				Targets.Add(poolableActor);
			}
		}
	}
	// ...
	
}


// Called every frame
void UObjectPool::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

