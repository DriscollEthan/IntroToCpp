#include "Driscoll_String.h"
#include <string>

int main()
{
	Driscoll_String Str = "Hello World! This is a Custom String Class";

	for (int i = 0; i < Str.GetLength(); ++i)
	{
		std::cout << Str.CharacterAt(i);
	}

	return 0;
}