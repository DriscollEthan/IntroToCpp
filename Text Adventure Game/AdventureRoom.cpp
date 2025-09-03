#include "AdventureRoom.h"

AdventureRoom::AdventureRoom()
{
	ItemInRoom = nullptr;
	bIsItemTakeable = false;
}

AdventureRoom::AdventureRoom(const Driscoll_String _roomName)
{
	RoomName = _roomName;
}

AdventureRoom::AdventureRoom(const Item _itemType, const bool _bIsStillThere, const Driscoll_String _roomName)
{
	ItemInRoom = new Item(_itemType);
	bIsItemTakeable = _bIsStillThere;
	RoomName = _roomName;
}

AdventureRoom::AdventureRoom(const bool _bIsSpellRoom, const Driscoll_String _roomName) : AdventureRoom()
{
	bIsSpellRoom = _bIsSpellRoom;
	RoomName = _roomName;
}

AdventureRoom::~AdventureRoom()
{
	delete ItemInRoom;
}

Item* AdventureRoom::GetItem()
{
	if (bIsItemTakeable)
	{
		return ItemInRoom;
	}
	return nullptr;
}

Driscoll_String AdventureRoom::GetItemName()
{
	return ItemInRoom->GetItemName();
}

Driscoll_String AdventureRoom::GetRoomName()
{
	return RoomName;
}

Driscoll_String AdventureRoom::GetItemDescription()
{
	return ItemInRoom->GetItemDescription();
}

bool AdventureRoom::IsSpellRoom()
{
	return bIsSpellRoom;
}

int AdventureRoom::GetRoomID()
{
	return RoomID;
}

void AdventureRoom::SetRoomID(int _newID)
{
	RoomID = _newID;
}
