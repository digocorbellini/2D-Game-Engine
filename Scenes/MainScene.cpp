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
    //// create object
    //GameObject* mario = new GameObject();
    //// get texture
    //Texture* marioTexture = new Texture();
    //marioTexture->loadFromFile("./Sprites/Mario.png");
    //// create sprite marioRend component
    //SpriteRenderer* marioRend = new SpriteRenderer(marioTexture, mario);
    //// set obj and component values
    //mario->transform->position = Vector2f(100, 800);
    ////marioRend->scale = Vector2f(.2, .2);
    //mario->transform->scale = Vector2f(.1, .1);
    //// add collider to mario and gravity
    //BoxCollider* testCol = new BoxCollider(marioTexture->getSize(), mario);
    ////Rigidbody* gravityComp = new Rigidbody(mario);
    ////mario->addComponent(gravityComp);
    //mario->addComponent(testCol);
    //// make another component
    ////TestComp* testComp = new TestComp(mario);
    //// add components
    //mario->addComponent(marioRend);
    //// mario->addComponent(testComp);
    //// add obj to game engine
    //engine->addGameObject(mario);
    //mario->gameLayer = GameLayer::ENEMIES;
    ////testCol->isTrigger = true;


    /* ========= Player Object ========= */
    GameObject* player = prefabMan->playerPrefab();
    player->transform->position = Vector2f(-500, 600);

    /* ========= wall =========== */
    GameObject* wall = new GameObject();
    engine->addGameObject(wall);
    // give it a sprite
    Texture* wallTexture = new Texture();
    wallTexture->loadFromFile("./Sprites/cereal_box_sprite.png");
    SpriteRenderer* wallSprite = new SpriteRenderer(wallTexture, wall);
    wall->addComponent(wallSprite);
    float xOffset = (wallTexture->getSize().x / 2);
    float yOffset = (wallTexture->getSize().y / 2);
    wall->transform->position = Vector2f(-900 - xOffset, 960 - yOffset);
    // give it a boxCollider
    BoxCollider* wallCol = new BoxCollider(wallTexture->getSize(), wall);
    wall->addComponent(wallCol);

    /* ========== Camera =========== */
    GameObject* cameraObj = prefabMan->cameraPrefab(player, screenWidth, screenHeight);
    cameraObj->transform->position = player->transform->position;

    /* ========== Table ============ */
    GameObject* floor = new GameObject();
    engine->addGameObject(floor);
    floor->transform->position = Vector2f(0, 1000);
    // give the floor the floor sprite stretched really far
    Texture* floorTexture = new Texture();
    floorTexture->loadFromFile("./Sprites/table_sprite.png");
    //floorTexture->setRepeated(true);
    SpriteRenderer* floorRend = new SpriteRenderer(floorTexture, floor);
    floor->addComponent(floorRend);
    floorRend->scale = Vector2f(100, 1.6);
    floorRend->layer = RenderingLayer::FOREGROUND1;
    floorRend->orderInLayer = -1;
    // give the floor a box Collider
    Vector2u floorColSize;
    floorColSize.x = floorRend->scale.x * floorTexture->getSize().x;
    floorColSize.y = 50;
    BoxCollider* floorCol = new BoxCollider(floorColSize, floor);
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
    heartUI1->transform->position = Vector2f(80, 80);
    // ui 2
    GameObject* heartUI2 = prefabMan->UIHeartPrefab();
    heartUI2->transform->position = Vector2f(160 + 20, 80);
    // ui 3
    GameObject* heartUI3 = prefabMan->UIHeartPrefab();
    heartUI3->transform->position = Vector2f(240 + 40, 80);

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

    /* ========= Background ========== */
    GameObject* backgroundObj = new GameObject();
    engine->addGameObject(backgroundObj);
    // add a UI renderer
    Texture* backgroundTexture = new Texture();
    backgroundTexture->loadFromFile("./Sprites/background_sprite.png");
    UIRenderer* backgroundRend = new UIRenderer(backgroundObj, backgroundTexture);
    backgroundObj->addComponent(backgroundRend);
    backgroundRend->layer = RenderingLayer::BACKGROUND;
    backgroundRend->orderInLayer = -10;
    // place in center of the screen and size it so that the whole screen is covered
    Vector2f backgroundPos = Vector2f(screenWidth / 2, screenHeight / 2);
    backgroundObj->transform->position = backgroundPos;
    backgroundObj->transform->scale = Vector2f(1.08, 1.08);

    /* ========= Ant ========= */
    GameObject* ant1 = prefabMan->antPrefab();
    ant1->transform->position = Vector2f(600, 0);

    /* ========= Game Manager ========== */
    GameObject* gameManager = new GameObject();
    engine->addGameObject(gameManager);
    // create the game manager component
    GameManager* gameManComp = GameManager::getInstance();
    gameManComp->addGameObject(gameManager);
    gameManager->addComponent(gameManComp);
    
    //gameManComp->timeBetweenStates = 5;


    /* ========= safeSpaces =========*/
    SafeSpace* safeSpace3 = prefabMan->safeSpacePrefab("./Sprites/cereal_box_sprite.png",
        Vector2f(2157, 853));
    gameManComp->safeSpaces->push_back(safeSpace3);
    SafeSpace* safeSpace2 = prefabMan->safeSpacePrefab("./Sprites/cereal_box_sprite.png",
        Vector2f(1820, 853));
    gameManComp->safeSpaces->push_back(safeSpace2);
    SafeSpace* safeSpace = prefabMan->safeSpacePrefab("./Sprites/cereal_box_sprite.png", 
                Vector2f(1478, 853));
    gameManComp->safeSpaces->push_back(safeSpace);
    




    //// test safe space
    //GameObject* safeSpace1 = new GameObject();
    //engine->addGameObject(safeSpace1);
    //safeSpace1->transform->position = Vector2f(-1500, 0);
    //// give it a sprite
    //Texture* safeTexture1 = new Texture();
    //safeTexture1->loadFromFile("./Sprites/Mario.png");
    //SpriteRenderer* safeSpriteRend1 = new SpriteRenderer(safeTexture1, safeSpace1);
    //safeSpace1->addComponent(safeSpriteRend1);
    //safeSpriteRend1->layer = RenderingLayer::BACKGROUND;
    ////safeSpriteRend1->orderInLayer = -1;
    //// give it a safe space component
    //SafeSpace* safeSpaceComp1 = new SafeSpace(safeSpace1);
    //safeSpaceComp1->safeSpaceSize = Vector2f(safeTexture1->getSize());
    //safeSpace1->addComponent(safeSpaceComp1);

    //gameManComp->safeSpaces->push_back(safeSpaceComp1);
}