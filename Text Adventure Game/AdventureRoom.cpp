#include "AdventureRoom.h"

AdventureRoom::AdventureRoom()
{
	ItemInRoom = Item();
	bIsItemTakeable = false;
	RoomName = "NONE";
	bIsSpellRoom = false;
	RoomID = -1;
}

AdventureRoom::AdventureRoom(const Driscoll_String _roomName)
{
	RoomName = _roomName;
	ItemInRoom = Item();
	bIsItemTakeable = false;
	bIsSpellRoom = false;
	RoomID = -1;
}

AdventureRoom::AdventureRoom(const Item _itemType, const bool _bIsStillThere, const Driscoll_String _roomName)
{
	ItemInRoom = Item(_itemType);
	bIsItemTakeable = _bIsStillThere;
	RoomName = _roomName;
	bIsSpellRoom = false;
	RoomID = -1;
}

AdventureRoom::AdventureRoom(const bool _bIsSpellRoom, const Driscoll_String _roomName) : AdventureRoom()
{
	bIsSpellRoom = _bIsSpellRoom;
	RoomName = _roomName;
	ItemInRoom = Item();
	bIsItemTakeable = false;
	RoomID = -1;
}

AdventureRoom::AdventureRoom(const AdventureRoom& _other)
{
	ItemInRoom = _other.ItemInRoom;
	bIsItemTakeable = _other.bIsItemTakeable;
	RoomName = _other.RoomName;
	bIsSpellRoom = _other.bIsSpellRoom;
	RoomID = _other.RoomID;
}

AdventureRoom AdventureRoom::operator=(const AdventureRoom& _other)
{
	ItemInRoom = _other.ItemInRoom;
	bIsItemTakeable = _other.bIsItemTakeable;
	RoomName = _other.RoomName;
	bIsSpellRoom = _other.bIsSpellRoom;
	RoomID = _other.RoomID;
	return *this;
}

AdventureRoom::~AdventureRoom()
{

}

Item* AdventureRoom::GetItem()
{
	if (bIsItemTakeable)
	{
		return &ItemInRoom;
	}
	return nullptr;
}

Driscoll_String AdventureRoom::GetItemName()
{
	return ItemInRoom.GetItemName();
}

Driscoll_String AdventureRoom::GetRoomName()
{
	return RoomName;
}

Driscoll_String AdventureRoom::GetItemDescription()
{
	return ItemInRoom.GetItemDescription();
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

void AdventureRoom::SetItemTaken(bool _bIsItemTaken)
{
	bIsItemTakeable = (!_bIsItemTaken);
}
