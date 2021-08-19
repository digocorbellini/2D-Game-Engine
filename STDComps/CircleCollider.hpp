#ifndef CIRCLE_COLLIDER_H
#define CIRCLE_COLLIDER_H

#include "../Engine/ColliderComp.hpp"
#include "../Engine/Engine.hpp"
#include "../Engine/Physics.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace GameEngine;

class CircleCollider : public ColliderComp
{
	/* variables */
public:
	float radius;

private:
	GameObject* gameObject;
	CircleShape* circle;
	Vector2f oldPos;
	Physics* physics;

	/* methods */
public:
	/// <summary>
	/// Constructor for a circle collider component
	/// </summary>
	/// <param name="gameObject">the gameObject that this collider is 
	/// attached to</param>
	/// <param name="radius">the radius of this circle collider</param>
	CircleCollider(GameObject* gameObject, float radius);

	/// <summary>
	/// Destructor for a circle collider component
	/// </summary>
	~CircleCollider();

	/// <summary>
	/// called every frame by the GameObject that has this component
	/// </summary>
	void update();

	/// <summary>
	/// Called every frame after update. Used to handle physics and collisions
	/// </summary>
	void lateUpdate();

	/// <summary>
	/// Get the bounds of this collider
	/// </summary>
	/// <returns>the bounds of this collider</returns>
	FloatRect getBounds();

	/// <summary>
	/// Get the gameObject that this collider is attached to
	/// </summary>
	/// <returns>the gameobject that this collider is attached to</returns>
	GameObject* getGameObject();
};

#endif