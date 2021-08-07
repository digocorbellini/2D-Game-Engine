#include "Engine.hpp"

namespace GameEngine
{
	Engine::Engine()
	{
		gameObjectList = new vector<GameObject*>();
		window = NULL;
	}

	Engine::~Engine()
	{
		delete(gameObjectList);
		delete(window);
	}

	void Engine::setWindowDimensions(Vector2u dimensions)
	{
		// make sure a window has been made first before setting the dimensions
		if (window == NULL)
		{
			window = new RenderWindow(VideoMode(dimensions.x, dimensions.y), "game", Style::Close);
		}
		else
		{
			window->setSize(dimensions);
		}
	}

	void Engine::startEngine()
	{
		// only start game if a window exits
		if (window = NULL)
		{
			return;
		}

		while (window->pollEvent(event))
		{
			// check for the closing of the window
			if (event.type == Event::Closed)
			{
				// close window
				window->close();
			}
		}

		window->clear();

		// run all of the components on all of the game objects
		for (int i = 0; i < gameObjectList->size(); i++)
		{
			GameObject* currObj = (*gameObjectList)[i];
			currObj->runComponents();
		}


		window->display();
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

}
