#include <iostream>
#include <string>
#include <cstring>


void Print(std::string Text, bool bEndLine)
{
	std::cout << Text;

	if (bEndLine)
	{
		std::cout << std::endl;
	}
}

void EndLine()
{
	std::cout << std::endl;
}

void FlushInputBuffer()
{
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
}

void Greeting()
{
	char UserName[50];
	
	Print("Please provide your name.", true);
	std::cin >> UserName;
	Print("Hello ", false);
	Print(UserName, false);
	Print("!", true);

	EndLine();
}

void FavoriteColor()
{
	char UserFavoriteColor[50];

	Print("Please provide your favorite color.", true);
	std::cin >> UserFavoriteColor;
	
	if (strcmp(UserFavoriteColor, "Blue") == 0 || strcmp(UserFavoriteColor, "blue") == 0)
	{
		Print("Blue is great choice. It's a color that's used to help calm people on airplanes.", true);
	}
	
	else if (strcmp(UserFavoriteColor, "Red") == 0 || strcmp(UserFavoriteColor, "red") == 0)
	{
		Print("Red is great choice. It's a color that's seen in nature. The red roses are a great color that come to mind.", true);
	}

	else if (strcmp(UserFavoriteColor, "Orange") == 0 || strcmp(UserFavoriteColor, "orange") == 0)
	{
		Print("Orange is great choice. This seems to be Terry's favorite color. We will silently judge.", true);
	}

	else
	{
		Print("I am not entirerly aware of the color you output. I'm sure I'll learn about this color in the near future.", true);
	}

	EndLine();
}

void ToUpper(char String[], int Size)
{
	for (int i = 0; String[i] != '\0'; ++i)
	{
		//If the char is lowercase
		if (String[i] >= 97 && String[i] <= 122)
		{
			String[i] -= 32;
		}
	}
}

void RemoveWhitespace(char String[], int Size)
{
	//Init Variables
	int spacesUntilFirstLetter = 0;

	//Figure out where the first letter starts
	for (int i = 0; i < Size; ++i)
	{
		if (String[i] == ' ')
		{
			++spacesUntilFirstLetter;
		}
		else
		{
			break;
		}
	}

	//Remvove the begginging spaces by shifting the letters to the left to fill the spaces
	for (int i = spacesUntilFirstLetter; i < Size; ++i)
	{
		String[i - spacesUntilFirstLetter] = String[i];
	}

	//Remove the rest of the Spaces
	for (int i = 0; i < Size; ++i)
	{
		if (String[i] == ' ' && String[i] != '\0')
		{
			String[i] = String[i + 1];
			--i;
		}
		else if (String[i] == '\0')
		{
			break;
		}
	}
}

void Substring(char String[], int Size, int Start, int End)
{
	char tempString[256];
	int x = 0;

	for (int i = 0; i < Size; ++i)
	{
		if (i > Start - 1 && i < End)
		{
			tempString[x] = String[i];
			++x;
		}
	}

	tempString[x] = '\0';

	strcpy_s (String, Size, tempString);
}

int StringLength(char String[], int Size)
{
	int arrayLength = 0;

	for (int i = 0; i < Size; ++i)
	{
		if (String[i] == '\0')
		{
			arrayLength = i;
			break;
		}
	}
	return arrayLength;
}

void StringReversal(char String[], int Size)
{
	int arrayLength = StringLength(String, Size);

	//Reverse Array
	for (int i = 0; i < arrayLength / 2; ++i)
	{
		char tempVar = String[i];
		String[i] = String[arrayLength - 1 - i];
		String[arrayLength - 1 - i] = tempVar;
	}
}

bool PalindromeTest(char String[], int Size)
{
	//Create Array to be Tested
	char palindromeTestArray[256];

	//Copy the contents of the Origin Array
	strcpy_s(palindromeTestArray, Size, String);\

	//Reverse the contents of the Array to check for Palindrome
	StringReversal(palindromeTestArray, 256);

	return 0 == strcmp(palindromeTestArray, String);
}

void StringTrimming(char String[], int Size)
{
	//Init Variables
	int spacesUntilFirstLetter = 0;

	//Figure out where the first letter starts
	for (int i = 0; i < Size; ++i)
	{
		if (String[i] == ' ')
		{
			++spacesUntilFirstLetter;
		}
		else
		{
			break;
		}
	}

	//Remvove the begginging spaces by shifting the letters to the left to fill the spaces
	for (int i = spacesUntilFirstLetter; i < Size; ++i)
	{
		String[i - spacesUntilFirstLetter] = String[i];
	}

	//Reset the Var
	spacesUntilFirstLetter = 0;

	//Figure out where the first letter is going backwards.
	for (int i = Size; i >= 0; --i)
	{
		if (String[i] == ' ' || '\0')
		{
			++spacesUntilFirstLetter;
		}
		else
		{
			break;
		}
	}
	
	//The last letter without a letter is the new null terminator.
	String[StringLength(String, Size) - spacesUntilFirstLetter] = '\0';
}

int main()
{
	Greeting();

	FavoriteColor();

	char String[256] = "hello world!";
	ToUpper(String, 256);
	Print(String, true);
	EndLine();

	Print("Please provide a sentence, max 255 characters.", true);
	FlushInputBuffer();
	std::cin.getline(String, 256);
	RemoveWhitespace(String, 256);
	Print(String, true);
	EndLine();

	Substring(String, 256, 2, 11);
	Print(String, true);

	StringReversal(String, 256);
	Print(String, true);

	bool bIsPalindrome = PalindromeTest(String, 256);
	std::cout << "Is the word above a Palindrome? " << bIsPalindrome << std::endl;
	EndLine;

	char StringToTrim[256] = "  New Trimmed  ";

	StringTrimming(StringToTrim, 256);
	Print(StringToTrim, true);
}