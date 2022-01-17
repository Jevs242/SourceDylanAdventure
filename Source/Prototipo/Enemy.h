//Jose E Velazquez Sepulveda
//Enemy.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PrototipoCharacter.h"
#include "Sword.h"
#include "Gem.h"
#include "Enemy.generated.h"

UCLASS(config = Game)

class AEnemy : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;
public:
	AEnemy();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

protected:

	virtual void BeginPlay() override;

	void MoveForward(float Value);

	void MoveRight(float Value);

	void TurnAtRate(float Rate);

	void LookUpAtRate(float Rate);

	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

public:
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	//Enemy

	UPROPERTY(EditAnywhere)
		float MaxHealth = 100;

	UPROPERTY(EditAnywhere)
		int Damage = 20;

	void Death();

	void DestroyEnemy();

	FTimerHandle FDeath;

	bool See = false;

	bool Ok = false;

	int Health = 0;
	
	//Character Variable

	UFUNCTION(BlueprintPure)
		int vNumberSpawn();

	UFUNCTION(BlueprintPure)
	int vNumberSpawnPast();
	
	class APrototipoCharacter* Character;

	FRotator RotationCharacter;

	void RotatorEnemy(FVector LookAtTarget);


	int NumberSpawn = 0;

	//Sword

	UPROPERTY(EditAnywhere)
		TSubclassOf<ASword> SwordClass;

	ASword* Sword;
	
	//Gem

	UPROPERTY(EditAnywhere)
		class USceneComponent* DropObject;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class AGem> SpawnObject;

	//AI

	void Attack();

	void NotAttack();

	//Funcion Blueprint

	UFUNCTION(BlueprintPure)
		float GetHealthPercent() const;

	UFUNCTION(BlueprintCallable)
		void EnemyHeal();

	UFUNCTION(BlueprintPure)
		bool GetDead() const;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool AttackActive;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool bDeath = false;

	UFUNCTION(BlueprintCallable)
		void vDestroySword();

	//Sound

	UPROPERTY(EditAnywhere)
		USoundBase* AttackSound;

	UPROPERTY(EditAnywhere)
		USoundBase* DamageSound;

	void vDamageSound();

};