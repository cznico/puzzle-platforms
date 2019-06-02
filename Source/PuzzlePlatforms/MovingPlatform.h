// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	int ActiveTriggers = 1;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Setup)
	float MovementSpeed = 10.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Setup, Meta = (MakeEditWidget = true))
	FVector TargetLocation;
	FVector StartLocation;
	FVector EndLocation;
public:
	AMovingPlatform();

	void AddActiveTrigger();
	void RemoveActiveTrigger();

protected:	
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
};
