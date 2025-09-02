#pragma once
#include "Driscoll_String.h"

enum SpellType
{
	NONE,
	Fireball,
	Lighting,
	Poison,
	Curse
};

class Spell
{
public:
	//Constructors
	Spell();

	Spell(const Spell& _other);

	Spell operator=(const Spell& _other);

	~Spell();

protected:
	//Variables
	Driscoll_String SpellName;
	Driscoll_String SpellDescription;
	SpellType Type;

public:
	//Functions
	Driscoll_String GetSpellName();

	Driscoll_String GetSpellDescription();

	SpellType GetSpellType();
};

