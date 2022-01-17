//Jose E Velazquez Sepulveda
//Enemy.cpp

#include "Enemy.h"
#include "EnemyAIController.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"

AEnemy::AEnemy()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;


	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;


	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f;
	CameraBoom->bUsePawnControlRotation = true;


	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	DropObject = CreateDefaultSubobject<USceneComponent>(TEXT("DropObject"));
	DropObject->SetupAttachment(RootComponent);
	
	AIControllerClass = AEnemyAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;
	Character = Cast<APrototipoCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (SwordClass != nullptr)
	{
		Sword = GetWorld()->SpawnActor<ASword>(SwordClass);
		Sword->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("SwordSocket"));
		Sword->SetOwner(this);
	}
}

void AEnemy::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	Jump();
}

void AEnemy::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
	StopJumping();
}

void AEnemy::RotatorEnemy(FVector LookAtTarget)
{
	FVector LookAtTargetClean = FVector(LookAtTarget.X, LookAtTarget.Y, GetActorLocation().Z);
	FVector StartLocation = GetActorLocation();

	FRotator TurretRotation = FVector(LookAtTargetClean - StartLocation).Rotation();
	SetActorRotation(TurretRotation);
}

void AEnemy::Death()
{
	bDeath = true;
	DetachFromControllerPendingDestroy();
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	if (SpawnObject != NULL && !Ok)
	{
		FActorSpawnParameters SpawnParams;

		FVector SpawnLocation = DropObject->GetComponentLocation();
		FRotator Spawnrotation = FRotator::ZeroRotator;

		AGem* Gem = GetWorld()->SpawnActor<AGem>
			(SpawnObject, SpawnLocation, Spawnrotation, SpawnParams);
		Ok = true;
	}
	GetWorld()->GetTimerManager().SetTimer(FDeath, this, &AEnemy::DestroyEnemy, 10.0f, false);
}


void AEnemy::DestroyEnemy()
{
	if (SwordClass != nullptr)
	{
		Sword->Destroy();
	}
	Destroy();
}

void AEnemy::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AEnemy::LookUpAtRate(float Rate)
{
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AEnemy::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AEnemy::MoveRight(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

//AI

void AEnemy::Attack()
{
	AttackActive = true;

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	RotatorEnemy(PlayerPawn->GetActorLocation());

	if (SwordClass != nullptr)
	{
		Sword->bAttackEnemy = AttackActive;
		Sword->Damage = Damage;
		UGameplayStatics::SpawnSoundAttached(AttackSound, RootComponent, TEXT("SwordSocket"));
	}
}

void AEnemy::NotAttack()
{
	AttackActive = false;

	if (SwordClass != nullptr)
	{
		Sword->bAttackEnemy = AttackActive;
	}
}

//Funcion Blueprint

float AEnemy::GetHealthPercent() const
{
	return Health / MaxHealth;
}

void AEnemy::EnemyHeal()
{
	Health = MaxHealth;
}

bool AEnemy::GetDead() const
{
	return bDeath;
}

void AEnemy::vDestroySword()
{
	if (SwordClass != nullptr)
	{
		Sword->Destroy();
	}
}

void AEnemy::vDamageSound()
{
	UGameplayStatics::SpawnSoundAttached(DamageSound, RootComponent, TEXT("SwordSocket"));
}

int AEnemy::vNumberSpawnPast()
{
	return Character->NumberSpawnPast;
}

int AEnemy::vNumberSpawn()
{
	return NumberSpawn;
}
