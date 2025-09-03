#pragma once
#include "Item.h"
#include "Spell.h"

class Player
{
public:
	//CONSTRUCTORS AND DESTRUCTOR
	Player();

	~Player();

protected:
	//VARIABLES
	Item* ItemsCollected;
	Spell* SpellsLearned;
	float Health;
	float Mana;
	float DamageMultiplier;
	bool bIsHitable;


public:
	//FUNCTIONS
	float GetHealth();

	float GetMana();

	void Attack(Spell* _spellUsed);

	void TakeDamage(float _damage);

	void UseItem(Item* _itemToUse);

	Item* GetInventory();

	Spell* GetSpellsLeanred();

	void AddItem(Item* _itemToAdd);

	void LearnSpell(Spell _spellToLearn);
};

