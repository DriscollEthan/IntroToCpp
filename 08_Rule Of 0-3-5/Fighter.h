#pragma once
class Fighter
{
public:
	Fighter();

	Fighter(Fighter* Other);

	Fighter(int Health);

	int CurrentHealth;
	int CurrentDefense;

	Fighter* Opponent;

	~Fighter();
};

