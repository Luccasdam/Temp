// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TInteractInterface.h"
#include "GameFramework/Actor.h"
#include "TInteractiveDoor.generated.h"

UCLASS()
class TEST_API ATInteractiveDoor : public AActor, public ITInteractInterface
{
	GENERATED_BODY()
	
public:	
	ATInteractiveDoor();

	virtual void Interact_Implementation(AActor* InstigatorActor) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<UStaticMeshComponent> DoorTrim;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<UStaticMeshComponent> DoorMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay")
	float OpenDoorYaw = -90.0f;
};
