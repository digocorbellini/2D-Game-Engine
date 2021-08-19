#ifndef ENEMY_H
#define ENEMY_H

#include "../Engine/Component.hpp"
#include "Health.hpp"
#include "../Engine/GameObject.hpp"

using namespace GameEngine;

class Enemy : public Component
{
protected:
	GameObject* gameObject;
	Health* health;

public:
	int damage;

	/// <summary>
	/// Virtual destructor
	/// </summary>
	virtual ~Enemy()
	{

	}

	/// <summary>
	/// Damage this enemy by the given amount
	/// </summary>
	/// <param name="damange">the amount of damage to do to this enemy</param>
	virtual void damageEnemy(int damange) = 0;
};

#endif // !ENEMY_H