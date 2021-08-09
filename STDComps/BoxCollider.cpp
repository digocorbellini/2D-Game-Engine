#include "BoxCollider.hpp"

BoxCollider::BoxCollider(Vector2u size, GameObject* gameObject)
{
	this->size = Vector2f(size);
	this->gameObject = gameObject;
	oldPos = gameObject->transform->position;
	box = new RectangleShape(this->size);
	// set the origin to the center of the rectangle
	box->setOrigin(size.x / 2, size.y / 2);
	// the default position of this box collider is the position of the gameObject
	box->setPosition(oldPos);

	physics = Physics::getInstance();
	physics->addCollider(this);
}

BoxCollider::~BoxCollider()
{
	delete(box);
}

void BoxCollider::update()
{

}

void BoxCollider::fixedUpdate()
{
	// check for collisions here
	// check to see if new pos causes a collision and if it does then return to old pos
	// set size of box if it has been changed
	if(size != box->getSize())
		box->setSize(size);

	// check for collision in movement
	if (physics->isColliding(this) != NULL)
	{
		// collision occured so move object back to old position
		gameObject->transform->position = oldPos;
	}
	else
	{
		// no collision so replace old position
		oldPos = gameObject->transform->position;
	}

	// update box collider position
	box->setPosition(oldPos);
}

FloatRect BoxCollider::getBounds()
{
	return box->getGlobalBounds();
}