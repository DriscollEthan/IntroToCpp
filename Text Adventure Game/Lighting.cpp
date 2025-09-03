#include "Lighting.h"

Lighting::Lighting()
{
	SpellName = "Lighting";
	SpellDescription = "Lighting does a lot of Damage and stuns, but takes a while to recharge.";
	Type = E_Lighting;
	Damage = 40.0f;
	DamageOverTime = 0.0f;
	bStuns = true;
	RechargeLength = 2;
}
