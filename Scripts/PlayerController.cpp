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
		throw "rigidbody component not found in PlayerController";
	}
	spriteRenderer = gameObject->getComponent<SpriteRenderer>();
	if (spriteRenderer == NULL)
	{
		throw "sprite renderer component not found in PlayerController";
	}
	// create the ground checker
	groundChecker = new RectangleShape(groundCheckSize);
	groundChecker->setOrigin(Vector2f(groundCheckSize.x / 2, groundCheckSize.y / 2));
	groundChecker->setPosition(gameObject->transform->position + groundCheckOffset);
	haveDoubleJump = true;
	isGrounded = false;

	// add groundChecker to gizmos
	Renderer* renderer = Renderer::getInstance();
	groundChecker->setFillColor(Color::Transparent);
	groundChecker->setOutlineThickness(1);
	groundChecker->setOutlineColor(Color::Red);
	renderer->addGizmo(groundChecker);

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
	renderer->addGizmo(attackBox);

	facingRight = true;

	health = new Health(3);

	UIMan = UIManager::getInstance();

	sceneMan = SceneManager::getInstance();

	// make attack animation

	// THIS CAUSES MEMORY LEAKS. MAKE SURE TO CLEAN THIS UP LATER
	Texture* sp1T = new Texture();
	sp1T->loadFromFile("./Sprites/attack_anim/attack_anim1.png");
	Sprite* sp1 = new Sprite();
	sp1->setTexture(*sp1T);
	sp1->setOrigin(Vector2f(sp1T->getSize().x / 2, sp1T->getSize().y / 2));

	Texture* sp2T = new Texture();
	sp2T->loadFromFile("./Sprites/attack_anim/attack_anim2.png");
	Sprite* sp2 = new Sprite();
	sp2->setTexture(*sp2T);
	sp2->setOrigin(Vector2f(sp2T->getSize().x / 2, sp2T->getSize().y / 2));

	Texture* sp3T = new Texture();
	sp3T->loadFromFile("./Sprites/attack_anim/attack_anim3.png");
	Sprite* sp3 = new Sprite();
	sp3->setTexture(*sp3T);
	sp3->setOrigin(Vector2f(sp3T->getSize().x / 2, sp3T->getSize().y / 2));

	Texture* sp4T = new Texture();
	sp4T->loadFromFile("./Sprites/attack_anim/attack_anim4.png");
	Sprite* sp4 = new Sprite();
	sp4->setTexture(*sp4T);
	sp4->setOrigin(Vector2f(sp4T->getSize().x / 2, sp4T->getSize().y / 2));

	vector<Sprite*>* anim = new vector<Sprite*>();
	anim->push_back(sp1);
	anim->push_back(sp2);
	anim->push_back(sp3);
	anim->push_back(sp4);

	animObj = new GameObject();
	engine->addGameObject(animObj);
	attackAnim = new Animation(animObj, anim);
	animObj->addComponent(attackAnim);
}

PlayerController::~PlayerController()
{
	Renderer* renderer = Renderer::getInstance();
	renderer->removeGizmo(groundChecker);
	renderer->removeGizmo(attackBox);
	delete(groundChecker);
	delete(health);
}

void PlayerController::update()
{
	// check for player death
	if (health->getHealth() == 0)
	{
		// player has died
		// reload scene
		//cout << "Player has died" << endl;
		//UIMan->clearList();
		sceneMan->loadScene(sceneMan->getActiveScene()->sceneName);
	}

	// update player health UI
	UIMan->updateHeartUI(health->getHealth());

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

		// set anim position
		animObj->transform->position = gameObject->transform->position + attackRightOffset;
		animObj->transform->scale.x = abs(animObj->transform->scale.x);
	}
	else
	{
		// make the attack box face left
		attackBox->setPosition(gameObject->transform->position - attackRightOffset);

		// set anim position
		animObj->transform->position = gameObject->transform->position - attackRightOffset;
		animObj->transform->scale.x = -abs(animObj->transform->scale.x);
	}

	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space)
	{
		// attack
		vector<ColliderComp*>* collisions = physics->overlapBoxAll(attackBox, enemyLayer);
		for (int i = 0; i < collisions->size(); i++)
		{
			// damage each individual enemy
			cout << "attacked enemy #" << i + 1 << endl;
			GameObject* currEnemyObj = (*collisions)[i]->getGameObject();
			Enemy* currEnemy = currEnemyObj->getComponent<Enemy>();
			if (currEnemy != NULL)
			{
				currEnemy->damageEnemy(damage);
			}
		}
		delete(collisions);

		// play attack anim
		attackAnim->playAnimation();
	}

	// handle invincibility from taking damage
	Color newColor = spriteRenderer->color;
	if (isInvincible)
	{
		timeElapsed += engine->getDeltaTime();
		// make player semi transparent
		newColor.a = 100;
		spriteRenderer->color = newColor;

		// check to see if invinsibility time has elapsed
		if (timeElapsed > invincibilityTime)
		{
			isInvincible = false;
			timeElapsed = 0;
		}
	}
	else
	{
		// make player not transparent
		newColor.a = 255;
		spriteRenderer->color = newColor;
	}

}

void PlayerController::lateUpdate()
{

}

int PlayerController::getHealth()
{
	return health->getHealth();
}

void PlayerController::damagePlayer(int damage)
{
	if (!isInvincible)
	{
		health->addHealth(-damage);
		// start invincibility countdown
		isInvincible = true;
	}
}