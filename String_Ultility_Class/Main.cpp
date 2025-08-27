#include "Driscoll_String.h"

int main()
{
	Driscoll_String Str = "Hello World!";
	std::cout << Str << std::endl;

	/*TEST CASES*/

	//GetLength
	std::cout << "Length = ";
	std::cout << Str.GetLength() << std::endl;

	//Character At
	std::cout << "The Character at index 3 is: ";
	std::cout << Str.CharacterAt(3) << std::endl;

	//Equals
	std::cout << "Does this string = 'Hello World!': ";
	std::cout << Str.Equals("Hello World!") << std::endl;
	std::cout << "Does this string = 'Bye World!': ";
	std::cout << Str.Equals("Not") << std::endl;

	//Append
	std::cout << "Append: ' Bye World' ";
	Str.Append(" Bye World");
	std::cout << Str << std::endl;

	//Prepend
	std::cout << "Prepend: 'My name is: ' ";
	Str.Prepend("My name is: ");
	std::cout << Str << std::endl;

	//CStr
	std::cout << "CStr: ";
	const char* StrContentPtr = Str.CStr();
	std::cout << StrContentPtr << std::endl;

	//ToLower
	std::cout << "To Lowercase: ";
	Str.ToLower();
	std::cout << Str << std::endl;

	//ToUpper
	std::cout << "To Uppercase: ";
	Str.ToUpper();
	std::cout << Str << std::endl;

	//Find
	std::cout << "The substring 'Hello' starts at index: ";
	std::cout << Str.Find("Hello") << std::endl;

	//Replace
	std::cout << "Replace: 'MY NAME IS: ' with 'Goodbye World Too!' and you get: ";
	Str.Replace("MY NAME IS: ", "Goodbye World Too!");
	std::cout << Str << std::endl;

	return 0; 
}