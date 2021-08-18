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


    /* ========= Player Object ========= */
    GameObject* player = new GameObject();
    engine->addGameObject(player);
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
    PlayerController* playerCtlr = new PlayerController(player, Vector2f(100, 100));
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
    Camera* cameraComp = new Camera(FloatRect(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 1280, 720), cameraObj);
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


    // test obj for priting and such
    GameObject* testingObj = new GameObject();
    engine->addGameObject(testingObj);
    TestComp* testComp = new TestComp(testingObj);
    testingObj->addComponent(testComp);
}