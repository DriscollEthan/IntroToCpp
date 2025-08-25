#define NEWLINE (std::cout << std::endl)

#include <iostream>

//Pointers
int SumOfArrayElems(int* Arr, size_t Size)
{
  int sum = 0;
  for (int i = 0; i < Size; ++i)
  {
    sum += Arr[i];
  }
  return sum;
}

char* FindLetterInArray(char* Arr, size_t Size, char LetterToFind, bool bIsCaseSensitive)
{
  for (int i = 0; i < Size; ++i)
  {
    if (bIsCaseSensitive && Arr[i] == LetterToFind)
    {
      return &Arr[i];
    }
    else if (!bIsCaseSensitive && 
      (Arr[i] == LetterToFind - 32 
        || Arr[i] == LetterToFind + 32
        || Arr[i] == LetterToFind))
    {
      return &Arr[i];
    }
  }

  return nullptr;
}

char* FindSubstringInArray(char* Arr, size_t Size, bool bIsCaseSensitive, char* SubstringToFind, size_t SubstringSize)
{
  int x = 0;
  char* memAddress = &Arr[0];
  for (int i = 0; i < Size; ++i)
  {
    if (bIsCaseSensitive && Arr[i] == SubstringToFind[x])
    {
      ++x;
    }
    else if (!bIsCaseSensitive && 
      (Arr[i] == SubstringToFind[x] - 32 
      || Arr[i] == SubstringToFind[x] + 32 
      || Arr[i] == SubstringToFind[x]))
    {
      ++x;
    }
    else
    {
      x = 0;
      memAddress = &Arr[i];
    }

    if ( (SubstringSize - 1) == x)
    {
      return memAddress;
    }
  }

  return nullptr;
}

//Dynamic Pointers
int* ZeroArray(size_t Size)
{
  int* newArray = new int[Size];
  for (int i = 0; i < Size; ++i)
  {
    newArray[i] = 0;
  }

  return newArray;
}

void ILoveNumbers()
{
  int Size = 0;

  std::cout << "Howdy! How many numbers do you have?" << std::endl;
  std::cin >> Size;

  int* Numbers = ZeroArray(Size);

  NEWLINE;

  for (int i = 0; i < Size; ++i)
  {
    int UserInput = 0;
    std::cout << "Okay what's number " << i + 1 << "?" << std::endl;
    std::cin >> UserInput;

    Numbers[i] = UserInput;

    NEWLINE;
  }

  std::cout << "Okay, you have the numbers: ";
  for (int i = 0; i < Size; ++i)
  {
    int UserInput = 0;

    if (i < Size - 2)
    {
      std::cout << Numbers[i] << ", ";
    }
    else if (i == Size - 2)
    {
      std::cout << Numbers[i] << ", and ";
    }
    else
    {
      std::cout << Numbers[i] << "." << std::endl;
    }
  }

  delete[] Numbers;
}

int* DuplicateArray(int* OrigArray, size_t Size)
{
  int* newArray = ZeroArray(Size);

  for (int i = 0; i < Size; ++i)
  {
    newArray[i] = OrigArray[i];
  }

  return newArray;
}

int* DuplicateSubarrayArray(int* OrigArray, size_t Size, int StartIndex, int EndIndex)
{
  int* newArray = ZeroArray((EndIndex - StartIndex) + 1);

  for (int i = StartIndex; i <= EndIndex; ++i)
  {
    if (i < Size)
    {
      newArray[i - StartIndex] = OrigArray[i];
    }
  }

  return newArray;
}

void InfiniteNumbers()
{
  int* IndexingPtr = new int(0);
  int* StartingAdress = IndexingPtr;
  int UserInput = -1;

  do
  {
    std::cout << "Give me a number or (enter 0 to stop)!" << std::endl;

    std::cin >> UserInput;

    NEWLINE;

    *IndexingPtr = UserInput;

    ++IndexingPtr;

  } while (UserInput != 0);

    std::cout << "You Gave me: ";
  while (StartingAdress != (IndexingPtr - 2))
  {
    std::cout << *StartingAdress << ", ";
    
    StartingAdress++;
  }

  std::cout << *StartingAdress << "!" << std::endl;
  NEWLINE;
  //delete IndexingPtr;
}

int main()
{
  int ArrX[] = { 0, 2, 8, 10 };
  std::cout << SumOfArrayElems(ArrX, 4) << std::endl;

  char ArrChar[] = { 'a', 'b', 'c', 'd' };
  char* returnValue = FindLetterInArray(ArrChar, 5, 'A', false);
 if (returnValue != nullptr)
 {
   std::cout << returnValue;
 }
 else
 {
   std::cout << "NULL";
 }

  NEWLINE;

  char ArrSubstring[] = { 'A', 'B', 'C' };
  returnValue = FindSubstringInArray(ArrChar, 5, false, ArrSubstring, 4);
  if (returnValue != nullptr)
  {
    std::cout << returnValue;
  }
  else
  {
    std::cout << "NULL";
  }

  //Dynamic Allocatation
  int* DynArray = ZeroArray(10);
  for (int i = 0; i < 10; ++i)
  {
    DynArray[i] += i + 1;
    std::cout << DynArray[i];
    NEWLINE;
  }


  NEWLINE;

  ILoveNumbers();

  int* NewDynArray = DuplicateArray(DynArray, 10);

  NewDynArray = DuplicateSubarrayArray(DynArray, 10, 11, 15);

  InfiniteNumbers();

  delete[] DynArray;
  delete[] NewDynArray;
}