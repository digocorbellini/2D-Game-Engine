#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include "DrawableComp.hpp"
#include <vector>
#include <algorithm>

using namespace sf;

namespace GameEngine
{
	class Renderer
	{
		/* variables */
	private:
		static Renderer* instance;
		vector<DrawableComp*>* renderQueue; // hold objects to render. Must stay sorted


		/* functions */

		/// <summary>
		/// Constructor for a renderer instance.
		/// Private since this class is a singleton
		/// </summary>
		Renderer();

	public:
		/// <summary>
		/// Gets the instance of this singleton class
		/// </summary>
		/// <returns>The instance of this signleton class</returns>
		static Renderer* getInstance()
		{
			if (instance == NULL)
			{
				instance = new Renderer();
			}
			return instance;
		}

		/// <summary>
		/// Destructor for a Renderer instance
		/// </summary>
		~Renderer();

		/// <summary>
		/// Add the given drawable component to the render queue
		/// </summary>
		/// <param name="comp">drawale component to add to the render queue</param>
		void addToRenderQueue(DrawableComp* comp);

		/// <summary>
		/// Remove the given drawable component from the render queue
		/// </summary>
		/// <param name="comp">drawable component to be removed from render queue</param>
		/// <returns>return true if the given component was removed, 
		/// otherwise return false</returns>
		bool removeFromRenderQueue(DrawableComp* comp);

		/// <summary>
		/// Render all of the items in the render queue by calling all of the
		/// draw methods on the drawable components
		/// </summary>
		void render();
	};
}

#endif // !RENDERER_H

