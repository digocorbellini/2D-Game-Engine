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
Holds all of the files that either handle the game systems (Game loop, physics, and scene management) aswell as abstract classes used to make components and scenes.
### [./STDComp](STDComp)
Holds general components that implement features which are intented to be used in most games (BoxCollider, SpriteRenderer, etc).
### [./Scripts](Scripts)
Holds all of the code that will be used to make the game
### [./Scenes](Scenes)
Holds all of the scenes in the game


