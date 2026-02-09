// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseDoor.h"

// Sets default values
ABaseDoor::ABaseDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	RootComponent = DoorMesh;
	
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionBox->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ABaseDoor::BeginPlay()
{
	Super::BeginPlay();
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this,	
		&ABaseDoor::OnOverlapBegin);
	
	CollisionBox->OnComponentEndOverlap.AddDynamic(this,
		&ABaseDoor::OnOverlapEnd);
}

// Called every frame
void ABaseDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ABaseDoor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp,
								  AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
								  bool bFromSweep, const FHitResult& SweepResult)
{
	OpenDoor();
}

void ABaseDoor::OnOverlapEnd(UPrimitiveComponent* OverlappedComp,
								  AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	CloseDoor();
}
