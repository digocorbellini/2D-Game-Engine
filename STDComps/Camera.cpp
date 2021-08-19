#include "Camera.hpp"

Camera::Camera(FloatRect rectangle, GameObject* gameObject)
{
	cameraView = new View(rectangle);
	this->gameObject = gameObject;
	window = Renderer::getInstance()->getWindow();
	window->setView(*cameraView);
}

Camera::~Camera()
{
	delete(cameraView);
}

void Camera::update()
{
	// make camera stay centered on the gameObject
	cameraView->setCenter(gameObject->transform->position);
	// set the view
	window->setView(*cameraView);
}

void Camera::lateUpdate()
{

}

View* Camera::getView()
{
	return cameraView;
}