# 2D-Game-Engine
## Goal 
Make a 2D game engine using CPP and SFML and then make a small game with it

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


