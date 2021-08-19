#include "PlayerController.hpp"

#include <iostream>
using namespace std;

PlayerController::PlayerController(GameObject* gameObject, Vector2f groundCheckSize, Vector2f attackSize)
{
	groundCheckOffset = Vector2f(0, 0);
	attackRightOffset = Vector2f(0, 0);
	this->gameObject = gameObject;
	// rigidbody component is essential to this component working
	rb = gameObject->getComponent<Rigidbody>();
	if (rb == NULL)
	{
		//throw "rigidbody component not found in PlayerController";
	}
	// create the ground checker
	groundChecker = new RectangleShape(groundCheckSize);
	groundChecker->setOrigin(Vector2f(groundCheckSize.x / 2, groundCheckSize.y / 2));
	groundChecker->setPosition(gameObject->transform->position + groundCheckOffset);
	haveDoubleJump = true;
	isGrounded = false;

	// add groundChecker to gizmos
	Renderer* rend = Renderer::getInstance();
	groundChecker->setFillColor(Color::Transparent);
	groundChecker->setOutlineThickness(1);
	groundChecker->setOutlineColor(Color::Red);
	rend->addGizmo(groundChecker);

	// get reference to the physics engine
	physics = Physics::getInstance();

	// get reference to engine
	engine = Engine::getInstance();

	// create attack box
	attackBox = new RectangleShape(attackSize);
	attackBox->setOrigin(Vector2f(attackSize.x / 2, attackSize.y / 2));
	attackBox->setPosition(gameObject->transform->position + attackRightOffset);

	// add attack box to gizmos
	attackBox->setFillColor(Color::Transparent);
	attackBox->setOutlineThickness(1);
	attackBox->setOutlineColor(Color::Red);
	rend->addGizmo(attackBox);

	facingRight = true;
}

//PlayerController::PlayerController(GameObject* gameObject, Vector2f groundCheckSize, Vector2f groundCheckOffset)
//{
//	this->gameObject = gameObject;
//	// rigidbody component is essential to this component working
//	rb = gameObject->getComponent<Rigidbody>();
//	if (rb == NULL)
//	{
//		//throw "rigidbody component not found in PlayerController";
//	}
//	// create the ground checker
//	groundChecker = new RectangleShape(groundCheckSize);
//	groundChecker->setOrigin(Vector2f(groundCheckSize.x / 2, groundCheckSize.y / 2));
//	groundChecker->setPosition(gameObject->transform->position + groundCheckOffset);
//	this->groundCheckOffset = Vector2f(groundCheckOffset);
//	haveDoubleJump = true;
//
//	// add groundChecker to gizmos
//	groundChecker->setFillColor(Color::Transparent);
//	groundChecker->setOutlineThickness(1);
//	groundChecker->setOutlineColor(Color::Red);
//	Renderer::getInstance()->addGizmo(groundChecker);
//
//	// get reference to the physics engine
//	physics = Physics::getInstance();
//
//	// get reference to engine
//	engine = Engine::getInstance();
//}

PlayerController::~PlayerController()
{
	Renderer::getInstance()->removeGizmo(groundChecker);
	delete(groundChecker);
}

void PlayerController::update()
{
	Event event = engine->getEvent();

	// player movement
	Vector2f newPlayerScale = gameObject->transform->scale;
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		// go left
		rb->velocity.x = -moveSpeed;
		// flip sprite
		newPlayerScale.x = -abs(newPlayerScale.x);
		facingRight = false;
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		// go right
		rb->velocity.x = moveSpeed;
		// flip sprite
		newPlayerScale.x = abs(newPlayerScale.x);
		facingRight = true;
	}
	else
	{
		// idle in the horizontal direction
		rb->velocity.x = 0;
	}
	gameObject->transform->scale = newPlayerScale;

	// check to see if the player is grounded
	groundChecker->setPosition(gameObject->transform->position + groundCheckOffset);
	ColliderComp* col = physics->overlapBox(groundChecker, groundLayer);
	if (col != NULL)
	{
		isGrounded = true;
		haveDoubleJump = true;
	}
	else
	{
		isGrounded = false;
	}

	// handle jump and double jump
	if (event.type == Event::KeyPressed && event.key.code == Keyboard::W)
	{
		if (isGrounded)
		{
			// jump
			rb->velocity.y = -jumpSpeed;
		}
		else if (haveDoubleJump)
		{
			// double jump
			rb->velocity.y = -jumpSpeed;
			haveDoubleJump = false;
		}
	}

	// handle attack
	if (facingRight)
	{
		// make the attack box face right
		attackBox->setPosition(gameObject->transform->position + attackRightOffset);
	}
	else
	{
		// make the attack box face left
		attackBox->setPosition(gameObject->transform->position - attackRightOffset);
	}

	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space)
	{
		// attack
		vector<ColliderComp*>* collisions = physics->overlapBoxAll(attackBox, enemyLayer);
		for (int i = 0; i < collisions->size(); i++)
		{
			// damage each individual enemy
			cout << "attacked enemy #" << i + 1 << endl;
		}
	}



}

void PlayerController::lateUpdate()
{

}