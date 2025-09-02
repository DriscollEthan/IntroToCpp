#pragma once
#include <iostream>

class Driscoll_String
{
private:
	/* Privated Global Variables */

	size_t TOTAL_LENGTH;
	size_t CONTENTS_LENGTH;
	char* Contents;

public:
	/* Public Constructors and Destructor */

	//Default Constructor
	Driscoll_String();

	//String Creation Constructor
	Driscoll_String(const char* _string);

	//Base Copy Constructor
	Driscoll_String(const Driscoll_String& _other);

	//Base Destructor
	~Driscoll_String();

public:
	/* Public Functions */

	//Get The Lenght of the String without the Null Terminating Operator
	size_t GetLength() const;

	//Get a Specific Character at a Specific Index
	char& CharacterAt(size_t _index);

	//Get a Specific Constant Character at a Specific Index
	char& CharacterAt(size_t _index) const;

	//Does The Does Contents of This String Equal Another
	bool Equals(const Driscoll_String& _otherString) const;

	//Puts the Other String at the end of This String.
	Driscoll_String& Append(const Driscoll_String& _otherString);

	//Puts the Other String in front of This String.
	Driscoll_String& Prepend(const Driscoll_String& _otherString);

	//Retruns a Const-Qualifed Pointer to the Beggining of this string.
	const char* CStr() const;

	//Create a copy of this String with all letters set to Lowercase.
	Driscoll_String ToLower() const;

	//Create a copy of this String with all letters set to Uppercase.
	Driscoll_String ToUpper() const;

	//Find the First occurance of a Given SubString. || Return - 1 if Not Found
	int Find(const Driscoll_String& _subString);

	//Find the First occurance of a Given SubString. At or After the Start Index || Return - 1 if Not Found
	int Find(size_t _startIndex, const Driscoll_String& _subString);

	//Find and Replace all Occurances of the SubString: _findString with _replaceString.
	Driscoll_String& Replace(const Driscoll_String& _findString,
		const Driscoll_String& _replaceString);

public:
	/* General Operator Overloads */

	//Base Copy Assignment
	Driscoll_String& operator=(const Driscoll_String& _other);

	//Create a new String by Appending String b to String a (a + b)
	Driscoll_String operator+(const Driscoll_String& _other) const;

	//Creates and sets this String by Appending String b to String a (a += b)
	Driscoll_String& operator+=(const Driscoll_String& _other);

	//Checks if this String is EQUAL to another String
	bool operator==(const Driscoll_String& _other) const;

	//Checks if this String is NOT EQUAL to another String
	bool operator!=(const Driscoll_String& _other) const;

	//Subscript Access to the Character at Index
	char& operator[](size_t _index);

	//Const-Qualifed Subscript Acess to the Character at Index
	const char& operator[](size_t _index) const;

	//Support Printing to the ostream objects.
	friend std::ostream& operator<<(std::ostream& _stream,
		const Driscoll_String& _string);

};

