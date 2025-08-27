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
	Driscoll_String tempString(Driscoll_String(*this));
	return tempString.Append(_other);
}

Driscoll_String& Driscoll_String::operator+=(const Driscoll_String& _other)
{
	return this->Append(_other);
}

bool Driscoll_String::operator==(const Driscoll_String& _other) const
{
	return this->Equals(_other);
}

bool Driscoll_String::operator!=(const Driscoll_String& _other) const
{
	return !(this->Equals(_other));
}

char& Driscoll_String::operator[](size_t _index)
{
	return this->CharacterAt(_index);
}

const char& Driscoll_String::operator[](size_t _index) const
{
	return this->CharacterAt(_index);
}

std::ostream& operator<<(std::ostream& _stream, const Driscoll_String& _string)
{
	_stream << _string.Contents;
	return _stream;
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
	//If We Need To Get rid of Old Memory, and create new memory to store this string and the other String. Then DO IT as done below
	
	if (TOTAL_LENGTH < (TOTAL_LENGTH + _otherString.CONTENTS_LENGTH))
	{
		//Allocate new Memory.
		TOTAL_LENGTH += _otherString.TOTAL_LENGTH;
		char* tempPointerToNewMemory = new char[TOTAL_LENGTH];

		//Do Append Functionality
		for (int i = 0; i < (TOTAL_LENGTH); ++i)
		{
			if ((i <= CONTENTS_LENGTH) && (CharacterAt(i) != '\0'))
			{
				tempPointerToNewMemory[i] = CharacterAt(i);
			}
			else
			{
				tempPointerToNewMemory[i] = _otherString.CharacterAt(i - CONTENTS_LENGTH);
			}
		}
		tempPointerToNewMemory[TOTAL_LENGTH - 1] = '\0';

		//Destroy old Memory
		delete[] Contents;
		
		//Update Contets Pointer to New Memory.
		Contents = tempPointerToNewMemory;
	}

	else
	{
		//Do Append Functionality
		for (int i = CONTENTS_LENGTH; i < (TOTAL_LENGTH); ++i)
		{
			Contents[i] = _otherString.CharacterAt(i);
		}
	}

	//Ensure that the last index has a NULL TERMINATING OPERATOR and That the CONTENTS_LENGTH is Properly Reset Then Return this String Class.
	Contents[TOTAL_LENGTH - 1] = '\0';
	CONTENTS_LENGTH = TOTAL_LENGTH - 1;
	return *this;
}

Driscoll_String& Driscoll_String::Prepend(const Driscoll_String& _otherString)
{
	//If We Need To Get rid of Old Memory, and create new memory to store this string and the other String. Then DO IT as done below

	if (TOTAL_LENGTH < (TOTAL_LENGTH + _otherString.CONTENTS_LENGTH))
	{
		//Allocate new Memory.
		TOTAL_LENGTH += _otherString.TOTAL_LENGTH;
		char* tempPointerToNewMemory = new char[TOTAL_LENGTH];

		//Do Prepend Functionality
		for (int i = 0; i < (TOTAL_LENGTH - 1); ++i)

		{
			if (i <= CONTENTS_LENGTH)
			{
				tempPointerToNewMemory[i] = _otherString.CharacterAt(i);

			}
			else
			{
				tempPointerToNewMemory[i] = CharacterAt(i - _otherString.CONTENTS_LENGTH);
			}
		}
		tempPointerToNewMemory[TOTAL_LENGTH - 1] = '\0';

		//Destroy old Memory
		delete[] Contents;

		//Update Contets Pointer to New Memory.
		Contents = tempPointerToNewMemory;
	}

	else
	{
		TOTAL_LENGTH += _otherString.CONTENTS_LENGTH;

		//Shift Current String to Fit Old String
		for (int i = (TOTAL_LENGTH - 1); i >= _otherString.CONTENTS_LENGTH; --i)
		{
			Contents[i] = CharacterAt(i - _otherString.CONTENTS_LENGTH);
		}

		//Do Prepend Functionality
		for (int i = 0; i < (_otherString.CONTENTS_LENGTH); ++i)
		{
			Contents[i] = _otherString.CharacterAt(i);
		}
	}

	//Ensure that the last index has a NULL TERMINATING OPERATOR and That the CONTENTS_LENGTH is Properly Reset Then Return this String Class.
	Contents[TOTAL_LENGTH - 1] = '\0';
	CONTENTS_LENGTH = TOTAL_LENGTH - 1;
	return *this;
}

const char* Driscoll_String::CStr() const
{
	return Contents;
}

Driscoll_String Driscoll_String::ToLower() const
{
	for (int i = 0; i < GetLength(); ++i)
	{
		//Figure out if it's Uppercase. If So, then add 32 to make the letter Lowercase.
		if ((CharacterAt(i) >= 65) && CharacterAt(i) <= 90)
		{
			Contents[i] = CharacterAt(i) + 32;
		}
	}

	return Driscoll_String();
}

Driscoll_String Driscoll_String::ToUpper() const
{
	for (int i = 0; i < GetLength(); ++i)
	{
		//Figure out if it's Lowercase. If So, then subtract 32 to make the letter Uppercase.
		if ((CharacterAt(i) >= 97) && CharacterAt(i) <= 122)
		{
			Contents[i] = CharacterAt(i) - 32;
		}
	}
	return Driscoll_String();
}

int Driscoll_String::Find(const Driscoll_String& _subString)
{
	//x is the counter to see how many letter in a row match the Subtring from this string.
	int x = 0;

	for (int i = 0; i < GetLength(); ++i)
	{
		if (CharacterAt(i) == _subString.CharacterAt(x))
		{
			++x;
			if (x == _subString.GetLength())
			{
				return i - _subString.GetLength() + 1;
			}
		}
		else
		{
			x = 0;
		}
	}

	return -1;
}

int Driscoll_String::Find(size_t _startIndex, const Driscoll_String& _subString)
{
	//x is the counter to see how many letter in a row match the Subtring from this string.
	int x = 0;

	for (int i = _startIndex; i < GetLength(); ++i)
	{
		if (CharacterAt(i) == _subString.CharacterAt(x))
		{
			++x;
			if (x == _subString.GetLength())
			{
				return i;
			}
		}
		else
		{
			x = 0;
		}
	}

	return -1;
}

Driscoll_String& Driscoll_String::Replace(const Driscoll_String& _findString, const Driscoll_String& _replaceString)
{
	//Resize Memory
	int occurences = 0;

	for (int i = Find(_findString); Find(i, _findString) != -1; ++occurences)
	{
		i = Find(i, _findString) + 1;
	}

	int difference = (occurences * (_replaceString.GetLength() - _findString.GetLength()));
	TOTAL_LENGTH += difference + 10;

	char* tempPointerToNewMemory = new char[TOTAL_LENGTH + 1];

	for (int i = GetLength() + difference; i >= 0; --i)
	{
		if (i - difference >= 0)
		{
			tempPointerToNewMemory[i] = Contents[i - difference];
		}
		else
		{
			tempPointerToNewMemory[i] = '\0';
		}

	}
	tempPointerToNewMemory[TOTAL_LENGTH - 1] = '\0';
	delete[] Contents;
	CONTENTS_LENGTH = TOTAL_LENGTH - 1;
	Contents = tempPointerToNewMemory;

	//Figure out which string is longer, and use that numbers to remove the strings to remove and replace them.
	size_t stringLengthRemovalAtATime = (_findString.GetLength() >= _replaceString.GetLength()) ? _findString.GetLength() : _replaceString.GetLength();

	while (Find(_findString) != -1)
	{
		int index = Find(_findString);

		for (int i = index; i < stringLengthRemovalAtATime + index; ++i)
		{
			if (Contents[i] != '\0')
			{
				Contents[i] = '\0';
			}
		}

		for (int i = index; Contents[i] == '\0'; ++i)
		{
			Contents[i] = _replaceString[i - index];
		}

	}

	while (Contents[0] == '\0')
	{
		for (int i = 0; Contents[i] == '\0'; ++i)
		{
			Contents[i] = ' ';
		}
	}

	Contents[TOTAL_LENGTH] = '\0';
	return *this;
}