#include "VictorySceneMan.hpp"

VictorySceneMan::VictorySceneMan(GameObject* gameObject)
{
	this->gameObject = gameObject;
	engine = Engine::getInstance();
	sceneMan = SceneManager::getInstance();
}



void VictorySceneMan::update()
{
	Event event = engine->getEvent();

	if (event.type == Event::KeyPressed)
	{
		if (event.key.code == Keyboard::Escape)
		{
			// quit game
			engine->quit();
		}
		else
		{
			// reload game
			sceneMan->loadScene("main scene");
		}
	}
}

void VictorySceneMan::lateUpdate()
{

}

