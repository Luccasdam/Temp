// Fill out your copyright notice in the Description page of Project Settings.


#include "TCharacter.h"
#include "TInteractComponent.h"

// Sets default values
ATCharacter::ATCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	JumpMaxCount = 2;

	InteractComponent = CreateDefaultSubobject<UTInteractComponent>("InteractComponent");
}

// Called when the game starts or when spawned
void ATCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

