#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    SDL_Surface *button[7];
    SDL_Surface *button_select[7];
    SDL_Surface *button_clicked[7];
    SDL_Rect posbutton[7];
}buttons;
typedef struct
{
    SDL_Surface *backgrounds[3];
    SDL_Rect posbackground;
}

void initialiser(SDL_Surface *screen, buttons but);
void instructionss (SDL_Surface *screen);
int quit (SDL_Surface *screen);
void menu (SDL_Surface *screen);
void objects (SDL_Surface * screen);
void enigmes(SDL_Surface *screen);
//int main ( int argc, char** argv );

#endif // MENU_H_INCLUDED
