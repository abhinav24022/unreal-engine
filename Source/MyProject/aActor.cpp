// Fill out your copyright notice in the Description page of Project Settings.


#include "aActor.h"

// Sets default values
AaActor::AaActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AaActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AaActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

