#include "Rigidbody.hpp"
#include <math.h>
#include <iostream>
using namespace std;

Rigidbody::Rigidbody(GameObject* gameObject)
{
	this->gameObject = gameObject;
	this->engine = Engine::getInstance();
	prevYPos = gameObject->transform->position.y;
}

void Rigidbody::update()
{
	// stop applying gravity if the object has stopped moving down
	if (abs(gameObject->transform->position.y - prevYPos) < gravThresh)
	{
		velocity.y = 0;
	}
	//cout << abs(gameObject->transform->position.y - prevYPos) << endl;
}

void Rigidbody::fixedUpdate()
{
	// calculate the final y velocity given the acceleration of gravity
	float deltaTime = engine->getDeltaTime();
	float currYVel = velocity.y;
	float finalYVel = currYVel + gravityAccel * deltaTime;

	//cout << currYVel << endl;
	//cout << finalYVel << endl;
	//cout << "prev y: " << prevYPos << endl;
	//cout << "curr y: " << gameObject->transform->position.y << endl;


	// the curr y vel is the prev y vel for the next frame
	velocity.y = finalYVel;
	prevYPos = gameObject->transform->position.y;

	// apply the y velocity
	gameObject->transform->position.y += finalYVel * deltaTime;
	// apply x velocity
	gameObject->transform->position.x += velocity.x * deltaTime;
}