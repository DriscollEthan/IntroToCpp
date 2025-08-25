#include <iostream>
#include "Room.h"
#define NEWLINE (std::cout << std::endl)

Room::Room(size_t Width,
	size_t Height,
	size_t PillarWidthSpacing,
	size_t PillarHeightSpacing)
{
	//Setup default Variables
	bool bIsWidthEven = (Width % 2 == 0);
	bool bIsHeightEven = (Height % 2 == 0);
	int doorWidthLocation = (bIsWidthEven) ? (Width / 2) - 1 : (Width / 2);
	int doorHeightLocation = (bIsHeightEven) ? (Height / 2) - 1 : (Height / 2);

	//Allocate HEAP Memory for the RoomLayout
	RoomLayout = new char*[Width];
	for (int i = 0; i < Height; ++i)
	{
		RoomLayout[i] = new char[Height];
	}

	for (int i = 0; i < Height; ++i)
	{
		if (i != 0)
		{
			NEWLINE;
		}
		for (int j = 0; j < Width; ++j)
		{
			//Check for Height and OR Height being at the Edges and Print The Width Door/No Door Accordingly
			if ((i == 0 || i == Height - 1))
			{
				//If a Door Should be in this Spot then Print a Door Because of Width
				if ((bIsWidthEven) ? (j == doorWidthLocation 
					|| j == doorWidthLocation + 1) : (j == doorWidthLocation))
				{
					Print('@');
					RoomLayout[i][j] = '@';
					continue;
				}
				//Otherwise Print a Wall
				else
				{
					Print('X');
					RoomLayout[i][j] = 'X';
					continue;
				}
			}
			if ((j == 0 || j == Width - 1))
			{
				//If a Door Should be in this Spot then Print a Door Because of Height
				if ((bIsHeightEven) ? (i == doorHeightLocation
					|| i == doorHeightLocation + 1) : (i == doorHeightLocation))
				{
					Print('@');
					RoomLayout[i][j] = '@';
					continue;
				}
				//Otherwise Print a Wall
				else
				{
					Print('X');
					RoomLayout[i][j] = 'X';
					continue;
				}
			}
			//Otherwise IF Check for a Pillar Placement in this Grid Spot
			else if ((i % (PillarHeightSpacing + 1) == 0)
				&& (j % (PillarWidthSpacing + 1) == 0))
			{
				Print('X');
				RoomLayout[i][j] = 'X';
				continue;
			}
			//If Both Fail then Print a Space
			else
			{
				Print(' ');
				RoomLayout[i][j] = ' ';
				continue;
			}
		}
	}
}

void Room::Print(char charToPrint)
{
	std::cout << charToPrint;
}
