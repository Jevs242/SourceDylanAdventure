//Jose E Velazquez Sepulveda
//Sword.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Enemy.h"
#include "PrototipoCharacter.h"
#include "Sword.generated.h"

UCLASS()
class PROTOTIPO_API ASword : public AActor
{
	GENERATED_BODY()

public:
	ASword();

	UFUNCTION()
		void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* BoxCollision;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* PMesh;

protected:
	virtual void BeginPlay() override;

public:

	UPROPERTY(EditAnywhere)
		bool CharacterSword = true;

	class APrototipoCharacter* Character;
		
	float Damage;

	bool bAttackEnemy = false;
		
};
