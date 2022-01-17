//Jose E Velazquez Sepulveda
//BTTask_NotAttack.h

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_NotAttack.generated.h"

UCLASS()
class PROTOTIPO_API UBTTask_NotAttack : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_NotAttack();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
