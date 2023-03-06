// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WebSocketTestGameInstance.h"
#include "FirstActor.generated.h"

UCLASS()
class MYPROJECT_API AFirstActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFirstActor();

	//int32 loot;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WebSocket variables")
		float ValueOne;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WebSocket variables")
		float ValueTwo;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WebSocket variables")
		float ValueThree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WebSocket variables")
		int32 e;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
