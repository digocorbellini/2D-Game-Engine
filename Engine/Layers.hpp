#ifndef LAYERS_H
#define LAYERS_H

enum class GameLayer
{
	DEFAULT,
	GROUND,
	ENEMIES,
	PLAYER
};

enum class RenderingLayer
{
	DEFAULT,
	UIELEMENT // all UIRenderer components are automatically set to this
};

#endif // !LAYERS_H

