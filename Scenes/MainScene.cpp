#include "MainScene.hpp"

MainScene::MainScene(string sceneName)
{
    engine = Engine::getInstance();
    prefabMan = PrefabManager::getInstance();
    this->sceneName = sceneName;
    Vector2u screenSize = engine->getWindow()->getSize();
    screenWidth = screenSize.x;
    screenHeight = screenSize.y;
}

MainScene::~MainScene()
{

}

void MainScene::loadScene()
{
    // create object
    GameObject* mario = new GameObject();
    // get texture
    Texture* marioTexture = new Texture();
    marioTexture->loadFromFile("./Sprites/Mario.png");
    // create sprite marioRend component
    SpriteRenderer* marioRend = new SpriteRenderer(marioTexture, mario);
    // set obj and component values
    mario->transform->position = Vector2f(100, 800);
    //marioRend->scale = Vector2f(.2, .2);
    mario->transform->scale = Vector2f(.1, .1);
    // add collider to mario and gravity
    BoxCollider* testCol = new BoxCollider(marioTexture->getSize(), mario);
    //Rigidbody* gravityComp = new Rigidbody(mario);
    //mario->addComponent(gravityComp);
    mario->addComponent(testCol);
    // make another component
    //TestComp* testComp = new TestComp(mario);
    // add components
    mario->addComponent(marioRend);
    // mario->addComponent(testComp);
    // add obj to game engine
    engine->addGameObject(mario);
    mario->gameLayer = GameLayer::ENEMIES;
    //testCol->isTrigger = true;


    /* ========= Player Object ========= */
    GameObject* player = prefabMan->playerPrefab();

    // bob
    /*GameObject* bob = new GameObject();
    bob->transform->position = Vector2f(500, 500);
    bob->tag = "bob";
    Texture* bobTexture = new Texture();
    bobTexture->loadFromFile("./Sprites/bob.png");
    SpriteRenderer* bobRend = new SpriteRenderer(bobTexture, bob);
    BoxCollider* bobCol = new BoxCollider(bobTexture->getSize(), bob);
    bob->addComponent(bobRend);
    bob->addComponent(bobCol);
    engine->addGameObject(bob);*/


    /* ========== Camera =========== */
    GameObject* cameraObj = prefabMan->cameraPrefab(player, screenWidth, screenHeight);

    // test floor
    GameObject* floor = new GameObject();
    engine->addGameObject(floor);
    floor->transform->position = Vector2f(0, 1000);
    BoxCollider* floorCol = new BoxCollider(Vector2u(100000, 10), floor);
    floor->addComponent(floorCol);
    floor->gameLayer = GameLayer::GROUND;


    // test obj for priting and such
    GameObject* testingObj = new GameObject();
    engine->addGameObject(testingObj);
    TestComp* testComp = new TestComp(testingObj);
    testingObj->addComponent(testComp);
    testComp->playerController = player->getComponent<PlayerController>();

    /* ======= Heart UI ======== */
    // ui 1
    GameObject* heartUI1 = prefabMan->UIHeartPrefab();
    heartUI1->transform->position = Vector2f(100, 100);
    // ui 2
    GameObject* heartUI2 = prefabMan->UIHeartPrefab();
    heartUI2->transform->position = Vector2f(250, 100);
    // ui 3
    GameObject* heartUI3 = prefabMan->UIHeartPrefab();
    heartUI3->transform->position = Vector2f(400, 100);

    /* ========= UI Manager ========= */
    GameObject* UIManagerObj = new GameObject();
    engine->addGameObject(UIManagerObj);
    UIManager* UIManComp = UIManager::getInstance();
    UIManComp->addGameObject(UIManagerObj);
    UIManComp->heartUIObjs->push_back(heartUI1);
    UIManComp->heartUIObjs->push_back(heartUI2);
    UIManComp->heartUIObjs->push_back(heartUI3);
    UIManagerObj->addComponent(UIManComp);
    UIManComp->updateHeartUI(3);

    /* ========= Ant ========= */
    GameObject* ant1 = prefabMan->antPrefab();
    ant1->transform->position = Vector2f(600, 0);

}