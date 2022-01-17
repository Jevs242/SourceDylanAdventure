//Jose E Velazquez Sepulveda
//Portal.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Portal.generated.h"

UCLASS()
class PROTOTIPO_API APortal : public AActor
{
	GENERATED_BODY()

public:
	APortal();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* BoxCollision;

	UFUNCTION()
		void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere)
		class USceneComponent* TeleportLocation;

protected:
	
	virtual void BeginPlay() override;

public:
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool bTeleport = false;

	UPROPERTY(EditAnywhere)
		int IslandNumber = 0;

	UPROPERTY(EditAnywhere)
		int Waves = 0;

private:
	
	FVector TargetTeleportLocation;

	FTimerHandle FTeleport;

	FTimerHandle FMove;

	void Teleport();

	void Move();

	class APrototipoCharacter* Character;
};
