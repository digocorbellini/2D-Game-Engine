#ifndef PHYSICS_H
#define PHYSICS_H

#include <vector>
#include "ColliderComp.hpp"

using namespace std;

namespace GameEngine
{
	/// <summary>
	/// singleton class that handles physics actions such as collisions
	/// </summary>
	class Physics
	{
		/* Variables */
	private:
		static Physics* instance;
		vector<ColliderComp*>* colliders;

		/* functions */

		/// <summary>
		/// Private constructor for a Physics object. This class is a singleton
		/// </summary>
		Physics();
	public:
		/// <summary>
		/// Get an instance of this singleton class
		/// </summary>
		/// <returns>an instance of this singleton class</returns>
		static Physics* getInstance()
		{
			if (instance == NULL)
			{
				instance = new Physics();
			}
			return instance;
		}

		/// <summary>
		/// A destructor for a physics object
		/// </summary>
		~Physics();

		/// <summary>
		/// Add the given collider to the list of colliders in the game
		/// </summary>
		/// <param name="collider">the collider to be added to the list of colliders
		/// in the game</param>
		void addCollider(ColliderComp* collider);

		/// <summary>
		/// Remove the given collider from the list of colliders in the game
		/// </summary>
		/// <param name="collider">the collider to be removed from the list
		/// of colliders in the game</param>
		/// <returns>true if the collider is found and removed, and false otherwise</returns>
		bool removeCollider(ColliderComp* collider);

		/// <summary>
		/// See if the given collider is colliding with any other collider,
		/// and if it is then return the first collider that it is colliding with
		/// </summary>
		/// <param name="collider">the collider to be checked for collisions</param>
		/// <returns>The first collider component that is colliding with
		/// with the given collider component, and null otherwise</returns>
		ColliderComp* isColliding(ColliderComp* collider);
	};
}


#endif