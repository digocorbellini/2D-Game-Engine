#include "PlayerController.hpp"

PlayerController::PlayerController(GameObject* gameObject, Vector2f groundCheckSize)
{
	groundCheckOffset = Vector2f(0, 0);
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

	// add groundChecker to gizmos
	groundChecker->setFillColor(Color::Transparent);
	groundChecker->setOutlineThickness(1);
	groundChecker->setOutlineColor(Color::Red);
	Renderer::getInstance()->addGizmo(groundChecker);
}

PlayerController::PlayerController(GameObject* gameObject, Vector2f groundCheckSize, Vector2f groundCheckOffset)
{
	groundCheckOffset = Vector2f(0, 0);
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
	this->groundCheckOffset = groundCheckOffset;
	haveDoubleJump = true;

	// add groundChecker to gizmos
	groundChecker->setFillColor(Color::Transparent);
	groundChecker->setOutlineThickness(1);
	groundChecker->setOutlineColor(Color::Red);
	Renderer::getInstance()->addGizmo(groundChecker);
}

PlayerController::~PlayerController()
{
	Renderer::getInstance()->removeGizmo(groundChecker);
	delete(groundChecker);
}

void PlayerController::update()
{
	// handle player movement and attacks
	
	// player movement
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		// go left
		rb->velocity.x = -moveSpeed;
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		// go right
		rb->velocity.x = moveSpeed;
	}
	else
	{
		// idle in the horizontal direction
		rb->velocity.x = 0;
	}

	// check to see if the player is grounded
	groundChecker->setPosition(gameObject->transform->position + groundCheckOffset);

}

void PlayerController::lateUpdate()
{

}