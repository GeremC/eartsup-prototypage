// Fill out your copyright notice in the Description page of Projact Settings.


#include "WorldObjects/BaseFallingPlatform.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
ABaseFallingPlatform::ABaseFallingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));	
	RootComponent = PlatformMesh;
	
	PlatformMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionBox->SetupAttachment(RootComponent);
	
	CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

}

// Called when the game starts or when spawned
void ABaseFallingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	InitialTransform = GetActorTransform();
	
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ABaseFallingPlatform::OnOverlapBegin);
	CollisionBox->OnComponentEndOverlap.AddDynamic(this, &ABaseFallingPlatform::OnOverlapEnd);
	
}

void ABaseFallingPlatform::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	PlatformMesh->SetSimulatePhysics(true);
}

void ABaseFallingPlatform::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	CurrentTransform = GetActorTransform();
	PlatformMesh->SetSimulatePhysics(false);
	ResetPlatformTransform();
}

// Called every frame
void ABaseFallingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}