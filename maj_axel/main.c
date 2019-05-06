/*!
* @file main.c
* @brief Testing Program
* @author axel
* @version 1.0
* @date Apr 24, 2019
* Testing the main
*
 */

#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "defs.h"
#include "fonctions.h"

int main ( int argc, char** argv )
{

	SDL_Surface *screen;
int k=0;
	// initialize SDL video
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		printf( "Unable to init SDL: %s\n", SDL_GetError() );
		return 1;
	}

	// make sure SDL cleans up before exit
	atexit(SDL_Quit);

	// create a new window
	screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32,SDL_HWSURFACE|SDL_DOUBLEBUF | SDL_SRCALPHA);

	if ( !screen ) {
		printf("Unable to set 600x300 video: %s\n", SDL_GetError());
		return 1;
	}

	k=jouer(screen);

	// all is well ;)
	printf("Exited cleanly\n");
	return 0;
}
