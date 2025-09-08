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
			Print(" \n ");
			std::cin >> input;
			strInput = input;
			strInput.ToLower();

			if (strInput == "left" || strInput == "1")
			{
				Print("You move to the room on the left.");
				CurrentRoom = AllRooms[3];
			}
			else if (strInput == "up" || strInput == "2")
			{
				Print("You move to the room on the top.");
				CurrentRoom = AllRooms[1];
			}
			else if (strInput == "right" || strInput == "3")
			{
				Print("You move to the room on the right.");
				CurrentRoom = AllRooms[4];
			}
			else if (strInput.Find("inv") != -1 || strInput == "4")
			{
				Item* inventory = CurrentPlayer->GetInventory();
				if (inventory[0].GetItemType() == NONE)
				{
					Print("There is nothing in your inventory.");
				}
				else
				{
					for (int i = 0; inventory[i].GetItemType() != NONE && i < 3; ++i)
					{
						Print(inventory[i].GetItemName());
						Print(inventory[i].GetItemDescription());
						Print(" \n ");
					}
				}
			}
			else if (strInput.Find("quit") != -1 || strInput == "5")
			{
				bIsKeepPlaying = false;
				break;
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
			Print(" \n ");
			std::cin >> input;
			strInput = input;
			strInput.ToLower();

			if (strInput == "left" || strInput == "1")
			{
				Print("You move to the room on the left.");
				CurrentRoom = AllRooms[5];
			}
			else if (strInput == "up" || strInput == "2")
			{
				Print("You move to the room on the top.");
				CurrentRoom = AllRooms[2];
			}
			else if (strInput == "right" || strInput == "3")
			{
				Print("You move to the room on the right.");
				CurrentRoom = AllRooms[6];
			}
			else if (strInput == "down" || strInput == "4")
			{
				Print("You move to the room on the bottom.");
				CurrentRoom = AllRooms[0];
			}
			else if (strInput.Find("inv") != -1 || strInput == "5")
			{
				Item* inventory = CurrentPlayer->GetInventory();
				if (inventory[0].GetItemType() == NONE)
				{
					Print("There is nothing in your inventory.");
				}
				else
				{
					for (int i = 0; inventory[i].GetItemType() != NONE && i < 3; ++i)
					{
						Print(inventory[i].GetItemName());
						Print(inventory[i].GetItemDescription());
						Print(" \n ");
					}
				}
			}
			else if (strInput.Find("quit") != -1 || strInput == "6")
			{
				bIsKeepPlaying = false;
				break;
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
			Print(" \n ");
			bIsExploring = false;
			break;
		case 3:
			//WITCH'S BREWING ROOM
			if (CurrentRoom.GetItem() != nullptr)
			{
				Print("This room has a big pot in the middle filled with some green liquid. \n There is an empty bottle on the table next to the pot.");
				Print("You may grab the item by typing, \n 0. Grab");
			}
			Print("To switch rooms by typing: \n 1. Right");
			Print("You may also check your inventory by typing: \n 2. Inventory");
			Print("You may quit by typing: \n 3. Quit");
			Print(" \n ");
			std::cin >> input;
			strInput = input;
			strInput.ToLower();

			if (strInput == "right" || strInput == "1")
			{
				Print("You move to the room on the right.");
				CurrentRoom = AllRooms[0];
			}
			else if ((strInput.Find("grab") != -1 || strInput == "0") && CurrentRoom.GetItem() != nullptr)
			{
				Print(Driscoll_String("You acquired a ") + CurrentRoom.GetItemName());
				CurrentPlayer->AddItem(CurrentRoom.GetItem());
				CurrentRoom.SetItemTaken(true);
				AllRooms[3].SetItemTaken(true);
			}
			else if (strInput.Find("inv") != -1 || strInput == "2")
			{
				Item* inventory = CurrentPlayer->GetInventory();
				if (inventory[0].GetItemType() == NONE)
				{
					Print("There is nothing in your inventory.");
				}
				else
				{
					for (int i = 0; inventory[i].GetItemType() != NONE && i < 3; ++i)
					{
						Print(inventory[i].GetItemName());
						Print(inventory[i].GetItemDescription());
						Print(" \n ");
					}
				}
			}
			else if (strInput.Find("quit") != -1 || strInput == "3")
			{
				bIsKeepPlaying = false;
				break;
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
				Print("You may grab the item by typing, \n 0. Grab");
			}
			Print("To switch rooms by typing: \n 1. Left");
			Print("You may also check your inventory by typing: \n 2. Inventory");
			Print("You may quit by typing: \n 3. Quit");
			Print(" \n ");
			std::cin >> input;
			strInput = input;
			strInput.ToLower();

			if (strInput == "left" || strInput == "1")
			{
				Print("You move to the room on the left.");
				CurrentRoom = AllRooms[0];
			}
			else if ((strInput.Find("grab") != -1 || strInput == "0") && CurrentRoom.GetItem() != nullptr)
			{
				Print(Driscoll_String("You acquired a ") + CurrentRoom.GetItemName());
				CurrentPlayer->AddItem(CurrentRoom.GetItem());
				CurrentRoom.SetItemTaken(true);
				AllRooms[4].SetItemTaken(true);
			}
			else if (strInput.Find("inv") != -1 || strInput == "2")
			{
				Item* inventory = CurrentPlayer->GetInventory();
				if (inventory[0].GetItemType() == NONE)
				{
					Print("There is nothing in your inventory.");
				}
				else
				{
					for (int i = 0; inventory[i].GetItemType() != NONE && i < 3; ++i)
					{
						Print(inventory[i].GetItemName());
						Print(inventory[i].GetItemDescription());
						Print(" \n ");
					}
				}
			}
			else if (strInput.Find("quit") != -1 || strInput == "3")
			{
				bIsKeepPlaying = false;
				break;
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
				Print("You may grab the item by typing, \n 0. Grab");
			}
			Print("To switch rooms by typing: \n 1. Right");
			Print("You may also check your inventory by typing: \n 2. Inventory");
			Print("You may quit by typing: \n 3. Quit");
			Print(" \n ");
			std::cin >> input;
			strInput = input;
			strInput.ToLower();

			if (strInput == "right" || strInput == "1")
			{
				Print("You move to the room on the right.");
				CurrentRoom = AllRooms[1];
			}
			else if ((strInput.Find("grab") != -1 || strInput == "0") && CurrentRoom.GetItem() != nullptr)
			{
				Print(Driscoll_String("You acquired a ") + CurrentRoom.GetItemName());
				CurrentPlayer->AddItem(CurrentRoom.GetItem());
				CurrentRoom.SetItemTaken(true);
				AllRooms[5].SetItemTaken(true);
			}
			else if (strInput.Find("inv") != -1 || strInput == "2")
			{
				Item* inventory = CurrentPlayer->GetInventory();
				if (inventory[0].GetItemType() == NONE)
				{
					Print("There is nothing in your inventory.");
				}
				else
				{
					for (int i = 0; inventory[i].GetItemType() != NONE && i < 3; ++i)
					{
						Print(inventory[i].GetItemName());
						Print(inventory[i].GetItemDescription());
						Print(" \n ");
					}
				}
			}
			else if (strInput.Find("quit") != -1 || strInput == "3")
			{
				bIsKeepPlaying = false;
				break;
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
				Print("You may learn a new spell by typing, \n 1. Lightning \n 2. Poison \n 3. Curse");
			}
			Print("To switch rooms by typing: \n 4. Left");
			Print("You may also check your inventory by typing: \n 5. Inventory");
			Print("You may quit by typing: \n 6. Quit");
			Print(" \n ");
			std::cin >> input;
			strInput = input;
			strInput.ToLower();

			if (strInput == "left" || strInput == "4")
			{
				Print("You move to the room on the left.");
				CurrentRoom = AllRooms[1];
			}
			else if (strInput.Find("lightning") != -1 || strInput == "1")
			{
				Print("You learned the Lightning Spell.");
				CurrentPlayer->LearnSpell(Lighting());
			}
			else if (strInput.Find("poison") != -1 || strInput == "2")
			{
				Print("You learned the Poison Spell.");
				CurrentPlayer->LearnSpell(Poison());
			}
			else if (strInput.Find("curse") != -1 || strInput == "3")
			{
				Print("You learned the Curse Spell.");
				CurrentPlayer->LearnSpell(Curse());
			}
			else if (strInput.Find("inv") != -1 || strInput == "5")
			{
				Item* inventory = CurrentPlayer->GetInventory();
				if (inventory[0].GetItemType() == NONE)
				{
					Print("There is nothing in your inventory.");
				}
				else
				{
					for (int i = 0; inventory[i].GetItemType() != NONE && i < 3; ++i)
					{
						Print(inventory[i].GetItemName());
						Print(inventory[i].GetItemDescription());
						Print(" \n ");
					}
				}
			}
			else if (strInput.Find("quit") != -1 || strInput == "6")
			{
				bIsKeepPlaying = false;
				break;
			}
			else
			{
				Print("Please type a valid Command.");
			}
			break;
		}
		Print("====================================================================================================== \n");
	}
	else
	{
		//Combat Sequence
		char input[256];
		Driscoll_String strInput;

		while (CurrentEnemy->GetHealth() > 0.0f && CurrentPlayer->GetHealth() > 0.0f)

		{
			Print("====================================================================================================== \n");
			std::cout << "Your health is: " << CurrentPlayer->GetHealth() << std::endl;
			Print(" ");
			std::cout << "The Witch's health is: " << CurrentEnemy->GetHealth() << std::endl;
			Print("You can use a Spell to attack, use an item as a consumable, or quit.");
			std::cout << "0. " << CurrentPlayer->GetSpellsLeanred()[0].GetSpellName() << ' ' << CurrentPlayer->GetSpellsLeanred()[0].GetSpellDescription() << std::endl;
			if ((CurrentPlayer->GetSpellsLeanred()[1].GetSpellType() != NONE) && (CurrentPlayer->SpellCooldownRoundTimer <= 0))
			{
				std::cout << "1. " << CurrentPlayer->GetSpellsLeanred()[1].GetSpellName() << ' ' << CurrentPlayer->GetSpellsLeanred()[1].GetSpellDescription() << std::endl;
			}
			else if (CurrentPlayer->SpellCooldownRoundTimer > 0)
			{
				std::cout << CurrentPlayer->GetSpellsLeanred()[1].GetSpellName() << " is recharging, it has: " << CurrentPlayer->SpellCooldownRoundTimer << " rounds left on the cooldown." << std::endl;
			}
			if (CurrentPlayer->GetInventory()[0].GetItemType() != NONE)
			{
				std::cout << "2. " << CurrentPlayer->GetInventory()[0].GetItemName() << ' ' << CurrentPlayer->GetInventory()[0].GetItemDescription() << std::endl;
			}
			if (CurrentPlayer->GetInventory()[1].GetItemType() != NONE)
			{
				std::cout << "3. " << CurrentPlayer->GetInventory()[1].GetItemName() << ' ' << CurrentPlayer->GetInventory()[1].GetItemDescription() << std::endl;
			}
			if (CurrentPlayer->GetInventory()[2].GetItemType() != NONE)
			{
				std::cout << "4. " << CurrentPlayer->GetInventory()[2].GetItemName() << ' ' << CurrentPlayer->GetInventory()[2].GetItemDescription() << std::endl;
			}
			Print("5. Quit");

			CurrentPlayer->SpellCooldownRoundTimer -= 1;
			CurrentPlayer->bIsLingeringEffect = (CurrentPlayer->SpellCooldownRoundTimer - 1 <= 0);

			//GET INPUT AND CHECK INPUT
			std::cin >> input;
			strInput = input;
			strInput.ToLower();

			if (strInput == "fireball" || strInput == "0")
			{
				float damage = CurrentPlayer->Attack(&(CurrentPlayer->GetSpellsLeanred()[0]));
				CurrentEnemy->TakeDamage(damage);
				std::cout << "You casted: " << CurrentPlayer->GetSpellsLeanred()[0].GetSpellName() << std::endl;
				std::cout << std::endl;
			}
			else if ((strInput == CurrentPlayer->GetSpellsLeanred()[1].GetSpellName().ToLower() || strInput == "1") && (CurrentPlayer->GetSpellsLeanred()[1].GetSpellType() != NONE) && (CurrentPlayer->SpellCooldownRoundTimer <= 0))
			{
				float damage = CurrentPlayer->Attack(&(CurrentPlayer->GetSpellsLeanred()[1]));
				CurrentEnemy->TakeDamage(damage);
				CurrentPlayer->SpellCooldownRoundTimer = 3;
				CurrentPlayer->bIsLingeringEffect = true;
				std::cout << "You casted: " << CurrentPlayer->GetSpellsLeanred()[1].GetSpellName() << std::endl;
				std::cout << std::endl;
			}
			else if ((strInput == CurrentPlayer->GetInventory()[0].GetItemName().ToLower() || strInput == "2") && CurrentPlayer->GetInventory()[0].GetItemType() != NONE)
			{
				std::cout << "You used a: " << CurrentPlayer->GetInventory()[0].GetItemName() << std::endl;
				CurrentPlayer->UseItem(&(CurrentPlayer->GetInventory()[0]));
				std::cout << std::endl;
			}
			else if ((strInput == CurrentPlayer->GetInventory()[1].GetItemName().ToLower() || strInput == "3") && CurrentPlayer->GetInventory()[1].GetItemType() != NONE)
			{
				std::cout << "You used a: " << CurrentPlayer->GetInventory()[1].GetItemName() << std::endl;
				CurrentPlayer->UseItem(&(CurrentPlayer->GetInventory()[1]));
				std::cout << std::endl;
			}
			else if ((strInput == CurrentPlayer->GetInventory()[2].GetItemName().ToLower() || strInput == "4") && CurrentPlayer->GetInventory()[2].GetItemType() != NONE)
			{
				std::cout << "You used a: " << CurrentPlayer->GetInventory()[2].GetItemName() << std::endl;
				CurrentPlayer->UseItem(&(CurrentPlayer->GetInventory()[2]));
				std::cout << std::endl;
			}
			else if (strInput == "quit" || strInput == "5")
			{
				bIsKeepPlaying = false;
				break;
			}
			else
			{
				Print("Please type a valid Command.");
			}

			//POISON DAMAGE
			if (CurrentPlayer->bIsLingeringEffect && CurrentPlayer->GetSpellsLeanred()[1].GetSpellType() == E_Poison)
			{
				CurrentEnemy->TakeDamage(CurrentPlayer->GetSpellsLeanred()[1].GetDamageOverTime());
			}
			//Enemy Death Check
			if (CurrentEnemy->GetHealth() <= 0.0f) { break; }

			//Enemy Attack
			if (CurrentPlayer->bIsLingeringEffect && CurrentPlayer->GetSpellsLeanred()[1].GetSpellType() == E_Lighting)
			{
				CurrentPlayer->bIsLingeringEffect = false;
				break;
			}

			//CURSE CHECK TO LOWER DAMAGE
			if (CurrentPlayer->bIsLingeringEffect && CurrentPlayer->GetSpellsLeanred()[1].GetSpellType() == E_Curse)
			{
				CurrentPlayer->TakeDamage((CurrentEnemy->GetDamage()) / 2);
			}
			else { CurrentPlayer->TakeDamage(CurrentEnemy->GetDamage()); }
		}

		std::cout << std::endl;
		if (CurrentEnemy->GetHealth() <= 0.0f)
		{
			Print("You killed the witch. \nCongratulations on defeating this dungeon. \nYou should try this again with some different spells.");
			bIsKeepPlaying = false;
		}
		else if (CurrentPlayer->GetHealth() <= 0.0f)
		{
			Print("You have died to the witch. \nYou should try gathering more items and spells to defeat the witch.");
			bIsKeepPlaying = false;
		}
	}
}
}