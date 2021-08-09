#include "Renderer.hpp"

namespace GameEngine
{
	// make sure Renderer is initialized as NULL
	Renderer* Renderer::instance = NULL;

	Renderer::Renderer()
	{
		renderQueue = new vector<DrawableComp*>();
	}

	Renderer::~Renderer()
	{
		delete(renderQueue);
	}

	void Renderer::addToRenderQueue(DrawableComp* comp)
	{
		renderQueue->push_back(comp);
	}

	bool Renderer::removeFromRenderQueue(DrawableComp* comp)
	{
		// find the drawable component
		int pos = 0;
		for (pos = 0; pos < renderQueue->size(); pos++)
		{
			DrawableComp* currComp = (*renderQueue)[pos];
			if (comp == currComp)
			{
				break;
			}
		}

		// if the drawable component was found then remove it
		if (pos < renderQueue->size())
		{
			renderQueue->erase(renderQueue->begin() + pos);
			return true;
		}

		// drawable component was not found
		return false;
	}

	void Renderer::render()
	{
		// later also sort by rendering layer

		// sort queue in ascending order first
		std::sort(renderQueue->begin(), renderQueue->end());

		// run all of the draw functions on the render queue
		for (int i = 0; i < renderQueue->size(); i++)
		{
			DrawableComp* currComp = (*renderQueue)[i];
			currComp->draw();
		}
	}
}