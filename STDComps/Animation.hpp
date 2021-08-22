#ifndef ANIMATION_H
#define ANIMATION_H

#include "../Engine/DrawableComp.hpp"
#include <SFML/Graphics.hpp>
#include "../Engine/Engine.hpp"
#include "../Engine/Renderer.hpp"
#include <vector>

using namespace sf;
using namespace GameEngine;

class Animation : public DrawableComp
{
	/* variables */
public:
	float timeBetweenFrames;

private:
	bool isPlaying;
	vector<Sprite*>* sprites;
	int currSprite;
	Engine* engine;
	RenderWindow* window;
	float elapsedTime;
	GameObject* gameObject;

	/* methods */
public:
	/// <summary>
	/// Constructor for a new animation component
	/// </summary>
	/// <param name="sprites">a list of the sprites for the animation in order</param>
	Animation(GameObject* gameObject, vector<Sprite*>* sprites);

	/// <summary>
	/// Destructor for a animation component
	/// </summary>
	~Animation();

	/// <summary>
	/// called every frame by the renderer in the render queue
	/// </summary>
	void draw();

	void update();

	void lateUpdate();

	/// <summary>
	/// Play this animation
	/// </summary>
	void playAnimation();
};


#endif // !ANIMATION_H
