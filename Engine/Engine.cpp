#include "Engine.hpp"

namespace GameEngine
{
	// make sure engine is initialized as NULL
	Engine* Engine::instance = NULL;

	Engine::Engine()
	{
		gameObjectList = new vector<GameObject*>();
		window = NULL;
		deltaTime = 0;
		renderer = Renderer::getInstance();
	}

	Engine::~Engine()
	{
		delete(gameObjectList);
		delete(window);
	}

	void Engine::setWindowDimensions(Vector2u dimensions, bool isFullScreen)
	{
		// make sure a window has been made first before setting the dimensions
		if (window == NULL)
		{
			if (isFullScreen)
			{
				window = new RenderWindow(VideoMode::getFullscreenModes()[0], "game",
					Style::Fullscreen);
			}
			else
			{
				window = new RenderWindow(VideoMode(dimensions.x, dimensions.y), "game",
					Style::Close);
			}
			
			
			renderer->setWindow(window);
		}
		else
		{
			window->setSize(dimensions);
		}
	}

	void Engine::gameLoop()
	{
		Clock clock;
		Time dTime;

		// start game loop
		while (window->isOpen())
		{
			if (window->pollEvent(event))
			{
				// check for the closing of the window
				if (event.type == Event::Closed || shouldQuit)
				{
					// close window
					window->close();
				}
			}

			// update delta time
			dTime = clock.restart();
			deltaTime = dTime.asSeconds();

			window->clear();

			// run all of the components on all of the game objects
			for (int i = 0; i < gameObjectList->size(); i++)
			{
				GameObject* currObj = (*gameObjectList)[i];
				currObj->runComponents();
			}

			// handle all of the drawing onto the screen
			renderer->render();

			window->display();

			// if list was asked to be cleared this frame, then clear it now
			if (shouldClearList)
			{
				shouldClearList = false;
				clearList();
			}

			if (shouldLoadScene)
			{
				shouldLoadScene = false;
				if (sceneToLoad != NULL)
					sceneToLoad->loadScene();
			}
		}
	}

	void Engine::startEngine()
	{
		// only start game if a window exits
		if (window == NULL)
		{
			return;
		}
		
		gameLoop();
		
	}

	void Engine::addGameObject(GameObject* gameObject)
	{
		gameObjectList->push_back(gameObject);
	}

	bool Engine::removeGameObject(GameObject* gameObject)
	{
		// find the game object
		int pos = 0;
		for (pos = 0; pos < gameObjectList->size(); pos++)
		{
			GameObject* currObj = (*gameObjectList)[pos];
			if (gameObject == currObj)
			{
				break;
			}
		}
		
		// if the game object was found then remove it
		if (pos < gameObjectList->size())
		{
			gameObjectList->erase(gameObjectList->begin() + pos);
			return true;
		}
		
		// game object not found
		return false;
	}

	Event Engine::getEvent()
	{
		return event;
	}

	RenderWindow* Engine::getWindow()
	{
		return window;
	}

	float Engine::getDeltaTime()
	{
		return deltaTime;
	}

	void Engine::clearGameObjectList()
	{
		shouldClearList = true;
	}

	void Engine::clearList()
	{
		for (int i = 0; i < gameObjectList->size(); i++)
		{
			GameObject* currObj = (*gameObjectList)[i];
			if (currObj != NULL)
			{
				// clear all of the components on the obj before deleting it
				currObj->clearComponents();
				delete(currObj);
			}
		}

		gameObjectList->clear();
	}

	GameObject* Engine::findGameObjectWithTag(string tag)
	{
		// go through all gameObjects in the game until an Object with the tag
		// is found
		for (int i = 0; i < gameObjectList->size(); i++)
		{
			GameObject* currObj = (*gameObjectList)[i];
			if (currObj->tag == tag)
			{
				// found a gameObject with the tag
				return currObj;
			}
		}

		// no gameObject found with the given tag
		return NULL;
	}

	void Engine::quit()
	{
		shouldQuit = true;
	}
}
