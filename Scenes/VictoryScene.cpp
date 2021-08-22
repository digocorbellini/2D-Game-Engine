#include "VictoryScene.hpp"

VictoryScene::VictoryScene(string sceneName)
{
	this->sceneName = sceneName;
    engine = Engine::getInstance();
    Vector2u screenSize = engine->getWindow()->getSize();
    screenWidth = screenSize.x;
    screenHeight = screenSize.y;
}

VictoryScene::~VictoryScene()
{

}

void VictoryScene::loadScene()
{
	/* ========= victory background ============ */
    GameObject* backgroundObj = new GameObject();
    engine->addGameObject(backgroundObj);
    // add a UI renderer
    Texture* backgroundTexture = new Texture();
    backgroundTexture->loadFromFile("./Sprites/victory_screen.png");
    UIRenderer* backgroundRend = new UIRenderer(backgroundObj, backgroundTexture);
    backgroundObj->addComponent(backgroundRend);
    backgroundRend->layer = RenderingLayer::BACKGROUND;
    backgroundRend->orderInLayer = -10;
    // place in center of the screen and size it so that the whole screen is covered
    Vector2f backgroundPos = Vector2f(screenWidth / 2, screenHeight / 2);
    backgroundObj->transform->position = backgroundPos;
    backgroundObj->transform->scale = Vector2f(1.08, 1.08);

    /* ========== retry component ============ */
    GameObject* retryObj = new GameObject();
    engine->addGameObject(retryObj);
    VictorySceneMan* vicMan = new VictorySceneMan(retryObj);
    retryObj->addComponent(vicMan);
}