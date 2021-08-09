#ifndef BOX_COLLIDER_H
#define BOX_COLLIDER_H

#include "..\Engine\Component.hpp"
#include "..\Engine\Engine.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace GameEngine;

class BoxCollider : public Component
{
	/* variables */
public:
	Vector2f size;

private:
	GameObject* gameObject;
	RectangleShape* box;
	Vector2f oldPos;

public:
	BoxCollider(Vector2f size, GameObject* gameObject);

	~BoxCollider();

	/// <summary>
	/// called every frame by the GameObject that has this component
	/// </summary>
	void update();

	/// <summary>
	/// Called every frame after update. Used to handle physics and collisions
	/// </summary>
	void fixedUpdate();
};

#endif // !BOX_COLLIDER_H

