// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "Math.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool ABaseCharacter::ReceiveDamage(int DamageAmount)
{
	int EffectiveDamage = FMath::Max(0, DamageAmount - Armor);

	if (CurrentHP - EffectiveDamage < 0)
	{
		CurrentHP = 0;
		return false;
	}
	else
	{
		CurrentHP -= EffectiveDamage;
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red,
		FString::Printf(TEXT("Player received %d damage, current HP: %d"), EffectiveDamage, CurrentHP));
	return true;
}
