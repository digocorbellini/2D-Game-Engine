#ifndef ENGINE_H
#define ENGINE_H

#include "GameObject.hpp"
#include "Renderer.hpp"
#include <vector>

#include "Scene.hpp"

namespace GameEngine
{
	/// <summary>
	/// Singleton class that starts the game loop and handles the running of all of the game code
	/// </summary>
	class Engine
	{
		/* variables */ 
	public:
		// temporary solution to reloading scenes
		bool shouldLoadScene = false;
		Scene* sceneToLoad = NULL;

	private:
		static Engine* instance; // for singleton
		vector<GameObject*>* gameObjectList; // holds all of the GameObjects in this game
		Event event;
		RenderWindow* window;
		float deltaTime;
		Renderer* renderer;
		bool shouldClearList = false;		

		/* functions */

		/// <summary>
		/// Constructor for a game engine instance.
		/// Private since this class is a singleton
		/// </summary>
		Engine();

		/// <summary>
		/// Run the game loop
		/// </summary>
		void gameLoop();
		
	public:
		/// <summary>
		/// Gets the instance of this singleton class
		/// </summary>
		/// <returns>The instance of this signleton class</returns>
		static Engine* getInstance()
		{
			if (instance == NULL)
			{
				instance = new Engine();
			}
			return instance;
		}

		/// <summary>
		/// Destructor for a game engine instance
		/// </summary>
		~Engine();	

		/// <summary>
		/// Set the dimensions of the window
		/// </summary>
		/// <param name="dimensions">the dimensions of the window
		/// with x being the width and y being the height</param>
		void setWindowDimensions(Vector2u dimensions);

		/// <summary>
		/// Start the game loop in this engine. Window dimensions MUST 
		/// be set first
		/// </summary>
		void startEngine();

		/// <summary>
		/// Add the given game object to this game (equivalent of instantiate in unity)
		/// </summary>
		/// <param name="gameObject">the game object to be added to this game</param>
		void addGameObject(GameObject* gameObject);

		/// <summary>
		/// Remove the given game object from this game (Equivalent of Destroy in unity)
		/// </summary>
		/// <param name="gameObject">the gameobject to be removed</param>
		/// <returns>true if the gameobject is sucessfully removed, and false otherwise</returns>
		bool removeGameObject(GameObject* gameObject);

		/// <summary>
		/// Get the event that occured this frame
		/// </summary>
		/// <returns>the event that occured this frame</returns>
		Event getEvent();

		/// <summary>
		/// Get a reference to the window
		/// </summary>
		/// <returns>a reference to the window</returns>
		RenderWindow* getWindow();

		/// <summary>
		/// Get the time between frames
		/// </summary>
		/// <returns>the time between frames in seconds</returns>
		float getDeltaTime();

		/// <summary>
		/// Clear the list of gameObjects in this engine (frees memory)
		/// </summary>
		void clearGameObjectList();

		/// <summary>
		/// Get a reference to the first game object found with the given tag.
		/// THIS IS A VERY EXPENSIVE OPERATION
		/// </summary>
		/// <param name="tag">the tag of the object to be searched</param>
		/// <returns>a reference to the first game object found with the 
		/// given tag or NULL if no game object with the given tag is found</returns>
		GameObject* findGameObjectWithTag(string tag);

	private:
		void clearList();
	};
}

#endif
