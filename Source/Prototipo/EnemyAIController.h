//Jose E Velazquez Sepulveda
//EnemyAIController.h

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

UCLASS()
class PROTOTIPO_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

protected:
	
	virtual void BeginPlay() override;
	
private:
	
	UPROPERTY(EditAnywhere)
		class UBehaviorTree* AIBehavior;

	FTimerHandle FStart;

	void StartLocation();
};
