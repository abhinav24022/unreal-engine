// Fill out your copyright notice in the Description page of Project Settings.


#include "ColouredCube.h"

// Sets default values
AColouredCube::AColouredCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AColouredCube::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AColouredCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

