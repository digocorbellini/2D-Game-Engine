#ifndef CAMERA_H
#define CAMERA_H

#include <SFML/Graphics.hpp>
#include "../Engine/Component.hpp"
#include "../Engine/GameObject.hpp"
#include "../Engine/Renderer.hpp"

using namespace GameEngine;
using namespace sf;

class Camera : public Component
{
	/* Variables */
public:
	GameObject* gameObject;

private:
	View* cameraView;
	RenderWindow* window;

	/* Methods */
public:
	/// <summary>
	/// Constructor for a new camera component
	/// </summary>
	/// <param name="rectangle">the size and position of the view</param>
	/// <param name="gameObject">the gameObject that this
	/// component is attatched to</param>
	Camera(FloatRect rectangle, GameObject* gameObject);

	/// <summary>
	/// A destructor for a camera object
	/// </summary>
	~Camera();

	/// <summary>
	/// called every frame by the GameObject that has this component
	/// </summary>
	void update();

	/// <summary>
	/// Called every frame after update. Used to handle physics and collisions
	/// </summary>
	void fixedUpdate();

};

#endif
