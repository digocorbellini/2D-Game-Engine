#include "Health.hpp"

Health::Health(int maxHearts)
{
	numOfHearts = maxHearts;
	this->maxHearts = maxHearts;
}

void Health::addHealth(int amountOfHearts)
{
	numOfHearts = clamp(numOfHearts + amountOfHearts, 0, maxHearts);
}

int Health::getHealth()
{
	return numOfHearts;
}

int Health::clamp(int val, int min, int max)
{
	if (val <= min)
	{
		return min;
	}
	else if (val <= max)
	{
		return val;
	}
	else
	{
		return max;
	}
}