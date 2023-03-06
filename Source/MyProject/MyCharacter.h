// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WebSocketTestGameInstance.h"
#include "MyCharacter.generated.h"

UCLASS()
class MYPROJECT_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

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

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
