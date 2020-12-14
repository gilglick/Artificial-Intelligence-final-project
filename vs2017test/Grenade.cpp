#include "Grenade.h"
#include "glut.h"
#include <math.h>


Grenade::Grenade(double x, double y) 
{
	double alpha, teta = 2*PI/NUM_BULLETS;
	int i;
	this->x = x;
	this->y = y;
	// init all bullets
	for ( i = 0,alpha = 0; i < NUM_BULLETS; i++,alpha+=teta)
	{
		bullets[i].SetX(x);
		bullets[i].SetY(y);
		bullets[i].SetDirX(cos(alpha));
		bullets[i].SetDirY(sin(alpha));
	}

}

void Grenade::Explode()
{
	double alpha, teta = 2 * PI / NUM_BULLETS;
	int i;
	for ( i = 0, alpha = 0; i < NUM_BULLETS; i++, alpha += teta)
	{
		bullets[i].SetDirX(cos(alpha));
		bullets[i].SetDirY(sin(alpha));
		bullets[i].Shoot();
	}
}

void Grenade::Draw()
{
	for (int i = 0; i < NUM_BULLETS; i++)
		bullets[i].Draw();
}

void Grenade::UpdateSecurityMap(int maze[MSZ][MSZ], double map[MSZ][MSZ])
{
	int j, k;
	for (j = 0; j < MSZ; j++)
	{
		for (k = 0; k < MSZ; k++)
			map[j][k] = 0;
	}
	bool stop = false;
	int row, col,i;
	double delta = 0.001;
	for (i = 0; i < NUM_BULLETS; i++)
		bullets[i].Shoot();

	while (!stop)
	{
		stop = true;		
		for ( i = 0; i < NUM_BULLETS; i++)
		{
			if (bullets[i].GetIsMoving())
			{
				stop = false;
				row = MSZ * (bullets[i].GetY() + 1) / 2;
				col = MSZ * (bullets[i].GetX() + 1) / 2;
				if (row >= 0 && row < MSZ && col >= 0 && col < MSZ && maze[row][col] == SPACE)
				{
					map[row][col] += delta;
					bullets[i].Move(maze);
				}
				else
					bullets[i].StopMoving();
			}
		}
	}
}

void Grenade::Move(int maze[MSZ][MSZ])
{
	for (int i = 0; i < NUM_BULLETS; i++)
		bullets[i].Move(maze);

}
