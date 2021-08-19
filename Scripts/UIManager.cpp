#include "UIManager.hpp"

UIManager* UIManager::instance = NULL;

UIManager::UIManager()
{
	gameObject = NULL;
	heartUIObjs = new vector<GameObject*>();
	health = 0;
	destroyOnLoad = false;
}


UIManager::~UIManager()
{
	delete(heartUIObjs);
}

void UIManager::addGameObject(GameObject* gameObject)
{
	this->gameObject = gameObject;
}

void UIManager::update()
{
	// activate hearts for health
	for (int i = 0; i < heartUIObjs->size(); i++)
	{
		GameObject* currHeart = (*heartUIObjs)[i];
		if (i < health)
		{
			// enable heart sprite
			currHeart->setEnabled(true);
		}
		else
		{
			// disable heart sprite
			currHeart->setEnabled(false);
		}
	}
}

void UIManager::resetComponent()
{
	gameObject = NULL;
	heartUIObjs->clear();
	health = 0;
	destroyOnLoad = false;
}

void UIManager::lateUpdate()
{

}

void UIManager::updateHeartUI(int health)
{
	this->health = clamp(health, 0, heartUIObjs->size());
}

int UIManager::clamp(int val, int min, int max)
{
	if (val <= min)
	{
		return min;
	}
	else if (val <= max)
	{
		return val;
	}
	else
	{
		return max;
	}
}