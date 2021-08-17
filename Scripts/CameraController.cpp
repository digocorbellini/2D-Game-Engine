#include "CameraController.hpp"

CameraController::CameraController(GameObject* gameObject)
{
	this->gameObject = gameObject;
	this->engine = Engine::getInstance();
}

CameraController::CameraController(GameObject* gameObject, GameObject::ObjTransform* target, 
		float speed, float lerpThresh)
{
	this->gameObject = gameObject;
	this->engine = Engine::getInstance();
	this->target = target;
	this->speed = speed;
	this->lerpThresh = lerpThresh;
}

CameraController::~CameraController()
{

}

void CameraController::update()
{
	Vector2f currPos = gameObject->transform->position;
	Vector2f targetPos = target->position;
	// lerp to the position of the target
	Vector2f finalPos = lerpVector2f(currPos, targetPos, speed * engine->getDeltaTime());
	// set the position of this object to the new lerping position
	gameObject->transform->position = finalPos;
}

void CameraController::lateUpdate()
{

}

Vector2f CameraController::lerpVector2f(Vector2f a, Vector2f b, float t)
{
	return a + (b - a) * t;
}