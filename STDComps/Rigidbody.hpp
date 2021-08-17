#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "../Engine/Component.hpp"
#include "../Engine/GameObject.hpp"
#include "../Engine/Engine.hpp"

using namespace GameEngine;

/// <summary>
/// MUST BE ADDED TO GAMEOBJECT BEFORE COLLIDERS
/// TODO: fix order of fixed update calls
/// </summary>
class Rigidbody : public Component
{
	/* variables */
public:
	float gravityAccel = 500;
	Vector2f velocity;
	float gravThresh = .001;
	
private:
	GameObject* gameObject;
	Engine* engine;
	float prevYPos;

	/* methods */
public:
	/// <summary>
	/// A constructor for a gravity component 
	/// </summary>
	/// <param name="GameObject">the game object that this component
	/// is attached to</param>
	Rigidbody(GameObject* gameObject);

	/// <summary>
	/// called every frame by the GameObject that has this component
	/// </summary>
	void update();
	
	/// <summary>
	/// Called every frame after update. Used to handle physics and collisions
	/// </summary>
	void lateUpdate();
};

#endif