#ifndef __PLAYER_H
#define __PLAYER_H
#pragma once

#include "AStar.h"
#include <thread>
#include "Target.h"
#include "Bullet.h"
#include <list>
#include <math.h>
#include <set>
class Player: public Target
{
public:
	Player(Point2D* pos,int targets,int otherPlayer);
	void decreaseHealth();
	void decreaseHealth(int gap);
	void refillHealth();
	void decreaseAmmo();
	void refillAmmo();
	int getHealth();
	int getAmmo();
	int getVariable();
	void mouve(Point2D* next);
	void simulateShoot(int maze[MSZ][MSZ],double ** securityMap);
	void shoot(Target t, int maze[MSZ][MSZ],double securityMap[MSZ][MSZ], std::set<Point2D*>* bullets=nullptr);
	void setOpponentsTeam(std::list<Player*>opponentsTeam);
	Bullet* getBullet();
	std::list<Player*> getOpponnentsTeam();
private:
	
	int otherPlayer;
	int health;
	int ammo;
	int variable;
	Bullet* bullet;
	std::list<Player*>opponentsTeam;

};
#endif // __PLAYER_H_
