//Jose E Velazquez Sepulveda
//Blocking.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PrototipoCharacter.h"
#include "Blocking.generated.h"

UCLASS()
class PROTOTIPO_API ABlocking : public AActor
{
	GENERATED_BODY()
	
public:	
	ABlocking();

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* PMesh;

	UPROPERTY(EditAnywhere)
		int Waves;
	
	class APrototipoCharacter* Character;

	void vWaves(int iWaves);
	
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
};
