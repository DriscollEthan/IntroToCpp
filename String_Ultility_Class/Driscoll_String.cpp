#include "Driscoll_String.h"

Driscoll_String::Driscoll_String()
{
	//Initialize the Null Terminating Operator. By Creating the Memory space the Null Terminating Operator.
	Length = 1;
	Contents = new char[Length]; 
	Contents[0] = '\0';
}

Driscoll_String::Driscoll_String(const char* _string)
{
	//Find The Length of the String, and include the Null Terminating Operating into the Length by Default.
	Length = 1;
	for (int i = 0; _string[i] != '\0'; ++i)
	{
		Length++;
	}

	//Allocate the memeory for the new Length of the String
	Contents = new char[Length];

	//Set the String Contents to the Inputted String
	for (int i = 0; i < Length - 1; ++i)
	{
		Contents[i] = _string[i];
	}

	//Add the Null Terminating Operator the end of the String.
	Contents[Length - 1] = '\0';
}

Driscoll_String::Driscoll_String(const Driscoll_String& _other)
{
	//Find The Length of the String, and include the Null Terminating Operating into the Length by Default.
	Length = (_other.GetLength()) + 1;

	//Allocate the memeory for the new Length of the String
	Contents = new char[Length];

	//Set the String Contents to the Inputted String
	for (int i = 0; i < Length - 1; ++i)
	{
		Contents[i] = _other.CharacterAt(i);
	}

	//Add the Null Terminating Operator the end of the String.
	Contents[Length - 1] = '\0';
}

Driscoll_String& Driscoll_String::operator=(const Driscoll_String& _other)
{
	delete[] Contents;

	//Find The Length of the String, and include the Null Terminating Operating into the Length by Default.
	Length = (_other.GetLength()) + 1;

	//Allocate the memeory for the new Length of the String
	Contents = new char[Length];

	//Set the String Contents to the Inputted String
	for (int i = 0; i < Length - 1; ++i)
	{
		Contents[i] = _other.CharacterAt(i);
	}

	//Add the Null Terminating Operator the end of the String.
	Contents[Length - 1] = '\0';

	return *this;
}

Driscoll_String::~Driscoll_String()
{
	delete[] Contents;
}

size_t Driscoll_String::GetLength() const
{
	//Return the Length, and exclude the Null Terminating Operator.
	return Length - 1;
}

char& Driscoll_String::CharacterAt(size_t _index)
{
	//Bounds Checking || Length - 1 is where the Null Terminating Operator is, so if the Index is less than that, it should be in bounds.
	if (_index < Length - 1)
	{
		return Contents[_index];
	}

	//This should return the Null Terminating Operator, saying that the Index was out of Bounds.
	return Contents[Length - 1];
}

char& Driscoll_String::CharacterAt(size_t _index) const
{
	//Bounds Checking || Length - 1 is where the Null Terminating Operator is, so if the Index is less than that, it should be in bounds.
	if (_index < Length - 1)
	{
		return Contents[_index];
	}

	//This should return the Null Terminating Operator, saying that the Index was out of Bounds.
	return Contents[Length - 1];
}
