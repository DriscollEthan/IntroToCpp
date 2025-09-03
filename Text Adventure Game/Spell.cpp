#include "Spell.h"

Spell::Spell()
{
	SpellName = "NULL";
	SpellDescription = "NULL";
	Type = NONE;
	Damage = 0.0f;
	DamageOverTime = 0.0f;
	bStuns = false;
	RechargeLength = 0;
}

Spell::Spell(const Spell& _other)
{
	SpellName = _other.SpellName;
	SpellDescription = _other.SpellDescription;
	Type = _other.Type;
	Damage = _other.Damage;
	DamageOverTime = _other.DamageOverTime;
	bStuns = _other.bStuns;
	RechargeLength = _other.RechargeLength;
}

Spell Spell::operator=(const Spell& _other)
{
	SpellName = _other.SpellName;
	SpellDescription = _other.SpellDescription;
	Type = _other.Type;
	Damage = _other.Damage;
	DamageOverTime = _other.DamageOverTime;
	bStuns = _other.bStuns;
	RechargeLength = _other.RechargeLength;
	return Spell();
}

Spell::~Spell()
{

}

Driscoll_String Spell::GetSpellName()
{
	return SpellName;
}

Driscoll_String Spell::GetSpellDescription()
{
	return SpellDescription;
}

SpellType Spell::GetSpellType()
{
	return Type;
}

float Spell::GetDamage()
{
	return Damage;
}

bool Spell::GetDoesStun()
{
	return bStuns;
}

float Spell::GetDamageOverTime()
{
	return DamageOverTime;
}

int Spell::GetRechargeLength()
{
	return RechargeLength;
}


