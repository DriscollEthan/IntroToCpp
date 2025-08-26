#include "Driscoll_String.h"

/* CONSTRUCTORS */

Driscoll_String::Driscoll_String()
{
	//Initialize the Null Terminating Operator. By Creating the Memory space the Null Terminating Operator.
	TOTAL_LENGTH = 1;
	CONTENTS_LENGTH = TOTAL_LENGTH - 1;
	Contents = new char[TOTAL_LENGTH]; 
	Contents[0] = '\0';
}

Driscoll_String::Driscoll_String(const char* _string)
{
	//Find The Length of the String, and include the Null Terminating Operating into the Length by Default.
	TOTAL_LENGTH = 1;
	for (int i = 0; _string[i] != '\0'; ++i)
	{
		TOTAL_LENGTH++;
	}

	//Allocate the memeory for the new Length of the String
	Contents = new char[TOTAL_LENGTH];
	CONTENTS_LENGTH = TOTAL_LENGTH - 1;

	//Set the String Contents to the Inputted String
	for (int i = 0; i < TOTAL_LENGTH - 1; ++i)
	{
		Contents[i] = _string[i];
	}

	//Add the Null Terminating Operator the end of the String.
	Contents[TOTAL_LENGTH - 1] = '\0';
}

Driscoll_String::Driscoll_String(const Driscoll_String& _other)
{
	//Find The Length of the String, and include the Null Terminating Operating into the Length by Default.
	TOTAL_LENGTH = (_other.GetLength()) + 1;
	CONTENTS_LENGTH = TOTAL_LENGTH - 1;

	//Allocate the memeory for the new Length of the String
	Contents = new char[TOTAL_LENGTH];

	//Set the String Contents to the Inputted String
	for (int i = 0; i < TOTAL_LENGTH - 1; ++i)
	{
		Contents[i] = _other.CharacterAt(i);
	}

	//Add the Null Terminating Operator the end of the String.
	Contents[TOTAL_LENGTH - 1] = '\0';
}

/* OPERATOR OVERLOADS */

Driscoll_String& Driscoll_String::operator=(const Driscoll_String& _other)
{
	//NEEDS BUFFER CHECK
	delete[] Contents;
	Contents = nullptr;

	//Find The Length of the String, and include the Null Terminating Operating into the Length by Default.
	TOTAL_LENGTH = (_other.GetLength()) + 1;
	CONTENTS_LENGTH = TOTAL_LENGTH - 1;

	//Allocate the memeory for the new Length of the String
	Contents = new char[TOTAL_LENGTH];

	//Set the String Contents to the Inputted String
	for (int i = 0; i < TOTAL_LENGTH - 1; ++i)
	{
		Contents[i] = _other.CharacterAt(i);
	}

	//Add the Null Terminating Operator the end of the String.
	Contents[TOTAL_LENGTH - 1] = '\0';

	return *this;
}

Driscoll_String Driscoll_String::operator+(const Driscoll_String& _other) const
{
	return Driscoll_String();
}

Driscoll_String Driscoll_String::operator+=(const Driscoll_String& _other) const
{
	return Driscoll_String();
}

Driscoll_String Driscoll_String::operator==(const Driscoll_String& _other) const
{
	return Driscoll_String();
}

Driscoll_String Driscoll_String::operator!=(const Driscoll_String& _other) const
{
	return Driscoll_String();
}

Driscoll_String Driscoll_String::operator[](size_t _index)
{
	return Driscoll_String();
}

Driscoll_String Driscoll_String::operator[](size_t _index) const
{
	return Driscoll_String();
}

/* DESCTRUCTORS */

Driscoll_String::~Driscoll_String()
{
	delete[] Contents;
	Contents = nullptr;
	TOTAL_LENGTH = 0;
	CONTENTS_LENGTH = 0;
}

/* Driscoll_String FUNCTIONS */

size_t Driscoll_String::GetLength() const
{
	//Return the Length, and exclude the Null Terminating Operator.
	return CONTENTS_LENGTH;
}

char& Driscoll_String::CharacterAt(size_t _index)
{
	//Bounds Checking || Length - 1 is where the Null Terminating Operator is, so if the Index is less than that, it should be in bounds.
	if (_index < TOTAL_LENGTH - 1)
	{
		return Contents[_index];
	}

	//This should return the Null Terminating Operator, saying that the Index was out of Bounds.
	return Contents[TOTAL_LENGTH - 1];
}

char& Driscoll_String::CharacterAt(size_t _index) const
{
	//Bounds Checking || Length - 1 is where the Null Terminating Operator is, so if the Index is less than that, it should be in bounds.
	if (_index < TOTAL_LENGTH - 1)
	{
		return Contents[_index];
	}

	//This should return the Null Terminating Operator, saying that the Index was out of Bounds.
	return Contents[TOTAL_LENGTH - 1];
}

bool Driscoll_String::Equals(const Driscoll_String& _otherString) const
{
	//Early Exit Check. If the Legnths are not the same, then the String Can Not Be Equal to Each Other.
	if (GetLength() != _otherString.GetLength())
	{
		return false;
	}
	
	for (int i = 0; i < GetLength() - 1; ++i)
	{
		//The moment that the characters are not the same, the Strings must NOT be Equal to Each Other.
		if (CharacterAt(i) != _otherString.CharacterAt(i))
		{
			return false;
		}
	}

	//If we never Exit early because of Lengths being the same and the Character All seem to be the same, Then the Strings Must be equal to each other.
	return true;
}

Driscoll_String& Driscoll_String::Append(const Driscoll_String& _otherString)
{
	// TODO: insert return statement here
}

Driscoll_String& Driscoll_String::Prepend(const Driscoll_String& _otherString)
{
	// TODO: insert return statement here
}

const char* Driscoll_String::CStr() const
{
	return nullptr;
}

Driscoll_String Driscoll_String::ToLower() const
{
	return Driscoll_String();
}

Driscoll_String Driscoll_String::ToUpper() const
{
	return Driscoll_String();
}

int Driscoll_String::Find(const Driscoll_String& _subString)
{
	return 0;
}

int Driscoll_String::Find(size_t _startIndex, const Driscoll_String& _subString)
{
	return 0;
}

Driscoll_String& Driscoll_String::Replace(const Driscoll_String& _findString, const Driscoll_String& _replaceString)
{
	// TODO: insert return statement here
}

std::ostream& operator<<(std::ostream& _stream, const Driscoll_String& _string)
{
	// TODO: insert return statement here
}
