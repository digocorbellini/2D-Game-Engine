#include <iostream>
#include "Engine/Engine.hpp"
#include <Windows.h>
#include "STDComps/SpriteRenderer.hpp"
#include "STDComps/BoxCollider.hpp"
#include "STDComps/Camera.hpp"
#include "Scripts/CameraController.hpp"
#include "STDComps/Rigidbody.hpp"

#include "Scripts/Test.h"
#include "Scripts/TestComp.hpp"

// for checking for memory leaks
#define _CRTDBG_MAP_ALLOC //to get more details
#include <stdlib.h>  
#include <crtdbg.h>   //for malloc and free



using namespace GameEngine;

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;
const bool gizmosOn = true;

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
    Engine* gameEngine = Engine::getInstance();
    gameEngine->setWindowDimensions(Vector2u(SCREEN_WIDTH, SCREEN_HEIGHT));

    // set gizmos
    Renderer* rend = Renderer::getInstance();
    rend->gizmosOn = gizmosOn;

    // create object
    GameObject* mario = new GameObject();
    // get texture
    Texture marioTexture;
    marioTexture.loadFromFile("./Sprites/Mario.png");
    // create sprite marioRend component
    SpriteRenderer* marioRend = new SpriteRenderer(&marioTexture, mario);
    // set obj and component values
    mario->transform->position = Vector2f(100, 800);
    //marioRend->scale = Vector2f(.2, .2);
    mario->transform->scale = Vector2f(.1, .1);
    // add collider to mario and gravity
    BoxCollider* testCol = new BoxCollider(marioTexture.getSize(), mario);
    Rigidbody gravityComp(mario);
    mario->addComponent(&gravityComp);
    mario->addComponent(testCol);
    // make another component
    TestComp *testComp = new TestComp(mario);
    // add components
    mario->addComponent(marioRend);
    mario->addComponent(testComp);
    // add obj to game engine
    gameEngine->addGameObject(mario);


    // bob
    GameObject* bob = new GameObject();
    bob->transform->position = Vector2f(500, 500);
    bob->tag = "bob";
    Texture bobTexture;
    bobTexture.loadFromFile("./Sprites/bob.png");
    SpriteRenderer* bobRend = new SpriteRenderer(&bobTexture, bob);
    BoxCollider* bobCol = new BoxCollider(bobTexture.getSize(), bob);
    bob->addComponent(bobRend);
    bob->addComponent(bobCol);
    gameEngine->addGameObject(bob);

    // implement the camera
    GameObject* cameraObj = new GameObject();
    gameEngine->addGameObject(cameraObj);
    Camera* cameraComp = new Camera(FloatRect(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 1280, 720), cameraObj);
    cameraObj->addComponent(cameraComp);
    CameraController* camCtrl = new CameraController(cameraObj, mario->transform, 
            10, 0.5);
    cameraObj->addComponent(camCtrl);


    // test floor
    GameObject floor;
    gameEngine->addGameObject(&floor);
    floor.transform->position = Vector2f(0, 1000);
    BoxCollider floorCol(Vector2u(100000, 10), &floor);
    floor.addComponent(&floorCol);



    // start the game
    gameEngine->startEngine();



    delete(rend);
    
    delete(mario);
    delete(testComp);
    delete(marioRend);

    delete(cameraObj);

    delete(gameEngine);


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


