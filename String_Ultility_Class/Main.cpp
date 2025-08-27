#include "Driscoll_String.h"

int main()
{
	Driscoll_String Str = "Hello World!";
	std::cout << Str << std::endl;

	/*TEST CASES*/

	//GetLength
	std::cout << Str.GetLength() << std::endl;

	//Character At
	std::cout << Str.CharacterAt(3) << std::endl;

	//Equals
	std::cout << Str.Equals("Hello World!") << std::endl;
	std::cout << Str.Equals("Not") << std::endl;

	//Append
	Str.Append(" Bye World");
	std::cout << Str << std::endl;

	//Prepend
	Str.Prepend("My name is: ");
	std::cout << Str << std::endl;

	//CStr
	const char* StrContentPtr = Str.CStr();
	std::cout << StrContentPtr << std::endl;

	//ToLower
	Str.ToLower();
	std::cout << Str << std::endl;

	//ToUpper
	Str.ToUpper();
	std::cout << Str << std::endl;

	//Find
	std::cout << Str.Find("Hello") << std::endl;

	//Replace
	Str.Replace("H", "Goodbye");
	std::cout << Str << std::endl;

	return 0; 
}