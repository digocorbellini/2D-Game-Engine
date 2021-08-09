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
			GameObject* parent;
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
		/// Run all of the update functions in the components 
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
		Component* getComponent();
	};
}


#endif // !GAMEOBJECT_H

