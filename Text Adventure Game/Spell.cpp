#include "Spell.h"

Spell::Spell()
{
	SpellName = "NULL";
	SpellDescription = "NULL";
	Type = NONE;
}

Spell::Spell(const Spell& _other)
{
	SpellName = _other.SpellName;
	SpellDescription = _other.SpellDescription;
	Type = _other.Type;
}

Spell Spell::operator=(const Spell& _other)
{
	SpellName = _other.SpellName;
	SpellDescription = _other.SpellDescription;
	Type = _other.Type;
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
