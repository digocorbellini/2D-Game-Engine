#ifndef UI_RENDERER_H
#define UI_RENDERER_H

#include "../Engine/Renderer.hpp"
#include "../Engine/DrawableComp.hpp"
#include "../Engine/Engine.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace GameEngine;

class UIRenderer : public DrawableComp
{
	/* variables */
public:
	Vector2f scale;
	Color color;
	Sprite* sprite;

private:
	Renderer* renderer;
	RenderWindow* window;
	GameObject* gameObject;
	Texture* texture;

	/* methods */
public:
	/// <summary>
	/// Constructor for a new UIRenderer component
	/// </summary>
	/// <param name="gameObject">the gameObject that this component
	/// is attached to</param>
	/// <param name="spriteTexture">the texture of tthe sprite</param>
	UIRenderer(GameObject* gameObject, Texture* spriteTexture);

	/// <summary>
	/// Destrucor for a UIRenderer component
	/// </summary>
	~UIRenderer();

	/// <summary>
	/// called every frame by the renderer in the render queue
	/// </summary>
	void draw();

	/// <summary>
	/// called every frame by the GameObject that has this component
	/// </summary>
	void update();

	/// <summary>
	/// Called every frame after update. Used to handle physics and collisions
	/// </summary>
	void lateUpdate();
};

#endif