//Jose E Velazquez Sepulveda
//Spawner.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy.h"
#include "PrototipoCharacter.h"
#include "Spawner.generated.h"

UCLASS()
class PROTOTIPO_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* BoxCollision;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* OutBoxRespawn;

	UFUNCTION()
		void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
		void OnOverlapEnd2(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(EditAnywhere , BlueprintReadOnly)
		class USceneComponent* Spawn1;

	UPROPERTY(EditAnywhere , BlueprintReadOnly)
		class USceneComponent* Spawn2;
	
	UPROPERTY(EditAnywhere , BlueprintReadOnly)
		class USceneComponent* Spawn3;
	
	UPROPERTY(EditAnywhere , BlueprintReadOnly)
		class USceneComponent* Spawn4;
	
	UPROPERTY(EditAnywhere ,BlueprintReadOnly)
		class USceneComponent* Spawn5;

protected:
	
	virtual void BeginPlay() override;
	
public:	

	//Spawn

	UPROPERTY(EditAnywhere)
		bool BossFight = false;
	
	UFUNCTION(BlueprintCallable)
		void Spawn();

	void FSpawn(USceneComponent* SpawnScene);


	//Enemy Variable
	
	UPROPERTY(EditAnywhere)
		TSubclassOf<class AEnemy> SpawnObject;
	
	UPROPERTY(EditAnywhere)
		int Health = 100;

	UPROPERTY(EditAnywhere)
		int Damage = 25;
	
	UPROPERTY(EditAnywhere)
		int Waves = 0;

	UPROPERTY(EditAnywhere)
		int AmountEnemy = 0;

	//Character Variable
	
	class APrototipoCharacter* CharacterD;

	UPROPERTY(EditAnywhere)
		int NumberSpawn = 0;
	
	bool Battle = false;

	bool bRevive = false;

	bool OutBox = false;

	//Funcion Blueprint


	UFUNCTION(BlueprintPure)
		bool vBattle() const;

	UFUNCTION(BlueprintPure)
		bool vDeath() const;

	UFUNCTION(BlueprintPure)
		bool vRevive() const;

	UFUNCTION(BlueprintPure)
		int vNumberSpawn();

	UFUNCTION(BlueprintPure)
		int vNumberSpawnPast();
	
	UFUNCTION(BlueprintPure)
		int vNumberSpawnCharacter();

	//Sound

	UPROPERTY(EditAnywhere)
		USoundBase* BossBegin;
};
