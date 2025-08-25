#pragma once


class Room
{
public: 
	//Defaults: Constructors || Descuctors
	Room() = default;

	Room(size_t Width, 
		size_t Height, 
		size_t PillarWidthSpacing, 
		size_t PillarHeightSpacing);

	~Room();

	//Do we need any Variables?
	char** RoomLayout;

	//Define Function To Print the Room
	void Print(char charToPrint);
};

