#include <iostream>
#include "Engine/Engine.hpp"
#include <Windows.h>
#include "STDComps/SpriteRenderer.hpp"
#include "STDComps/BoxCollider.hpp"
#include "STDComps/Camera.hpp"
#include "Scripts/CameraController.hpp"

#include "Scripts/Test.h"
#include "Scripts/TestComp.hpp"

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
    GameObject* testObj = new GameObject();
    // get texture
    Texture marioTexture;
    marioTexture.loadFromFile("./Sprites/Mario.png");
    // create sprite renderer component
    SpriteRenderer* renderer = new SpriteRenderer(&marioTexture, testObj);
    // set obj and component values
    testObj->transform->position = Vector2f(100, 800);
    //renderer->scale = Vector2f(.2, .2);
    testObj->transform->scale = Vector2f(.2, .2);
    // make another component
    TestComp *testComp = new TestComp(testObj);
    // add components
    testObj->addComponent(renderer);
    testObj->addComponent(testComp);
    // add obj to game engine
    gameEngine->addGameObject(testObj);

    // add collider to testObj
    BoxCollider* testCol = new BoxCollider(marioTexture.getSize(), testObj);
    testObj->addComponent(testCol);

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

    GameObject* cameraObj = new GameObject();
    gameEngine->addGameObject(cameraObj);
    Camera* cameraComp = new Camera(FloatRect(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 1280, 720), cameraObj);
    cameraObj->addComponent(cameraComp);
    CameraController* camCtrl = new CameraController(cameraObj, testObj->transform, 
            10, 0.5);
    cameraObj->addComponent(camCtrl);


    // start the game
    gameEngine->startEngine();



    delete(rend);
    
    delete(testObj);
    delete(testComp);
    delete(renderer);

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


