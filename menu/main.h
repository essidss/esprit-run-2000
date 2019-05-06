#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

typedef struct
{
    SDL_Surface *play[3];
    SDL_Surface *instructions[3];
    SDL_Surface *setting[3];
    SDL_Surface *exit[3];
}buttons;

int main ( int argc, char** argv );
void cleanmenu(SDL_Surface *background);

#endif // MAIN_H_INCLUDED
