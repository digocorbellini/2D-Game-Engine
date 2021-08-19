#ifndef MAIN_SCENE_H
#define MAIN_SCENE_H

#include <SFML/Graphics.hpp>

#include "../Engine/SceneManager.hpp"

#include "../STDComps/SpriteRenderer.hpp"
#include "../STDComps/BoxCollider.hpp"
#include "../STDComps/Camera.hpp"
#include "../STDComps/Rigidbody.hpp"
#include "../STDComps/CircleCollider.hpp"
#include "../STDComps/UIRenderer.hpp"

#include "../Scripts/CameraController.hpp"
#include "../Scripts/PlayerController.hpp"
#include "../Scripts/UIManager.hpp"
#include "../Scripts/TestComp.hpp"

using namespace GameEngine;
using namespace std;
using namespace sf;

class MainScene : public Scene
{
private:
	Engine* engine;
	int screenWidth;
	int screenHeight;

public:
	MainScene(string sceneName);

	~MainScene();

	void loadScene();
};

#endif // !MAIN_SCENE_H

