// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstActor.h"

#include <Kismet/GameplayStatics.h>


// Sets default values
AFirstActor::AFirstActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFirstActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFirstActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	UWebSocketTestGameInstance* GameInstance = Cast<UWebSocketTestGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (GameInstance) {
		if (GameInstance->WebSocket->IsConnected()) {
			e = (GameInstance->temp);
			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Cyan, "e value: " + GameInstance->m);
			//UE_LOG(LogTemp,Warning,TEXT("%d"), e);

			if (e == 3) {
				ValueOne = 0.0f;
				ValueTwo = 255.0f;
				ValueThree = 0.0;
			}
			if (e == 4) {
				ValueOne = 255.0f;
				ValueTwo = 255.0f;
				ValueThree = 0.0;
			}
			if (e == 5) {
				ValueOne = 255.0f;
				ValueTwo = 0.0f;
				ValueThree = 0.0f;
			}
			/*else {
				ValueOne = 255.0f;
				ValueTwo = 140.0f;
				ValueThree = 0.0;

			}*/

		}
	}

}


