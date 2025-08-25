#define NEWLINE (std::cout << std::endl)

#include <iostream>

struct Vector2D
{
  float x, y;
};

void ZeroVector2D(Vector2D* Vector2DRef)
{
  Vector2DRef->x = 0;
  Vector2DRef->y = 0;
}

int main()
{
  int* x = new int;
  *x = 10;

  int Size = 3;
  Size += 5;
  int* xArray = new int[Size];

  std::cout << *x;

  NEWLINE;

  for (int i = 0; i < Size; ++i)
  {
    xArray[i] = i + 11;
    std::cout << xArray[i];
    NEWLINE;
  }

  delete x;
  delete[] xArray;
}