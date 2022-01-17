//Jose E Velazquez Sepulveda
//BTTask_See.h

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_See.generated.h"

UCLASS()
class PROTOTIPO_API UBTTask_See : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_See();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
