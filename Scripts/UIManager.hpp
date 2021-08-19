#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include "../Engine/Component.hpp";
#include "../Engine/GameObject.hpp"
#include <vector>

using namespace std;
using namespace GameEngine;

class UIManager : public Component
{
	/* variables */
public:
	vector<GameObject*>* heartUIObjs;

private:
	static UIManager* instance; // make this class a singleton
	GameObject* gameObject;
	int health;

	/* methods */
	UIManager();

public:
	/// <summary>
	/// Gets the instance of this singleton class
	/// </summary>
	/// <returns>The instance of this signleton class</returns>
	static UIManager* getInstance()
	{
		if (instance == NULL)
		{
			instance = new UIManager();
		}
		return instance;
	}

	/// <summary>
	/// A destructor for a UIManager Object
	/// </summary>
	~UIManager();

	/// <summary>
	/// Add a gameObject to this component
	/// </summary>
	/// <param name="gameObject">the gameObject that his component is attached to</param>
	void addGameObject(GameObject* gameObject);

	/// <summary>
	/// called every frame by the GameObject that has this component
	/// </summary>
	void update();

	/// <summary>
	/// Called every frame after update. Used to handle physics and collisions
	/// </summary>
	void lateUpdate();

	/// <summary>
	/// Update the heart UI to represent the given health
	/// </summary>
	/// <param name="health">The health of the player</param>
	void updateHeartUI(int health);

private:
	/// <summary>
	/// Clamp the given value between the given min and max values
	/// </summary>
	/// <param name="val">the value to be clamped</param>
	/// <param name="min">the minimum value that the given value can be</param>
	/// <param name="max">the maximum value that the given value can be</param>
	/// <returns></returns>
	int clamp(int val, int min, int max);
};


#endif // !UI_MANAGER_H

