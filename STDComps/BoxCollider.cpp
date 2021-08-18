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

	// test new position
	box->setPosition(gameObject->transform->position);

	// check for collision in new position
	ColliderComp* collision = physics->isColliding(this);
	if (collision != NULL)
	{
		// collision occured so move collider back to prev position

		Vector2f currPos = gameObject->transform->position;
		Vector2f newPos = oldPos;

		RectangleShape testShape(box->getSize());
		testShape.setOrigin(testShape.getSize().x / 2, testShape.getSize().y / 2);


		// check for collision in the x pos
		Vector2f testX(currPos.x, oldPos.y);
		testShape.setPosition(testX);
		if (!collision->getBounds().intersects(testShape.getGlobalBounds()))
		{
			// collision not caused by movement in X
			// so newPos x can stay the same
			newPos.x = currPos.x;
		}

		// check for collision in y pos
		Vector2f testY(oldPos.x, currPos.y);
		testShape.setPosition(testY);
		if (!collision->getBounds().intersects(testShape.getGlobalBounds()))
		{
			// collision not caused by movement in y
			// so newPos x can stay the same
			newPos.y = currPos.y;
		}

		// the oldPos to move back to to avoid going into collider is the
		// adjusted pos in the x and y directions
		oldPos = newPos;

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

GameObject* BoxCollider::getGameObject()
{
	return gameObject;
}
