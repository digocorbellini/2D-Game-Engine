#ifndef TEST_COMP_H
#define TEST_COMP_H

#include "../Engine/Component.hpp"
#include "../Engine/GameObject.hpp"
#include "../STDComps/Rigidbody.hpp"
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
    Rigidbody* rb;
public:
    int speed = 500;
    TestComp(GameObject* gameObject)
    {
        this->gameObject = gameObject;
        engine = Engine::getInstance();
        rb = gameObject->getComponent<Rigidbody>();
        if (rb == NULL)
        {
            cout << "rb comp is null" << endl;
        }
    }

	void update();

    void lateUpdate();
};

void TestComp::update()
{
    Vector2f objPos = gameObject->transform->position;
    Vector2f objScale = gameObject->transform->scale; 
    float deltaTime = engine->getDeltaTime();
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        // move left
        //objPos.x += -speed * deltaTime;
        rb->velocity.x = -speed;
        // flip sprite to face left
        objScale.x = -abs(objScale.x);
    }
    else if (Keyboard::isKeyPressed(Keyboard::D))
    {
        // move right
        //objPos.x += speed * deltaTime;
        rb->velocity.x = speed;
        // flip sprite to face right
        objScale.x = abs(objScale.x);
    }
    else
    {
        rb->velocity.x = 0;
    }
    
    if (Keyboard::isKeyPressed(Keyboard::S))
    {
        // move down
        //objPos.y += speed * deltaTime;
        rb->velocity.y = speed;
    }
    else if (Keyboard::isKeyPressed(Keyboard::W))
    {
        // move up
        //objPos.y += -speed * deltaTime;
        rb->velocity.y = -speed;
    }

    gameObject->transform->position = objPos;
    gameObject->transform->scale = objScale;

    if (Keyboard::isKeyPressed(Keyboard::Tab))
    {
        cout << "X pos: " << gameObject->transform->position.x << endl;
        cout << "Y pos: " << gameObject->transform->position.y << endl;
    }

}

void TestComp::lateUpdate()
{

}

#endif // !TEST_COMP_H

