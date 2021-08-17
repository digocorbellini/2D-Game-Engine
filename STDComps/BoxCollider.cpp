#include "BoxCollider.hpp"

BoxCollider::BoxCollider(Vector2u size, GameObject* gameObject)
{
	this->size = Vector2f(size);
	this->gameObject = gameObject;
	oldPos = gameObject->transform->position;
	box = new RectangleShape(this->size);
	// set the origin to the center of the rectangle
	box->setOrigin(box->getSize().x / 2, box->getSize().y / 2);
	// the default position of this box collider is the position of the gameObject
	box->setPosition(oldPos);

	physics = Physics::getInstance();
	physics->addCollider(this);

	// add gizmo for collider
	box->setFillColor(Color::Transparent);
	box->setOutlineColor(Color::Green);
	box->setOutlineThickness(1);
	Renderer::getInstance()->addGizmo(box);
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
	 
	// set new size
	Vector2f newSize;
	newSize.x = size.x * gameObject->transform->scale.x;
	newSize.y = size.y * gameObject->transform->scale.y;
	box->setSize(newSize);
	// re-center origin
	box->setOrigin(box->getSize().x / 2, box->getSize().y / 2);

	// test new position
	box->setPosition(gameObject->transform->position);

	// check for collision in new position
	if (physics->isColliding(this) != NULL)
	{
		// TODO: do this for y and x positions separately

		// collision occured so move object back to old position
		gameObject->transform->position = oldPos;
		box->setPosition(oldPos);
	}
	else
	{
		// no collision so replace old position with new position
		oldPos = gameObject->transform->position;
	}
}

FloatRect BoxCollider::getBounds()
{
	return box->getGlobalBounds();
}
