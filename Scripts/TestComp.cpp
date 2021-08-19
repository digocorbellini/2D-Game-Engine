#include "TestComp.hpp"

#include "../Engine/SceneManager.hpp"
#include "UIManager.hpp"

void TestComp::update()
{
    if (Keyboard::isKeyPressed(Keyboard::Tab))
    {
        // reaload same scene
        SceneManager* man = SceneManager::getInstance();
        man->loadScene(man->getActiveScene()->sceneName);
    }

    if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
        engine->clearGameObjectList();
    }
    Event e = engine->getEvent();
    if (e.type == Event::KeyPressed && e.key.code == Keyboard::Tilde)
    {
        //UIManager::getInstance()->updateHeartUI(--health);
        playerController->health->addHealth(-1);
    }

    if (e.type == Event::KeyPressed && e.key.code == Keyboard::Num1)
    {
        //UIManager::getInstance()->updateHeartUI(++health);
        playerController->health->addHealth(1);
    }

    if (health < 0)
    {
        health = 0;
    }
    else if (health > 3)
    {
        health = 3;
    }

}

void TestComp::lateUpdate()
{

}