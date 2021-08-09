#include "GameObject.hpp"

namespace GameEngine
{
	GameObject::GameObject()
	{
		transform = new ObjTransform();
		componentList = new vector<Component*>();
		gameLayer = GameLayer::DEFAULT;
		tag = "undefined";
	}

	GameObject::~GameObject()
	{
		delete(transform);
		delete(componentList);
	}

	void GameObject::addComponent(Component* component)
	{
		componentList->push_back(component);		
	}

	void GameObject::runComponents()
	{
		// go through all components and run their update function
		for (int i = 0; i < componentList->size(); i++)
		{
			Component* currComp = (*componentList)[i];
			// only run component if it is enabled
			if(currComp->getEnabled())
				currComp->update();
		}
	}

	template <typename componentType>
	Component* GameObject::getComponent()
	{
		// find the first component of the given type
		for (int i = 0; i < componentList->size(); i++)
		{
			Component* currComp = (*componentList)[i];
			componentType* comp = dynamic_cast<componentType*>(currComp);
			if (comp != NULL)
			{
				return currComp;
			}
		}

		// component not found
		return NULL;
	}

}