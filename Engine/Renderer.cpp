#include "Renderer.hpp"

namespace GameEngine
{
	// make sure Renderer is initialized as NULL
	Renderer* Renderer::instance = NULL;

	Renderer::Renderer()
	{
		renderQueue = new vector<DrawableComp*>();
		gizmos = new vector<Shape*>();
		window = NULL;
	}

	void Renderer::setWindow(RenderWindow* window)
	{
		this->window = window;
	}

	RenderWindow* Renderer::getWindow()
	{
		return window;
	}

	Renderer::~Renderer()
	{
		delete(renderQueue);
		delete(gizmos);
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
		// sort queue in ascending order first
		std::sort(renderQueue->begin(), renderQueue->end(), customLess);

		// run all of the draw functions on the render queue
		for (int i = 0; i < renderQueue->size(); i++)
		{
			DrawableComp* currComp = (*renderQueue)[i];
			// only draw if the component is enabled
			if(currComp->getEnabled())
				currComp->draw();
		}

		// draw gizmos if gizmos are on
		if(gizmosOn)
			drawGizmos();
	}

	void Renderer::drawGizmos()
	{
		// only attempt to draw all gizmos if window is not null
		if (window == NULL)
		{
			return;
		}

		// draw all gizmos
		for (int i = 0; i < gizmos->size(); i++)
		{
			Shape* currShape = (*gizmos)[i];
			window->draw(*currShape);
		}
	}

	void Renderer::addGizmo(Shape* gizmoShape)
	{
		gizmos->push_back(gizmoShape);
	}

	bool Renderer::removeGizmo(Shape* gizmoShape)
	{
		// find the gizmo
		int pos = 0;
		for (pos = 0; pos < gizmos->size(); pos++)
		{
			Shape* currShape = (*gizmos)[pos];
			if (gizmoShape == currShape)
			{
				break;
			}
		}

		// if the gizmo was found then remove it
		if (pos < gizmos->size())
		{
			gizmos->erase(gizmos->begin() + pos);
			return true;
		}

		// gizmo was not found
		return false;
	}
}