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
		virtual FloatRect getBounds() = 0;
	};
}

#endif // !COLLIDER_COMP_H

