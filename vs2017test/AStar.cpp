#include "AStar.h"
using namespace std;



AStar::AStar(Point2D*& pos)
{
	this->last = NULL;
	this->pos = pos;
	this->lastPos = Point2D(*pos);
}


AStar::~AStar()
{
	delete last;
}

int AStar::getColor(Point2D* point,int maze[MSZ][MSZ]) {
	return maze[point->getY()][point->getX()];
}

bool AStar::run(Point2D targetPoint,int maze[MSZ][MSZ],double **securityMap,int maxG) {
	if (maxG == -1 && getColor(&targetPoint,maze) == WALL)
		return false;
	if (last != NULL)
	{
		if (targetPoint == *last && *pos == lastPos)
			return true;
		delete last;
		solution.clear();
	}
	last = new Point2D(targetPoint);
	Point2D_hg bestPoint;
	priority_queue <Point2D_hg, vector <Point2D_hg>, ComparePoints> pq;
	vector <Point2D_hg> black;
	vector <Point2D_hg> gray;
	bestPoint = Point2D_hg(*pos, targetPoint);
	pq.emplace(bestPoint);
	gray.push_back(bestPoint);
	Point2D_hg* bestPointAsParent, neighborPos_hg;
	Point2D bestPointPos, neighborPos;
	vector<Point2D_hg>::iterator black_iterator;
	vector<Point2D_hg>::iterator gray_iterator;
	do {
		if (pq.empty())
			return false;
		bestPoint = pq.top();
		pq.pop();
		gray_iterator = find(gray.begin(), gray.end(), bestPoint);
		gray.erase(gray_iterator);
		black.push_back(bestPoint);
		bestPointAsParent = new Point2D_hg(bestPoint);
		bestPointPos = bestPointAsParent->getPoint();
		if (bestPointPos == targetPoint || maxG == bestPoint.getG()) {
			while (bestPointAsParent->getParent() != NULL)
			{
				solution.push_back(*bestPointAsParent);
				bestPointAsParent = bestPointAsParent->getParent();
			}
			return true;
		}
		double randomWeight= ((double)rand() / (RAND_MAX)) * ALPHA;
		
		neighborPos = Point2D(bestPointPos.getX() + 1, bestPointPos.getY());
		if (getColor(&neighborPos,maze) == SPACE|| getColor(&neighborPos,maze)== getColor(&targetPoint,maze)) {
			int g = bestPointAsParent->getG() + securityMap[neighborPos.getY()][neighborPos.getX()] * randomWeight;
			neighborPos_hg = Point2D_hg(bestPointAsParent, neighborPos, targetPoint,g);
			black_iterator = find(black.begin(), black.end(), neighborPos_hg);
			gray_iterator = find(gray.begin(), gray.end(), neighborPos_hg);
			if (black_iterator == black.end() && gray_iterator == gray.end())
			{
				pq.emplace(neighborPos_hg);
				gray.push_back(neighborPos_hg);
			}
		}

		neighborPos = Point2D(bestPointPos.getX() - 1, bestPointPos.getY());
		if (getColor(&neighborPos, maze) == SPACE || getColor(&neighborPos, maze) == getColor(&targetPoint, maze)) {
			int g = bestPointAsParent->getG() + securityMap[neighborPos.getY()][neighborPos.getX()] * randomWeight;
			neighborPos_hg = Point2D_hg(bestPointAsParent, neighborPos, targetPoint, g);
			black_iterator = find(black.begin(), black.end(), neighborPos_hg);
			gray_iterator = find(gray.begin(), gray.end(), neighborPos_hg);
			if (black_iterator == black.end() && gray_iterator == gray.end())
			{
				pq.emplace(neighborPos_hg);
				gray.push_back(neighborPos_hg);
			}
		}

		neighborPos = Point2D(bestPointPos.getX(), bestPointPos.getY() + 1);
		if (getColor(&neighborPos, maze) == SPACE || getColor(&neighborPos, maze) == getColor(&targetPoint, maze)) {
			int g = bestPointAsParent->getG() + securityMap[neighborPos.getY()][neighborPos.getX()] * randomWeight;
			neighborPos_hg = Point2D_hg(bestPointAsParent, neighborPos, targetPoint, g);
			black_iterator = find(black.begin(), black.end(), neighborPos_hg);
			gray_iterator = find(gray.begin(), gray.end(), neighborPos_hg);
			if (black_iterator == black.end() && gray_iterator == gray.end())
			{
				pq.emplace(neighborPos_hg);
				gray.push_back(neighborPos_hg);
			}
		}

		neighborPos = Point2D(bestPointPos.getX(), bestPointPos.getY() - 1);
		if (getColor(&neighborPos, maze) == SPACE || getColor(&neighborPos, maze) == getColor(&targetPoint, maze)) {
			int g = bestPointAsParent->getG() + securityMap[neighborPos.getY()][neighborPos.getX()] * randomWeight;
			neighborPos_hg = Point2D_hg(bestPointAsParent, neighborPos, targetPoint, g);
			black_iterator = find(black.begin(), black.end(), neighborPos_hg);
			gray_iterator = find(gray.begin(), gray.end(), neighborPos_hg);
			if (black_iterator == black.end() && gray_iterator == gray.end())
			{
				pq.emplace(neighborPos_hg);
				gray.push_back(neighborPos_hg);
			}
		}
	} while (true);
	return false;
}

Point2D* AStar::getTop()
{
	if (!solution.empty())
	{
		Point2D_hg best = solution.back();
		solution.pop_back();
		lastPos = Point2D(best.getPoint());
		return new Point2D(lastPos);
	}
	return NULL;
}

Point2D* AStar::getButtom()
{
	if (!solution.empty())
	{
		Point2D_hg best = solution.front();
		solution.pop_front();
		lastPos = Point2D(best.getPoint());
		return new Point2D(lastPos);
	}
	return NULL;
}

int AStar::getLen()
{
	return solution.size();
}