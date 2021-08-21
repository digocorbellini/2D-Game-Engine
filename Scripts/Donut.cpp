#include "Donut.hpp"

#include <iostream>

using namespace std;

Donut::Donut(GameObject* gameObject)
{
	this->gameObject = gameObject;
	renderer = Renderer::getInstance();
	physics = Physics::getInstance();
	sceneMan = SceneManager::getInstance();

	// create detection box
	detectionBox = new RectangleShape(detectionSize);
	detectionBox->setOrigin(Vector2f(detectionSize.x / 2, detectionSize.y / 2));
	detectionBox->setPosition(gameObject->transform->position);

	// add the detection box to gizmos
	detectionBox->setFillColor(Color::Transparent);
	detectionBox->setOutlineThickness(1);
	detectionBox->setOutlineColor(Color::Blue);
	renderer->addGizmo(detectionBox);
}

Donut::~Donut()
{
	renderer->removeGizmo(detectionBox);
	delete(detectionBox);
}

void Donut::update()
{
	// check to see if the player has reached the donut
	detectionBox->setSize(detectionSize);
	detectionBox->setOrigin(Vector2f(detectionSize.x / 2, detectionSize.y / 2));
	detectionBox->setPosition(gameObject->transform->position);

	ColliderComp* collision = physics->overlapBox(detectionBox, playerLayer);
	if (collision != NULL)
	{
		// player has reached the end
		cout << "player has won!" << endl;
		sceneMan->loadScene("victory scene");
	}
}

void Donut::lateUpdate()
{

}