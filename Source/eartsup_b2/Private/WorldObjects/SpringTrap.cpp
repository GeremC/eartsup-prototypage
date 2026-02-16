// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldObjects/SpringTrap.h"
#include "BaseCharacter.h"

void ASpringTrap::OnActivation(AActor* Actor)
{
	if (Actor->IsA(ABaseCharacter::StaticClass()))
	{
		ABaseCharacter* AffectedActor = Cast<ABaseCharacter>(Actor);
		AffectedActor->ReceiveDamage(SpikeDamage);
		FVector ForwardVector = AffectedActor->GetActorForwardVector();
		FVector LaunchVelocity = FVector(
			1000 * ForwardVector.X,
			1000 * ForwardVector.Y,
			3000);
		AffectedActor->LaunchCharacter(LaunchVelocity, true, true);
	}
}
