#ifndef CAMERA_CONTROLLER_H
#define CAMERA_CONTROLLER_H

#include "../Engine/Component.hpp"
#include "../Engine/GameObject.hpp"
#include "../Engine/Engine.hpp"

using namespace GameEngine;

class CameraController : public Component
{
	/* variables */
public:
	float lerpThresh = 0.5;
	float speed = 10;
	GameObject::ObjTransform* target;

private:
	GameObject* gameObject;
	Engine* engine;

	/* methods */
	
	/// <summary>
	/// Linearly interpolates between two points
	/// </summary>
	/// <param name="a">the start value, returned when t = 0</param>
	/// <param name="b">the end value, returned when t = 1</param>
	/// <param name="t">value used to interpolate between a and b</param>
	/// <returns></returns>
	Vector2f lerpVector2f(Vector2f a, Vector2f b, float t);
public:
	/// <summary>
	/// A constructor for a new camera controller component
	/// </summary>
	/// <param name="gameObject">the object that this component
	/// is attached to</param>
	CameraController(GameObject* gameObject);

	/// <summary>
	/// A constructor for a new camera controller component
	/// </summary>
	/// <param name="gameObject">the object that this component
	/// is attached to</param>
	/// <param name="target">the target of this camera controller</param>
	/// <param name="speed">the speed at which this camera controller
	/// should move at</param>
	/// <param name="lerpThresh">the threshold for lerping</param>
	CameraController(GameObject* gameObject, GameObject::ObjTransform* target, 
			float speed, float lerpThresh);

	/// <summary>
	/// A destructor for a camera controller object
	/// </summary>
	~CameraController();

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