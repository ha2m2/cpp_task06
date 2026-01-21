// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingObstacle.h"

ARotatingObstacle::ARotatingObstacle()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	PrimaryActorTick.bCanEverTick = true;
}

void ARotatingObstacle::BeginPlay()
{
	Super::BeginPlay();
}

void ARotatingObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalRotation(FRotator(0, 0, rotationSpeed * DeltaTime));
}

