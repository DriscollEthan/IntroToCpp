#include "Enemy.h"

Enemy::Enemy()
{
	Health = 100.0f;
	bIsStunned = false;
}

Enemy::Enemy(float _health)
{
	Health = _health;
	bIsStunned = false;
	Damage = 30.0f;
}

Enemy::~Enemy()
{

}

float Enemy::GetHealth()
{
	return Health;
}

void Enemy::TakeDamage(float _damage)
{
	Health -= _damage;
}

float Enemy::GetDamage()
{
	return Damage;
}
