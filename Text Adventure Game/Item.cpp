#include "Item.h"

Item::Item()
{
	ItemName = " ";
	ItemDescription = " ";
	Type = None;
}

Item::Item(const Item& _other)
{
	ItemName = _other.ItemName;
	ItemDescription = _other.ItemDescription;
	Type = _other.Type;
}

Item Item::operator=(const Item& _other)
{
	ItemName = _other.ItemName;
	ItemDescription = _other.ItemDescription;
	Type = _other.Type;
	return *this;
}

Item::~Item()
{

}

Driscoll_String Item::GetItemName()
{
	return ItemName;
}

Driscoll_String Item::GetItemDescription()
{
	return ItemDescription;
}

ItemType Item::GetItemType()
{
	return Type;
}
