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

    /* ======= wall at the end =========== */
    GameObject* endWall = new GameObject();
    engine->addGameObject(endWall);
    // give it a sprite
    Texture* endWallTexture = new Texture();
    endWallTexture->loadFromFile("./Sprites/cereal_box_sprite.png");
    SpriteRenderer* endWallSprite = new SpriteRenderer(endWallTexture, endWall);
    endWall->addComponent(endWallSprite);
    xOffset = (endWallTexture->getSize().x / 2);
    yOffset = (endWallTexture->getSize().y / 2);
    endWall->transform->position = Vector2f(8448 + xOffset, 960 - yOffset);
    // give it a boxCollider
    BoxCollider* endWallCol = new BoxCollider(endWallTexture->getSize(), endWall);
    endWall->addComponent(endWallCol);

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

    /* ========= Ants ========= */
    GameObject* ant1 = prefabMan->antPrefab();
    ant1->transform->position = Vector2f(400, 500);

    GameObject* ant2 = prefabMan->antPrefab();
    ant2->transform->position = Vector2f(1055, 500);

    GameObject* ant3 = prefabMan->antPrefab();
    ant3->transform->position = Vector2f(1945, 500);

    GameObject* ant4 = prefabMan->antPrefab();
    ant4->transform->position = Vector2f(2438, 500);

    GameObject* ant5 = prefabMan->antPrefab();
    ant5->transform->position = Vector2f(3558, 500);

    GameObject* ant6 = prefabMan->antPrefab();
    ant6->transform->position = Vector2f(4952, 500);

    GameObject* ant7 = prefabMan->antPrefab();
    ant7->transform->position = Vector2f(5141, 500);

    GameObject* ant8 = prefabMan->antPrefab();
    ant8->transform->position = Vector2f(5353, 500);

    GameObject* ant9 = prefabMan->antPrefab();
    ant9->transform->position = Vector2f(6017, 500);

    GameObject* ant10 = prefabMan->antPrefab();
    ant10->transform->position = Vector2f(6843, 500);

    /* ========= Game Manager ========== */
    GameObject* gameManager = new GameObject();
    engine->addGameObject(gameManager);
    // create the game manager component
    GameManager* gameManComp = GameManager::getInstance();
    gameManComp->addGameObject(gameManager);
    gameManager->addComponent(gameManComp);
    
    //gameManComp->timeBetweenStates = 15;
    gameManComp->timeBetweenStates = 1000;

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

    SafeSpace* safeSpace4 = prefabMan->safeSpacePrefab("./Sprites/fruit_bowl_sprite.png",
        Vector2f(6017, 853));
    gameManComp->safeSpaces->push_back(safeSpace4);
    
    
    /* ========= Obstacles ========== */
    prefabMan->obstaclePrefab("./Sprites/salt_side_sprite.png",
        Vector2f(-192, 970));
    prefabMan->obstaclePrefab("./Sprites/pepper_standing_sprite.png",
        Vector2f(80, 970));
    prefabMan->obstaclePrefab("./Sprites/salt_standing_sprite.png",
        Vector2f(2037, 970));
    prefabMan->obstaclePrefab("./Sprites/plate_sprite.png",
        Vector2f(3177, 970));
    prefabMan->obstaclePrefab("./Sprites/pepper_standing_sprite.png",
        Vector2f(3339, 870));
    prefabMan->obstaclePrefab("./Sprites/salt_standing_sprite.png",
        Vector2f(3832, 870));
    prefabMan->obstaclePrefab("./Sprites/salt_standing_sprite.png",
        Vector2f(3832, 705));
    prefabMan->obstaclePrefab("./Sprites/salt_standing_sprite.png",
        Vector2f(4775, 970));
    prefabMan->obstaclePrefab("./Sprites/pepper_standing_sprite.png",
        Vector2f(5450, 970));
    
    /* ============= Final Donut ============= */
    GameObject* donut = new GameObject();
    engine->addGameObject(donut);
    // give it a sprite 
    Texture* donutTexture = new Texture();
    donutTexture->loadFromFile("./Sprites/donut_sprite_large.png");
    SpriteRenderer* donutSprite = new SpriteRenderer(donutTexture, donut);
    donut->addComponent(donutSprite);
    donutSprite->layer = RenderingLayer::FOREGROUND1;
    // place it in the correct position
    float xOffsetDonut = (donutTexture->getSize().x / 2);
    float yOffsetDonut = (donutTexture->getSize().y / 2);
    donut->transform->position = Vector2f(7802 + xOffsetDonut, 970 - yOffsetDonut);
    // add donut component


    // test obj for priting and such
    GameObject* testingObj = new GameObject();
    engine->addGameObject(testingObj);
    TestComp* testComp = new TestComp(testingObj);
    testingObj->addComponent(testComp);
    testComp->playerController = player->getComponent<PlayerController>();
}