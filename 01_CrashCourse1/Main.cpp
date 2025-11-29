
#include <iostream>
#include <string>

int Points = 0;

//Exercise Functions

//Hello You
void HelloYou()
{
	//Name
	char UserName[256];

	std::cout << "What is your name? Do Not use Spaces!" << std::endl;
	std::cin >> UserName;
	std::cout << "Your name is: " << UserName << std::endl;

	//Candy
	char UserFavoriteCandy[256];
	
	std::cout << "What is your favorite Candy? Do Not use Spaces!" << std::endl;
	std::cin >> UserFavoriteCandy;
	std::cout << "Your favorite candy is: " << UserFavoriteCandy << std::endl;

	//Vegetable
	char UserVegatable[256];

	std::cout << "If you were a vegetable, what vegetable would you be? Do Not use Spaces!" << std::endl;
	std::cin >> UserVegatable;
	std::cout << "If you were a vegetable you would be a: " << UserVegatable << std::endl;

	//Years Playing Games
	int UserYearsPlayingGames;

	std::cout << "How many years have you been playing games? Whole Numbers ONLY!" << std::endl;
	std::cin >> UserYearsPlayingGames;
	std::cout << "You have been playing games for: " << UserYearsPlayingGames << " amount of years." << std::endl;

	//First Game Played
	char UserFirstEverGame[256];

	std::cout << "What is the first game you ever played? Do Not use Spaces!" << std::endl;
	std::cin >> UserFirstEverGame;
	std::cout << "The first game you have ever played is: " << UserFirstEverGame << std::endl;
}

//Area of a Rectangle
void AreaOfARectangle()
{
	float Length;
	float Height;

	std::cout << "What is the length of your Rectangle in Inches?" << std::endl;
	std::cin >> Length;

	std::cout << "What is the height of your Rectangle in Inches?" << std::endl;
	std::cin >> Height;

	std::cout << "The area of your Rectangle in Inches Squared is: " << Length * Height << std::endl;
}

//Print to save Time
void Print(std::string String)
{
	std::cout << String << std::endl;
}

//Buffer to add Extra an Extra Line Buffer
void Buffer()
{
	Print(" ");
}

//Quiz Game Options List
void OptionsList(std::string Option1, std::string Option2, std::string Option3, std::string Option4)
{
	Print("a. " + Option1);
	Print("b. " + Option2);
	Print("c. " + Option3);
	Print("d. " + Option4);
}

//Quiz Game AnswerSelection
void AnswerSelection(char CorrectOption, std::string FunFact)
{
	char UserChoice = 'e';
	Print("Choose your answer!");
	std::cin >> UserChoice;

	if (UserChoice == CorrectOption)
	{
		Print("You are: Correct! ");
		Print("A fun fact is: " + FunFact);
		++Points;
	}
	else
	{
		Print("You are: Incorrect!");
		std::cout << "The Correct Answer Was: " << CorrectOption << std::endl;
		Print("A fun fact is: " + FunFact);
	}

}



//Quiz Game
void QuizGame()
{

	Print("Welcome to Ethan's quiz about Soccer Laws!");
	Print("There will be x amount of questions about the laws of Soccer.");
	Print("This is a multiple choice quiz, you will choose from the options, 'a', 'b', 'c', and 'd'");
	Buffer();

	//First Question
	Print("The First Question is:");
	Print("How many Laws of Soccer are there currently?");
	OptionsList("5", "12", "17", "23");
	AnswerSelection('c', "They are 17 official Laws of Soccer. Albiet, not an official law, a lot of officials say the 18th law is Common Sense.");
	Buffer();

	//Second Question
	Print("The Second Question is:");
	Print("What is the title of Law 5?");
	OptionsList("The Referee", "The Players", "The Ball", "Free Kicks");
	AnswerSelection('a', "Law 5 - The Referee, talks about how the Referee operates on the field, including the authority, decsions, and even their equipment.");
	Buffer();

	//Third Question
	Print("The Third Question is:");
	Print("How many different types of criteria are there in determining a Handball Offence as stated in Law 12 - Fouls and Misconducts");
	OptionsList("There is Criteria to Determine a Handball Offence?!", "1", "5", "3");
	AnswerSelection('d', "The three different pieces of criteria to determine a handball offence is, 'Was the arm in a unnatural position?', 'Did the arm make a deliberate action towards the ball?', or 'Did the ball come off the arm and then immediatly into the Opponents Goal?' ");
	Buffer();

	std::cout << "You got: " << Points << " out of 3 Questions right!" << std::endl;
	Print("Thank you for playing Ethan's Soccer Laws QuizGame!");
}



//Main Function
int main()
{
	/*
	HelloYou();

	//Buffer
	std::cout << " " << std::endl;

	AreaOfARectangle();

	//Buffer
	std::cout << " " << std::endl;
	*/

	//QuizGame();

	/*
	int Cash = 20;
	float Distance = 15.3f; //Meters
	double Cot = 3.50;
	bool bIsProgrammingRad = true;

	const char* Name = "John Madden"; //String

	std::cout << "Hello World!" << std::endl;
	std::cout << Name << " Has $" << Cash << std::endl;

	//New Local Var
	int groundMoney = 0;

	std::cout << "How much money do you find on the ground?" << std::endl;
	std::cin >> groundMoney;

	//Add newly found money to total
	Cash += groundMoney;

	//Print New Total
	std::cout << Name << " Now Has Dollars: $" << Cash << std::endl;

	//Can Buy Game? (Variable Setup)
	double costOfGame = 21.24;
	bool bCanBuyGame = Cash >= costOfGame;

	if (bCanBuyGame)
	{
		std::cout << "Yes, you can buy Dice Gambit" << std::endl;

		//New Total
		Cash = Cash -  std::round(costOfGame);
		std::cout << Name << " Has: $" << Cash << " Leftover" << std::endl;
	}
	else
	{
		std::cout << "No, you can not buy Dice Gambit" << std::endl;
	}
	*/
	return 0;
}