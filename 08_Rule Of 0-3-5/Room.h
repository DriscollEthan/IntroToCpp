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

	//Do we need any Variables?
	char** RoomLayout;
	
	//Define Functions to Setup the Room


	//Define Function To Print the Room
	void Print(char charToPrint);
};

