// Fill out your copyright notice in the Description page of Project Settings.

#include "Target.h"
#include "Engine/Engine.h"
#include<time.h>
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/Actor.h"

// Sets default values
ATarget::ATarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//SetActorEnableCollision(true);
}

// Called when the game starts or when spawned
void ATarget::BeginPlay()
{
	Super::BeginPlay();
	//GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &ATimeActor::RepeatingFunc , 2.0f ,	true , 2.0f);
}

// Called every frame
void ATarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void ATarget::SetLifeSpan(float InlifeSpan)
{
	Lifespan = InlifeSpan;
	GetWorldTimerManager().SetTimer(lifeSpanTimer, this, &ATarget::Deactivate, Lifespan, false);
}

void ATarget::SetActive(bool InActive)
{
	Active = InActive;
	SetActorHiddenInGame(!InActive);
}

bool ATarget::isActive()
{
	return Active;

}
void ATarget::Deactivate()
{
	SetActive(false);
}