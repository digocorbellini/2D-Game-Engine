#ifndef COLLIDER_COMP_H
#define COLLIDER_COMP_H

#include "Component.hpp";
#include <SFML/Graphics.hpp>

using namespace sf;

namespace GameEngine
{
	class ColliderComp : public Component
	{
	public:
		/// <summary>
		/// Get the bounds of this collider
		/// </summary>
		/// <returns>the bounds of this collider</returns>
		virtual FloatRect getBounds() = 0;
	};
}

#endif // !COLLIDER_COMP_H

