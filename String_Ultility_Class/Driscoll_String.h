#pragma once
#include <iostream>

class Driscoll_String
{
private:
	/* Privated Global Variables */

	size_t Length;

	char* Contents;

public:
	/* Public Constructors and Destructor */

	//Default Constructor
	Driscoll_String();

	//String Creation Constructor
	Driscoll_String(const char* _string);

	//Base Copy Constructor
	Driscoll_String(const Driscoll_String& _other);

	//Base Copy Assignment
	Driscoll_String& operator=(const Driscoll_String& _other);

	~Driscoll_String();

public:
	/* Public Functions */

	size_t GetLength() const;

	char& CharacterAt(size_t _index);

	char& CharacterAt(size_t _index) const;
};

