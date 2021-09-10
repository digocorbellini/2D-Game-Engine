# 2D-Game-Engine
## Goal 
Make a 2D game engine using CPP and SFML and then make a small game with it

## Design 
This game engine is loosely based on an entity component system (ECS) with an observer pattern for individual systems. GameObjects serve as the entities, and the components and the systems are combined into classes which are added to gameObjects to give them behaviours. In a typical ECS implementation, a more data oriented approach would be utilized, which would split the data aspect of a component from its implementation in a system, however, I went for a more object oriented approach since I felt that it allowed the user of the engine to implement new features in a more intuative manner. The components have to individually subscribe to different overarching systems, such as the rendering system and the physics system, in order to get their behaviours executed. The behaviour of the systems are still implemented within the components, but they are executed by the overarching systems to which they subscribe to. Althuogh more is required within a component, I felt as though it helped reduce the number of components that needed to be iterated through wihtin each system.

Such an object oriented approach to an ECS does bring more overhead to the engine, but I felt as though Unity's approach of letting users implement behaviours through monobehaviour scripts was very intuative and my engine aims to emulate such an experience. 

## Features
- [x] GameObjects
- [x] Components
- [x] Rendering Layers and order in layers
- [x] Gizmos
- [x] Collisions
- [x] Physics (Gravity and object velocity)
- [x] Scenes
- [x] Prefabs
- [ ] Parenting
- [ ] Sound
- [ ] Animation

## Project stucture
### [./Engine](Engine)
Holds all of the files that either handle the game systems (Game loop, physics, and scene management) as well as abstract classes used to make components and scenes.
### [./STDComp](STDComps)
Holds general components that implement features which are intented to be used in most games (BoxCollider, SpriteRenderer, etc).
### [./Scripts](Scripts)
Holds all of the code that will be used to make the game
### [./Scenes](Scenes)
Holds all of the scenes in the game

## Game
[Bug Rush](https://digocorbellini.itch.io/bug-rush)

You are a hungry cockroach that has spotted a half eaten donut on the other side of the kitchen table that looks prefect for the taking! However, the owner of the house is out for you! Every time they walk into the kitchen and switch on the lights, you're in danger! 

Cross the kitchen table while avoiding enemy bugs and hiding from the lights behind objects in order to reach the sugary delight!


