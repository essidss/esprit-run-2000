#include <stdio.h>
#include <stdlib.h>

int tempPrecedent = 0,
    tempDelayEnMilliSecondes = 500; //la moitié d'une seconde

if(SDL_GetTicks() - tempPrecedent > tempDelayEnMilliSecondes) //si il y a plus de tempDelayEnMilliSecondes ecoulé depuis la derniere fois
{ //qu'on as executé le code :

 /* Execution du code */
   tempPrecedent = SDL_GetTicks(); //on met a jour tempPrecendent pour les futurs calculs
}

int main (int argc, char *argv[])
{

    SDL_Window *window = NULL;
    SDL_Surface *win_surf;
    SDL_Surface *map_test;
    SDL_Event event;
    SDL_Surface *bas[4];
    SDL_Surface *haut[4];
    SDL_Surface *gauche[4];
    SDL_Surface *droite[4];
    SDL_Rect curr;
    int quit = 0;
    int i = 1;
    int j = 1;
    int k = 1;
    int temp_actuel = 0;
    int temp_precedent = 0;
    curr.x = 450;
    curr.y = 450;

    window = SDL_CreateWindow(
                 "ceci est un test",
                 SDL_WINDOWPOS_UNDEFINED,
                 SDL_WINDOWPOS_UNDEFINED,
                 800,
                 600,
                 SDL_WINDOW_BORDERLESS | SDL_WINDOW_SHOWN
             );

    map_test = IMG_Load("blank.jpg");
    yuri_bas[1] = IMG_Load("animation_bas_1.png");
    yuri_bas[2] = IMG_Load("animation_bas_2.png");
    yuri_bas[3] = IMG_Load("animation_bas_3.png");

    yuri_haut[1] = IMG_Load("animation_haut_1.png");
    yuri_haut[2] = IMG_Load("animation_haut_2.png");
    yuri_haut[3] = IMG_Load("animation_haut_3.png");

    yuri_gauche[1] = IMG_Load("animation_gauche_1.png");
    yuri_gauche[2] = IMG_Load("animation_gauche_2.png");
    yuri_gauche[3] = IMG_Load("animation_gauche_3.png");

    yuri_droite[1] = IMG_Load("animation_droite_1.png");
    yuri_droite[2] = IMG_Load("animation_droite_2.png");
    yuri_droite[3] = IMG_Load("animation_droite_3.png");




win_surf = SDL_GetWindowSurface(window);

while (!quit)
    {

SDL_BlitSurface (map_test, NULL,win_surf, NULL);
SDL_BlitSurface (yuri_bas[1], NULL, win_surf, &curr);
        SDL_PollEvent(&event);
        switch(event.type)
        {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_UP:
                /*for(i = 1; i<4; i++)
                {*/
                    temp_actuel = SDL_GetTicks();
                    if (temp_actuel - temp_precedent > 35)
                    {
                        SDL_BlitSurface(haut[j], NULL, win_surf, &curr);
                        j++;
                        if(j<4)
                            j = 1;
                        temp_precedent = temp_actuel;

                    }
                    SDL_UpdateWindowSurface(window);
                    curr.y -=5;
                    SDL_Delay(20);
                /*}*/
                break;

            case SDLK_DOWN:
                for(i = 1; i<4; i++)
                {
                    temp_actuel = SDL_GetTicks();
                    if (temp_actuel - temp_precedent > 35)
                    {
                        SDL_BlitSurface(bas[i], NULL, win_surf, &curr);
                        i++;
                        if(i<4)
                            i = 1;
                        temp_precedent = temp_actuel;
                        SDL_UpdateWindowSurface(window);
                    }
                    curr.y +=5;
                    SDL_Delay(20);

                }
                break;

            case SDLK_LEFT:
                /*for(i = 1; i<4; i++)
                {*/
                    temp_actuel = SDL_GetTicks();
                    if (temp_actuel - temp_precedent > 65)
                    {

                        k++;
                        if(k<4)
                            k = 1;
                            SDL_BlitSurface(gauche[k], NULL, win_surf, &curr);
                        temp_precedent = temp_actuel;
                    }

                    curr.x -=5;
                    SDL_Delay(60);
                    SDL_UpdateWindowSurface(window);
                /*}*/
                break;

            case SDLK_RIGHT:
                for(i = 1; i<4; i++)
                {
                    temp_actuel = SDL_GetTicks();
                    if (temp_actuel - temp_precedent > 35)
                    {
                        SDL_BlitSurface(droite[i], NULL, win_surf, &curr);
                        i++;
                        if(i<4)
                            i = 1;
                        temp_precedent = temp_actuel;
                        SDL_UpdateWindowSurface(window);
                    }
                    curr.x +=5;
                SDL_Delay(20);
                SDL_UpdateWindowSurface(window);
                }

                break;

            }


        }
        SDL_UpdateWindowSurface(window);
    }
    SDL_FreeSurface(map_test);
    SDL_FreeSurface(bas);
    SDL_FreeSurface(haut);
    SDL_FreeSurface(gauche);
    SDL_FreeSurface(droite);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return (0);
}
