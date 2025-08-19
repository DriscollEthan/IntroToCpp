#include <iostream>

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
		if (Scores[i].HighScore < Scores[highestScoreIndex].HighScore)
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
			if (Scores[j].HighScore > Scores[i].HighScore)
			{
				HighScoreData tempVarForSwap = Scores[j];

				Scores[j] = Scores[i];

				Scores[i] = tempVarForSwap;
			}
		}
	}

	for (int i = 0; i < HIGHESTSCORESARRAY_LENGTH; ++i)
	{
		HighestScoresArray[i] = Scores[i];
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
};




int main()
{

}