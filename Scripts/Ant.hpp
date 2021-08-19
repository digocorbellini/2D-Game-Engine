#ifndef ANT_H
#define ANT_H

#include "Enemy.hpp";
#include <SFML/Graphics.hpp>
#include "../Engine/Renderer.hpp"
#include "../Engine/Layers.hpp"
#include "../Engine/Physics.hpp"
#include "../STDComps/Rigidbody.hpp"
#include <math.h>
#include "PlayerController.hpp"

using namespace std;
using namespace sf;

class Ant : public Enemy
{
	/* Variables */
public:
	Vector2f detectionSize = Vector2f(800, 800);
	Vector2f hitBoxSize = Vector2f(100, 100);
	GameLayer playerLayer = GameLayer::PLAYER;
	GameLayer enemyLayer = GameLayer::ENEMIES;
	float speed = 100;

private:
	RectangleShape* detectionBox;
	RectangleShape*	hitBox;
	Physics* physics;
	Renderer* renderer;
	Rigidbody* rb;

	/* methods */
public:
	Ant(GameObject* gameObject);

	~Ant();

	/// <summary>
	/// Damage this enemy by the given amount
	/// </summary>
	/// <param name="damange">the amount of damage to do to this enemy</param>
	void damageEnemy(int damange);

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
