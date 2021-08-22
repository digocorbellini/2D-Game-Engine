#include "Animation.hpp"
#include <iostream>

using namespace std;

Animation::Animation(GameObject* gameObject, vector<Sprite*>* sprites)
{
	this->sprites = sprites;
	isPlaying = false;
	currSprite = 0;
	engine = Engine::getInstance();
	window = engine->getWindow();
	this->gameObject = gameObject;
	// default time 
	timeBetweenFrames = 1.0 / 24.0; 
	layer = RenderingLayer::UIELEMENT;

	Renderer::getInstance()->addToRenderQueue(this);
}

Animation::~Animation()
{
	for (int i = 0; i < sprites->size(); i++)
	{
		Sprite* currSprite = (*sprites)[i];
		delete(currSprite);
	}
	free(sprites);
	Renderer::getInstance()->removeFromRenderQueue(this);
}

void Animation::draw()
{
	if (isPlaying)
	{
		if (currSprite < sprites->size())
		{
			cout << "draw sprite" << endl;
			Sprite* sprite = (*sprites)[currSprite];
			sprite->setPosition(gameObject->transform->position);
			sprite->setScale(gameObject->transform->scale);
			window->draw(*sprite);
		}
	}

	//Sprite* sprite = (*sprites)[0];
	//sprite->setPosition(gameObject->transform->position);
	//sprite->setScale(gameObject->transform->scale);
	//window->draw(*sprite);
}

void Animation::update()
{
	if (isPlaying)
	{
		elapsedTime += engine->getDeltaTime();

		if (currSprite >= sprites->size())
		{
			// animation finished playing
			isPlaying = false;
			currSprite = 0;
			elapsedTime = 0;
			return;
		}

		// draw current sprite
		if (elapsedTime > timeBetweenFrames)
		{
			elapsedTime = 0;
			currSprite++;
		}
	}
}

void Animation::lateUpdate()
{

}

void Animation::playAnimation()
{
	isPlaying = true;
	currSprite = 0;
	elapsedTime = 0;
}
