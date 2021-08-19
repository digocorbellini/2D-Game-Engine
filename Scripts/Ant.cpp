#include "Ant.hpp"

#include <iostream>

Ant::Ant(GameObject* gameObject)
{
	this->gameObject = gameObject;
	health = new Health(2);
	physics = Physics::getInstance();
	rb = gameObject->getComponent<Rigidbody>();
	if (rb == NULL)
	{
		throw "Rigidbody not found in Ant component";
	}
	damage = 1;

	// create detection box
	detectionBox = new RectangleShape(detectionSize);
	// center origin of detection box
	detectionBox->setOrigin(Vector2f(detectionSize.x / 2, detectionSize.y / 2));
	detectionBox->setPosition(gameObject->transform->position);

	// add detection box to gizmos
	renderer = Renderer::getInstance();
	detectionBox->setFillColor(Color::Transparent);
	detectionBox->setOutlineThickness(1);
	detectionBox->setOutlineColor(Color::Red);
	renderer->addGizmo(detectionBox);


	// create hitBox
	hitBox = new RectangleShape(hitBoxSize);
	// center hitbox
	hitBox->setOrigin(Vector2f(hitBoxSize.x / 2, hitBoxSize.y / 2));
	hitBox->setPosition(gameObject->transform->position);

	// add hitBox to Gizmos
	hitBox->setFillColor(Color::Transparent);
	hitBox->setOutlineThickness(1);
	hitBox->setOutlineColor(Color::Blue);
	renderer->addGizmo(hitBox);

	// set the layer of the gameObject to the enemy layer
	gameObject->gameLayer = enemyLayer;
}

Ant::~Ant()
{
	delete(health);
	renderer->removeGizmo(detectionBox);
	delete(detectionBox);
	renderer->removeGizmo(hitBox);
	delete(hitBox);

}

void Ant::damageEnemy(int damage)
{
	health->addHealth(-damage);
	cout << damage << " delt to ant" << endl;
}

void Ant::update()
{
	// handle movement towards player
	// check to see if the player is within range
	detectionBox->setSize(detectionSize);
	detectionBox->setOrigin(Vector2f(detectionSize.x / 2, detectionSize.y / 2));
	detectionBox->setPosition(gameObject->transform->position);
	ColliderComp* collision = physics->overlapBox(detectionBox, playerLayer);
	if (collision != NULL)
	{
		// player is within range
		// find direction towards player
		GameObject* player = collision->getGameObject();
		float direction = player->transform->position.x - gameObject->transform->position.x;
		direction /= abs(direction); // normalize direction
		// move in that direction
		rb->velocity.x = direction * speed;
		// flip sprite in according direction;
		gameObject->transform->scale.x = direction * abs(gameObject->transform->scale.x);
	}
	else
	{
		// player is not within range so don't move
		rb->velocity.x = 0;
	}

	// handle hurting the player
	hitBox->setSize(hitBoxSize);
	hitBox->setOrigin(Vector2f(hitBoxSize.x / 2, hitBoxSize.y / 2));
	hitBox->setPosition(gameObject->transform->position);
	collision = physics->overlapBox(hitBox, playerLayer);
	if (collision != NULL)
	{
		// player is within hitBox
		// damage player
		GameObject* playerObj = collision->getGameObject();
		PlayerController* playerCtrl = playerObj->getComponent<PlayerController>();
		if (playerCtrl != NULL)
		{
			playerCtrl->damagePlayer(damage);
		}
	}
}

void Ant::lateUpdate()
{

}

