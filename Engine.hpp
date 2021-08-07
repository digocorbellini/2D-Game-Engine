#ifndef ENGINE_H
#define ENGINE_H

#include "GameObject.hpp"
#include <vector>

namespace GameEngine
{
	/// <summary>
	/// Singleton class that starts the game loop and handles the running of all of the game code
	/// </summary>
	class Engine
	{
		// variables
	private:
		static Engine* instance; // for singleton
		vector<GameObject*>* gameObjectList; // holds all of the GameObjects in this game
		Event event;
		RenderWindow* window;

		/// <summary>
		/// Constructor for a game engine instance.
		/// Private since this class is a singleton
		/// </summary>
		Engine();
		
		// functions
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
	};
}

#endif
