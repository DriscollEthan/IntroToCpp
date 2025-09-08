#include "Player.h"

Player::Player()
{
	ItemsCollected = new Item[3];
	for (int i = 0; i < 3; ++i)
	{
		ItemsCollected[i] = Item();
	}

	SpellsLearned = new Spell[2];
	//FIREBALL
	SpellsLearned[0] = Fireball();
	SpellsLearned[1] = Spell();

	Health = 100.0f;

	Mana = 100.0f;

	DamageMultiplier = 1.0f;

	bIsHitable = true;
}

Player::~Player()
{
	delete[] ItemsCollected;
	delete[] SpellsLearned;
}

float Player::GetHealth()
{
	return Health;
}

float Player::GetMana()
{
	return Mana;
}

float Player::Attack(Spell* _spellUsed)
{
	float damage = _spellUsed->GetDamage() * DamageMultiplier;
	DamageMultiplier = 1.0f;
	return damage;
}

void Player::TakeDamage(float _damage)
{
	if (bIsHitable)
	{
		Health -= _damage;
		return;
	}
	else
	{
		bIsHitable = true;
	}
}

void Player::UseItem(Item* _itemToUse)
{
	switch (_itemToUse->GetItemType())
	{
	case E_HealthPotion:
		Health += 50.0f;
		break;
	case E_DamagePotion:
		DamageMultiplier = 1.5f;
		break;
	case E_Shield:
		bIsHitable = false;
		break;
	}

	for (int i = 0; ItemsCollected[i].GetItemType() != NONE; ++i)
	{
		if (ItemsCollected[i].GetItemType() == _itemToUse->GetItemType())
		{
			ItemsCollected[i].~Item();
			ItemsCollected[i] = Item();
		}
	}
}

Item* Player::GetInventory()
{
	return ItemsCollected;
}

Spell* Player::GetSpellsLeanred()
{
	return SpellsLearned;
}

void Player::AddItem(Item* _itemToAdd)
{
	for (int i = 0; i < 3; ++i)
	{
		if (ItemsCollected[i].GetItemType() == None)
		{
			ItemsCollected[i] = (*_itemToAdd);
			break;
		}
	}
}

void Player::LearnSpell(Spell _spellToLearn)
{
	SpellsLearned[1] = _spellToLearn;
}

