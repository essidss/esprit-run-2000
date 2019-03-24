#include <stdio.h>
#include "SDL/SDL.h"
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include <math.h>
#include "fonctions.h"
void init_perso(PERSONAGE *perso,SDL_Surface *personages[])
{ 
//chargement de toutes les images du personage dans le tableau "personages"



//chargement
  personages[0]=IMG_Load("perso1.png");
   if(personages[0]==NULL)
{
printf("Unable to load personage_0:%s\n",SDL_GetError());	
}

 /* *personage[1]=SDL_LoadBMP(".png");
if(*personage[1]==NULL)
{
printf("Unable to load personage_1:%s\n",SDL_GetError());	
}

*personage[2]=SDL_LoadBMP(".png");
if(*personage[2]==NULL)
{
printf("Unable to load personage_2:%s\n",SDL_GetError());	
}

personage*[3]=SDL_LoadBMP(".png");
if(*personage[3]==NULL)
{
printf("Unable to load personage_3:%s\n",SDL_GetError());	
}

*personage[4]=SDL_LoadBMP(".png");
if(*personage[4]==NULL)
{
printf("Unable to load personage_4:%s\n",SDL_GetError());	
}

*/
//initialisation des autres champs
perso->score=0;
strcpy(perso->nom_joueur,"joueur1");
perso->vie=3;
perso->pos_perso.x=200;
perso->pos_perso.y=80;
}


int afficher_perso(SDL_Surface *personages[],SDL_Surface *Surface_perso,SDL_Surface * screen)
{

SDL_Rect pos_perso;
pos_perso.x=200;
pos_perso.y=80;
//SDL_Surface * screen = NULL;

//SDL_Surface *Surface_perso=NULL;

//sert juste au test
/*
SDL_Surface * image=NULL;
	SDL_Rect positionecran;

	positionecran.x=0;
	positionecran.y=0;
*/
Surface_perso=personages[0];
if(Surface_perso==NULL)
	{
		printf("Unable to load personages[0]:%s\n",SDL_GetError());
		return 1;
	}

//juste pour le test
  /* image=IMG_Load("background.png");
	if(image==NULL)
	{
		printf("Unable to load bitmap:%s\n",SDL_GetError());
		return 1;
	}
*/
//


 //SDL_BlitSurface(image,NULL, screen, &positionecran);juste pour le test
 SDL_BlitSurface(Surface_perso,NULL, screen, &pos_perso);
SDL_Flip(screen);
return 0;
}


void deplacement_perso(SDL_Surface *personages[],SDL_Surface * screen,SDL_Surface *Surface_perso/*,SDL_Event event*/)
{
SDL_Event event;
SDL_Rect pos_perso;
      char pause;
        int done=1;
pos_perso.x=200;
pos_perso.y=80;
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
                 {
                  switch(event.key.keysym.sym)
                     {
                     case SDLK_UP:
                      pos_perso.y -=10;
                       SDL_WaitEvent(&event);
                       break;
                     case SDLK_DOWN:
                       pos_perso.y +=10;
                       SDL_WaitEvent(&event);
                       break;
                     case SDLK_LEFT:
                       pos_perso.x -=10;
                       SDL_WaitEvent(&event);
                       break;
                     case SDLK_RIGHT:
                       pos_perso.x +=10;
                       SDL_WaitEvent(&event);
                       break;
                    }
                 }
              }//fin switch
           
         
        //SDL_BlitSurface(image,NULL, screen, &positionecran);
	SDL_BlitSurface(Surface_perso,NULL, screen, &pos_perso);
        SDL_Flip(screen);
}//fin du message en cours
	}
	
	//SDL_FreeSurface(image);
	SDL_FreeSurface(Surface_perso);
        //pause = getchar();
	SDL_Quit();
}



int collision_trigo(SDL_Rect pos_perso,SDL_Rect pos_enemi)
{
 float W1,W2;//largeur resp du perso et de l enemi 
float H1,H2;//hauteur resp du perso et de l enemi 
//utiliser des define pour W1,W2,H1 ET H2
#define W1 170
#define H1 309
#define W2 347
#define H2 169

float X1,X2;//abscisse resp du cercle cirsconstrit au perso et de l enemi 
float Y1,Y2;//ordonnee resp du cercle cirsconstrit auperso et de l enemi
float w1,w2;//demie largeur resp du perso et de l enemi 
float h1,h2;//demie hauteur resp du perso et de l enemi
float x1,x2;//abscisse resp du perso et de l enemi 
float y1,y2;//ordonee resp du perso et de l enemi
float R1,R2;//rayon du cercle circonstrit resp au perso et de l enemi 
float D1,D2;
float result=0;

//initialisation
x1=pos_perso.x;
y1=pos_perso.y;
x2=pos_enemi.x;
y2=pos_enemi.y;
// 1-nous travaillons avec le cercle circonstrit a l'image


//2-determinons (X1,Y1) puis R1


w1=W1/2;
h1=H1/2;
//coordonnees finales
X1=x1+w1;
Y1=y1+h1;
// calcul de R1
R1=sqrt(pow(w1,2)+pow(h1,2));


//3-determinons (X2,Y2) puis R2

w2=W2/2;
h2=H2/2;
//coordonnees finales
X2=x2+w2;
y2=y2+h2;
// calcul de R1
R2=sqrt(pow(w2,2)+pow(h2,2));


//4-calcul de D1

D1=sqrt(pow(X1-X2,2)+pow(Y1-Y2,2));

//5- calcul de D2
D2=R1+R2;

//comparaison

if(D1<=D2)
{
result=1;
}
return result;
}
