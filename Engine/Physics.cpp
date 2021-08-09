#include "Physics.hpp"

namespace GameEngine
{
	// make sure physics is initialized as NULL
	Physics* Physics::instance = NULL;

	Physics::Physics()
	{
		colliders = new vector<ColliderComp*>();
	}

	Physics::~Physics()
	{
		delete(colliders);
	}

	void Physics::addCollider(ColliderComp* collider)
	{
		colliders->push_back(collider);
	}

	bool Physics::removeCollider(ColliderComp* collider)
	{
		// find the collider
		int pos = 0;
		for (pos = 0; pos < colliders->size(); pos++)
		{
			ColliderComp* currComp = (*colliders)[pos];
			if (currComp == collider)
			{
				break;
			}
		}

		// if the collider was found then remove it
		if (pos < colliders->size())
		{
			colliders->erase(colliders->begin() + pos);
			return true;
		}

		// collider not found
		return false;
	}

	ColliderComp* Physics::isColliding(ColliderComp* collider)
	{
		if (!collider->getEnabled())
			return NULL;

		FloatRect colBounds = collider->getBounds();

		// check for collisions with all of the enabled colliders in the game
		// AWFUL OPTIMIZATION. MUST IMPROVE IF YOU WANT A LARGER GAME
		for (int i = 0; i < colliders->size(); i++)
		{
			ColliderComp* currCol = (*colliders)[i];
			FloatRect currBounds = currCol->getBounds();
			if (currCol != collider 
					&& currCol->getEnabled() 
					&& colBounds.intersects(currBounds))
			{
				// found a collision
				return currCol;
			}
		}

		// no collision found
		return NULL;
	}
}


