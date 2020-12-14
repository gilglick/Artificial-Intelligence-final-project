#ifndef __TARGET_H
#define __TARGET_H


#include "Point2D.h"
#pragma once
 class Target: public Point2D
{
public:
	Target();
	Target(int x, int y,int target);
	int getTarget();
private:
	int target;
};

#endif // !__TARGET_H