#include "Poison.h"

Poison::Poison()
{
	SpellName = "Poison";
	SpellDescription = "Poison is a spell that does some damage, and will deal damage over time, but after beign used it will take some time to recharge.";
	Type = E_Poison;
	Damage = 10.0f;
	DamageOverTime = 15.0f;
	bStuns = false;
	RechargeLength = 3;
}
