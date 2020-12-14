#ifndef __STORAGE_H
#define __STORAGE_H

#pragma once

#include "Player.h"

class Storage : public Target
{
public:
	Storage(Point2D* pos, int target);
	void refillHealth(Player p);
	void refillAmmo(Player p);

private:

	int capacity;
};
#endif //__STORAGE_H
