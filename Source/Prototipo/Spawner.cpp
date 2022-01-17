//Jose E Velazquez Sepulveda
//Spawner.cpp

#include "Spawner.h"
#include "Misc/OutputDeviceNull.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

#define print(x) GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT(x));
#define log(x) UE_LOG(LogTemp, Error, TEXT(x));

ASpawner::ASpawner()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	Spawn1 = CreateDefaultSubobject<USceneComponent>(TEXT("Spawn1"));
	Spawn2 = CreateDefaultSubobject<USceneComponent>(TEXT("Spawn2"));
	Spawn3 = CreateDefaultSubobject<USceneComponent>(TEXT("Spawn3"));
	Spawn4 = CreateDefaultSubobject<USceneComponent>(TEXT("Spawn4"));
	Spawn5 = CreateDefaultSubobject<USceneComponent>(TEXT("Spawn5"));
	
	Spawn1->SetupAttachment(RootComponent);
	Spawn2->SetupAttachment(RootComponent);
	Spawn3->SetupAttachment(RootComponent);
	Spawn4->SetupAttachment(RootComponent);
	Spawn5->SetupAttachment(RootComponent);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetupAttachment(RootComponent);

	OutBoxRespawn = CreateDefaultSubobject<UBoxComponent>(TEXT("OutBoxRespawn"));
	OutBoxRespawn->SetupAttachment(RootComponent);
}

void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ASpawner::BeginOverlap);
	BoxCollision->OnComponentEndOverlap.AddDynamic(this, &ASpawner::OnOverlapEnd);
	
	OutBoxRespawn->OnComponentEndOverlap.AddDynamic(this, &ASpawner::OnOverlapEnd2);
	
	CharacterD = Cast<APrototipoCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	Spawn();
}

void ASpawner::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APrototipoCharacter* Character = Cast<APrototipoCharacter>(OtherActor);
	if(Character)
	{
		if (BossFight && !Character->Battle)
		{
			UGameplayStatics::SpawnSoundAttached(BossBegin, Spawn1, TEXT("BossFight"));
			Character->IslandNumber = 3;
		}
		Character->NumberSpawn = NumberSpawn;
		Character->EnemyWaves = AmountEnemy;
		Battle = true;
		Character-> Battle = true;
		Character->Waves = Waves;
	}
}

void ASpawner::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,int32 OtherBodyIndex)
{
	if (!BossFight)
	{
		APrototipoCharacter* Character = Cast<APrototipoCharacter>(OtherActor);
		if(Character)
		{	
			Battle = false;
			Character->Battle = false;
			Character->Healok = false;
			Character->bHeal = false;
			Character->NumberSpawnPast = NumberSpawn;
			Character->NumberSpawn = 0;
		}
	}
}

void ASpawner::OnOverlapEnd2(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,int32 OtherBodyIndex)
{
	if (!BossFight)
	{
		APrototipoCharacter* Character = Cast<APrototipoCharacter>(OtherActor);
		if (Character)
		{		
			FOutputDeviceNull ar;
			this->CallFunctionByNameWithArguments(TEXT("Respawns"), ar, NULL, true);
			Character->EnemyKill = 0;
		}
	}
}

void ASpawner::Spawn()
{
	if (SpawnObject != NULL)
	{
		if(AmountEnemy >= 1)
		{
			FSpawn(Spawn1);
			if (AmountEnemy >= 2)
			{
				FSpawn(Spawn2);
				if (AmountEnemy >= 3)
				{
					FSpawn(Spawn3);
					if (AmountEnemy >= 4)
					{
						FSpawn(Spawn4);
						if (AmountEnemy >= 5)
						{
							FSpawn(Spawn5);
						}
					}
				}
			}
		}
	}
}

void ASpawner::FSpawn(USceneComponent* SpawnScene)
{
	FActorSpawnParameters SpawnParams;

	FVector SpawnLocation = SpawnScene->GetComponentLocation();
	FRotator Spawnrotation = FRotator::ZeroRotator;
	AEnemy* Enemy = GetWorld()->SpawnActor<AEnemy>
			(SpawnObject, SpawnLocation, Spawnrotation, SpawnParams);

	if (Enemy != NULL)
	{
		Enemy->NumberSpawn = NumberSpawn;
		Enemy->Damage=Damage;
		Enemy->MaxHealth=Health;
	}
}

//Funcion Blueprint

bool ASpawner::vBattle() const
{
	return Battle;
}

bool ASpawner::vDeath() const
{
	if(CharacterD!= NULL)
	{
		return CharacterD->bDeath;
	}
	else
	{
		return true;
	}
}

bool ASpawner::vRevive() const
{
	if (CharacterD != NULL)
	{
		return CharacterD->bRevive;
	}
	else
	{
		return true;
	}
}

int ASpawner::vNumberSpawn()
{
	return NumberSpawn;
}

int ASpawner::vNumberSpawnPast()
{
	if (CharacterD != NULL)
	{
		return CharacterD->NumberSpawnPast;
	}
	else
	{
		return 0;
	}
}

int ASpawner::vNumberSpawnCharacter()
{
	if (CharacterD != NULL)
	{
		return CharacterD->NumberSpawn;
	}
	else
	{
		return 0;
	}
}

