#ifndef SCENE_H
#define SCENE_H

#include <string>

using namespace std;

namespace GameEngine
{
	class Scene
	{
		/* variables */
	public:
		string sceneName;

		/* methods */
		/// <summary>
		/// Load this scene. This will load all of the gameObjects and
		/// their components into the game
		/// </summary>		
		virtual void loadScene() = 0;

		/// <summary>
		/// Virtual destructor
		/// </summary>
		virtual ~Scene()
		{

		}
	};
}

#endif // !SCENE_H

