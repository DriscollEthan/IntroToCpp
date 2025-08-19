#include <iostream>
#include <cstdlib>
#include <ctime>

void Print(std::string Text, bool bEndLine)
{
	std::cout << Text;

	if (bEndLine)
	{
		std::cout << std::endl;
	}
}

//HighScore Data and Function
struct HighScoreData
{
	int HighScore = 0;
	float TimeToComplete = 0.0f;
};

int HighestScoreIndex(HighScoreData Scores[], int SCORES_LENGTH)
{
	int highestScoreIndex = 0;

	for (int i = 1; i < SCORES_LENGTH; ++i)
	{
		if (Scores[i].HighScore > Scores[highestScoreIndex].HighScore)
		{
			highestScoreIndex = i;
		}
	}
	return highestScoreIndex;
}

float AverageTimeToComplete(HighScoreData Scores[], int SCORES_LENGTH)
{
	float totalTimeToComplete = 0.0f;

	for (int i = 0; i < SCORES_LENGTH; ++i)
	{
		totalTimeToComplete += Scores[i].TimeToComplete;
	}

	return totalTimeToComplete / SCORES_LENGTH;
}

void HighestScores(HighScoreData Scores[], int SCORES_LENGTH, HighScoreData HighestScoresArray[], int HIGHESTSCORESARRAY_LENGTH)
{

	//Sort the HighScoreData to find the right amount of high scores
	for (int i = 0; i < SCORES_LENGTH; ++i)
	{
		for (int j = 0; j < SCORES_LENGTH; ++j)
		{
			if (Scores[j].HighScore < Scores[i].HighScore)
			{
				HighScoreData tempVarForSwap = Scores[j];

				Scores[j] = Scores[i];

				Scores[i] = tempVarForSwap;
			}
		}
	}

	for (int i = 0; i < HIGHESTSCORESARRAY_LENGTH; ++i)
	{
		HighestScoresArray[i].HighScore = Scores[i].HighScore;
		HighestScoresArray[i].TimeToComplete = Scores[i].TimeToComplete;
	}

	return;
}

int DifferenceBetweenFirstPlaceAndCurrentScore(HighScoreData Scores[], int SCORES_LENGTH, int CurrentScore)
{
	int highestScore = Scores[HighestScoreIndex(Scores, SCORES_LENGTH)].HighScore;

	return highestScore - CurrentScore;
}

//Player Class Data and Function
class Player
{
private:
	// The current health of the player
	int Health = 0;
	
	// The current Attack of the player
	int Attack = 0;
	
	// The current Defense of the player
	int Defense = 0;

	// The current Speed of the player
	int Speed = 0;

public:
	// Returns the current health of the player
	int GetHealth()
	{
		return Health;
	}

	// Returns the current Attack of the player
	int GetAttack()
	{
		return Attack;
	}

	// Returns the current Defense of the player
	int GetDefense()
	{
		return Defense;
	}

	// Returns the current Speed of the player
	int GetSpeed()
	{
		return Speed;
	}

	void RandomizeStats()
	{
		std::srand(std::time(nullptr));

		Health = std::rand() % 100;
		Attack = std::rand() % 100;
		Defense = std::rand() % 100;
		Speed = std::rand() % 100;
	}

	int TakeDamage(int DamageDealth)
	{
		std::srand(std::time(nullptr));

		bool bEvadedAttack = (0 == std::rand() % 10);

		if (!bEvadedAttack)
		{
			DamageDealth -= Defense;
			Health -= DamageDealth;
		}
		return Health;
	}

};

void PlayerRandomizerGenerator(Player Players[], int PLAYERS_LENGTH)
{

	for (int i = 0; i < PLAYERS_LENGTH; ++i)
	{
		Players[i].RandomizeStats();
		
		std::cout << "Health: " << Players[i].GetHealth() << std::endl;
		std::cout << "Attack: " << Players[i].GetAttack() << std::endl;
		std::cout << "Defense: " << Players[i].GetDefense() << std::endl;
		std::cout << "Speed: " << Players[i].GetSpeed() << std::endl;
	}
}


int main()
{
	HighScoreData HighScores[5] = { {71, 27}, {31, 47}, {83, 48}, {20, 69}, {94, 86} };
	Player Players[5] = {};
	HighScoreData HighestScoresArray[3] = {};

	std::cout << "Highest Score Index is: " << HighestScoreIndex(HighScores, 5) << std::endl;
	std::cout << "Average Time To Complete is: " << AverageTimeToComplete(HighScores, 5) << std::endl;

	HighestScores(HighScores, 5, HighestScoresArray, 3);
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "Highest Scores Are: " << HighestScoresArray[i].HighScore << std::endl;
	}
	std::cout << "Socre Difference to Highest Score is: " << DifferenceBetweenFirstPlaceAndCurrentScore(HighScores, 5, 9) << std::endl;

	PlayerRandomizerGenerator(Players, 5);

	for (int i = 0; i < 5; ++i)
	{
		std::srand(std::time(nullptr));

		int RandomValue = std::rand() % 100;

		std::cout << "Player has health left; " << Players[i].TakeDamage(RandomValue) << std::endl;
	}
}
