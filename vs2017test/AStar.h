#ifndef __ASTAR_H
#define __ASTAR_H

#pragma once

#include "Const.h"
#include "Point2D.h"
#include "Point2D_hg.h"
#include "ComparePoints.h"
#include <vector>
#include <queue>
#include <list>

class AStar
{
public:
	AStar(Point2D*& pos);
	~AStar();
	bool run(Point2D targetPoint,  int maze[MSZ][MSZ], double** securityMap,int maxG = -1);
	Point2D* getTop();
	Point2D* getButtom();
	int getLen();
private:
	std::list<Point2D_hg> solution;
	Point2D* last;
	Point2D* pos;
	Point2D lastPos;
	int getColor(Point2D* point,int maze[MSZ][MSZ]);
	int maze[MSZ][MSZ];
};
#endif //__ASTAR_H