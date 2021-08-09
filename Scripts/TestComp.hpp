#ifndef TEST_COMP_H
#define TEST_COMP_H

#include "../Engine/Component.hpp"
#include "../Engine/GameObject.hpp"
#include <iostream>
#include <math.h>

#include <SFML/Graphics.hpp>

using namespace GameEngine;
using namespace sf;
using namespace std;

class TestComp : public Component
{
private:
    GameObject* gameObject;
    Engine* engine;
public:
    int speed = 500;
    TestComp(GameObject* gameObject)
    {
        this->gameObject = gameObject;
        engine = Engine::getInstance();
    }

	void update();
};

void TestComp::update()
{
    Vector2f objPos = gameObject->transform->position;
    Vector2f objScale = gameObject->transform->scale; 
    float deltaTime = engine->getDeltaTime();
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        // move left
        objPos.x += -speed * deltaTime;
        // flip sprite to face left
        objScale.x = -abs(objScale.x);
    }
    else if (Keyboard::isKeyPressed(Keyboard::D))
    {
        // move right
        objPos.x += speed * deltaTime;
        // flip sprite to face right
        objScale.x = abs(objScale.x);
    }
    
    if (Keyboard::isKeyPressed(Keyboard::S))
    {
        // move down
        objPos.y += speed * deltaTime;
    }
    else if (Keyboard::isKeyPressed(Keyboard::W))
    {
        // move up
        objPos.y += -speed * deltaTime;
    }

    gameObject->transform->position = objPos;
    gameObject->transform->scale = objScale;

}

#endif // !TEST_COMP_H

