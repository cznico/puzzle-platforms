// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform() {
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay() {
	Super::BeginPlay();
	if (HasAuthority()) {
		SetReplicates(true);
		SetReplicateMovement(true);
	}

	StartLocation = GetActorLocation();	
	EndLocation = GetTransform().TransformPosition(TargetLocation);
}

void AMovingPlatform::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if (HasAuthority()) {
		FVector CurrentLocation = GetActorLocation();
		FVector Direction = EndLocation - StartLocation;
		float Distance = (EndLocation - CurrentLocation).Size();
		float Step = MovementSpeed * DeltaTime;

		if (Distance < Step) {
			CurrentLocation = EndLocation;
			EndLocation = StartLocation;
			StartLocation = CurrentLocation;
		}
		else {
			CurrentLocation += Step * Direction.GetSafeNormal();
			SetActorLocation(CurrentLocation);
		}
	}
	
}