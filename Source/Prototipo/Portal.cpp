//Jose E Velazquez Sepulveda
//Portal.cpp

#include "Portal.h"
#include "PrototipoCharacter.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

APortal::APortal()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));

	BoxCollision->SetupAttachment(RootComponent);

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &APortal::BeginOverlap);

	TeleportLocation = CreateDefaultSubobject<USceneComponent>(TEXT("TeleportLocation"));
	TeleportLocation->SetupAttachment(RootComponent);
}

void APortal::BeginPlay()
{
	Super::BeginPlay();
	TargetTeleportLocation = TeleportLocation->GetComponentLocation();
	Character = Cast<APrototipoCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

void APortal::Teleport()
{
	Character->IslandNumber = IslandNumber;
	Character->SetActorLocation(TargetTeleportLocation);
	GetWorld()->GetTimerManager().SetTimer(FTeleport, this, &APortal::Move, 2.f, false);
}

void APortal::Move()
{
	bTeleport = false;
	Character->bAttack = false;
}


void APortal::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Character == OtherActor && Character->WavesComplete[Waves] && Character->Accept[Waves] || Character == OtherActor && Waves == 0)
	{
		bTeleport = true;
		Character->bAttack = true;
		GetWorld()->GetTimerManager().SetTimer(FMove, this, &APortal::Teleport, 1.f, false);
	}
}

