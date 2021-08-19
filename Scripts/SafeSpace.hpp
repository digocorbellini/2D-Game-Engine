#ifndef SAFE_SPACE_H
#define SAFE_SPACE_H

#include "../Engine/Component.hpp"
#include "../Engine/GameObject.hpp"
#include <SFML/Graphics.hpp>
#include "../Engine/Renderer.hpp"

using namespace GameEngine;
using namespace sf;

class SafeSpace : public Component
{
	/* variables */
public:
	Vector2f safeSpaceSize;

private:
	GameObject* gameObject;
	RectangleShape* safeBox;

	/* methods */
public:
	/// <summary>
	/// A constructor for a safe space object
	/// </summary>
	/// <param name="gameObject">the game object that this component is
	/// attached to</param>
	SafeSpace(GameObject* gameObject);

	/// <summary>
	/// A destructor for a safe space Object
	/// </summary>
	~SafeSpace();

	/// <summary>
	/// called every frame by the GameObject that has this component
	/// </summary>
	void update();

	/// <summary>
	/// Called every frame after update. Used to handle physics and collisions
	/// </summary>
	void lateUpdate();

	/// <summary>
	/// Get the gameObject that this component is attached to
	/// </summary>
	/// <returns>the gameObject that this component is attached to</returns>
	GameObject* getGameObject();

	/// <summary>
	/// Get the shape of this safe space
	/// </summary>
	/// <returns>the shape of this safe space</returns>
	RectangleShape* getShape();
};

#endif // !SAFE_SPACE_H