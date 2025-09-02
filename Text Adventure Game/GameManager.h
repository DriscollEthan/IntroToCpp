#pragma once
#include "AdventureRoom.h"
#include "Player.h"
#include "Enemy.h"

class GameManager
{
public:
	GameManager();

	~GameManager();

private:
	AdventureRoom CurrentRoom;
	AdventureRoom* AllRooms;
	size_t ALLROOMS_LENGTH;
	Player* CurrentPlayer;
	Enemy* CurrentEnemy;

public:
	//FUNCTIONS

	void BeginPlay();

	void Update();
};

