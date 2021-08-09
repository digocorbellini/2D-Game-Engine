#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H

#include "..\Engine\DrawableComp.hpp"
#include "..\Engine\Component.hpp"
#include "..\Engine\Renderer.hpp"
#include "..\Engine\Engine.hpp"
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace GameEngine;

/// <summary>
/// Draws a sprite to the screen
/// </summary>
class SpriteRenderer : public DrawableComp
{
public:
	Vector2f scale;
	Color color;
	Sprite* sprite;

private:
	Renderer* renderer;
	RenderWindow* window;
	GameObject* gameObject; // the gameObject that this component is attached to 

public:
	/// <summary>
	/// Constructor for a new sprite renderer component
	/// </summary>
	/// <param name="spriteTexture">the texture of the sprite</param>
	/// <param name="gameObject">the gameobject that this component
	/// is attached to</param>
	SpriteRenderer(Texture* spriteTexture, GameObject* gameObject);

	/// <summary>
	/// Destructor for this sprite renderer
	/// </summary>
	~SpriteRenderer();

	/// <summary>
	/// Enable this 
	/// </summary>
	/// <param name="enabled"></param>
	void setEnabled(bool enabled);

	/// <summary>
	/// called every frame by the renderer in the render queue
	/// </summary>
	void draw();

	/// <summary>
	/// called every frame by the GameObject that has this component
	/// </summary>
	void update();
};

#endif // !SPRITE_RENDERER_H

