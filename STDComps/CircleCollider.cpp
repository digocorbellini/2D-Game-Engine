#include "CircleCollider.hpp"

CircleCollider::CircleCollider(GameObject* gameObject, float radius)
{
	this->radius = radius;
	this->gameObject = gameObject;
	oldPos = gameObject->transform->position;
	isTrigger = false;
	
	// create circle shape
	circle = new CircleShape(radius);
	circle->setOrigin(Vector2f(radius, radius));
	circle->setPosition(oldPos);

	// add gizmo for collider
	circle->setFillColor(Color::Transparent);
	circle->setOutlineColor(Color::Green);
	circle->setOutlineThickness(5);
	Renderer::getInstance()->addGizmo(circle);

	// add this collider to the collider list
	physics = Physics::getInstance();
	physics->addCollider(this);
}

CircleCollider::~CircleCollider()
{
	Renderer::getInstance()->removeGizmo(circle);
	physics->removeCollider(this);
	delete(circle);
}

void CircleCollider::update()
{

}

void CircleCollider::lateUpdate()
{
	// check for collisions here
	// set new scale
	circle->setRadius(radius);
	circle->setScale(gameObject->transform->scale);
	// re-center origin
	circle->setOrigin(radius, radius);

	// ignore collisions if this collider is a trigger
	if (isTrigger)
	{
		return;
	}

	// handle collisions
	// test new position for collision
	circle->setPosition(gameObject->transform->position);
	vector<ColliderComp*>* collisions = physics->isCollidingAll(this);

	if (collisions->size() == 0)
	{
		// no collision so replace old position with new position
		oldPos = gameObject->transform->position;
	}
	else
	{
		// collision occured so have to move back to a position where
		// there is no collision
		Vector2f currPos = gameObject->transform->position;
		Vector2f newPos = oldPos;

		CircleShape testShape(radius);
		testShape.setScale(circle->getScale());
		testShape.setOrigin(Vector2f(radius, radius));

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
		gameObject->transform->position = oldPos;
		circle->setPosition(oldPos);
	}
	delete(collisions);
}

FloatRect CircleCollider::getBounds()
{
	return circle->getGlobalBounds();
}

GameObject* CircleCollider::getGameObject()
{
	return gameObject;
}