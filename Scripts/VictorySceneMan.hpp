#ifndef VICTORY_SCENE_MAN_H
#define VICTORY_SCENE_MAN_H

#include "../Engine/Component.hpp"
#include "../Engine/Engine.hpp"
#include "../Engine/SceneManager.hpp"
#include <SFML/Graphics.hpp>

using namespace GameEngine;
using namespace sf;

class VictorySceneMan : public Component
{
private:
	Engine* engine;
	GameObject* gameObject;
	SceneManager* sceneMan;

public:
	VictorySceneMan(GameObject* gameObject);

	void update();

	void lateUpdate();

};

#endif // !VICTORY_SCENE_MAN_H
