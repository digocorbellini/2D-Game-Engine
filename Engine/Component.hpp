#ifndef COMPONENT_H
#define COMPONENT_H

namespace GameEngine
{
	/// <summary>
	/// abstract class that every component should extend
	/// </summary>
	class Component
	{
	protected:
		bool enabled = true;
	public:
		bool destroyOnLoad = true;

		/// <summary>
		/// called every frame by the GameObject that has this component
		/// </summary>
		virtual void update() = 0;

		/// <summary>
		/// Called every frame after update. Used to handle physics and collisions
		/// </summary>
		virtual void lateUpdate() = 0;

		/// <summary>
		/// Set whether this component is enabled or disabled
		/// </summary>
		/// <param name="enabled"></param>
		virtual void setEnabled(bool isEnabled)
		{
			enabled = isEnabled;
		}

		/// <summary>
		/// Get whether this component is enabled or not
		/// </summary>
		/// <returns>true if this component is enabled and false otherwise</returns>
		virtual bool getEnabled()
		{
			return enabled;
		}

		/// <summary>
		/// Virtual destructor
		/// </summary>
		virtual ~Component()
		{

		}

		/// <summary>
		/// Reset this component to the status it would be at when a scene is
		/// first loaded
		/// </summary>
		virtual void resetComponent()
		{

		}
	};
}

#endif // !COMPONENT_H

