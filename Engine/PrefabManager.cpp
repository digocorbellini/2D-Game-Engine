#include "PrefabManager.hpp"

namespace GameEngine
{
	PrefabManager* PrefabManager::instance = NULL;

	PrefabManager::PrefabManager()
	{
        engine = Engine::getInstance();
	}

	PrefabManager::~PrefabManager()
	{

	}

	GameObject* PrefabManager::playerPrefab()
	{
        GameObject* player = new GameObject();
        engine->addGameObject(player);
        player->tag = "Player";
        player->gameLayer = GameLayer::PLAYER;
        // rigidbody comp
        Rigidbody* playerRB = new Rigidbody(player);
        player->addComponent(playerRB);
        // sprite renderer comp
        Texture* playerTexture = new Texture();
        playerTexture->loadFromFile("./Sprites/Mario.png");
        SpriteRenderer* playerRend = new SpriteRenderer(playerTexture, player);
        player->addComponent(playerRend);

        // TEMPORARY
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

        return player;
	}

    GameObject* PrefabManager::antPrefab()
	{
        GameObject* ant = new GameObject();
        engine->addGameObject(ant);
        // give ant a sprite
        Texture* antTexture = new Texture();
        antTexture->loadFromFile("./Sprites/bob.png");
        SpriteRenderer* antSpriteRend = new SpriteRenderer(antTexture, ant);
        ant->addComponent(antSpriteRend);
        // give ant a rigidbody
        Rigidbody* antRb = new Rigidbody(ant);
        ant->addComponent(antRb);
        // give ant a boxCollider
        BoxCollider* antCol = new BoxCollider(antTexture->getSize(), ant);
        ant->addComponent(antCol);
        // add ant component
        Ant* antComp = new Ant(ant);
        Vector2f antHitBoxSize;
        antHitBoxSize.x = antCol->size.x * ant->transform->scale.x + 10;
        antHitBoxSize.y = antCol->size.y * ant->transform->scale.y + 10;
        antComp->hitBoxSize = antHitBoxSize;
        ant->addComponent(antComp);

        return ant;
	}

    GameObject* PrefabManager::cameraPrefab(GameObject* target, float screenWidth, float screenHeight)
    {
        GameObject* cameraObj = new GameObject();
        engine->addGameObject(cameraObj);
        // camera comp
        Camera* cameraComp = new Camera(FloatRect(screenWidth / 2, screenHeight / 2, 1280, 720), cameraObj);
        cameraObj->addComponent(cameraComp);
        // cam controller
        CameraController* camCtrl = new CameraController(cameraObj, target->transform,
            10, 0.5);
        cameraObj->addComponent(camCtrl);

        return cameraObj;
    }

    GameObject* PrefabManager::UIHeartPrefab()
    {
        GameObject* heart = new GameObject();
        engine->addGameObject(heart);
        Texture* heartTexture = new Texture();
        heartTexture->loadFromFile("./Sprites/bob.png");
        UIRenderer* heartUIRend = new UIRenderer(heart, heartTexture);
        heart->addComponent(heartUIRend);
        
        // TEMPORARY
        heart->transform->scale = Vector2f(.5, .5);

        return heart;
    }

    GameObject* PrefabManager::viewPanelPrefab()
    {
        GameObject* viewPanel = new GameObject();
        engine->addGameObject(viewPanel);
        // add UI component
        Texture* viewTexture = new Texture();
        viewTexture->loadFromFile("./Sprites/white_square.jpg");
        UIRenderer* panelRend = new UIRenderer(viewPanel, viewTexture);
        viewPanel->addComponent(panelRend);
        // set order in layer and layer
        panelRend->orderInLayer = -1;
        // scale to fit the whole screen
        viewPanel->transform->scale = Vector2f(3, 3);
        // make it transparent
        panelRend->color.a = 0;

        return viewPanel;
    }
}