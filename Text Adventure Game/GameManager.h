#pragma once
#include "AdventureRoom.h"
#include "Player.h"
#include "Enemy.h"

class GameManager
{
public:
	GameManager();

	~GameManager();

	bool bIsKeepPlaying;
private:
	AdventureRoom CurrentRoom;
	AdventureRoom* AllRooms;
	size_t ALLROOMS_LENGTH;
	Player* CurrentPlayer;
	Enemy* CurrentEnemy;
	bool bIsExploring;

public:
	//FUNCTIONS

	void BeginPlay();

	void Update();
	
};

