#include "Fireball.h"

Fireball::Fireball()
{
	SpellName = "Fireball";
	SpellDescription = "Fireball does a lot of damage.";
	Type = E_Fireball;
	Damage = 20.0f;
	DamageOverTime = 0.0f;
	bStuns = false;
	RechargeLength = 0;
}
