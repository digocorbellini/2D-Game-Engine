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
        playerTexture->loadFromFile("./Sprites/cockroach_sprite.png");
        SpriteRenderer* playerRend = new SpriteRenderer(playerTexture, player);
        player->addComponent(playerRend);
        // collider component
        BoxCollider* playerCol = new BoxCollider(playerTexture->getSize(), player);
        player->addComponent(playerCol);
        // controller comp
        PlayerController* playerCtlr = new PlayerController(player,
            Vector2f(playerTexture->getSize().x * player->transform->scale.x - 10, 25),
            Vector2f(80, playerTexture->getSize().y * player->transform->scale.y));
        playerCtlr->groundCheckOffset = Vector2f(0, 35);
        playerCtlr->attackRightOffset = Vector2f(110, 0);
        player->addComponent(playerCtlr);

        return player;
	}

    GameObject* PrefabManager::antPrefab()
	{
        GameObject* ant = new GameObject();
        engine->addGameObject(ant);
        // give ant a sprite
        Texture* antTexture = new Texture();
        antTexture->loadFromFile("./Sprites/ant_sprite.png");
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
        cameraComp->posOffset = Vector2f(0, -100);
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
        heartTexture->loadFromFile("./Sprites/heart_sprite.png");
        UIRenderer* heartUIRend = new UIRenderer(heart, heartTexture);
        heart->addComponent(heartUIRend);

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
        panelRend->layer = RenderingLayer::BACKGROUND_FILTER;
        panelRend->orderInLayer = 0;
        // scale to fit the whole screen
        viewPanel->transform->scale = Vector2f(3, 3);
        // make it transparent
        panelRend->color.a = 0;

        return viewPanel;
    }

    SafeSpace* PrefabManager::safeSpacePrefab(string spriteLocation, Vector2f posOfBottomLeft)
    {
        GameObject* obj = new GameObject();
        engine->addGameObject(obj);
        // give it a sprite
        Texture* texture = new Texture();
        texture->loadFromFile(spriteLocation);
        SpriteRenderer* sprite = new SpriteRenderer(texture, obj);
        obj->addComponent(sprite);
        sprite->layer = RenderingLayer::FOREGROUND1;
        // set it at the given position
        float xOffset = (texture->getSize().x / 2);
        float yOffset = (texture->getSize().y / 2);
        obj->transform->position = Vector2f(posOfBottomLeft.x + xOffset, 
                posOfBottomLeft.y - yOffset);
        // safe space component
        SafeSpace* safeComp = new SafeSpace(obj);
        Vector2f safeSpaceSize;
        safeSpaceSize.x = texture->getSize().x;
        safeSpaceSize.y = texture->getSize().y + 200;
        safeComp->safeSpaceSize = safeSpaceSize;
        obj->addComponent(safeComp);

        return safeComp;
    }

    GameObject* PrefabManager::obstaclePrefab(string spriteLocation, Vector2f posOfBottomLeft)
    {
        GameObject* obj = new GameObject();
        // give it a sprite
        Texture* texture = new Texture();
        texture->loadFromFile(spriteLocation);
        SpriteRenderer* sprite = new SpriteRenderer(texture, obj);
        obj->addComponent(sprite);
        // set it at the given location
        float xOffset = (texture->getSize().x / 2);
        float yOffset = (texture->getSize().y / 2);
        obj->transform->position = Vector2f(posOfBottomLeft.x + xOffset,
            posOfBottomLeft.y - yOffset);
        // give it a box collider
        BoxCollider* col = new BoxCollider(texture->getSize(), obj);
        obj->addComponent(col);
        // make these obstacles floors
        obj->gameLayer = GameLayer::GROUND;

        return obj;
    }

    GameObject* PrefabManager::UITextPrefab(Vector2f position)
    {
        GameObject* UITextObj = new GameObject();
        engine->addGameObject(UITextObj);
        // add UI text comp
        Font* font = new Font();
        font->loadFromFile("./Fonts/game_over.ttf");
        UIText* UITextComp = new UIText(UITextObj, font);
        UITextObj->addComponent(UITextComp);
        // change text properties
        UITextComp->fontSize = 150;
        UITextComp->outlineThickness = 5;
        // pos
        UITextObj->transform->position = position;

        return UITextObj;
    }

}