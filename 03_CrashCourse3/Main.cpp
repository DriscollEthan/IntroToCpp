#include <iostream>
#include <cmath>

void Buffer()
{
	std::cout << " " << std::endl;
}

void PairPrinting(int a, int b)
{
	std::cout << a << ", " << b << std::endl;
}

int SumOfThree(int a, int b, int c)
{
	return a + b + c;
}

int MinNumber(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int MaxNumber(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int MinArray(int Numbers[], size_t Size)
{
	int leastNumb = Numbers[0];

	for (int i = 1; i < Size; ++i)
	{
		if (leastNumb > Numbers[i])
		{
			leastNumb = Numbers[i];
		}
	}
	return leastNumb;
}

int MaxArray(int Numbers[], size_t Size)
{
	int maxNumb = Numbers[0];

	for (int i = 1; i < Size; ++i)
	{
		if (maxNumb < Numbers[i])
		{
			maxNumb = Numbers[i];
		}
	}
	return maxNumb;
}

int ClampInt(int Value, int Min, int Max)
{
	if (Value < Min)
	{
		Value = Min;
	}
	else if (Value > Max)
	{
		Value = Max;
	}
	return Value;
}

int FindIndex(int Numbers[], size_t Size, int Value)
{
	int foundIndex = -1;

	for (int i = 0; i < Size; ++i)
	{
		if (Value == Numbers[i])
		{
			foundIndex = i;
			break;
		}
	}

	return foundIndex;
}

void ReverseArray(int Numbers[], size_t Size)
{
	for (int i = 0; i < Size / 2; ++i)
	{
		int tempVar = Numbers[i];
		Numbers[i] = Numbers[Size - 1 - i];
		Numbers[Size - 1 - i] = tempVar;
	}
}

double Vector2Distance(double VectA_x, double VectA_y, double VectB_x, double VectB_y)
{
	return sqrt(((VectB_x - VectA_x) * (VectB_x - VectA_x)) + ((VectB_y - VectA_y) * (VectB_y - VectA_y)));
}

int main()
{
	PairPrinting(5, 10);
	Buffer();

	std::cout << "The sum of 101, 202, 303 is: " << SumOfThree(101, 202, 505) << std::endl;
	Buffer();

	std::cout << "The number: " << MinNumber(8, 80) << " is smaller than 80." << std::endl;
	Buffer();

	std::cout << "The number: " << MaxNumber(8, 80) << " is bigger than 8." << std::endl;
	Buffer();
	
	const int NUMB_ARRAY_LENGTH = 8;
	int NumbArray[NUMB_ARRAY_LENGTH] = { 5, 20, 50, 2, 60, 0, 1, -10 };

	std::cout << "The smallest number in an array is:  " << MinArray(NumbArray, NUMB_ARRAY_LENGTH) << std::endl;
	Buffer();

	std::cout << "The highest number in an array is:  " << MaxArray(NumbArray, NUMB_ARRAY_LENGTH) << std::endl;
	Buffer();

	std::cout << "The clamped value is: " << ClampInt(10, 5, 15) << std::endl;
	Buffer();

	std::cout << "The number '0' is in the index: " << FindIndex(NumbArray, NUMB_ARRAY_LENGTH, 0) << std::endl;
	Buffer();

	ReverseArray(NumbArray, NUMB_ARRAY_LENGTH);
	for (int i = 0; i < NUMB_ARRAY_LENGTH; ++i)
	{
		std::cout << NumbArray[i] << std::endl;
	}
	Buffer();

	std::cout << "The Distance is: " << Vector2Distance(5, 2, 3, 8) << std::endl;
	Buffer();

}