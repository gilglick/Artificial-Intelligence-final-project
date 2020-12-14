#ifndef __POINT2D_H
#define __POINT2D_H

#pragma once
class Point2D
{
public:
	Point2D();
	~Point2D();
	Point2D(int x, int y);
	Point2D(Point2D* other);
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	bool operator==(const Point2D& other);
	void copy(const Point2D& other);
protected:
	int x;
	int y;
};
#endif //__POINT2D_H

