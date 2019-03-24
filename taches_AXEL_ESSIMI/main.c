#include <stdio.h>
#include "SDL/SDL.h"
#include<stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include <math.h>
#include "fonctions.h"



int main(void) 
{
SDL_Surface * screen = NULL;
SDL_Surface *Surface_perso=NULL;

int k;
SDL_Surface *personages[5];
PERSONAGE perso;
init_perso(&perso,personages);
 //SDL_SetColorKey(perso.pos_perso,SDL_SRCCOLORKEY, SDL_MapRGB(Surface_perso->format,255,255,255));
	SDL_Init(SDL_INIT_VIDEO);
	screen = SDL_SetVideoMode(600,400,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
	if(!screen)
	{
		printf("Unable to set 600x400 video:%s\n",SDL_GetError());
		return(-1);
	}

	if(SDL_Init(SDL_INIT_VIDEO)!=0)
	{
	  printf("Unable to initialize mode:%s\n",SDL_GetError());
		return 1;	
	}
//k=afficher_perso(perso,personages);
//getchar();
k=afficher_perso(personages,Surface_perso,screen);
//SDL_EnableKeyRepeat(20,20);//repetition des touches
deplacement_perso(personages,screen,Surface_perso);
int collision_trigo(SDL_Rect pos_perso,SDL_Rect pos_enemi);
return 0;
}
