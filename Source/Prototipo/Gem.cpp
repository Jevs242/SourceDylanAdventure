//Jose E Velazquez Sepulveda
//Gem.cpp


#include "Gem.h"
#include "PrototipoCharacter.h"
#include "Components/BoxComponent.h"

AGem::AGem()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	PMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PMesh"));
	PMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));

	PMesh->SetupAttachment(RootComponent);
	BoxCollision->SetupAttachment(RootComponent);
}

void AGem::BeginPlay()
{
	Super::BeginPlay();
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AGem::BeginOverlap);
}

void AGem::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APrototipoCharacter* Character = Cast<APrototipoCharacter>(OtherActor);
	if (Character)
	{
		Character->Gems += FMath::RandRange(1, 2);
		Destroy();
	}
}