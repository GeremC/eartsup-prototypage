// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldObjects/BaseSpikes.h"
#include "BaseCharacter.h"

// Sets default values
ABaseSpikes::ABaseSpikes()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	RootComponent = CollisionBox;

	SpikeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpikeMesh"));
	SpikeMesh->SetupAttachment(CollisionBox);


}

// Called when the game starts or when spawned
void ABaseSpikes::BeginPlay()
{
	Super::BeginPlay();

	CollisionBox->OnComponentBeginOverlap.AddDynamic(this,
		&ABaseSpikes::OnOverlapBegin);
	
}

// Called every frame
void ABaseSpikes::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseSpikes::OnOverlapBegin(UPrimitiveComponent* OverlappedComp,
                                 AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
                                 bool bFromSweep, const FHitResult& SweepResult)
{
	OnActivation(OtherActor);
}

void ABaseSpikes::OnActivation(AActor* Actor)
{
	if (Actor->IsA(ABaseCharacter::StaticClass()))
	{
		Cast<ABaseCharacter>(Actor)->ReceiveDamage(SpikeDamage);
	}
}
