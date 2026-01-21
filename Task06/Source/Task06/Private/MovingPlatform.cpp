// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	PrimaryActorTick.bCanEverTick = true;
	Direction = 1;
	CurrentDistance = 0;
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CurrentLocation = GetActorLocation();

	SetActorLocation(CurrentLocation + FVector((Direction * MoveForwardSpeed * DeltaTime), (Direction * MoveRightSpeed * DeltaTime), (Direction * MoveUpSpeed * DeltaTime)));

	CurrentDistance = FVector::Distance(StartLocation, CurrentLocation);

	if (CurrentDistance > MaxRange)
	{
		Direction *= -1;
		TempLocation = StartLocation;
		StartLocation = CurrentLocation;
	}
}

