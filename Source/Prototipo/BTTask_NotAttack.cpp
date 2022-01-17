//Jose E Velazquez Sepulveda
//BTTask_NotAttack.cpp

#include "BTTask_NotAttack.h"
#include "AIController.h"
#include "Enemy.h"
#include "PrototipoCharacter.h"
#include "GameFramework/Controller.h"
#include "Kismet/GameplayStatics.h"

UBTTask_NotAttack::UBTTask_NotAttack()
{
	NodeName = "NotAttack";
}

EBTNodeResult::Type UBTTask_NotAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
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

	Character->NotAttack();

	return EBTNodeResult::Succeeded;
}
