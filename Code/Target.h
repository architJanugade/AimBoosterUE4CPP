// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Target.generated.h"

UCLASS()
class AIMBOOSTERPROTOTYPE_API ATarget : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATarget();
	virtual void SetLifeSpan(float InlifeSpan) override;
	void SetActive(bool InActive);
	bool isActive();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float Lifespan = 5.0f;
	FTimerHandle lifeSpanTimer;
	bool Active;
	void Deactivate();
	
};
