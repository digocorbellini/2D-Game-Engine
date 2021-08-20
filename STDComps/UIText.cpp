#include "UIText.hpp"

UIText::UIText(GameObject* gameObject, Font* font)
{
	this->gameObject = gameObject;
	this->font = font;
	color = Color::White;
	fontSize = 15;
	renderer = Renderer::getInstance();
	renderer->addToRenderQueue(this);
	window = Engine::getInstance()->getWindow();

	// make a text object
	textObj = new Text();
	textObj->setFont(*font);
	textObj->setFillColor(color);
	textObj->setCharacterSize(fontSize);
	textObj->setOrigin(Vector2f(fontSize / 2, fontSize / 2));
	textObj->setOutlineThickness(outlineThickness);

	layer = RenderingLayer::UIELEMENT;
}

UIText::~UIText()
{
	renderer->removeFromRenderQueue(this);
	delete(font);
	delete(textObj);
}

void UIText::draw()
{
	// update the text
	textObj->setCharacterSize(fontSize);
	textObj->setFillColor(color);
	textObj->setString(text);
	textObj->setOrigin(Vector2f(fontSize / 2, fontSize / 2));
	textObj->setOutlineThickness(outlineThickness);

	// set the position
	Vector2f objPos = gameObject->transform->position;
	Vector2i screenPos = Vector2i(objPos);
	Vector2f worldPos = window->mapPixelToCoords(screenPos);
	textObj->setPosition(worldPos);

	// draw the text
	window->draw(*textObj);
}

void UIText::update()
{

}

void UIText::lateUpdate()
{

}