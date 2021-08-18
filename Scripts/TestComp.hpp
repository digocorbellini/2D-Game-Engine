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
public:
    int speed = 500;
    TestComp(GameObject* gameObject)
    {
        this->gameObject = gameObject;
        engine = Engine::getInstance();
    }

	void update();

    void lateUpdate();
};

#endif // !TEST_COMP_H

