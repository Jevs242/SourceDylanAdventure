//Jose E Velazquez Sepulveda
//MySaveGame.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "MySaveGame.generated.h"

/**
 *
 */
UCLASS()
class PROTOTIPO_API UMySaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UMySaveGame();

	UPROPERTY(EditAnywhere)
		FVector PlayerLocation;

	UPROPERTY(EditAnywhere)
		int Gems;

	UPROPERTY(EditAnywhere)
		int IslandNumber;

	UPROPERTY(EditAnywhere)
		FString	TextMission;

	UPROPERTY(EditAnywhere)
		bool WavesComplete1;

	UPROPERTY(EditAnywhere)
		bool WavesComplete2;

	UPROPERTY(EditAnywhere)
		bool WavesComplete3;

	UPROPERTY(EditAnywhere)
		bool WavesComplete4;

	UPROPERTY(EditAnywhere)
		bool WavesComplete5;

	UPROPERTY(EditAnywhere)
		float Damage;

	UPROPERTY(EditAnywhere)
		int MaxHealth;

	UPROPERTY(EditAnywhere)
		float MaxResistence;

	UPROPERTY(EditAnywhere)
		bool Accept1;

	UPROPERTY(EditAnywhere)
		bool Accept2;

	UPROPERTY(EditAnywhere)
		bool Accept3;

	UPROPERTY(EditAnywhere)
		int NumberSpawnPast;

	UPROPERTY(EditAnywhere)
		int NumberSpawn;

	UPROPERTY(EditAnywhere)
		int EnemyWaves;

	UPROPERTY(EditAnywhere)
		int Waves;

	UPROPERTY(EditAnywhere)
		int EnemyKill;

	UPROPERTY(EditAnywhere)
		bool Battle;
	
};
