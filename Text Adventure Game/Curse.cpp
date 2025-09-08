#include "Curse.h"

Curse::Curse()
{
	SpellName = "Curse";
	SpellDescription = "Curse is a spell that will nerf the damage of an enemy for a couple rounds.";
	Type = E_Curse;
	Damage = 15.0f;
	DamageOverTime = 0.0f;
	bStuns = false;
	RechargeLength = 3;
}
