#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL.h"
#include "alya_taches.h"

int main(void)
{
  ENEMI enemi;
int B;
      B=collision_boundingbox(pos_perso,pos_enemi);

SDL_Rect pos_perso, pos_enemi;

SDL_Surface * screen = NULL;

SDL_Event event;

init_enemi(&enemi);

afficher_enemi(enemi,screen);
        SDL_Flip(screen); //pas sure
	}

SDL_FreeSurface(screen);

	SDL_Quit();
return 0;
}
}
