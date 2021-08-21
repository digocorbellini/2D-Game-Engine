#ifndef DONUT_H
#define DONUT_H

#include "../Engine/Component.hpp"
#include "../Engine/GameObject.hpp"
#include "../Engine/Physics.hpp"
#include "../Engine/Renderer.hpp"
#include "../Engine/Layers.hpp"
#include "../Engine/SceneManager.hpp"
#include <SFML/Graphics.hpp>

using namespace GameEngine;
using namespace sf;

class Donut : public Component
{
	/* variables */
public:
	Vector2f detectionSize;
	GameLayer playerLayer = GameLayer::PLAYER;

private:
	GameObject* gameObject;
	RectangleShape* detectionBox;
	Renderer* renderer;
	Physics* physics;
	SceneManager* sceneMan;
	

	/* methods */
public:
	Donut(GameObject* gameObject);

	~Donut();

	void update();

	void lateUpdate();
};

#endif // !DONUT_H

