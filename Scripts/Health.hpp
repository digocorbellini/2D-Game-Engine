#ifndef HEALTH_H
#define HEALTH_H

/// <summary>
/// Heart based health system
/// </summary>
class Health
{
	/* variables */
private:
	int numOfHearts;
	int maxHearts;

	/* methods */
	/// <summary>
	/// Clamp the given value between the given min and max values
	/// </summary>
	/// <param name="val">the value to be clamped</param>
	/// <param name="min">the minimum value that the given value can be</param>
	/// <param name="max">the maximum value that the given value can be</param>
	/// <returns></returns>
	int clamp(int val, int min, int max);
public:
	/// <summary>
	/// Constructor for a new Health object
	/// </summary>
	/// <param name="maxHealth">the max amount of health</param>
	Health(int maxHearts);

	/// <summary>
	/// Add the given amount of hearts to the health
	/// </summary>
	/// <param name="amount">The amount of hearts to add to health</param>
	void addHealth(int amountOfhearts);

	/// <summary>
	/// Get the number of hearts
	/// </summary>
	/// <returns>the number of hearts</returns>
	int getHealth();

};

#endif // !HEALTH_H

