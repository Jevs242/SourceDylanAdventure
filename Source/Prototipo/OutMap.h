//Jose E Velazquez Sepulveda
//OutMap.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OutMap.generated.h"

UCLASS()
class PROTOTIPO_API AOutMap : public AActor
{
	GENERATED_BODY()

public:
	AOutMap();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* BoxCollision;

	UFUNCTION()
		void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	virtual void BeginPlay() override;
};
