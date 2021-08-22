#ifndef VICTORY_SCENE_H
#define VICTORY_SCENE_H

#include "../Engine/Scene.hpp"
#include <SFML/Graphics.hpp>
#include "../Engine/Engine.hpp"
#include "../STDComps/UIRenderer.hpp"
#include "../Engine/Layers.hpp"
#include "../Scripts/VictorySceneMan.hpp"

using namespace GameEngine;
using namespace sf;

class VictoryScene : public Scene
{
private:
	Engine* engine;
	float screenWidth;
	float screenHeight;

public:
	VictoryScene(string sceneName);

	~VictoryScene();

	void loadScene();
};

#endif // !VICTORY_SCENE_H
