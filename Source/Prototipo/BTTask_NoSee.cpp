//Jose E Velazquez Sepulveda
//BTTask_NoSee.cpp

#include "BTTask_NoSee.h"
#include "AIController.h"
#include "Enemy.h"
#include "PrototipoCharacter.h"
#include "GameFramework/Controller.h"
#include "Kismet/GameplayStatics.h"

UBTTask_NoSee::UBTTask_NoSee()
{
	NodeName = "No See Player";
}

EBTNodeResult::Type UBTTask_NoSee::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
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

	Character->See=false;

	return EBTNodeResult::Succeeded;
}
