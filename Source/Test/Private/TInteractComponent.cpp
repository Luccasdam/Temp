// Fill out your copyright notice in the Description page of Project Settings.


#include "TInteractComponent.h"
#include "TInteractInterface.h"


#define TRACE_DISTANCE 200.0f
#define TRACE_SPHERE_RADIUS 25.0f


// Sets default values for this component's properties
UTInteractComponent::UTInteractComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UTInteractComponent::Interact() const
{	
	if (AActor* ActorToInteract = FindBestActorToInteract())
	{
		ITInteractInterface::Execute_Interact(ActorToInteract, GetOwner());
	}
}


AActor* UTInteractComponent::FindBestActorToInteract() const
{
	const AActor* OwnerActor = GetOwner();
	if (!IsValid(OwnerActor)) return nullptr;
	
	TArray<FHitResult> Hits;

	const FVector TraceStart = OwnerActor->GetActorLocation();
	const FVector TraceEnd = TraceStart + OwnerActor->GetActorForwardVector() * TRACE_DISTANCE;

	FCollisionObjectQueryParams ObjQueryParams;
	ObjQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);

	FCollisionShape CollisionShape;
	CollisionShape.SetSphere(TRACE_SPHERE_RADIUS);
	
	AActor* ActorToInteract = nullptr;
	
	if (GetWorld()->SweepMultiByObjectType(Hits, TraceStart, TraceEnd, FQuat::Identity, ObjQueryParams, CollisionShape))
	{
		float BestInteractionDistance = TRACE_DISTANCE;
		
		for (FHitResult& Hit : Hits)
		{
			AActor* HitActor = Hit.GetActor();
						
			if (IsValid(HitActor) && HitActor->Implements<UTInteractInterface>())
			{
				const float CurrentInteractionDistance = FVector::Distance(HitActor->GetActorLocation(), TraceStart);
				if (CurrentInteractionDistance < BestInteractionDistance)
				{
					BestInteractionDistance = CurrentInteractionDistance;
					ActorToInteract = HitActor;
				}
			}
		}
	}

	return ActorToInteract;
}
