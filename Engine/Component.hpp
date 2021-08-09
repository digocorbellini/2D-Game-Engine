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
		/// <summary>
		/// called every frame by the GameObject that has this component
		/// </summary>
		virtual void update() = 0;

		/// <summary>
		/// Called every frame after update. Used to handle physics and collisions
		/// </summary>
		virtual void fixedUpdate() = 0;

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
	};
}

#endif // !COMPONENT_H

