#include "BoxCollider.hpp"

BoxCollider::BoxCollider(Vector2f size, GameObject* gameObject)
{
	this->size = size;
	this->gameObject = gameObject;
	oldPos = gameObject->transform->position;
	box = new RectangleShape(size);
	// the default position of this box collider is the position of the gameObject
	box->setPosition(oldPos);
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


}