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
			AllRooms[i].SetRoomID(i);
			break;
		case 1:
			//CONNECTING ROOM
			AllRooms[i] = AdventureRoom(Item(), false, "Hallway");
			AllRooms[i].SetRoomID(i);
			break;
		case 2:
			//FINAL BOSS ROOM
			AllRooms[i] = AdventureRoom("Boss Room");
			AllRooms[i].SetRoomID(i);
			break;
		case 3:
			//WITCH'S BREWING ROOM
			AllRooms[i] = AdventureRoom(Item(), true, "Brewing Room");
			AllRooms[i].SetRoomID(i);
			break;
		case 4:
			//WIZARD'S LAIR
			AllRooms[i] = AdventureRoom(Item(), true, "Lair");
			AllRooms[i].SetRoomID(i);
			break;
		case 5:
			//ARMORY
			AllRooms[i] = AdventureRoom(Item(), true, "Armory");
			AllRooms[i].SetRoomID(i);
			break;
		case 6:
			//THE ALTAR
			AllRooms[i] = AdventureRoom(true, "Altar");
			AllRooms[i].SetRoomID(i);
			break;
		}

	}
		bIsKeepPlaying = true;

	CurrentRoom = AllRooms[0];

	CurrentPlayer = new Player();

	CurrentEnemy = new Enemy();

	bIsExploring = true;
}

GameManager::~GameManager()
{
	delete[] AllRooms;

	delete CurrentPlayer;

	delete CurrentEnemy;
}

void GameManager::BeginPlay()
{
	bIsExploring = true;
}

void GameManager::Update()
{
	char Input[256];

	if (bIsExploring)
	{
		//Exploring Sequences
		switch (CurrentRoom.GetRoomID())
		{
		case 0:
			//START ROOM
			
			break;
		case 1:
			//CONNECTING ROOM
			break;
		case 2:
			//FINAL BOSS ROOM
			break;
		case 3:
			//WITCH'S BREWING ROOM
			break;
		case 4:
			//WIZARD'S LAIR
			break;
		case 5:
			//ARMORY
			break;
		case 6:
			//THE ALTAR
			break;
		}
	}
	else
	{
		//Combat Sequence
	}
}
