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
				if (event.type == Event::Closed)
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

}
