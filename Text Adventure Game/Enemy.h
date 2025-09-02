#pragma once
class Enemy
{
public:
	Enemy();

	Enemy(float _health);

	~Enemy();

protected:
	float Health;
	bool bIsStunned;

public:
	float GetHealth();

	void TakeDamage(float _damage);
};

