#pragma once
#include "Point2D_hg.h"

class ComparePoints
{
public:
	ComparePoints();
	~ComparePoints();

	bool operator () (Point2D_hg& p1, Point2D_hg& p2)
	{
		return p1.getF() > p2.getF();
	}
};


