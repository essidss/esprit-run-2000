#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

int main (int argc, char *argv[])
{

SDL_Window *window = NULL;
SDL_Surface *win_surf;
SDL_Surface *map_test;
SDL_Event event;
SDL_Surface *moustache[4];
SDL_Rect curr;
int quit = 0;
int cmp = 1;
int i;
Uint32 temps_courant, prochain_rendu = 0;
curr.x = 450;
curr.y = 450;

window = SDL_CreateWindow(
			    "Back to Midgar",
			    SDL_WINDOWPOS_UNDEFINED,
			    SDL_WINDOWPOS_UNDEFINED,
			    800,
			    600,
			    SDL_WINDOW_BORDERLESS | SDL_WINDOW_SHOWN
			    );

map_test = IMG_Load("moustacheland.jpg");
yuri_bas[1] = IMG_Load("moustache_bas_1.png");
yuri_bas[2] = IMG_Load("moustache_bas_2.png");
yuri_bas[3] = IMG_Load("moustache_bas_3.png");


win_surf = SDL_GetWindowSurface(window);


while (!quit)
{

     SDL_BlitSurface (map_test, NULL,win_surf, NULL);
     // position par defaut
     SDL_BlitSurface (moustache[1], NULL, win_surf, &curr);
     SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_UP:
            curr.y -=10;
            cmp = 1;
            break;
        case SDLK_DOWN:
             /*faire une animation quand j'appuie sur la touche "bas" du clavier, malheureusement le SDL_Delay est mal adapté pour ça, on m'avait conseillé SDL_GetTick(), mais je n'ais aucune idée du fonctionnement de la fonction même en regardant les tutos.*/
             for(i = 1; i<4; i++){
                SDL_BlitSurface(moustache[i], NULL, win_surf, &curr);
                SDL_UpdateWindowSurface(window);
                SDL_Delay(60);}
            curr.y +=5;
            cmp = 2;
            break;
         }
    }
    SDL_UpdateWindowSurface(window);
    SDL_Delay(60);
}
    SDL_FreeSurface(map_test);
   SDL_FreeSurface(moustache);
   SDL_DestroyWindow(window);
   SDL_Quit();
}
