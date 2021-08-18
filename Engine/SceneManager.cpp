#include "SceneManager.hpp"

namespace GameEngine
{
	SceneManager* SceneManager::instance = NULL;

	SceneManager::SceneManager()
	{
		scenes = new unordered_map<string, Scene*>();
		activeScene = NULL;
		engine = engine->getInstance();
	}

	SceneManager::~SceneManager()
	{
		delete(scenes);
	}

	void SceneManager::addScene(Scene* scene)
	{
		scenes->insert({scene->sceneName, scene});
	}

	void SceneManager::removeScene(string sceneName)
	{
		scenes->erase(sceneName);
	}

	void SceneManager::loadScene(string sceneName)
	{
		// unload previous scene
		engine->clearGameObjectList();

		// load new scene and set it as active scene
		Scene* scene = (*scenes)[sceneName];
		activeScene = scene;

		if (scene != NULL)
		{
			engine->shouldLoadScene = true;
			engine->sceneToLoad = scene;
		}
	}

	Scene* SceneManager::getActiveScene()
	{
		return activeScene;
	}
}
