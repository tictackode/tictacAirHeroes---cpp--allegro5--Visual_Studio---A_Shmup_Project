
#include "Glow.h"
#include "Globals.h"

#include <cstdio>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/display.h>

ALLEGRO_EVENT event;
ALLEGRO_KEYBOARD_STATE state;

class GameScreen
{
public:

	unsigned short SCREEN_X;
	unsigned short SCREEN_Y;
	unsigned short NUMBER_OF_BLOCKS;
	unsigned short BLOCK_SIDE_SIZE;
	unsigned long int gameCicles;
	ALLEGRO_BITMAP* bufferBackground=NULL; //*buffer;

	GameScreen()
	{
		this->NUMBER_OF_BLOCKS = 20;
		this->BLOCK_SIDE_SIZE = 40;
		this->SCREEN_X = this->BLOCK_SIDE_SIZE * this->NUMBER_OF_BLOCKS;
		this->SCREEN_Y = this->BLOCK_SIDE_SIZE * this->NUMBER_OF_BLOCKS;
		this->gameCicles = 0;
		this->bufferBackground = NULL;

	}
	~GameScreen()
	{

	}

	void drawGrass()
	{
		this->bufferBackground = al_create_bitmap(800, 800);
		al_set_target_bitmap(bufferBackground);

		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				al_draw_bitmap(grass.image, (i * 40.0), (j * 40.0), 0);
				//al_draw_rectangle((i * 40.0), (j * 40.0), (i * 40.0) + 40, (j * 40.0) + 40, al_map_rgb(0, 255, 0),5);
			}
		}

	}

	void drawScreen()
	{

		al_draw_bitmap(bufferBackground, 0, 0, 0);

		for (int i = 0; i < 6; i++)
		{
			if(star_projectile1[i].isActive)
			{
				al_draw_bitmap(star_projectile1[i].image, star_projectile1[i].x, star_projectile1[i].y, 0);
			}
		}
		

		al_draw_bitmap(player1.image, player1.x , player1.y , 0);
		//al_draw_filled_rectangle(player1.x * this->BLOCK_SIDE_SIZE, player1.y * this->BLOCK_SIDE_SIZE, (player1.x * this->BLOCK_SIDE_SIZE) + 40, (player1.y * this->BLOCK_SIDE_SIZE) + 40, al_map_rgb(0, 0, 255));

		//al_draw_bitmap(buffer, 0, 0, 0);

		al_flip_display();

	}

	void controls()
	{

		al_get_keyboard_state(&state);


		if(al_key_down(&state, ALLEGRO_KEY_A))
		{
			if(player1.x > 0)
			{
				player1.x-= player1.objectSpeed;
			}
			
			//keyPressed = true;

		}
		if(al_key_down(&state, ALLEGRO_KEY_D))
		{
			if (player1.x < 720)
			{
				player1.x+=player1.objectSpeed;
			}

			//keyPressed = true;
		}

		if(al_key_down(&state, ALLEGRO_KEY_S))
		{
			if (player1.y < 720)
			{
				player1.y+= player1.objectSpeed;
			}

			//keyPressed = true;
		}
		if(al_key_down(&state, ALLEGRO_KEY_W))
		{
			if (player1.y > 0)
			{
				player1.y-= player1.objectSpeed;
			}

			//keyPressed = true;
		}
		if(al_key_down(&state, ALLEGRO_KEY_ESCAPE))
		{
			running = false;

			//keyPressed = true;
		}
		if(al_key_down(&state, ALLEGRO_KEY_SPACE))
		{
			
			if (!star_projectile1[number_of_projectile].isActive)
			{
				star_projectile1[number_of_projectile].isActive = true;
				star_projectile1[number_of_projectile].y = player1.y;
				star_projectile1[number_of_projectile].x = player1.x + 20;
				number_of_projectile++;
			}
			else
			{
				if (number_of_projectile > 0)
				{
					//star_projectile1[number_of_projectile].isActive = false;
					number_of_projectile--;
				}
			}
			
		}

	}
	
};
