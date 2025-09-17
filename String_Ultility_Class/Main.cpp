#include "Driscoll_String.h"
#include <fstream>
#include <ctime>

Driscoll_String WhatToPrint(bool _bool)
{
	if (_bool)
	{
		return "Successful";
	}
	
	else
	{
		return "Failed";
	}
}

int main()
{
	Driscoll_String Str = "Hello World!";

	// Replace
	Driscoll_String FullName = "Terr John Madden";

	FullName.Replace("Terr", "Bohn");
	std::cout << (FullName == "Bohn John Madden");

	// GROW from Middle
	FullName.Replace("John", "Sharpshooter");
	std::cout << (FullName == "Bohn Sharpshooter Madden");

	// SHRINK from START
	FullName.Replace("Bohn", "B.");
	std::cout << (FullName == "B. Sharpshooter Madden");

	std::fstream StringTestFile;
	StringTestFile.open("StringTestFile.txt", std::ios::out);
	if (StringTestFile.is_open())
	{
		StringTestFile << "Test Cases: \n";
	}
	StringTestFile.close();

	StringTestFile.open("StringTestFile.txt", std::ios::out);
	if (StringTestFile.is_open())
	{
		StringTestFile << "Test 0 Length " << WhatToPrint(Str.GetLength() == 12) << std::endl;

		StringTestFile << "Test 1 CharacterAt " << WhatToPrint(Str.CharacterAt(3) == 'l') << std::endl;

		StringTestFile << "Test 2 Equals " << WhatToPrint(Str.Equals("Hello World!") && !Str.Equals("hello world!")) << std::endl;

		StringTestFile << "Test 3 Append " << WhatToPrint(Str.Append(" Hi") == "Hello World! Hi") << std::endl;

		StringTestFile << "Test 4 Prepend " << WhatToPrint(Str.Prepend("Hi ") == "Hi Hello World! Hi") << std::endl;

		StringTestFile << "Test 5 CStr " << WhatToPrint(Str.Equals(Str.CStr())) << std::endl;

		Str.ToLower();
		StringTestFile << "Test 6 ToLower " << WhatToPrint(Str == "hi hello world! hi") << std::endl;

		Str.ToUpper();
		StringTestFile << "Test 7 ToUpper " << WhatToPrint(Str == "HI HELLO WORLD! HI") << std::endl;

		StringTestFile << "Test 8 Find " << WhatToPrint(Str.Find("HI") == 0) << std::endl;

		Str.Replace("HI", "bye");
		StringTestFile << "Test 9 Replace " << WhatToPrint(Str == "bye HELLO WORLD! bye") << std::endl;
	}
	StringTestFile.close();

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