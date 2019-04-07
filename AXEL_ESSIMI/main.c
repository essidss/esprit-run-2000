#include <stdio.h>
#include "SDL/SDL.h"
#include <stdlib.h>
#include <math.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "fonctions.h"
#include "SDL/SDL_ttf.h"


int main(void)
{
int k,done=1;
char pause;
PERSONAGE perso;
vie V;
SDL_Rect pos_perso, pos_enemi;
SDL_Surface * screen = NULL;
SDL_Event event;
init_perso(&perso);
k=collision_trigo(pos_perso,pos_enemi);

SDL_SetColorKey(perso.V.surface_vie,SDL_SRCCOLORKEY, SDL_MapRGB(perso.V.surface_vie->format,255,255,255));

SDL_Init(SDL_INIT_VIDEO);
if(SDL_Init(SDL_INIT_VIDEO)!=0)
	{
	  printf("Unable to initialize mode:%s\n",SDL_GetError());
			
	}


	screen = SDL_SetVideoMode(1200,800,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
	if(!screen)
	{
		printf("Unable to set 1200x800 video:%s\n",SDL_GetError());
		
	}
SDL_EnableKeyRepeat(30,30);//repetition des touches
SDL_WM_SetCaption("AXEL_ESSIMI",NULL);

SDL_ShowCursor(SDL_ENABLE);

	while(done)
	{
           while(SDL_PollEvent(&event))
           {
             switch(event.type)
              {
                case SDL_QUIT:
                 done=0;
                 break;
                case SDL_KEYDOWN:
                 depacer_perso(&perso,event);
		 break;
              }//fin switch
           }//fin du message en cours
         
	afficher_perso(perso,screen);
        SDL_Flip(screen);
	}
SDL_FreeSurface(screen);

	SDL_Quit();
return 0;
}



