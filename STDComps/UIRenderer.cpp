#include "UIRenderer.hpp"

UIRenderer::UIRenderer(GameObject* gameObject, Texture* spriteTexture)
{
	scale = Vector2f(1, 1);
	color = Color::White;
	// set texture
	texture = spriteTexture;
	sprite = new Sprite();
	sprite->setTexture(*spriteTexture);
	// center sprite origin
	sprite->setOrigin(spriteTexture->getSize().x / 2, spriteTexture->getSize().y / 2);
	this->gameObject = gameObject;
	renderer = Renderer::getInstance();
	renderer->addToRenderQueue(this);

	window = Engine::getInstance()->getWindow();

	layer = RenderingLayer::UIELEMENT;
}

UIRenderer::~UIRenderer()
{
	renderer->removeFromRenderQueue(this);
	delete(sprite);
	delete(texture);
}

void UIRenderer::draw()
{
	sprite->setColor(color);

	// update sprite scale according to player scale
	Vector2f objScale = gameObject->transform->scale;
	Vector2f newScale(objScale.x * scale.x, objScale.y * scale.y);
	sprite->setScale(newScale);
	sprite->setOrigin(texture->getSize().x / 2, texture->getSize().y / 2);

	// convert the game object position to a static screen position
	Vector2f objPos = gameObject->transform->position;
	Vector2i screenPos = Vector2i((int)objPos.x, (int)objPos.y);
	Vector2f worldPos = window->mapPixelToCoords(screenPos);
	sprite->setPosition(worldPos);

	// draw sprite
	window->draw(*sprite);
}

void UIRenderer::update()
{

}

void UIRenderer::lateUpdate()
{

}