#include <iostream>
#include "Engine/Engine.hpp"
#include "Engine/Renderer.hpp"
#include "Engine/Physics.hpp"
#include <Windows.h>

#include "Scenes/MainScene.hpp"

// for checking for memory leaks
#define _CRTDBG_MAP_ALLOC //to get more details
#include <stdlib.h>  
#include <crtdbg.h>   //for malloc and free



using namespace GameEngine;

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;
const bool gizmosOn = false;

Engine* engine;
Renderer* renderer;
Physics* physics;
SceneManager* sceneManager;

//void loadScene1();

int main()
{
    // check for memory leaks
    //_CrtMemState sOld;
    //_CrtMemState sNew;
    //_CrtMemState sDiff;
    //_CrtMemCheckpoint(&sOld); //take a snapchot

    // hide console window
    //::ShowWindow(::GetConsoleWindow(), SW_HIDE);
    
    // create game engine
    engine = Engine::getInstance();
    engine->setWindowDimensions(Vector2u(SCREEN_WIDTH, SCREEN_HEIGHT));

    // set gizmos
    renderer = Renderer::getInstance();
    renderer->gizmosOn = gizmosOn;

    // get the physics engine
    physics = Physics::getInstance();

    // get sceneManager
    sceneManager = SceneManager::getInstance();

    // make scenes and add them to scene manager
    MainScene* mainScene = new MainScene("main scene");
    sceneManager->addScene(mainScene);
    
    // load scene
    sceneManager->loadScene("main scene");
    //loadScene1();

    // start the game
    engine->startEngine();

    delete(engine);
    delete(renderer);

    delete(mainScene);



    // check for memory leaks
    //_CrtMemCheckpoint(&sNew); //take a snapchot 
    //if (_CrtMemDifference(&sDiff, &sOld, &sNew)) // if there is a difference
    //{
    //    /*OutputDebugString(L"-----------_CrtMemDumpStatistics ---------");
    //    _CrtMemDumpStatistics(&sDiff);
    //    OutputDebugString(L"-----------_CrtMemDumpAllObjectsSince ---------");
    //    _CrtMemDumpAllObjectsSince(&sOld);*/
    //    OutputDebugString(L"-----------_CrtDumpMemoryLeaks ---------");
    //    _CrtDumpMemoryLeaks();
    //}
    //else
    //{
    //    cout << "No memory leaks" << endl;
    //}

    //cout << "END OF PROGRAM" << endl;

    return 0;
}

//void loadScene1()
//{
//    // create object
//    GameObject* mario = new GameObject();
//    // get texture
//    Texture *marioTexture = new Texture();
//    marioTexture->loadFromFile("./Sprites/Mario.png");
//    // create sprite marioRend component
//    SpriteRenderer* marioRend = new SpriteRenderer(marioTexture, mario);
//    // set obj and component values
//    mario->transform->position = Vector2f(100, 800);
//    //marioRend->scale = Vector2f(.2, .2);
//    mario->transform->scale = Vector2f(.1, .1);
//    // add collider to mario and gravity
//    BoxCollider* testCol = new BoxCollider(marioTexture->getSize(), mario);
//    //Rigidbody* gravityComp = new Rigidbody(mario);
//    //mario->addComponent(gravityComp);
//    mario->addComponent(testCol);
//    // make another component
//    //TestComp* testComp = new TestComp(mario);
//    // add components
//    mario->addComponent(marioRend);
//    // mario->addComponent(testComp);
//    // add obj to game engine
//    engine->addGameObject(mario);
//
//
//    /* ========= Player Object ========= */
//    GameObject* player = new GameObject();
//    engine->addGameObject(player);
//    // rigidbody comp
//    Rigidbody* playerRB = new Rigidbody(player);
//    player->addComponent(playerRB);
//    // sprite renderer comp
//    Texture* playerTexture = new Texture();
//    playerTexture->loadFromFile("./Sprites/Mario.png");
//    SpriteRenderer* playerRend = new SpriteRenderer(playerTexture, player);
//    player->addComponent(playerRend);
//    player->transform->scale = Vector2f(.1, .1);
//    // collider component
//    BoxCollider* playerCol = new BoxCollider(playerTexture->getSize(), player);
//    player->addComponent(playerCol);
//    // controller comp
//    PlayerController* playerCtlr = new PlayerController(player, Vector2f(100, 100));
//    player->addComponent(playerCtlr);
//
//
//
//    // bob
//    GameObject* bob = new GameObject();
//    bob->transform->position = Vector2f(500, 500);
//    bob->tag = "bob";
//    Texture* bobTexture = new Texture();
//    bobTexture->loadFromFile("./Sprites/bob.png");
//    SpriteRenderer* bobRend = new SpriteRenderer(bobTexture, bob);
//    BoxCollider* bobCol = new BoxCollider(bobTexture->getSize(), bob);
//    bob->addComponent(bobRend);
//    bob->addComponent(bobCol);
//    engine->addGameObject(bob);
//
//
//    /* ========== Camera =========== */
//    GameObject* cameraObj = new GameObject();
//    engine->addGameObject(cameraObj);
//    // camera comp
//    Camera* cameraComp = new Camera(FloatRect(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 1280, 720), cameraObj);
//    cameraObj->addComponent(cameraComp);
//    // cam controller
//    CameraController* camCtrl = new CameraController(cameraObj, player->transform,
//        10, 0.5);
//    cameraObj->addComponent(camCtrl);
//
//
//    // test floor
//    GameObject* floor = new GameObject();
//    engine->addGameObject(floor);
//    floor->transform->position = Vector2f(0, 1000);
//    BoxCollider* floorCol = new BoxCollider(Vector2u(100000, 10), floor);
//    floor->addComponent(floorCol);
//}


