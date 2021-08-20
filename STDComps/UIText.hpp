#ifndef UI_TEXT_H
#define UI_TEXT_H

#include "../Engine/Renderer.hpp"
#include "../Engine/DrawableComp.hpp"
#include "../Engine/Engine.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace GameEngine;


class UIText : public DrawableComp
{
	/* variables */
public:
	Color color;
	unsigned int fontSize;
	float outlineThickness;
	string text;

private:
	Renderer* renderer;
	RenderWindow* window;
	GameObject* gameObject;
	Font* font;
	Text* textObj;

	/* methods */
public:
	/// <summary>
	/// Constructor for a new UI Text component
	/// </summary>
	/// <param name="gameObject">the gameObject that this component is 
	/// attached to</param>
	/// <param name="font">the font for this text component</param>
	UIText(GameObject* gameObject, Font* font);

	/// <summary>
	/// Destructor for a UIText component
	/// </summary>
	~UIText();

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
#endif // !UI_TEXT_H

