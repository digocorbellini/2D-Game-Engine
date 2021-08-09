#include <iostream>
#include "Engine.hpp"
#include <Windows.h>

#include "Scripts/Test.h"

using namespace GameEngine;

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

int main()
{
    // hide console window
    //::ShowWindow(::GetConsoleWindow(), SW_HIDE);
    
    // create game engine
    Engine* gameEngine = Engine::getInstance();
    gameEngine->setWindowDimensions(Vector2u(SCREEN_WIDTH, SCREEN_HEIGHT));
    gameEngine->startEngine();

   

    delete(gameEngine);
    std::cout << "Hello World!\n";
}


