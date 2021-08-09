#ifndef DRAWABLE_COMP_H
#define DRAWABLE_COMP_H

#include "Component.hpp"
#include <string>
#include "Layers.hpp"

using namespace std;

namespace GameEngine
{
	class DrawableComp : public Component
	{
	public:
		int orderInLayer;
		RenderingLayer layer;

		/// <summary>
		/// called every frame by the renderer in the render queue
		/// </summary>
		virtual void draw() = 0;

		bool operator < (const DrawableComp& other) const
		{
			return (orderInLayer < other.orderInLayer);
		}

		bool operator > (const DrawableComp& other) const
		{
			return (orderInLayer > other.orderInLayer);
		}
	};
}

#endif
