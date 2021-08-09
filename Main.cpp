#include <iostream>
#include "Engine/Engine.hpp"
#include <Windows.h>
#include "STDComps/SpriteRenderer.hpp"

#include "Scripts/Test.h"
#include "Scripts/TestComp.hpp"

#define _CRTDBG_MAP_ALLOC //to get more details
#include <stdlib.h>  
#include <crtdbg.h>   //for malloc and free



using namespace GameEngine;

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

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

    GameObject* testObj = new GameObject();
    Texture marioTexture;
    marioTexture.loadFromFile("./Sprites/Mario.png");
    SpriteRenderer* renderer = new SpriteRenderer(&marioTexture, testObj);
    testObj->transform->position = Vector2f(0, 0);
    renderer->scale = Vector2f(.2, .2);
    testObj->transform->scale = Vector2f(.5, .5);
    TestComp *testComp = new TestComp(testObj);
    testObj->addComponent(testComp);
    gameEngine->addGameObject(testObj);

    Sprite thingy(marioTexture);
    thingy.setPosition(100, 100);
    RenderWindow* wind = gameEngine->getWindow();
    wind->draw(thingy);
    wind->display();


    gameEngine->startEngine();


    delete(gameEngine);

    Renderer* rend = Renderer::getInstance();
    delete(rend);
    
    delete(testObj);
    delete(testComp);
    delete(renderer);

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


