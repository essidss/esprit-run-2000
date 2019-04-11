#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL.h"
#include "alya_taches.h"

void init_enemi(ENEMI *enemi)
{
int i;
for(i=0;i<5;i++)
{
  enemi->tab_image[i]=NULL;
}

for(i=0;i<4;i++)
{
  enemi->V.tab_image[i]=NULL;
}

enemi->surface_enemi=NULL;

enemi->surface_enemi=IMG_Load(".png");
	if(enemi->surface_enemi==NULL)
	{
	printf("Unable to load image %s\n",SDL_GetError());
	}

enemi->tab_image[0] = IMG_Load(".png");
	if(enemi->tab_image[0]==NULL)
	{
	 printf("Unable to load image %s\n",SDL_GetError());
	}

enemi->tab_image[1] = IMG_Load(".png");
	if(enemi->tab_image[1]==NULL)
	{
	  printf("Unable to load image %s\n",SDL_GetError());
	}

enemi->tab_image[2] = IMG_Load(".png");
	if(enemi->tab_image[2]==NULL)
	{
	  printf("Unable to load image %s\n",SDL_GetError());
	}

enemi->tab_image[3] = IMG_Load(".png");
	if(enemi->tab_image[3]==NULL)
	{
	  printf("Unable to load image %s\n",SDL_GetError());
	}

enemi->tab_image[4] = IMG_Load(".png");
	if(enemi->tab_image[4]==NULL)
	{
	  printf("Unable to load image %s\n",SDL_GetError());
	}

};

void afficher_enemi(ENEMI enemi,SDL_Surface *screen)
{
SDL_BlitSurface(perso.surface_enemi,NULL,screen, &perso.pos_enemi);
};

int collision_boundingbox(SDL_Rect pos_perso,SDL_Rect pos_enemi)
{
  //en train de le faire...
};

int animer_personnage(PERSONAGE * perso->surface_perso,PERSONAGE * perso->tab_img[])
{
        perso = IMG_Load("avatar01jump.png");
//haut
    perso_haut[1] = IMG_Load("avatar01jump.png");
    perso_haut[2] = IMG_Load("avatar01walk1png");
    perso_haut[3] = IMG_Load("avatar01walk2.png");
    perso_haut[4] = IMG_Load("avatar01walk1png");
    perso_haut[5] = IMG_Load("avatar01jump.png");
//bas
    perso_bas[1] = IMG_Load(".png");
    perso_bas[2] = IMG_Load(".png");
    perso_bas[3] = IMG_Load(".png");
    perso_bas[4] = IMG_Load(".png");
    perso_bas[5] = IMG_Load(".png");
//droite
    perso_droite[1] = IMG_Load("avatar01jump.png");
    perso_droite[2] = IMG_Load("avatar01walk1png");
    perso_droite[3] = IMG_Load("avatar01walk2.png");
    perso_droite[4] = IMG_Load("avatar01jump.png");
//gauche
    perso_gauche[1] = IMG_Load("avatar01jump - left.png");
    perso_gauche[1] = IMG_Load("avatar01walk1- left.png");
    perso_gauche[2]= IMG_Load("avatar01walk2- left.png");
    perso_gauche[3] = IMG_Load("avatar01jump- left.png");

win_surf = SDL_GetWindowSurface(window)
while (!quit)
    {
SDL_BlitSurface (perso, NULL,win_surf, NULL);
SDL_BlitSurface (perso_haut[1], NULL, win_surf, &curr);
        SDL_PollEvent(&event);
        switch(event.type)
        {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_UP:
                for(i = 1; i<6; i++)
                {
                    temp_actuel = SDL_GetTicks();
                    if (temp_actuel - temp_precedent > 35)
                    {
                        SDL_BlitSurface(haut[j], NULL, win_surf, &curr);
                        j++;
                        if(j<6)
                            j = 1;
                        temp_precedent = temp_actuel;

                    }
                    SDL_UpdateWindowSurface(window);
                    curr.y -=7;
                    SDL_Delay(20);
                }
                break;

           case SDLK_DOWN:
                for(i = 1; i<6; i++)
                {
                    temp_actuel = SDL_GetTicks();
                    if (temp_actuel - temp_precedent > 35)
                    {
                        SDL_BlitSurface(bas[i], NULL, win_surf, &curr);
                        i++;
                        if(i<6)
                            i = 1;
                        temp_precedent = temp_actuel;
                        SDL_UpdateWindowSurface(window);
                    }
                    curr.y +=7;
                    SDL_Delay(20);

                }
                break;

            case SDLK_RIGHT:
                for(i = 1; i<5; i++)
                {
                    temp_actuel = SDL_GetTicks();
                    if (temp_actuel - temp_precedent > 35)
                    {
                        SDL_BlitSurface(droite[i], NULL, win_surf, &curr);
                        i++;
                        if(i<5)
                            i = 1;
                        temp_precedent = temp_actuel;
                        SDL_UpdateWindowSurface(window);
                    }
                    curr.x +=6;
                SDL_Delay(20);
                SDL_UpdateWindowSurface(window);
                }
                break;

            case SDLK_LEFT:
                for(i = 1; i<5; i++)
                {
                    temp_actuel = SDL_GetTicks();
                    if (temp_actuel - temp_precedent > 65)
                    {

                        k++;
                        if(k<5)
                            k = 1;
                            SDL_BlitSurface(gauche[k], NULL, win_surf, &curr);
                        temp_precedent = temp_actuel;
                    }

                    curr.x -=6;
                    SDL_Delay(60);
                    SDL_UpdateWindowSurface(window);
                }
                break;

            }
        }
        SDL_UpdateWindowSurface(window);
    }
    SDL_FreeSurface(perso);
    SDL_FreeSurface(bas);
    SDL_FreeSurface(haut);
    SDL_FreeSurface(gauche);
    SDL_FreeSurface(droite);
    SDL_Quit();
    return (0);
}
