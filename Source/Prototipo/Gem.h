//Jose E Velazquez Sepulveda
//Gem.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gem.generated.h"

UCLASS()
class PROTOTIPO_API AGem : public AActor
{
	GENERATED_BODY()

public:
	AGem();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* BoxCollision;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* PMesh;

	UFUNCTION()
		void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	
	virtual void BeginPlay() override;
};
