#include "Fighter.h"

Fighter::Fighter()
{
	CurrentHealth = 100;
	CurrentDefense = 20;
}

Fighter::Fighter(Fighter* Other)
{
	CurrentHealth = Other->CurrentHealth;
	CurrentDefense = Other->CurrentDefense;
}

Fighter::Fighter(int Health)
{
	CurrentHealth = Health;
	CurrentDefense = 20;
}

Fighter::~Fighter()
{
}
