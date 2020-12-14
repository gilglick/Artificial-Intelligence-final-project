#include "Target.h"

Target::Target()
{
}

Target::Target(int x, int y, int target):Point2D(x,y)
{
	this->target = target;
}

int Target::getTarget()
{
	return target;
}
