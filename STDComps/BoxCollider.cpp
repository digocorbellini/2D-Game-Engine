#include "BoxCollider.hpp"

BoxCollider::BoxCollider(Vector2u size, GameObject* gameObject)
{
	this->size = Vector2f(size);
	this->gameObject = gameObject;
	oldPos = gameObject->transform->position + offset;
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

	isTrigger = false;
}

BoxCollider::~BoxCollider()
{
	Renderer::getInstance()->removeGizmo(box);
	physics->removeCollider(this);
	delete(box);
}

void BoxCollider::update()
{

}

void BoxCollider::lateUpdate()
{
	// check for collisions here
	 
	// set new size
	Vector2f newSize;
	newSize.x = size.x * gameObject->transform->scale.x;
	newSize.y = size.y * gameObject->transform->scale.y;
	box->setSize(newSize);
	// re-center origin
	box->setOrigin(box->getSize().x / 2, box->getSize().y / 2);

	// ignore collisions if this collider is a trigger
	if (isTrigger)
	{
		return;
	}

	// handle collisions
	// test new position for collision
	box->setPosition(gameObject->transform->position + offset);
	vector<ColliderComp*>* collisions = physics->isCollidingAll(this);

	if (collisions->size() == 0)
	{
		// no collision so replace old position with new position
		oldPos = gameObject->transform->position + offset;
	}
	else
	{
		// collision occured so have to move back to a position where
		// there is no collision
		Vector2f currPos = gameObject->transform->position + offset;
		Vector2f newPos = oldPos;

		RectangleShape testShape(box->getSize());
		testShape.setOrigin(testShape.getSize().x / 2, testShape.getSize().y / 2);

		// check for collision in the x direction
		Vector2f testX(currPos.x, oldPos.y);
		testShape.setPosition(testX);
		// if the movement in the x direction does not cause this collider to
		// collide with any of the collided with colliders, then move in the
		// x direction
		newPos.x = currPos.x;
		for (int i = 0; i < collisions->size(); i++)
		{
			ColliderComp* currCol = (*collisions)[i];
			if (currCol->getBounds().intersects(testShape.getGlobalBounds()))
			{
				// collision caused by movement in X
				// so newPos x has to go back to oldPos x
				newPos.x = oldPos.x;
			}
		}	

		// check for collision in y direction
		Vector2f testY(oldPos.x, currPos.y);
		testShape.setPosition(testY);
		// if the movement in the y direction does not cause this collider to
		// collide with any of the collided with colliders, then move in the
		// y direction
		newPos.y = currPos.y;
		for (int i = 0; i < collisions->size(); i++)
		{
			ColliderComp* currCol = (*collisions)[i];
			if (currCol->getBounds().intersects(testShape.getGlobalBounds()))
			{
				// collision caused by movement in y
				// so newPos x has to go back to oldPos y
				newPos.y = oldPos.y;
			}
		}

		// the oldPos to move back to to avoid going into collider is the
		// adjusted pos in the x and y directions
		oldPos = newPos;

		// collision occured so move object back to old position
		gameObject->transform->position = oldPos - offset;
		box->setPosition(oldPos);
	}
	delete(collisions);
}

FloatRect BoxCollider::getBounds()
{
	return box->getGlobalBounds();
}

GameObject* BoxCollider::getGameObject()
{
	return gameObject;
}