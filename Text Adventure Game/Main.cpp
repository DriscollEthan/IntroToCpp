//GAME LOOP SETUP
#include "GameManager.h"

int main()
{
	bool bOverlordPlaying = true;

	while (bOverlordPlaying)
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

		char input[256];
		Driscoll_String strInput;
		std::cout << "Do you want to restart? \n If so then type: Yes." << std::endl;
		std::cin >> input;
		strInput = input;
		strInput.ToLower();
		if (strInput != "yes")
		{
		 bOverlordPlaying = false;
		}

	}
}