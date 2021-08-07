#include <iostream>
#include "GameObject.hpp"
#include <vector>

using namespace GameEngine;

// add all game objects in the game to this list
vector<GameObject*> *gameObjectList;

int main()
{
    gameObjectList = new vector<GameObject*>();



    std::cout << "Hello World!\n";
}


