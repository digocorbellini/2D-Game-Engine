#include "GameManager.hpp"
#include <iostream>

GameManager* GameManager::instance = NULL;

GameManager::GameManager()
{
	safeSpaces = new vector<SafeSpace*>();
	gameObject = NULL;
	destroyOnLoad = false;
	engine = Engine::getInstance();
	physics = Physics::getInstance();
	playerController = NULL;
	isSafe = true;
	elapsedTime = 0;
	viewPanel = NULL;

	GameObject* viewPanelObj = PrefabManager::getInstance()->viewPanelPrefab();
	viewPanel = viewPanelObj->getComponent<UIRenderer>();
}

void GameManager::addGameObject(GameObject* gameObject)
{
	this->gameObject = gameObject;
	// find the player game object
	// used in the logic for this component in update so need to set it
	// before update is run on the gameObject that this component is added to
	GameObject* playerObj = engine->findGameObjectWithTag(playerTag);
	if (playerObj != NULL)
	{
		playerController = playerObj->getComponent<PlayerController>();
	}
	
	GameObject* viewPanelObj = PrefabManager::getInstance()->viewPanelPrefab();
	viewPanel = viewPanelObj->getComponent<UIRenderer>();
}

GameManager::~GameManager()
{
	delete(safeSpaces);
}

void GameManager::update()
{
	if (playerController == NULL)
	{
		cout << "Player controller is null in game manager" << endl;
		return;
	}

	if (viewPanel == NULL)
	{
		cout << "view panel is null in game manager" << endl;
		return;
	}

	// switch between safe and unsafe states
	elapsedTime += engine->getDeltaTime();
	// check to see if the current state has elapsed
	if (elapsedTime > timeBetweenStates)
	{
		// reset elapsed time for the next state
		elapsedTime = 0;
		// flip states
		isSafe = !isSafe;

		cout << "is safe: " << isSafe << endl;
	}

	if (!isSafe)
	{
		// make the view panel not transparent (aka light on)
		viewPanel->color.a = 100;

		// handle all uncovered parts being dangerous
		bool playerIsSafe = false;
		// go through all safe spaces to see if player is within a safe space
		for (int i = 0; i < safeSpaces->size(); i++)
		{
			SafeSpace* currSafeSpace = (*safeSpaces)[i];
			ColliderComp* collision = physics->overlapBox(currSafeSpace->getShape(), 
					playerLayer);
			if (collision != NULL)
			{
				// player is in a safe area
				playerIsSafe = true;
				break;
			}
		}

		// kill player if they are not in a safe space
		if (!playerIsSafe)
		{
			//playerController->damagePlayer(playerController->getHealth());
			
			// TEMPORARY FOR TESTING SO THAT NOT KILLED INSTANTLY
			playerController->damagePlayer(1); 
		}
	}
	else
	{
		// make the view panel transparent (aka light off)
		viewPanel->color.a = 0;
	}

}

void GameManager::lateUpdate()
{

}

void GameManager::resetComponent()
{
	gameObject = NULL;
	safeSpaces->clear();
	playerController = NULL;
	isSafe = true;
	elapsedTime = 0;
	viewPanel = NULL;
}