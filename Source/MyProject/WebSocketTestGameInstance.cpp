// Fill out your copyright notice in the Description page of Project Settings.


#include "WebSocketTestGameInstance.h"
#include "WebSocketsModule.h"
#include "FirstActor.h"
//wss://s8xnksme9e.execute-api.ap-northeast-1.amazonaws.com/dev
//wss://gtg3p8yh66.execute-api.us-east-1.amazonaws.com/production
void UWebSocketTestGameInstance::Init()
{
	Super::Init();
	if (!FModuleManager::Get().IsModuleLoaded("WebSockets"))
	{
		FModuleManager::Get().LoadModule("WebSockets");
	}
	WebSocket= FWebSocketsModule::Get().CreateWebSocket("wss://s8xnksme9e.execute-api.ap-northeast-1.amazonaws.com/dev");
	
	WebSocket->OnConnected().AddLambda([]()
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "successfully connected");
		});
	WebSocket->OnConnectionError().AddLambda([](const FString& Error)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red,Error);

	});
	WebSocket->OnClosed().AddLambda([](int32 StatusCode,const FString& Reason,bool bWasClean)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, bWasClean ? FColor::Green : FColor::Red,"connection closed "+Reason);

	});
	WebSocket->OnMessage().AddLambda([this](const FString& MessageString)
		{
			//AFirstActor* ThePC = Cast<AFirstActor>(GetWorld()->GetFirstPlayerController());
			
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Cyan, "received message: " + MessageString);
			FString s = MessageString;
			TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
			TSharedRef< TJsonReader<> > Jsonreader= TJsonReaderFactory<>::Create(s);
			if (FJsonSerializer::Deserialize(Jsonreader, JsonObject) && JsonObject.IsValid()) {
				temp = JsonObject->GetIntegerField("message");
				id = JsonObject->GetStringField("id");
				//ThePC->loot = temp;
			}

			//m = FCString::Atoi(*MessageString);
			//UE_LOG(LogTemp, Warning, TEXT("%d"), temp);

	});
	WebSocket->OnMessageSent().AddLambda([](const FString& MessageString)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "sent message: " + MessageString);

	});
	WebSocket->Connect();

}

void UWebSocketTestGameInstance::Shutdown()
{
	if (WebSocket->IsConnected()) {
		WebSocket->Close();
	}
	Super::Shutdown();

}
