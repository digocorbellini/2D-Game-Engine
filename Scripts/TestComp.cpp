#include "TestComp.hpp"

#include "../Engine/SceneManager.hpp"

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

}

void TestComp::lateUpdate()
{

}