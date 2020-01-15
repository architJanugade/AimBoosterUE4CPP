// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Target.h"
#include "Components/ActorComponent.h"
#include "ObjectPool.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AIMBOOSTERPROTOTYPE_API UObjectPool : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UObjectPool();
	ATarget* GetPooledObject();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UPROPERTY(EditAnywhere , Category = "ObjectPooler")
		TSubclassOf<class ATarget> PooledObjectSubclass;
	UPROPERTY(EditAnywhere, Category = "ObjectPooler")
		int PoolSize = 100;
	TArray<ATarget*> Targets;

};
