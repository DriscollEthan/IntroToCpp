#include <iostream>
#include <cstdlib>
#include <ctime>

void Buffer()
{
	std::cout << " " << std::endl;
}

void FizzBuzz(int Iterations)
{
	for (int i = 1; i <= Iterations; ++i)
	{
		if (i % 3 == 0)
		{
			std::cout << "Fizz";
		}
		if (i % 5 == 0)
		{
			std::cout << "Buzz";
		}
		if (i % 3 != 0 && i % 5 != 0)
		{
			std::cout << i;
		}
		std::cout << " " << std::endl;
	}
}

void FibonacciSequence(int Iterations)
{
	int a = 0;
	int b = 1;
	int c = -1;

	//print first 2 numbers in sequence
	std::cout << a << std::endl;
	std::cout << b << std::endl;


	//Run the Iterations for the rest of the sequence. || Iterations - 2, because the first two numbers in the sequence is printed above.
	for (int i = 0; i < Iterations - 2; ++i)
	{
		//Create Next Number in Sequence
		c = a + b;

		//Print Next Number in Sequence
		std::cout << c << std::endl;

		//Reset Sequence for next Iteration
		a = b;
		b = c;
	}
}

void GridGenerator(int Width, int Height, char LetterToUse)
{
	for (int y = 0; y < Height; ++y)
	{
		for (int x = 0; x < Width; ++x)
		{
			std::cout << LetterToUse;
		}
		std::cout << " " << std::endl;
	}
}

void FreeFormNumberInput()
{
	//Array Setup
	const int ARR_NUMBERS_LENGTH = 5;
	int Numbers[ARR_NUMBERS_LENGTH];

	std::cout << "You are to provide: 10 Numbers to be fitted into an Array." << std::endl;
	Buffer();

	for (int i = 0; i < ARR_NUMBERS_LENGTH; ++i)
	{
		std::cout << "Input Number: " << i + 1 << std::endl;
		std::cin >> Numbers[i];
		Buffer();
	}

	std::cout << "You provided the follow numbers:" << std::endl;

	for (int i = 0; i < ARR_NUMBERS_LENGTH; ++i)
	{

		//Add the "and", if this is the 2nd to last element, as deamed by i + 1 (1 for 2nd to last element).
		if (i + 1 == ARR_NUMBERS_LENGTH)
		{
			std::cout << "and ";
		}

		std::cout << Numbers[i] << ", ";
	}

	Buffer();
}

void HigherLower(int AmountOfTries, int HighEndThreshold)
{
	std::srand(std::time(nullptr));

	int RandomValue = std::rand() % HighEndThreshold;

	std::cout << "Hey there! I'm going to generate a numnber between 1 and " << HighEndThreshold << "." << std::endl;

	std::cout << "You will have " << AmountOfTries << " to guess it!" << std::endl;

	for (int i = 0; i < AmountOfTries; ++i)
	{
		int currentGuess = 0;

		std::cout << "Round " << i + 1 << " - Make Your Guess" << std::endl;
		std::cin >> currentGuess;

		if (currentGuess < RandomValue)
		{
			std::cout << "Sorry, that isn't quite it. Your guess is too low!" << std::endl;
		}

		else if (currentGuess > RandomValue)
		{
			std::cout << "Sorry, that isn't quite it. Your guess is too high!" << std::endl;
		}

		else
		{
			std::cout << "That's it! You guessed the number!" << std::endl;
			break;
		}

	}
}

int main()
{
	/*
	std::cout << "FizzBuzz" << std::endl;
	FizzBuzz(30);
	Buffer();

	std::cout << "Fibonacci Sequence" << std::endl;
	FibonacciSequence(9);
	Buffer();

	std::cout << "Grid Generator" << std::endl;
	GridGenerator(5, 3, 'x');
	Buffer();

	FreeFormNumberInput();
	Buffer();
	*/
	HigherLower(5, 40);
	Buffer();

}