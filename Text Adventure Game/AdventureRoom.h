#pragma once
#include "Driscoll_String.h"
#include "Item.h"

class AdventureRoom
{
public:
	//Constructors
	AdventureRoom();

	AdventureRoom(const Driscoll_String _roomName);

	AdventureRoom(const Item _itemType, const bool _bIsStillThere, const Driscoll_String _roomName);

	AdventureRoom(const bool _bIsSpellRoom, Driscoll_String _roomName);

	AdventureRoom(const AdventureRoom& _other);

	AdventureRoom operator=(const AdventureRoom& _other);

	//Destructors
	~AdventureRoom();

protected:
	//Variables
	Item ItemInRoom;

	bool bIsItemTakeable;

	Driscoll_String RoomName;

	bool bIsSpellRoom;

	int RoomID;

public:
	//Functions
	Item* GetItem();

	Driscoll_String GetItemName();

	Driscoll_String GetRoomName();

	Driscoll_String GetItemDescription();

	bool IsSpellRoom();

	int GetRoomID();

	void SetRoomID(int _newID);

	void SetItemTaken(bool _bIsItemTaken);
};


