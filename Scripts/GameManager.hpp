#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "../Engine/Component.hpp"
#include "../Engine/GameObject.hpp"
#include "../Engine/Engine.hpp"
#include "../Engine/Physics.hpp"
#include "../Engine/Layers.hpp"
#include "../STDComps/UIRenderer.hpp"
#include "../Engine/PrefabManager.hpp"
#include "SafeSpace.hpp"
#include "PlayerController.hpp"
#include <vector>
#include "../STDComps/UIText.hpp"

using namespace GameEngine;
using namespace std;

// Must be added to a gameObject after the player is made
class GameManager : public Component
{
	/* variables */
public:
	string playerTag = "Player";
	float timeBetweenStates = 30;
	vector<SafeSpace*>* safeSpaces; // hold all the safeSpaces on the map
	GameLayer playerLayer = GameLayer::PLAYER;

private:
	static GameManager* instance; // make this class a singleton
	GameObject* gameObject;
	Engine* engine;
	Physics* physics;
	PrefabManager* prefabMan;
	PlayerController* playerController;
	float elapsedTime;
	bool isSafe;
	UIRenderer* viewPanel;
	UIText* timeCounter;
	float counter;
	Vector2f counterPos = Vector2f(500, 0);

	/* methods */

	/// <summary>
	/// A private constructor for this singleton class
	/// </summary>
	GameManager();

public:
	/// <summary>
	/// Gets the instance of this singleton class
	/// </summary>
	/// <returns>The instance of this signleton class</returns>
	static GameManager* getInstance()
	{
		if (instance == NULL)
		{
			instance = new GameManager();
		}
		return instance;
	}

	/// <summary>
	/// Add a gameObject to this component.
	/// MUST HAPPEN AFTER THE PLAYER GAME OBJECT IS MADE
	/// </summary>
	/// <param name="gameObject">the gameObject that his component is attached to</param>
	void addGameObject(GameObject* gameObject);

	/// <summary>
	/// A destructor for a GameManager object
	/// </summary>
	~GameManager();

	/// <summary>
	/// called every frame by the GameObject that has this component
	/// </summary>
	void update();

	/// <summary>
	/// Called every frame after update. Used to handle physics and collisions
	/// </summary>
	void lateUpdate();

	/// <summary>
	/// Reset this component to the status it would be at when a scene is
	/// first loaded
	/// </summary>	
	void resetComponent();
};

#endif // !GAME_MANAGER_H