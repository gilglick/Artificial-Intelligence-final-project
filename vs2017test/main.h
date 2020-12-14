#ifndef __MAIN_H
#define __MAIN_H

#pragma once
#include "glut.h"
#include <time.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <list>
#include <set>
#include <queue>
#include "Point2D.h"
#include "Player.h"
#include "Storage.h"
#include "Const.h"
#include "Node.h"
#include "Room.h"
#include "CompareNodes.h"
#include "Bullet.h"
#include "Grenade.h"

int maze[MSZ][MSZ];
int roomMat[MSZ][MSZ];
double security_map[MSZ][MSZ] = { 0 };
int numOfShooting=0;

Room rooms[NUM_ROOMS]; // runs default constructor
std::list<Player*> groupA;
std::list<Player*> groupB;
std::vector<Target> ammoStorages;
std::vector<Target> healthStorages;
bool start_BFS = false;


Bullet* pb = nullptr;
Grenade* pg = nullptr;
Point2D** storages;

void SetupMaze();
void initTwoPlayers();
void initStorages();
void initObjects();
void init();
void initGame();
void cleanPlayersPoints(std::list<Player*> group);
void cleanPlayers();
void UpdateSecurityMap(std::list<Player> B);
double Distance(int x1, int y1, int x2, int y2);
void RestorePath(Node* pCurrent);
void DigPath(int index1, int index2);
void DigPathes();
void SetupMaze();
void DrawMaze();
void BuildPath(Node* pCurrent);
void display();
void idle();
void menu(int choice);
std::set<int> randomTwoRoomsNums();
int randomRoomNum();
Point2D* getPoint(Room room);
std::queue<int> setToQueue(std::set<int> roomsForPlayers);
void initTwoPlayers();
void initStorages();
void initObjects();
void play(std::list<Player*>*A, std::list<Player*> *B);
std::vector<Target> chooseTarget(Player p1, std::list<Player*> B);
//std::list<Target> findMinTargetInVector(Player p1, std::vector<Target> t);
std::vector<Target>  createTargetVectorFromPlayers(std::list<Player*> players);
void game();
void main(int argc, char* argv[]);
int getColor(Point2D& point);
int getRoom(Point2D* p);
Point2D* findRoomExit(std::list<Point2D_hg> solution, int currentRoom);
Point2D* Astar(Point2D* pos, Point2D targetPoint, int maxG, int* length,int targetColor);
bool isHealthStorage(Point2D* pos);
bool isAmmoStorage(Point2D* pos);
bool isStorage(Point2D* pos);
bool isTargetAnopponentPlayer(Player p, Target t);
void action(int roomIndex, Player* p1, Target t);



#endif //__MAIN_H