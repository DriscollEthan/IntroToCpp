#pragma once


class Room
{
public: 
	//Defaults: Constructors || Descuctors
	Room() = default;

	//Room Generator Constructor
	Room(size_t Width, 
		size_t Height, 
		size_t PillarWidthSpacing, 
		size_t PillarHeightSpacing);

	// Copy constructor
	// Constructs a new 'Room' by copying an existing one
	Room(const Room& Other);

	// Copy assignment
	// Updates an existing 'Room' by copying another existing Room
	Room& operator=(const Room& Other);

	// Move constructor
	// Constructs a new 'Room' by stealing the data of an existing one
	Room(Room&& Other);

	// Move assignment
	// Updates an existing 'Room' by stealing the data of another existing Room
	Room& operator=(Room&& Other);

	~Room();

	//Do we need any Variables?
	//RoomLayout, 2D Array of Characters used to print the Room Layout
	char** RoomLayout;
	//Room Width, The 1D Width of the RoomLayout, including room for the \0 char.
	int RoomWidth;
	//Room Height, The 1D Height of the RoomLayout, including room for the \0 char.
	int RoomHeight;

	//Define Function To Print the Room
	void Print(char charToPrint);
	void PrintRoom();
};

