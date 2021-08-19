#ifndef LAYERS_H
#define LAYERS_H

enum class GameLayer
{
	DEFAULT, // all gameObjects are automatically set to this
	GROUND,
	ENEMIES,
	PLAYER
};

enum class RenderingLayer
{
	BACKGROUND,
	DEFAULT, // all drawable components are automatically set to this
	UIELEMENT // all UIRenderer components are automatically set to this
};

#endif // !LAYERS_H

