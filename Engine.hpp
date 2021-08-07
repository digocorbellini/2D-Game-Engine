#ifndef ENGINE_H
#define ENGINE_H

#include "GameObject.hpp"
#include <vector>

namespace GameEngine
{
	// maybe make this a singleton so that game objects can be instantiated mid game?
	class Engine
	{
	private:
		vector<GameObject*>* gameObjectList;

	public:
		/// <summary>
		/// Constructor for a game engine instance
		/// </summary>
		Engine()
		{
			gameObjectList = new vector<GameObject*>();
		}

		/// <summary>
		/// Destructor for a game engine instance
		/// </summary>
		~Engine()
		{
			delete(gameObjectList);
		}

		/// <summary>
		/// Start the game loop in this engineS
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
	};
}

#endif
