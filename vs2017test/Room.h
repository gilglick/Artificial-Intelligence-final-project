#ifndef __ROOM_H
#define __ROOM_H

#pragma once
#include <math.h>
#include "Const.h"
#include <vector>
#include "Point2D.h"
#include "Player.h"

class Room
{
private:
	int cx, cy, width, height,myIndex;
	std::vector<Point2D> objects;
	std::vector<Target*> targets;
	
   
public:
	Room();
	Room(int row, int col, int w, int h,int index);
	void SetCenterX(int col);
	void SetCenterY(int row);
	void SetWidth(int w);
	void SetHeight(int h);
	void SetObjects(std::vector<Point2D> o);
	void SetMyIndex(int index);

	int GetCenterX();
	int GetCenterY();
	int GetWidth();
	int GetHeight();
	std::vector<Point2D> GetObjects();
	void addTarget(Target* t);
	bool ramoveTarget(Target* t);
	bool containsTarget(Target t);
	Point2D* aStar(int m[MSZ][MSZ], Player* p, Point2D* t);
	void Init(int m[MSZ][MSZ],int roomsMat[MSZ][MSZ]);
	bool Overlap(int w, int h, int cx, int cy);


};

#endif // __ROOM_H