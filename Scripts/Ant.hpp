#ifndef ANT_H
#define ANT_H

#include "Enemy.hpp";
#include <SFML/Graphics.hpp>

using namespace sf;

class Ant : public Enemy
{
	/* Variables */
public:
	Vector2f detectionSize;

private:
	RectangleShape* detectionBox;

	/* methods */
public:
	Ant(GameObject* gameObject);

	~Ant();

	/// <summary>
	/// Damage this enemy by the given amount
	/// </summary>
	/// <param name="damange">the amount of damage to do to this enemy</param>
	void damangeEnemy(int damange);

	/// <summary>
	/// called every frame by the GameObject that has this component
	/// </summary>
	void update();

	/// <summary>
	/// Called every frame after update. Used to handle physics and collisions
	/// </summary>
	void lateUpdate();
};

#endif // !ANT_H
