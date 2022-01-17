//Jose E Velazquez Sepulveda
//BTTask_See.cpp

#include "BTTask_See.h"
#include "AIController.h"
#include "Enemy.h"
#include "PrototipoCharacter.h"
#include "GameFramework/Controller.h"
#include "Kismet/GameplayStatics.h"

UBTTask_See::UBTTask_See()
{
	NodeName = "See Player";
}

EBTNodeResult::Type UBTTask_See::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	AEnemy* Character = Cast<AEnemy>(OwnerComp.GetAIOwner()->GetPawn());
	if (Character == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	Character->See = true;

	return EBTNodeResult::Succeeded;
}