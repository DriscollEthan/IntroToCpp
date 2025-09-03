//GAME LOOP SETUP
#include "GameManager.h"

int main()
{
	bool bKeepPlaying = true;
	GameManager* Game = new GameManager();

	Game->BeginPlay();

	while (bKeepPlaying)
	{
		//BEGIN
		Game->Update();
	}

	delete Game;
}