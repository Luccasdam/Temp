// Fill out your copyright notice in the Description page of Project Settings.


#include "TInteractiveDoor.h"

// Sets default values
ATInteractiveDoor::ATInteractiveDoor()
{
	PrimaryActorTick.bCanEverTick = true;
	
	DoorTrim = CreateDefaultSubobject<UStaticMeshComponent>("DoorTrim");
	SetRootComponent(DoorTrim);

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>("DoorMesh");
	DoorMesh->SetupAttachment(RootComponent);
}

void ATInteractiveDoor::Interact_Implementation(AActor* InstigatorActor)
{
	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Green, FString::Printf(TEXT("Interacting with %s"), *GetNameSafe(this)));
}
