#include "Point2D_hg.h"


Point2D_hg::Point2D_hg()
{
}


Point2D_hg::~Point2D_hg()
{

}


Point2D_hg::Point2D_hg(Point2D& myPos, Point2D& targetPoint)
{
	point = myPos;
	h = abs(point.getX() - targetPoint.getX()) + abs(point.getY() - targetPoint.getY());// Manhattan Distance
	g = 0;
	f = h + g;
	parent = NULL;
}


Point2D_hg::Point2D_hg(Point2D_hg* parent, Point2D& myPos, Point2D& targetPoint, int newG)
{
	point = myPos;
	h = (abs(point.getX() - targetPoint.getX()) + abs(point.getY() - targetPoint.getY())) * A_STAR_WEIGHT;// Manhattan Distance
	g = newG;
	this->parent = parent;
	f = h + g;
}


Point2D Point2D_hg::getPoint()
{
	return point;
}

int Point2D_hg::getH()
{
	return h;
}

int Point2D_hg::getG()
{
	return g;
}

int Point2D_hg::getF()
{
	return f;
}

Point2D_hg* Point2D_hg::getParent()
{
	return parent;
}

bool Point2D_hg::operator==(const Point2D_hg& other)
{
	return point == other.point;
}