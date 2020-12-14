#include "Storage.h"

Storage::Storage(Point2D* pos,int target): Target(pos->getX(),pos->getY(),target)
{
	
	this->capacity = 100;
}

void Storage::refillHealth(Player p)
{
	p.refillHealth();
}

void Storage::refillAmmo(Player p)
{
	p.refillAmmo();
}



