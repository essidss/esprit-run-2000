#include "menu.h"
void intiaBackground(background *B)
{
SDL_Rect position;
position.x=0;
position.y=0;
B->image=IMG_Load("background.png");
SDL_BlitSurface(b->image,NULL, screen, &position);
SDL_Flip(screen);
Mix_Music *music;//construct mix music pointer
music = Mix_LoadMUS("music.mp3");//load the music
Mix_PlayMusic(music,-1);//play music
}
