#ifndef COMPONENT_H
#define COMPONENT_H

namespace GameEngine
{
	/// <summary>
	/// abstract class that every component should extend
	/// </summary>
	class Component
	{
	public:
		bool enabled;

		/// <summary>
		/// called every frame by the GameObject that has this component
		/// </summary>
		virtual void update() = 0;

		void setEnabled(bool enabled)
		{
			this->enabled = enabled;
		}
	};
}

#endif // !COMPONENT_H

