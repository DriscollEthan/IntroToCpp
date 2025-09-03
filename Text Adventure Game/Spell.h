#pragma once
#include "Driscoll_String.h"

enum SpellType
{
	NONE,
	E_Fireball,
	E_Lighting,
	E_Poison,
	E_Curse
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
	float Damage;
	float DamageOverTime;
	bool bStuns;
	int RechargeLength;

public:
	//Functions
	Driscoll_String GetSpellName();

	Driscoll_String GetSpellDescription();

	SpellType GetSpellType();

	float GetDamage();

	bool GetDoesStun();

	float GetDamageOverTime();

	int GetRechargeLength();
};

