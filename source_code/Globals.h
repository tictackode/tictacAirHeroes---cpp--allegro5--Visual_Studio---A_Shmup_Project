#pragma once
#include <stdio.h>

bool running = true;
bool isShooting = false;
int number_of_projectile = 0; // begins with 0, so first projectile

struct tictacMapObject
{

	int x=0;
	int y=0;
	bool colided=false;
	ALLEGRO_BITMAP* image;
	int objectSpeed=5;
	bool isActive = false;
};

struct tictacMapObject player1;
struct tictacMapObject grass;
struct tictacMapObject star_projectile1[6];





void shooting()
{

	
		
	for (int i = 0; i < 6; i++)
	{
		if (star_projectile1[i].isActive)
		{
			if (star_projectile1[i].y > 1)
			{
				star_projectile1[i].y -= star_projectile1[i].objectSpeed;
			}
			else
			{
				star_projectile1[i].isActive = false;
			}
		}
	}
		
	

}


