//Jose E Velazquez Sepulveda
//EnemyAIController.cpp

#include "EnemyAIController.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "BehaviorTree/BlackboardComponent.h"

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();

	if (AIBehavior != nullptr)
	{
		RunBehaviorTree(AIBehavior);

		APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		GetWorld()->GetTimerManager().SetTimer(FStart, this, &AEnemyAIController::StartLocation, 3.f, false);
	}
}

void AEnemyAIController::StartLocation()
{
	GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"),GetPawn()->GetActorLocation());
}
