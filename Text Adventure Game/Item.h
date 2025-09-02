#pragma once
#include "Driscoll_String.h"

enum ItemType
{
	HealthPotion,
	DamagePotion,
	Shield
};

class Item
{
public:
	//Constructors
	Item();

	Item(const Item& _other);

	Item operator=(const Item& _other);

	~Item();

protected:
	//Variables
	Driscoll_String ItemName;
	Driscoll_String ItemDescription;
	ItemType Type;

public:
	//Functions
	Driscoll_String GetItemName();

	Driscoll_String GetItemDescription();

	ItemType GetItemType();
};

