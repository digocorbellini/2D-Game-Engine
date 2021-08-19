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
	public:
		bool gizmosOn = true;

	private:
		static Renderer* instance;
		vector<DrawableComp*>* renderQueue; // hold objects to render. Must stay sorted
		vector<Shape*>* gizmos;
		RenderWindow* window;

		/* functions */

		/// <summary>
		/// Constructor for a renderer instance.
		/// Private since this class is a singleton
		/// </summary>
		Renderer();

		/// <summary>
		/// Draw all gizmos
		/// </summary>
		void drawGizmos();
	
		/// <summary>
		/// custom less than operator for sorting the renderQueue by sorting
		/// layer and order in sorting layer
		/// </summary>
		struct
		{
			bool operator()(DrawableComp* d1, DrawableComp* d2) const
			{ 
				if (d1->layer == d2->layer)
				{
					return (d1->orderInLayer < d2->orderInLayer);
				}

				return ((int)d1->layer < (int)d2->layer);
			}
		}customLess;

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
		/// Set the window to render stuff to
		/// </summary>
		/// <param name="window">the window to render to</param>
		void setWindow(RenderWindow* window);

		/// <summary>
		/// Get the render window
		/// </summary>
		/// <returns>the render window</returns>
		RenderWindow* getWindow();

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

		/// <summary>
		/// Add a gizmo to the list of gizmos to be drawm
		/// </summary>
		/// <param name="gizmoShape">the shape to be drawn</param>
		void addGizmo(Shape* gizmoShape);

		/// <summary>
		/// Remove a gizmo from the list of gizmos to be drawn
		/// </summary>
		/// <param name="gizmoShape">the shape to be removed</param>
		/// <returns>true if the shape is removed and false otherwise</returns>
		bool removeGizmo(Shape* gizmoShape);
	};
}

#endif // !RENDERER_H

