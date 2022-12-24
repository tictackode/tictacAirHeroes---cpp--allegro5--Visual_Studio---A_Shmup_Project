/*

*/
#include <time.h>

#include "GameScreen.h"
#include "Globals.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/display.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include <cstdio>
#include <iostream>

using namespace std;

void initImages();
void DebugLog();

GameScreen gameScreen;

/*ALLEGRO_SAMPLE* hit;
ALLEGRO_SAMPLE* intro;*/


ALLEGRO_BITMAP* loadImage(const char* path);




/*void initSound()
{
	hit = al_load_sample("sound/phase2.wav");
	intro = al_load_sample("sound/chime.wav");

	if (!al_install_audio())
	{
		fprintf(stderr, "failed to initialize audio!\n");
	}

	if (!al_init_acodec_addon())
	{
		fprintf(stderr, "failed to initialize audio codecs!\n");

	}

}

void playHit()
{
	al_play_sample(hit, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
}
void playIntro()
{
	al_play_sample(intro, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
}*/


int main()
{

	player1.x = 380;
	player1.y = 700;

	for (int i = 0; i < 6; i++)
	{
		star_projectile1[i].objectSpeed = 8;
	}
	

	al_init();
	al_init_image_addon();
	al_install_keyboard();
	//al_install_audio();
	//al_init_acodec_addon();

	
	initImages();
	gameScreen.drawGrass();
	//al_init_primitives_addon();
	
	//to generate real random numbers
	srand(time(0));

	//load images used in the game
	initImages();

	//plays a sound in the begining of the game
	 //al_install_audio(ALLEGRO_AUDIO_DRIVER_AUTODETECT);
	//gameAudio.playSample(gameAudio.intro);

	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_TIMER* timer = NULL;
	ALLEGRO_EVENT _event;
	//ALLEGRO_TIMEOUT timeout;
	
	//sets the size of the console window
	al_set_window_title(display, "tictacAir Heroes >>> an opensource spaceship shooter game");

	// Initialize allegro
	if(!al_init()) {
		fprintf(stderr, "Failed to initialize allegro.\n");
		return 1;
	}

	// Initialize the timer
	timer = al_create_timer(1.0 / 100);
	if (!timer) {
		fprintf(stderr, "Failed to create timer.\n");
		return 1;
	}

	// Create the display
	display = al_create_display(800, 800);
	if (!display) {
		fprintf(stderr, "Failed to create display.\n");
		return 1;
	}

	// Create the event queue
	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "Failed to create event queue.");
		return 1;
	}

	
	// Register event sources
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	// Display a black screen
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();

	// Start the timer
	al_start_timer(timer);

	//gameAudio.playIntro();
	// Game loop
	//al_init_timeout(&timeout, 0.01);
	while (running) 
	{

		//gameScreen.controls();
		//gameScreen.drawScreen();
		//al_flip_display();

		// Fetch the event (if one exists)
		al_wait_for_event(event_queue, &_event);

		switch (_event.type)
		{
		case ALLEGRO_EVENT_TIMER:

			gameScreen.controls();
			gameScreen.drawScreen();
			shooting();
		
			break;
		case ALLEGRO_EVENT_DISPLAY_CLOSE:

			running = false;
			break;
		default:
			fprintf(stderr, "Unsupported event received: %d\n", event.type);
			//gameScreen.controls();
			//gameScreen.drawScreen();
			//al_flip_display();
			break;
		}
		
	}//while

	// Check if we need to redraw
	/*if (redraw && al_is_event_queue_empty(event_queue)) {
		// Redraw
		al_clear_to_color(al_map_rgb(0, 0, 0));

		gameScreen.drawScreen();
		//al_flip_display();
		redraw = false;
	}*/

	// Clean up
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);
	
	al_destroy_bitmap(player1.image);
	al_destroy_bitmap(grass.image);
	al_destroy_bitmap(star_projectile1[0].image);

	return 0;
}

void initImages()
{

	player1.image=loadImage("images/spaceship1.png");
	grass.image=loadImage("images/grass.bmp");
	
	for (int i = 0 ; i < 6; i++)
	{
		star_projectile1[i].image = loadImage("images/star_projectile1.png");
	}
	

}


void DebugLog()
{
	/*system("cls");
	printf("StarProjectile Position X: %d \n", star_projectile1.x);
	printf("StarProjectile Position Y: %d \n", star_projectile1.y);*/
}


ALLEGRO_BITMAP* loadImage(const char* path)
{
	ALLEGRO_BITMAP* temp = NULL;
	temp = al_load_bitmap(path);

	if (!temp)
	{
		printf("Did not load ");
		puts(path);
		running = false;
	}
	else
	{
		printf("Sucessfull load of ");
		puts(path);
	}

	return temp;
}








