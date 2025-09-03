#include "GameManager.h"
#include "Driscoll_String.h"
#include "DamagePotion.h"
#include "HealthPotion.h"
#include "Shield.h"
#include "Lighting.h"
#include "Poison.h"
#include "Curse.h"

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
			AllRooms[i] = AdventureRoom(HealthPotion(), true, "Brewing Room");
			AllRooms[i].SetRoomID(i);
			break;
		case 4:
			//WIZARD'S LAIR
			AllRooms[i] = AdventureRoom(DamagePotion(), true, "Lair");
			AllRooms[i].SetRoomID(i);
			break;
		case 5:
			//ARMORY
			AllRooms[i] = AdventureRoom(Shield(), true, "Armory");
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
				if (inventory[0].GetItemType() == NONE)
				{
					Print("There is nothing in your inventory.");
				}
				else
				{
					for (int i = 0; inventory[i].GetItemType() != NONE; ++i)
					{
						Print(inventory[i].GetItemName());
						Print(inventory[i].GetItemDescription());
					}
				}
			}
			else
			{
				Print("Please type a valid Command.");
			}
			break;
		case 1:
			//CONNECTING ROOM
			Print("This is just the hallway that will connect you to the rest of the dungeon.");
			Print("To switch rooms by typing: \n 1. Left \n 2. Up (BOSS ROOM) \n 3. Right \n 4. Down");
			Print("You may also check your inventory by typing: \n 5. Inventory");
			Print("You may quit by typing: \n 6. Quit");
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
				CurrentRoom = AllRooms[5];
			}
			else if (strInput.Find("up") != -1)
			{
				Print("You move to the room on the top.");
				CurrentRoom = AllRooms[2];
			}
			else if (strInput.Find("right") != -1)
			{
				Print("You move to the room on the right.");
				CurrentRoom = AllRooms[6];
			}
			else if (strInput.Find("down"))
			{
				Print("You move to the room on the bottom.");
				CurrentRoom = AllRooms[0];
			}
			else if (strInput.Find("inventory") != -1)
			{
				Item* inventory = CurrentPlayer->GetInventory();
				if (inventory[0].GetItemType() == NONE)
				{
					Print("There is nothing in your inventory.");
				}
				else
				{
					for (int i = 0; inventory[i].GetItemType() != NONE; ++i)
					{
						Print(inventory[i].GetItemName());
						Print(inventory[i].GetItemDescription());
					}
				}
			}
			else
			{
				Print("Please type a valid Command.");
			}
			break;
		case 2:
			//FINAL BOSS ROOM
			Print("'HAHAHA' cackles the witch. 'It's time to fight my new Giant Skeleton! Don't worry, it's won every fight so far! HAHAHAHA'");
			Print("'Best of luck my Wizard. Use your spells and items to survive, and I'll see you on the other side of this mansion.'");
			bIsExploring = false;
			break;
		case 3:
			//WITCH'S BREWING ROOM
			if (CurrentRoom.GetItem() != nullptr)
			{
				Print("This room has a big pot in the middle filled with some green liquid. \n There is an empty bottle on the table next to the pot.");
				Print("You may grab the item by typing, \n 0. Retrieve");
			}
			Print("To switch rooms by typing: \n 1. Right");
			Print("You may also check your inventory by typing: \n 2. Inventory");
			Print("You may quit by typing: \n 3. Quit");
			std::cin >> input;
			strInput = input;
			strInput.ToLower();

			if (strInput.Find("quit") != -1)
			{
				bIsKeepPlaying = false;
				break;
			}
			else if (strInput.Find("right") != -1)
			{
				Print("You move to the room on the right.");
				CurrentRoom = AllRooms[0];
			}
			else if ((strInput.Find("retrieve") != -1) && CurrentRoom.GetItem() != nullptr)
			{
					Print(Driscoll_String("You acquired a ") + CurrentRoom.GetItemName());
					CurrentPlayer->AddItem(CurrentRoom.GetItem());
					CurrentRoom.SetItemTaken(true);
			}
			else if (strInput.Find("inventory") != -1)
			{
				Item* inventory = CurrentPlayer->GetInventory();
				if (inventory[0].GetItemType() == NONE)
				{
					Print("There is nothing in your inventory.");
				}
				else
				{
					for (int i = 0; inventory[i].GetItemType() != NONE; ++i)
					{
						Print(inventory[i].GetItemName());
						Print(inventory[i].GetItemDescription());
					}
				}
			}
			else
			{
				Print("Please type a valid Command.");
			}
			break;
		case 4:
			//WIZARD'S LAIR
			if (CurrentRoom.GetItem() != nullptr)
			{
				Print("This room has a tiny potion located in the corner on a shelf. \n It appears to have a red liquid inside of it.");
				Print("You may grab the item by typing, \n 0. Retrieve");
			}
			Print("To switch rooms by typing: \n 1. Left");
			Print("You may also check your inventory by typing: \n 2. Inventory");
			Print("You may quit by typing: \n 3. Quit");
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
				CurrentRoom = AllRooms[0];
			}
			else if ((strInput.Find("retrieve") != -1) && CurrentRoom.GetItem() != nullptr)
			{
				Print(Driscoll_String("You acquired a ") + CurrentRoom.GetItemName());
				CurrentPlayer->AddItem(CurrentRoom.GetItem());
				CurrentRoom.SetItemTaken(true);
			}
			else if (strInput.Find("inventory") != -1)
			{
				Item* inventory = CurrentPlayer->GetInventory();
				if (inventory[0].GetItemType() == NONE)
				{
					Print("There is nothing in your inventory.");
				}
				else
				{
					for (int i = 0; inventory[i].GetItemType() != NONE; ++i)
					{
						Print(inventory[i].GetItemName());
						Print(inventory[i].GetItemDescription());
					}
				}
			}
			else
			{
				Print("Please type a valid Command.");
			}
			break;
		case 5:
			//ARMORY
			if (CurrentRoom.GetItem() != nullptr)
			{
				Print("This room has a lot of locked lockers on the outskirts of the room. \n In the middle of the room you find an open locker with a shield inside.");
				Print("You may grab the item by typing, \n 0. Retrieve");
			}
			Print("To switch rooms by typing: \n 3. Right");
			Print("You may also check your inventory by typing: \n 5. Inventory");
			Print("You may quit by typing: \n 6. Quit");
			std::cin >> input;
			strInput = input;
			strInput.ToLower();

			if (strInput.Find("quit") != -1)
			{
				bIsKeepPlaying = false;
				break;
			}
			else if (strInput.Find("right") != -1)
			{
				Print("You move to the room on the right.");
				CurrentRoom = AllRooms[1];
			}
			else if ((strInput.Find("retrieve") != -1) && CurrentRoom.GetItem() != nullptr)
			{
				Print(Driscoll_String("You acquired a ") + CurrentRoom.GetItemName());
				CurrentPlayer->AddItem(CurrentRoom.GetItem());
				CurrentRoom.SetItemTaken(true);
			}
			else if (strInput.Find("inventory") != -1)
			{
				Item* inventory = CurrentPlayer->GetInventory();
				if (inventory[0].GetItemType() == NONE)
				{
					Print("There is nothing in your inventory.");
				}
				else
				{
					for (int i = 0; inventory[i].GetItemType() != NONE; ++i)
					{
						Print(inventory[i].GetItemName());
						Print(inventory[i].GetItemDescription());
					}
				}
			}
			else
			{
				Print("Please type a valid Command.");
			}
			break;
		case 6:
			//THE ALTAR
			if (CurrentPlayer->GetSpellsLeanred()[1].GetSpellType() == NONE)
			{
				Print("This room has a big altar in the middle, with a spellbook on the reading stand. \n You walk upto the spellbook and on the first page you figure out how you can learn a new spell.");
				Print("You may learn a new spell by typing, \n 1. Lighting \n 2. Poison \n 3. Curse");
			}
			Print("To switch rooms by typing: \n 4. Left");
			Print("You may also check your inventory by typing: \n 5. Inventory");
			Print("You may quit by typing: \n 6. Quit");
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
				CurrentRoom = AllRooms[1];
			}
			else if (strInput.Find("lighting") != -1)
			{
				Print("You learned the Lighting Spell.");
				CurrentPlayer->LearnSpell(Lighting());
			}
			else if (strInput.Find("poison") != -1)
			{
				Print("You learned the Poison Spell.");
				CurrentPlayer->LearnSpell(Poison());
			}
			else if (strInput.Find("curse") != -1)
			{
				Print("You learned the Curse Spell.");
				CurrentPlayer->LearnSpell(Curse());
			}
			else if (strInput.Find("inventory") != -1)
			{
				Item* inventory = CurrentPlayer->GetInventory();
				if (inventory[0].GetItemType() == NONE)
				{
					Print("There is nothing in your inventory.");
				}
				else
				{
					for (int i = 0; inventory[i].GetItemType() != NONE; ++i)
					{
						Print(inventory[i].GetItemName());
						Print(inventory[i].GetItemDescription());
					}
				}
			}
			else
			{
				Print("Please type a valid Command.");
			}
			break;
		}
		Print("======================================================================================================");
	}
	else
	{
		//Combat Sequence
	}
}

