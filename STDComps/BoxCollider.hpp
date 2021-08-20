#ifndef BOX_COLLIDER_H
#define BOX_COLLIDER_H

#include "..\Engine\ColliderComp.hpp"
#include "..\Engine\Engine.hpp"
#include "..\Engine\Physics.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace GameEngine;

class BoxCollider : public ColliderComp
{
	/* variables */
public:
	Vector2f size;
	Vector2f offset;

private:
	GameObject* gameObject;
	RectangleShape* box;
	Vector2f oldPos;
	Physics* physics;

	/* methods */
public:
	/// <summary>
	/// Constructor for a new box collider component
	/// </summary>
	/// <param name="size">the size of this box collider (square dimensions)</param>
	/// <param name="gameObject">the gameObject that this component is attached to</param>
	BoxCollider(Vector2u size, GameObject* gameObject);

	/// <summary>
	/// Destructor for a box collider component
	/// </summary>
	~BoxCollider();

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

#endif // !BOX_COLLIDER_H

