#include "TestComp.hpp"

#include "../Engine/SceneManager.hpp"
#include "UIManager.hpp"

void TestComp::update()
{
    // Reset scene
    if (Keyboard::isKeyPressed(Keyboard::Tab))
    {
        // reaload same scene
        SceneManager* man = SceneManager::getInstance();
        man->loadScene(man->getActiveScene()->sceneName);
    }
       
    // end game
    if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
        engine->quit();
    }

    //if (Keyboard::isKeyPressed(Keyboard::Escape))
    //{
    //    engine->clearGameObjectList();
    //}
    //Event e = engine->getEvent();
    //if (e.type == Event::KeyPressed && e.key.code == Keyboard::Tilde)
    //{
    //    //UIManager::getInstance()->updateHeartUI(--health);
    //    playerController->damagePlayer(1);
    //}

    //if (e.type == Event::KeyPressed && e.key.code == Keyboard::Num1)
    //{
    //    //UIManager::getInstance()->updateHeartUI(++health);
    //    playerController->damagePlayer(-1);
    //}

    //if (e.type == Event::MouseButtonPressed && e.mouseButton.button == Mouse::Button::Left)
    //{
    //    // print position of the mouse
    //    RenderWindow* window = engine->getWindow();
    //    Vector2i mouseScreenPos = Mouse::getPosition(*window);
    //    Vector2f mouseWorldPos = window->mapPixelToCoords(mouseScreenPos);
    //    cout << "x: " << mouseWorldPos.x << endl;
    //    cout << "y: " << mouseWorldPos.y << endl;

    //}

    //if (health < 0)
    //{
    //    health = 0;
    //}
    //else if (health > 3)
    //{
    //    health = 3;
    //}

}

void TestComp::lateUpdate()
{

}