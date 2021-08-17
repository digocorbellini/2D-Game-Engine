#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Component.hpp"
#include "DrawableComp.hpp"
#include "Layers.hpp"

using namespace std;
using namespace sf;

namespace GameEngine
{
	class GameObject
	{
		/* variables */
	private:
		vector<Component*>* componentList;
		
	public:
		string tag;
		GameLayer gameLayer;
		class ObjTransform
		{
		public:
			Vector2f position;
			Vector2f scale;
			GameObject* parent;

			ObjTransform()
			{
				position = Vector2f(0, 0);
				scale = Vector2f(1, 1);
				parent = NULL;
			}
		};

		ObjTransform* transform;

		/* functions */ 

		/// <summary>
		/// Constructor for a new GameObject
		/// </summary>
		GameObject();
		
		/// <summary>
		/// Destructor for a GameObject
		/// </summary>
		~GameObject();		

		/// <summary>
		/// Add a new component to this GameObject
		/// </summary>
		/// <param name="component">the component to be added</param>
		void addComponent(Component* component);

		/// <summary>
		/// Run all of the update and fixed update functions in the components 
		/// that this GameObject holds. Called every frame by the engine
		/// </summary>
		void runComponents();

		/// <summary>
		/// Get the first component of the given type that this GameObject holds
		/// </summary>
		/// <typeparam name="component">The type of the component</typeparam>
		/// <returns>a reference to the first component of the given type that this
		///	GameObject holds</returns>
		template <typename componentType>
		componentType* getComponent()
		{
			// find the first component of the given type
			for (int i = 0; i < componentList->size(); i++)
			{
				Component* currComp = (*componentList)[i];
				componentType* comp = dynamic_cast<componentType*>(currComp);
				if (comp != NULL)
				{
					return (componentType *)currComp;
				}
			}

			// component not found
			return NULL;
		}
	};
}


#endif // !GAMEOBJECT_H

