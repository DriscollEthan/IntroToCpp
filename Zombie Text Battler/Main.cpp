#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Main.h"

///	Feature List:
///	*Block Increases Defense vs Mitigates Damage [COMPLETE]
/// *Potion Randomely Regains health or Buffs Damage [NEEDS TESTING]
/// *Player Feedback, such as letting the player know of any Critcal Hits, What The Potion Does, etc. [DO THIS BEFORE MAKING A ZOMBIE BOT]
///	*Zombie Makes Realistic Choices (Besides Block)
/// *More Randomness in this Random Generator (I NEED SOME RESEARCH FOR THIS)

//C-String Equal
bool StrEqual(char StringA[], int STRING_A_LENGTH, char StringB[], int STRING_B_LENGTH)
{
	for (int i = 0; i < STRING_A_LENGTH; ++i)
	{
		if (StringA[i] != StringB[i])
		{
			return false;
		}
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
int StrSwitch(char String[], int STRING_LENGTH, char Case1[], char Case2[], char Case3[])
{
	if (StrEqual(String, STRING_LENGTH, Case1, STRING_LENGTH))
	{
		return 0;
	}
	else if (StrEqual(String, STRING_LENGTH, Case2, STRING_LENGTH))
	{
		return 1;
	}
	else if (StrEqual(String, STRING_LENGTH, Case3, STRING_LENGTH))
	{
		return 2;
	}
	return -1;
}

//Character Class
class Character
{
	float CurrentHealth = 100.0f;
	float DamageBase = 10.0f;
	float CriticalDamageMultiplier = 2.0f;
	int CriticalChance = 3;
	float Defense = 2.0f;
	float DefenseIncreaseBase = 1.0f;
	float MaxBaseDamage = 50.0f;

public:
	Character() { }
	Character(float BaseDamage, float BaseMaxDamage) { DamageBase = BaseDamage; MaxBaseDamage = BaseMaxDamage; }

	float GetCurrentHealth()
	{
		return CurrentHealth;
	}

	float GetBaseDamage() { return DamageBase; }

	void ChangeDamageBase(float ChangeDamageBy)
	{
		DamageBase += ChangeDamageBy;
	}

	float GetDamage(float EnemyDefense)
	{
		bool bIsCriticalHit = (std::rand() % CriticalChance == 0);

		float postCalculatedDefense = EnemyDefense / 10;

		if (DamageBase <= 0)
		{
			DamageBase = 1;
		}

		if (DamageBase > MaxBaseDamage)
		{
			DamageBase = MaxBaseDamage;
		}

		if (bIsCriticalHit)
		{
			std::cout << "Critical Hit!" << std::endl;
			std::cout << std::endl;

			postCalculatedDefense *= 7.0;

			float postCalcDamage = (DamageBase * CriticalDamageMultiplier) - postCalculatedDefense;
			if (postCalcDamage <= 0)
			{
				postCalcDamage = ((DamageBase * CriticalDamageMultiplier) / 10) * 3.0;
			}
			return postCalcDamage;
		}
		else
		{
			postCalculatedDefense *= 8.5f;

			float postCalcDamage = DamageBase - postCalculatedDefense;
			if (postCalcDamage <= 0)
			{
				postCalcDamage = (DamageBase / 10) * 1.5f;
			}
			return postCalcDamage;
		} 
	}

	float TakeDamage(float DamageDealt)
	{
		CurrentHealth -= DamageDealt;
		return GetCurrentHealth();
	}

	float GetDefense()
	{
		return Defense;
	}

	void IncreaseDefense()
	{
		Defense += DefenseIncreaseBase;
	}

	void UsePotion()
	{
		//	Potition Types:
		//	Increase Damage
		//	Increase Health
		//	Increase Defense

		int potionType = std::rand() % 3;

		switch (potionType)
		{
		case 0:
			DamageBase += 2.5f;
			std::cout << "Damage Increased!" << std::endl;
			std::cout << std::endl;
			break;
		case 1:
			CurrentHealth += 20;
			std::cout << "Health Increased!" << std::endl;
			std::cout << std::endl;
			break;
		case 2:
			IncreaseDefense();
			IncreaseDefense();
			std::cout << "Defense Increased!" << std::endl;
			std::cout << std::endl;
			break;
		default:
			std::cout << "Potion Missed" << std::endl;
			std::cout << std::endl;
			break;
		}
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
	const int INPUT_ARRAY_LENGTH = 50;
	char GlobalInput[INPUT_ARRAY_LENGTH] = {};
	Character Player(9.0f, 100000.0f);
	Character Zombie(8.0f, 20.0f);
	bool bKeepBattling = true;
	std::srand(std::time(nullptr));
		
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
		StrReset(GlobalInput, INPUT_ARRAY_LENGTH);
		std::cout << "Are you ready to fight? If you are ready type, 'true'" << std::endl;
		std::cout << std::endl;
		std::cin >> GlobalInput;
	}

	//Battle Loop
	while (bKeepBattling)
	{
		//Reset Global Variables
		//Display Player Health and Zombie Health
		DisplayBattleInformation(Player, Zombie);
		StrReset(GlobalInput, INPUT_ARRAY_LENGTH);
		bool bIsPlayerStunned = false;
		bool bIsZombieStunned = false;


		//Prompt Player on Choices
		// +
		//Get Player's Command (Attack, Block, [TBD]Potion[TBD])
		if (!bIsPlayerStunned)
		{
			char AttackInput[INPUT_ARRAY_LENGTH] = "attack";
			char BlockInput[INPUT_ARRAY_LENGTH] = "defense";
			char PotionInput[INPUT_ARRAY_LENGTH] = "potion";
			while (!StrEqual(GlobalInput, INPUT_ARRAY_LENGTH, AttackInput, INPUT_ARRAY_LENGTH)
				&& !StrEqual(GlobalInput, INPUT_ARRAY_LENGTH, BlockInput, INPUT_ARRAY_LENGTH)
				&& !StrEqual(GlobalInput, INPUT_ARRAY_LENGTH, PotionInput, INPUT_ARRAY_LENGTH))
			{
				std::cout << "You may choose to attack by typing 'attack', Increase Defense by typing 'defense', or use a potion by typing	'potion'. The potion can heal, increase defense 2 fold, or increase attack. Please choose wisely." << std::endl;

				std::cout << std::endl;
				std::cin >> GlobalInput;
			}
			float DamageToDeal = 0.0f;
			//Do Player's Command in Background and Display Information
			switch (StrSwitch(GlobalInput, INPUT_ARRAY_LENGTH, AttackInput, BlockInput, PotionInput))
			{
			case 0:
				std::cout << "You Attack The Zombie!" << std::endl;
				std::cout << std::endl;
				DamageToDeal = Player.GetDamage(Zombie.GetDefense());
				Zombie.TakeDamage(DamageToDeal);
				if (DamageToDeal > Player.GetBaseDamage())
				{
					bIsZombieStunned = true;
				}
				Zombie.ChangeDamageBase(1.0f);
				break;
			case 1:
				std::cout << "You Increase Your Defense" << std::endl;
				std::cout << std::endl;
				Player.IncreaseDefense();

				Zombie.ChangeDamageBase(-0.5f);
				break;
			case 2:
				std::cout << "You Use A Potion" << std::endl;
				std::cout << std::endl;
				Player.UsePotion();
				Zombie.ChangeDamageBase(1.5f);
				break;
			}
		}

		else 
		{

		}

		DisplayBattleInformation(Player, Zombie);

		//Zombie Moves

		//When Zombie Should Always Attack
		if (!bIsZombieStunned)
		{
			if (Zombie.GetCurrentHealth() > 30.0f)
			{
				std::cout << "The Zombie Attacks!" << std::endl;
				std::cout << std::endl;

				float DamageToDeal = Zombie.GetDamage(Player.GetDefense());
				if (DamageToDeal > Player.GetBaseDamage())
				{
					bIsPlayerStunned = true;
				}
				Player.TakeDamage(DamageToDeal);
			}
			//Randomely Increases Defense
			else
			{
			float DamageToDeal = 0.0f;
				switch (std::rand() % 3)
				{
				case 0:
					std::cout << "The Zombie Increases Defense!" << std::endl;
					std::cout << std::endl;
					Zombie.IncreaseDefense();
					Zombie.TakeDamage((Player.GetDamage(Zombie.GetDefense()) / 2) / 2);
					break;
				case 1:
					std::cout << "The Zombie Uses a Potion!" << std::endl;
					std::cout << std::endl;
					Zombie.UsePotion();
					Zombie.TakeDamage((Player.GetDamage(Zombie.GetDefense()) / 2) / 2);
					break;
				case 2:
					std::cout << "The Zombie Attacks!" << std::endl;
					std::cout << std::endl;
					DamageToDeal = Zombie.GetDamage(Player.GetDefense());
					if (DamageToDeal > Player.GetBaseDamage())
					{
						bIsPlayerStunned = true;
					}
					Player.TakeDamage(DamageToDeal);
				}
				Zombie.TakeDamage(Player.GetDamage(Zombie.GetDefense()));
				break;
			}
		}
	}
		//Check for Deaths (Someone Died) ? End Loop : Keep Going
		if (Player.GetCurrentHealth() <= 0 || Zombie.GetCurrentHealth() <= 0)
		{
			bKeepBattling = false;
		}


	//Inform Player of Result
	if (Zombie.GetCurrentHealth() < Player.GetCurrentHealth()) 
	{
		std::cout << "You have defeated the Zombie. Can you do it faster?" << std::endl;
	}

	else
	{
		std::cout << "You have died fighting the Zombie. Better luck next time!" << std::endl;
	}

	DisplayBattleInformation(Player, Zombie);

	std::cout << std::endl;

	std::cout << "Thank you for playing! Please come back again soon!";

	StrReset(GlobalInput, INPUT_ARRAY_LENGTH);
	char QuitInput[INPUT_ARRAY_LENGTH] = "quit";
	while (!StrEqual(GlobalInput, INPUT_ARRAY_LENGTH, QuitInput, INPUT_ARRAY_LENGTH))
	{
		StrReset(GlobalInput, INPUT_ARRAY_LENGTH);
		std::cout << "Type 'quit' to quit" << std::endl;
		std::cout << std::endl;
		std::cin >> GlobalInput;
	}
}