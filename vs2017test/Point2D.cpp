#include "Point2D.h"


Point2D::Point2D()
{
}


Point2D::~Point2D()
{
}

Point2D::Point2D(int x, int y)
{
	this->x = x;
	this->y = y;
}

Point2D::Point2D(Point2D* other)
{
	this->x = other->getX();
	this->y = other->getY();
}


int Point2D::getX()
{
	return x;
}


int Point2D::getY()
{
	return y;
}

void Point2D::setX(int x)
{
	this->x = x;
}

void Point2D::setY(int y)
{
	this->y = y;
}


bool Point2D::operator==(const Point2D& other)
{
	return x == other.x && y == other.y;
}

void Point2D::copy(const Point2D& other)
{
	this->x = other.x;
	this->y = other.y;
}