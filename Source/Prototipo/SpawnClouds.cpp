//Jose E Velazquez Sepulveda
//SpawnClouds.cpp

#include "SpawnClouds.h"

ASpawnClouds::ASpawnClouds()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	Cloud1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cloud1"));
	Cloud1->SetupAttachment(RootComponent);

	Cloud2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cloud2"));
	Cloud2->SetupAttachment(RootComponent);

	Cloud3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cloud3"));
	Cloud3->SetupAttachment(RootComponent);

	Cloud4 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cloud4"));
	Cloud4->SetupAttachment(RootComponent);

	Cloud5 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cloud5"));
	Cloud5->SetupAttachment(RootComponent);

	Cloud6 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cloud6"));
	Cloud6->SetupAttachment(RootComponent);

	Cloud7 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cloud7"));
	Cloud7->SetupAttachment(RootComponent);

	Cloud8 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cloud8"));
	Cloud8->SetupAttachment(RootComponent);

	BeginLocation = CreateDefaultSubobject<USceneComponent>(TEXT("BeginLocation"));

	EndLocation = CreateDefaultSubobject<USceneComponent>(TEXT("EndLocation"));

	MaxY = CreateDefaultSubobject<USceneComponent>(TEXT("MaxY"));
	MaxY->SetupAttachment(RootComponent);

	MinY = CreateDefaultSubobject<USceneComponent>(TEXT("MinY"));
	MinY->SetupAttachment(RootComponent);
}

void ASpawnClouds::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveClouds(DeltaTime, Cloud1);
	MoveClouds(DeltaTime, Cloud2);
	MoveClouds(DeltaTime, Cloud3);
	MoveClouds(DeltaTime, Cloud4);
	MoveClouds(DeltaTime, Cloud5);
	MoveClouds(DeltaTime, Cloud6);
	MoveClouds(DeltaTime, Cloud7);
	MoveClouds(DeltaTime, Cloud8);
}

void ASpawnClouds::MoveClouds(float DeltaTime, UStaticMeshComponent* Clouds)
{
	float MoveX = Clouds->GetRelativeLocation().X;
	FVector NewLocation = Clouds->GetRelativeLocation();

	if (Clouds->GetRelativeLocation().X >= EndLocation->GetRelativeLocation().X)
	{
		NewLocation.X += Speed * DeltaTime;
		Clouds->SetRelativeLocation(FVector(NewLocation));
	}
	else
	{
		Clouds->SetRelativeLocation(FVector(BeginLocation->GetRelativeLocation().X, FMath::RandRange(MinY->GetRelativeLocation().Y, MaxY->GetRelativeLocation().Y), BeginLocation->GetRelativeLocation().Z));
	}
}