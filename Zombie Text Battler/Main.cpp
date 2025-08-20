#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Main.h"

//C-String Equal
bool StrEqual(char StringA[], int STRING_A_LENGTH, char StringB[], int STRING_B_LENGTH)
{
	if (STRING_A_LENGTH = STRING_B_LENGTH)
	{
		for (int i = 0; i < STRING_A_LENGTH; ++i)
		{
			if (StringA[i] != StringB[i])
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
	return true;
}

//C-String Reset
void StrReset(char String[], int STRING_LENGTH)
{
	for (int i = 0; i < STRING_LENGTH; ++i)
	{
		String[i] = 0;
	}
}

//C-String Switch
int StrSwitch(char String[], int STRING_LENGTH, char Case1[], char Case2[])
{
	if (StrEqual(String, STRING_LENGTH, Case1, STRING_LENGTH))
	{
		return 0;
	}
	else if (StrEqual(String, STRING_LENGTH, Case2, STRING_LENGTH))
	{
		return 1;
	}
	return -1;
}

//Character Class
class Character
{
	float CurrentHealth = 100.0f;
	float DamageBase = 10.0f;
	float CriticalDamageMultiplier = 2.0f;
	int CriticalChance = 15;

public:
	float GetCurrentHealth()
	{
		return CurrentHealth;
	}

	float GetDamage()
	{
		std::srand(std::time(nullptr));

		bool bIsCriticalHit = (std::rand() % CriticalChance == 0);

		if (bIsCriticalHit)
		{
			return DamageBase * CriticalDamageMultiplier;
		}
		else
		{
			return DamageBase;
		}
	}

	float TakeDamage(float DamageDealt)
	{
		CurrentHealth -= DamageDealt;
		return GetCurrentHealth();
	}
};

//Extra Functions To Be Used In Battle
void DisplayBattleInformation(Character& Player, Character& Zombie)
{
	std::cout << "Your Current Health Is: " << Player.GetCurrentHealth() << std::endl;
	std::cout << std::endl;
	std::cout << "The Zombie's Current Health Is:  " << Zombie.GetCurrentHealth() << std::endl;
	std::cout << std::endl;
}

int main()
{
	//Global Variables
	const int INPUT_ARRAY_LENGTH = 10;
	char GlobalInput[INPUT_ARRAY_LENGTH] = {};
	Character Player = {};
	Character Zombie = {};
	bool bKeepBattling = true;
		
	//Greet Player
	std::cout << "Welcome to the Driscoll Arena! Today we've prepared some zombies ready for a battle!" << std::endl;
	std::cout << std::endl;

	//Get Player's Ok to Start Battle
	std::cout << "Are you ready to fight? If you are ready type, 'true'" << std::endl;
	std::cout << std::endl;
	std::cin >> GlobalInput;

	char ReadyToPlayInput[INPUT_ARRAY_LENGTH] = "true";
	while (!StrEqual(GlobalInput, INPUT_ARRAY_LENGTH, ReadyToPlayInput, INPUT_ARRAY_LENGTH))
	{
		std::cout << "Are you ready to fight? If you are ready type, 'true'" << std::endl;
		std::cout << std::endl;
		std::cin >> GlobalInput;
	}

	//Battle Loop
	while (bKeepBattling)
	{
		//Reset Global Variables
		StrReset(GlobalInput, INPUT_ARRAY_LENGTH);
		bool bDidPlayerBlock = false;

		//Display Player Health and Zombie Health
		DisplayBattleInformation(Player, Zombie);

		//Prompt Player on Choices
		// +
		//Get Player's Command (Attack, Block, [TBD]Potion[TBD])
		char AttackInput[INPUT_ARRAY_LENGTH] = "attack";
		char BlockInput[INPUT_ARRAY_LENGTH] = "block";
		while (!StrEqual(GlobalInput, INPUT_ARRAY_LENGTH, AttackInput, INPUT_ARRAY_LENGTH) && !StrEqual(GlobalInput, INPUT_ARRAY_LENGTH, BlockInput, INPUT_ARRAY_LENGTH))
		{
			std::cout << "You may choose to attack by typing 'attack' or block by typing 'block'. Please choose wisely." << std::endl;
			std::cout << std::endl;
			std::cin >> GlobalInput;
		}

		//Do Player's Command in Background and Display Information
		switch (StrSwitch(GlobalInput, INPUT_ARRAY_LENGTH, AttackInput, BlockInput))
		{
		case 0:
			Zombie.TakeDamage(Player.GetDamage());
			break;
		case 1:
			bDidPlayerBlock = true;
			break;
		}
		
		DisplayBattleInformation(Player, Zombie);

		//Have Zombie Attack Player
		if (!bDidPlayerBlock)
		{
			Player.TakeDamage(Zombie.GetDamage());
		}

		//Check for Deaths (Someone Died) ? End Loop : Keep Going
		if (Player.GetCurrentHealth() <= 0 || Zombie.GetCurrentHealth() <= 0)
		{
			bKeepBattling = false;
		}

	}

	//Inform Player of Result
	if (Zombie.GetCurrentHealth() <= 0) 
	{
		std::cout << "You have died fighting the Zombie. Better luck next time!" << std::endl;
	}

	else
	{
		std::cout << "You have defeated the Zombie. Can you do it faster?" << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Thank you for playing! Please come back again soon!";

}