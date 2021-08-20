#ifndef PREFAB_MANAGER_H
#define PREFAB_MANAGER_H

#include <SFML/Graphics.hpp>

#include "../Engine/Layers.hpp"

#include "../STDComps/SpriteRenderer.hpp"
#include "../STDComps/BoxCollider.hpp"
#include "../STDComps/Camera.hpp"
#include "../STDComps/Rigidbody.hpp"
#include "../STDComps/CircleCollider.hpp"
#include "../STDComps/UIRenderer.hpp"

#include "../Scripts/CameraController.hpp"
#include "../Scripts/PlayerController.hpp"
#include "../Scripts/UIManager.hpp"
#include "../Scripts/TestComp.hpp"
#include "../Scripts/Ant.hpp"
#include "../Scripts/SafeSpace.hpp"

using namespace std;
using namespace sf;

namespace GameEngine
{
	class PrefabManager
	{
	private:
		static PrefabManager* instance; // make this class a singleton
		Engine* engine;
	
		/// <summary>
		/// Private constructor for this singleton class
		/// </summary>
		PrefabManager();
	public:
		/// <summary>
		/// Gets the instance of this singleton class
		/// </summary>
		/// <returns>The instance of this signleton class</returns>
		static PrefabManager* getInstance()
		{
			if (instance == NULL)
			{
				instance = new PrefabManager();
			}
			return instance;
		}

		/// <summary>
		/// Destructor for a prefab manager instance
		/// </summary>
		~PrefabManager();

		/// <summary>
		/// Instatiate a player game Object
		/// </summary>
		/// <returns>The player game Object</returns>
		GameObject* playerPrefab();

		/// <summary>
		/// Instantiate an ant game Object
		/// </summary>
		/// <returns>The ant game object</returns>
		GameObject* antPrefab();

		/// <summary>
		/// Instantiate a camera game object
		/// </summary>
		/// <param name="target">the target that the camera will follow</param>
		/// <param name="screenWidth">the width of the camera view</param>
		/// <param name="screenHeight">the height of the camera view</param>
		/// <returns>a camera game object</returns>
		GameObject* cameraPrefab(GameObject* target, float screenWidth, float screenHeight);

		/// <summary>
		/// Instantiate a UI heart game object
		/// </summary>
		/// <returns>the UI heart game object</returns>
		GameObject* UIHeartPrefab();

		/// <summary>
		/// Instantiate a camera game object
		/// </summary>
		/// <returns>the view panel game object</returns>
		GameObject* viewPanelPrefab();

		/// <summary>
		/// Instantiate a safe space game object
		/// </summary>
		/// <param name="spriteLocation">the location of the sprite for this
		/// safe space object</param>
		/// <param name="posOfBottomLeft">the position of the bottom left corner
		/// of the safe space game object</param>
		/// <returns>a reference to the safe space component</returns>
		SafeSpace* safeSpacePrefab(string spriteLocation, Vector2f posOfBottomLeft);

		/// <summary>
		/// Instantiate a obstacle game object
		/// </summary>
		/// <param name="spriteLocation">the location of the sprite for this
		/// obstacle game object</param>
		/// <param name="posOfBottomLeft">the position of the bottom left corner
		/// of the safe space game object</param>
		/// <returns>the obstacle game object</returns>
		GameObject* obstaclePrefab(string spriteLocation, Vector2f posOfBottomLeft);
	};

}

#endif // !PREFAB_MANAGER_H