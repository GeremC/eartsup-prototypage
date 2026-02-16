// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WorldObjects/BaseSpikes.h"
#include "SpringTrap.generated.h"

/**
 * 
 */
UCLASS()
class EARTSUP_B2_API ASpringTrap : public ABaseSpikes
{
	GENERATED_BODY()
	
protected:
	
	int SpikeDamage = 10;
	
	virtual void OnActivation(AActor* Actor) override;
	
	
};
