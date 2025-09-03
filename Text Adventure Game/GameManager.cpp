#include "GameManager.h"
#include "Driscoll_String.h"

void Print(Driscoll_String _text)
{
	std::cout << _text << std::endl;
}

GameManager::GameManager()
{
	ALLROOMS_LENGTH = 7;
	AllRooms = new AdventureRoom[ALLROOMS_LENGTH];

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
	char input[256];
	Driscoll_String strInput;

	if (bIsExploring)
	{
		//Exploring Sequences
		std::cout << "You are in the ";
		Print(CurrentRoom.GetRoomName());
		switch (CurrentRoom.GetRoomID())
		{
		case 0:
			//START ROOM
			Print("You have acquired the Fireball Spell. \n You may now move to another room.");
			Print("To switch rooms by typing: \n 1. Left \n 2. Up \n 3. Right");
			Print("You may also check your inventory by typing: \n 4. Inventory");
			Print("You may quit by typing: \n 5. Quit");
			std::cin >> input;
			strInput = input;
			strInput.ToLower();

			if (strInput.Find("quit") != -1)
			{
				bIsKeepPlaying = false;
				break;
			}
			else if (strInput.Find("left") != -1)
			{
				Print("You move to the room on the left.");
				CurrentRoom = AllRooms[3];
			}
			else if (strInput.Find("up") != -1)
			{
				Print("You move to the room on the top.");
				CurrentRoom = AllRooms[1];
			}
			else if (strInput.Find("right") != -1)
			{
				Print("You move to the room on the right.");
				CurrentRoom = AllRooms[4];
			}
			else if (strInput.Find("inventory") != -1)
			{
				Item* inventory = CurrentPlayer->GetInventory();
				for (int i = 0; inventory[i].GetItemType() != NONE; ++i)
				{
					Print(inventory[i].GetItemName());
					Print(inventory[i].GetItemDescription());
				}
			}
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

