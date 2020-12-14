#include "Room.h"

Room::Room()
{
	cy = MSZ/2;
	cx = MSZ / 2;
	width = MSZ / 2;
	height = MSZ / 2;

}

Room::Room(int row, int col, int w, int h,int index)
{
	myIndex = index;
	cy = row;
	cx = col;
	width = w;
	height = h;
}

void Room::SetCenterX(int col)
{
	cx = col;
}

void Room::SetCenterY(int row)
{
	cy = row;
}

void Room::SetWidth(int w)
{
	width = w;
}

void Room::SetHeight(int h)
{
	height = h;
}

void Room::SetObjects(std::vector<Point2D> o)
{
	objects = o;
}

void Room::SetMyIndex(int index)
{
	this->myIndex = index;
}

int Room::GetCenterX()
{
	return cx;
}

int Room::GetCenterY()
{
	return cy;
}

int Room::GetWidth()
{
	return width;
}

int Room::GetHeight()
{
	return height;
}

std::vector<Point2D> Room::GetObjects()
{
	return this->objects;
}

void Room::addTarget(Target* t)
{
	targets.push_back(t);
}

bool Room::ramoveTarget(Target* t)
{
	for (auto it = targets.begin(); it != targets.end(); ++it)
	{
		Target* target = *it;
		if (t == target)
		{
			targets.erase(it);
			return true;
		}
	}
	return false;
}

bool Room::containsTarget(Target t)
{
	for (auto it = targets.begin(); it != targets.end(); ++it)
	{
		Target* target = *it;
		if (t == target)
			return true;
	}
	return false;
}

Point2D* Room::aStar(int m[MSZ][MSZ], Player* p, Point2D* t)
{
	Point2D* init = new Point2D(p->getX(), p->getY());
	Point2D* temp,lastTemp;
	double** securityMap= (double**)malloc(sizeof(double*)*MSZ);
	for (int i = 0; i < MSZ; i++)
	{
		securityMap[i] = (double*)calloc(MSZ, sizeof(double));
	}
	std::list<Player*> opponnentTeam = p->getOpponnentsTeam();
	for (std::list<Player*>::iterator it = opponnentTeam.begin(); it != opponnentTeam.end(); ++it)
	{
		Target temp = **it;
		Player* i = *it;
		if (this->containsTarget(temp))
			i->simulateShoot(m,securityMap);
	}
	AStar* roomA = new AStar(init);
	bool ans=roomA->run(Point2D(t->getX(), t->getY()), m, securityMap ,-1);
	if (ans)
	{
		
		return roomA->getTop();//needs to be checked
	}
}



void Room::Init(int m[MSZ][MSZ], int roomsMat[MSZ][MSZ])
{
	int i, j;

	for (i = cy - height / 2; i <= cy + height / 2; i++)
		for (j = cx - width / 2; j <= cx + width / 2; j++)
		{
			m[i][j] = SPACE;
			roomsMat[i][j] = myIndex;
		}
}

bool Room::Overlap(int w, int h, int cx, int cy)
{
	int hdist, vdist; // distance between center of rooms

	hdist = abs(cx - this->cx);
	vdist = abs(cy - this->cy);

	// if both horizontal distance between two rooms centers is below sum of these rooms half widths
	// and vertical distance between two rooms centers is below sum of these rooms half heights
	// then they overlap. otherwise they do not.
	return this->width/2+w/2>hdist-4 && vdist-4<this->height/2+h/2;
}
