//GAME LOOP SETUP
#include "GameManager.h"

int main()
{
	GameManager* Game = new GameManager();
	bool bKeepPlaying = Game->bIsKeepPlaying;

	Game->BeginPlay();

	while (bKeepPlaying)
	{
		//BEGIN
		Game->Update();
		bKeepPlaying = Game->bIsKeepPlaying;
	}

	delete Game;
}