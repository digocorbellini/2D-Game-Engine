#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "Scene.hpp"
#include "Engine.hpp"
#include <unordered_map>

using namespace std;

namespace GameEngine
{
	class SceneManager
	{
		/* variables */
	private:
		static SceneManager* instance;
		// an unordered map to hold all of the scenes in this game
		unordered_map<string, Scene*>* scenes;
		Scene* activeScene;
		Engine* engine;

		/* methods */
		
		/// <summary>
		/// A constructor for a new scene manager object
		/// </summary>
		SceneManager();
	public:
		/// <summary>
		/// Gets the instance of this singleton class
		/// </summary>
		/// <returns>The instance of this signleton class</returns>
		static SceneManager* getInstance()
		{
			if (instance == NULL)
			{
				instance = new SceneManager();
			}
			return instance;
		}

		/// <summary>
		/// A destructor for a scene manager object
		/// </summary>		
		~SceneManager();

		/// <summary>
		/// Add the given scene to this game. This scene will be able to be
		/// loaded and unloaded by this scene manager in the game
		/// </summary>
		/// <param name="scene">The scene to be added</param>
		void addScene(Scene* scene);

		/// <summary>
		/// Remove the scene with the given name from this scene manager
		/// </summary>
		/// <param name="sceneName">The name of the scene to be removed</param>
		void removeScene(string sceneName);

		/// <summary>
		/// Load the given scene. This will unload the currently active scene
		/// </summary>
		/// <param name="sceneName">The name of the scene to be loaded</param>
		void loadScene(string sceneName);

		/// <summary>
		/// Get the currently active scene
		/// </summary>
		/// <returns>The currently active scene if it exists, and null
		/// otherwise</returns>
		Scene* getActiveScene();
	};
}

#endif // !SCENE_MANAGER_H

