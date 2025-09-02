#include "GameManager.h"

GameManager::GameManager()
{
	AllRooms = new AdventureRoom[7];
	ALLROOMS_LENGTH = 7;

	//Create the Rooms
	for (int i = 0; i < ALLROOMS_LENGTH; ++i)
	{
		switch (i)
		{
		case 0:
			//START ROOM
			AllRooms[i] = AdventureRoom(Item(), false, "Starting Room");
			break;
		case 1:
			//CONNECTING ROOM
			AllRooms[i] = AdventureRoom(Item(), false, "Hallway");
			break;
		case 2:
			//FINAL BOSS ROOM
			AllRooms[i] = AdventureRoom("Boss Room");
			break;
		case 3:
			//WITCH'S BREWING ROOM
			AllRooms[i] = AdventureRoom(Item(), true, "Brewing Room");
			break;
		case 4:
			//WIZARD'S LAIR
			AllRooms[i] = AdventureRoom(Item(), true, "Lair");
			break;
		case 5:
			//ARMORY
			AllRooms[i] = AdventureRoom(Item(), true, "Armory");
			break;
		case 6:
			//THE ALTAR
			AllRooms[i] = AdventureRoom(true, "Altar");
			break;
		}
	}

	CurrentRoom = AllRooms[0];

	CurrentPlayer = new Player();

	CurrentEnemy = new Enemy();
}

GameManager::~GameManager()
{
	delete[] AllRooms;

	delete CurrentPlayer;

	delete CurrentEnemy;
}

void GameManager::BeginPlay()
{

}

void GameManager::Update()
{

}
