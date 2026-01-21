// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class TASK06_API AMovingPlatform : public AActor
{
	GENERATED_BODY()

public:
	AMovingPlatform();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Platform|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Value")
	float MoveUpSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Value")
	float MoveForwardSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Value")
	float MoveRightSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Value")
	float MaxRange;

	FVector StartLocation;
	FVector CurrentLocation;
	FVector TempLocation;
	float CurrentDistance;
	int Direction;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
