//Jose E Velazquez Sepulveda
//Sword.cpp

#include "Sword.h"
#include "Kismet/GameplayStatics.h"

ASword::ASword()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	PMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PMesh"));
	PMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));

	PMesh->SetupAttachment(RootComponent);
	BoxCollision->SetupAttachment(RootComponent);
}

void ASword::BeginPlay()
{
	Super::BeginPlay();

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ASword::BeginOverlap);

	Character = Cast<APrototipoCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

void ASword::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (CharacterSword)
	{
		AEnemy* Enemy = Cast<AEnemy>(OtherActor);
		if (Enemy && !Enemy->bDeath && Character->bAttackActive)
		{
			Character->bAttackActive = false;
			Enemy->vDamageSound();
			Enemy->Health -= Character->Damage;
			if (Enemy->Health <= 0)
			{
				Character->EnemyKill++;
				Character->vWavesComplete();
 				Enemy->Death();
			}
		}
	}
	else
	{
		if (Character == OtherActor)
		{
			if (!Character->bDefence && bAttackEnemy && !Character->bDeath)
			{
				bAttackEnemy = false;
				Character->vDamageSound();
				Character->Health -= Damage;
				if (Character->Health <= 0)
				{
					Character->vDeath();
				}
			}
		}
	}
}
