#include "Lighting.h"

Lighting::Lighting()
{
	SpellName = "Lighting";
	SpellDescription = "Lighting does a lot of Damage and stuns the enemy for a round.";
	Type = E_Lighting;
	Damage = 30.0f;
	DamageOverTime = 0.0f;
	bStuns = true;
	RechargeLength = 2;
}
