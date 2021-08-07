#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

using namespace sf;

namespace GameEngine
{
	class ObjTransform
	{
	public:
		Vector2f position;
		GameObject* parent;

	};
}

#endif // !TRANSFORM_H

