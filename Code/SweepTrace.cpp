// Fill out your copyright notice in the Description page of Project Settings.

#include "SweepTrace.h"
#include "DrawDebugHelpers.h"

// Sets default values
ASweepTrace::ASweepTrace()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASweepTrace::BeginPlay()
{
	Super::BeginPlay();
	TArray<FHitResult> hitResults;
	FVector actorLocation = GetActorLocation();
	FCollisionShape myColSphere = FCollisionShape::MakeSphere(500.f);
	DrawDebugSphere(GetWorld(), actorLocation, myColSphere.GetSphereRadius(), 100, FColor::Purple, true, 1000);
	bool isHit = GetWorld()->SweepMultiByChannel(hitResults, actorLocation, actorLocation, FQuat::Identity, ECC_WorldStatic, myColSphere);
	if (isHit)
	{
		for (auto& Hit : hitResults)
		{
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, FString::Printf(TEXT("Hit Result: %s"), *Hit.Actor->GetName()));
			}
		}
	}
}

// Called every frame
void ASweepTrace::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

