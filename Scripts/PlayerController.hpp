#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "../Engine/Component.hpp"
#include "../Engine/GameObject.hpp"
#include "../STDComps/Rigidbody.hpp"
#include "../Engine/Renderer.hpp"
#include "../Engine/Physics.hpp"
#include "../Engine/SceneManager.hpp"
#include "UIManager.hpp"
#include "Health.hpp"
#include "Enemy.hpp"
#include "../STDComps/SpriteRenderer.hpp"

using namespace GameEngine;

class PlayerController : public Component
{
	/* Variables */
public:
	float moveSpeed = 300;
	float jumpSpeed = 500;
	int damage = 1;
	float invincibilityTime = 1;
	Vector2f groundCheckOffset;
	// offset of the attack for the player when it is playing right
	Vector2f attackRightOffset; 
	GameLayer groundLayer = GameLayer::GROUND;
	GameLayer enemyLayer = GameLayer::ENEMIES;

private:
	Health* health; // damage player through here
	GameObject* gameObject;
	Rigidbody* rb;
	SpriteRenderer* spriteRenderer;
	RectangleShape* groundChecker; // use to check to see if the player is grounded
	RectangleShape* attackBox;
	bool isGrounded;
	bool haveDoubleJump;
	Physics* physics;
	Engine* engine;
	SceneManager* sceneMan;
	UIManager* UIMan;
	bool facingRight;
	float timeElapsed = 0;
	bool isInvincible = false;

	/* Methods */
public:
	/// <summary>
	/// A constructor for a new player controller component 
	/// </summary>
	/// <param name="gameObject">the gameObject that this component
	/// is attached to</param>
	/// <param name="groundCheckSize">the size of the ground checker</param>
	PlayerController(GameObject* gameObject, Vector2f groundCheckSize, Vector2f attackSize);

	/// <summary>
	/// A constructor for a new player controller component 
	/// </summary>
	/// <param name="gameObject">the gameObject that this component
	/// is attached to</param>
	/// <param name="groundCheckSize">the size of the ground checker</param>
	/// <param name="groundCheckOffset">the offset of the ground checker
	/// position relative to the position of the gameObject that this
	/// component is attached to</param>
	//PlayerController(GameObject* gameObject, Vector2f groundCheckSize, Vector2f groundCheckOffset);

	/// <summary>
	/// A destructor for a player controller component 
	/// </summary>
	~PlayerController();

	/// <summary>
	/// called every frame by the GameObject that has this component
	/// </summary>
	void update();

	/// <summary>
	/// Called every frame after update. Used to handle physics and collisions
	/// </summary>
	void lateUpdate();

	/// <summary>
	/// Get the player's current health
	/// </summary>
	/// <returns>the player's current health</returns>
	int getHealth();

	/// <summary>
	/// Damage the player the given amount of damage
	/// </summary>
	/// <param name="damage">the amount of damage to deal to the player</param>
	void damagePlayer(int damage);
};

#endif