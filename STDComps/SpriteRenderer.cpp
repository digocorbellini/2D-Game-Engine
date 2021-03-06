#include "SpriteRenderer.hpp"

SpriteRenderer::SpriteRenderer(Texture* spriteTexture, GameObject* gameObject)
{
	scale = Vector2f(1, 1);
	color = Color::White;
	// set texture
	sprite = new Sprite();
	sprite->setTexture(*spriteTexture);
	// set the origin of the sprite to the center
	sprite->setOrigin(spriteTexture->getSize().x / 2, spriteTexture->getSize().y / 2);

	this->gameObject = gameObject;

	renderer = Renderer::getInstance();
	renderer->addToRenderQueue(this);

	window = Engine::getInstance()->getWindow();

	texture = spriteTexture;

	layer = RenderingLayer::DEFAULT;
}

SpriteRenderer::~SpriteRenderer()
{
	renderer->removeFromRenderQueue(this);
	delete(sprite);
	delete(texture);
}

void SpriteRenderer::draw()
{
	sprite->setPosition(gameObject->transform->position);
	sprite->setColor(color);
	Vector2f objScale = gameObject->transform->scale;
	Vector2f newScale(objScale.x * scale.x, objScale.y * scale.y);
	sprite->setScale(newScale);
	window->draw(*sprite);
}

void SpriteRenderer::update()
{

}

void SpriteRenderer::lateUpdate()
{

}