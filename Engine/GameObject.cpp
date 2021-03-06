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
		int size = componentList->size();
		for (int i = 0;i < size; i++)
		{
			Component* currComp = (*componentList)[i];
			// only run component if it is enabled
			if(currComp->getEnabled())
				currComp->update();
		}

		// go through all components and run their fixed update function
		for (int i = 0; i < size; i++)
		{
			Component* currComp = (*componentList)[i];
			// only run component if it is enabled
			if (currComp->getEnabled())
				currComp->lateUpdate();
		}
	}

	void GameObject::clearComponents()
	{
		for (int i = 0; i < componentList->size(); i++)
		{
			Component* currComp = (*componentList)[i];
			if (currComp->destroyOnLoad)
			{
				delete(currComp);
			}
			else
			{
				currComp->resetComponent();
			}
		}

		componentList->clear();		
	}

	void GameObject::setEnabled(bool isEnabled)
	{
		// go through all components and enable or disable them 
		// so that they are in the same state as this gameObject
		for (int i = 0; i < componentList->size(); i++)
		{
			Component* currComp = (*componentList)[i];
			currComp->setEnabled(isEnabled);
		}

		this->isEnabled = isEnabled;
	}

	bool GameObject::getEnabled()
	{
		return isEnabled;
	}
}