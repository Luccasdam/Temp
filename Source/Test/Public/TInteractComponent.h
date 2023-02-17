// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TInteractComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TEST_API UTInteractComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UTInteractComponent();

	UFUNCTION(BlueprintCallable)
	void Interact() const;

private:
	AActor* FindBestActorToInteract() const;
};
