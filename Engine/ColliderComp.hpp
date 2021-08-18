#ifndef COLLIDER_COMP_H
#define COLLIDER_COMP_H

#include "Component.hpp";
#include "GameObject.hpp"
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


		/// <summary>
		/// Get the gameObject that this collider is attached to
		/// </summary>
		/// <returns>the gameobject that this collider is attached to</returns>
		virtual GameObject* getGameObject() = 0;

		/// <summary>
		/// Virtual destructor
		/// </summary>
		virtual ~ColliderComp()
		{

		}
	};
}

#endif // !COLLIDER_COMP_H

