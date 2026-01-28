// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BasePlayer.generated.h"

UCLASS()
class EARTSUP_B2_API ABasePlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABasePlayer();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Player Stats")
	int MaxHP;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Player Stats")
	int CurrentHP;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Player Stats")
	int Armor;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION(BlueprintCallable)
	void TakeDamage(int DamageAmount);

};
