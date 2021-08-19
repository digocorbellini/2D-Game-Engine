#include "SafeSpace.hpp"

SafeSpace::SafeSpace(GameObject* gameObject)
{
	this->gameObject = gameObject;

	// create safe box
	safeBox = new RectangleShape(safeSpaceSize);
	safeBox->setOrigin(Vector2f(safeSpaceSize.x / 2, safeSpaceSize.y / 2));
	safeBox->setPosition(gameObject->transform->position);

	// add safe box to gizmos
	safeBox->setFillColor(Color::Transparent);
	safeBox->setOutlineColor(Color::Blue);
	safeBox->setOutlineThickness(1);
	Renderer::getInstance()->addGizmo(safeBox);
}

SafeSpace::~SafeSpace()
{
	Renderer::getInstance()->removeGizmo(safeBox);
	delete(safeBox);
}

void SafeSpace::update()
{
	safeBox->setSize(safeSpaceSize);
	safeBox->setOrigin(Vector2f(safeSpaceSize.x / 2, safeSpaceSize.y / 2));
	safeBox->setPosition(gameObject->transform->position);
}

void SafeSpace::lateUpdate()
{

}

GameObject* SafeSpace::getGameObject()
{
	return gameObject;
}

RectangleShape* SafeSpace::getShape()
{
	return safeBox;
}
