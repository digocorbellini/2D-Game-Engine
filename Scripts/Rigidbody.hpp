#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "../Engine/Component.hpp"
#include "../Engine/GameObject.hpp"
#include "../Engine/Engine.hpp"

using namespace GameEngine;

class Rigidbody : public Component
{
	/* variables */
public:
	float gravityAccel = 500;
	Vector2f velocity;
	float gravThresh = .005;
	
private:
	GameObject* gameObject;
	Engine* engine;
	float prevYPos;
	bool applyGrav;

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
	void fixedUpdate();
};

#endif