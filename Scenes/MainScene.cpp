#include "MainScene.hpp"

MainScene::MainScene(string sceneName)
{
    engine = Engine::getInstance();
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
    GameObject* player = new GameObject();
    engine->addGameObject(player);
    player->tag = "Player";
    // rigidbody comp
    Rigidbody* playerRB = new Rigidbody(player);
    player->addComponent(playerRB);
    // sprite renderer comp
    Texture* playerTexture = new Texture();
    playerTexture->loadFromFile("./Sprites/Mario.png");
    SpriteRenderer* playerRend = new SpriteRenderer(playerTexture, player);
    player->addComponent(playerRend);
    player->transform->scale = Vector2f(.1, .1);
    // collider component
    BoxCollider* playerCol = new BoxCollider(playerTexture->getSize(), player);
    player->addComponent(playerCol);
    // controller comp
    PlayerController* playerCtlr = new PlayerController(player, 
            Vector2f(playerTexture->getSize().x * player->transform->scale.x, 50),
            Vector2f(200, playerTexture->getSize().y * player->transform->scale.y));
    playerCtlr->groundCheckOffset = Vector2f(0, 100);
    playerCtlr->attackRightOffset = Vector2f(200, 0);
    player->addComponent(playerCtlr);



    // bob
    GameObject* bob = new GameObject();
    bob->transform->position = Vector2f(500, 500);
    bob->tag = "bob";
    Texture* bobTexture = new Texture();
    bobTexture->loadFromFile("./Sprites/bob.png");
    SpriteRenderer* bobRend = new SpriteRenderer(bobTexture, bob);
    BoxCollider* bobCol = new BoxCollider(bobTexture->getSize(), bob);
    bob->addComponent(bobRend);
    bob->addComponent(bobCol);
    engine->addGameObject(bob);


    /* ========== Camera =========== */
    GameObject* cameraObj = new GameObject();
    engine->addGameObject(cameraObj);
    // camera comp
    Camera* cameraComp = new Camera(FloatRect(screenWidth / 2, screenHeight / 2, 1280, 720), cameraObj);
    cameraObj->addComponent(cameraComp);
    // cam controller
    CameraController* camCtrl = new CameraController(cameraObj, player->transform,
        10, 0.5);
    cameraObj->addComponent(camCtrl);


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
    testComp->playerController = playerCtlr;

    // test UI
    // ui 1
    GameObject* testUI = new GameObject();
    engine->addGameObject(testUI);
    Texture* testUITexture = new Texture();
    testUITexture->loadFromFile("./Sprites/bob.png");
    UIRenderer* testUIRend = new UIRenderer(testUI, testUITexture);
    testUI->addComponent(testUIRend);
    testUI->transform->position = Vector2f(100, 100);
    testUI->transform->scale = Vector2f(.5, .5);
    // ui 2
    GameObject* testUI2 = new GameObject();
    engine->addGameObject(testUI2);
    Texture* testUITexture2 = new Texture();
    testUITexture2->loadFromFile("./Sprites/bob.png");
    UIRenderer* testUIRend2 = new UIRenderer(testUI2, testUITexture2);
    testUI2->addComponent(testUIRend2);
    testUI2->transform->position = Vector2f(250, 100);
    testUI2->transform->scale = Vector2f(.5, .5);
    // ui 3
    GameObject* testUI3 = new GameObject();
    engine->addGameObject(testUI3);
    Texture* testUITexture3 = new Texture();
    testUITexture3->loadFromFile("./Sprites/bob.png");
    UIRenderer* testUIRend3 = new UIRenderer(testUI3, testUITexture3);
    testUI3->addComponent(testUIRend3);
    testUI3->transform->position = Vector2f(400, 100);
    testUI3->transform->scale = Vector2f(.5, .5);

    // UIManager 
    GameObject* UIManagerObj = new GameObject();
    engine->addGameObject(UIManagerObj);
    UIManager* UIManComp = UIManager::getInstance();
    UIManComp->addGameObject(UIManagerObj);
    UIManComp->heartUIObjs->push_back(testUI);
    UIManComp->heartUIObjs->push_back(testUI2);
    UIManComp->heartUIObjs->push_back(testUI3);
    UIManagerObj->addComponent(UIManComp);
    UIManComp->updateHeartUI(3);
}