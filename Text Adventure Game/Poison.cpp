#include "Poison.h"

Poison::Poison()
{
	SpellName = "Poison";
	SpellDescription = "Poison is a spell that does some damage, and will deal damage to an enemy over time.";
	Type = E_Poison;
	Damage = 5.0f;
	DamageOverTime = 15.0f;
	bStuns = false;
	RechargeLength = 3;
}
