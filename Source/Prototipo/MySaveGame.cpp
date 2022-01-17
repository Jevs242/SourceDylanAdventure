//Jose E Velazquez Sepulveda
//MySaveGame.cpp


#include "MySaveGame.h"

UMySaveGame::UMySaveGame()
{
	PlayerLocation = FVector(0.f, 0.f, 0.f);
	Gems = 0;
	IslandNumber = 0;
	WavesComplete1 = false;
	WavesComplete2 = false;
	WavesComplete3 = false;
	WavesComplete4 = false;
	WavesComplete5 = false;

	Accept1 = false;
	Accept2 = false;
	Accept3 = false;
	

	MaxHealth = 200;
	Damage = 25;
	MaxResistence = 100;

	NumberSpawnPast = 0;
	NumberSpawn = 0;
	Waves = 0;
	EnemyKill = 0;
	Battle = false;

}
