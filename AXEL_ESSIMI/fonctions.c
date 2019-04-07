#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL.h"
#include "fonctions.h"

//utiliser des define pour W1,W2,H1 ET H2 
const int W1=170;
const int H1=309;
const int W2=347;
const int H2=169;

int collision_trigo(SDL_Rect pos_perso,SDL_Rect pos_enemi)
{
 //float W1,W2;//largeur resp du perso et de l enemi 
//float H1,H2;//hauteur resp du perso et de l enemi 



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


R1=W1/2;
h1=H1/2;
//coordonnees finales
X1=x1+w1;
Y1=y1+h1;
// calcul de R1



//3-determinons (X2,Y2) puis R2

R2=W2/2;
h2=H2/2;
//coordonnees finales
X2=x2+w2;
y2=y2+h2;
// calcul de R1



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


 void init_perso(PERSONAGE *perso)
{ 
int i;
//initialisation

for(i=0;i<5;i++)
{
  perso->tab_img[i]=NULL;
}

for(i=0;i<4;i++)
{
  perso->V.tab_img[i]=NULL;
}

perso->surface_perso=NULL;
perso->V.surface_vie=NULL;

//PERSONAGE

//chargement surface perso
        perso->surface_perso=IMG_Load("detective.png");
	if(perso->surface_perso==NULL)
	{
	  printf("Unable to load perso->surface_perso:%s\n",SDL_GetError());	
	}
//chargement tableau d images du perso
        perso->tab_img[0] = IMG_Load("detective.png");
	if(perso->tab_img[0]==NULL)
	{
	  printf("Unable to load tab_img[0]:%s\n",SDL_GetError());	 
	}

        perso->tab_img[1] = IMG_Load("detective.png");
	if(perso->tab_img[1]==NULL)
	{
	  printf("Unable to load tab_img[1]:%s\n",SDL_GetError());	  
	}

        perso->tab_img[2] = IMG_Load("detective.png");
	if(perso->tab_img[2]==NULL)
	{
	  printf("Unable to load tab_img[2]:%s\n",SDL_GetError());	
	}

        perso->tab_img[3] = IMG_Load("detective.png");
	if(perso->tab_img[3]==NULL)
	{
	  printf("Unable to load tab_img[3]:%s\n",SDL_GetError());	
	}

        perso->tab_img[4] = IMG_Load("detective.png");
	if(perso->tab_img[4]==NULL)
	{
	  printf("Unable to load tab_img[4]:%s\n",SDL_GetError());	
	}
//VIE
        
         //chargement surface vie du perso
        perso->V.surface_vie=IMG_Load("vie0.png");
	if(perso->V.surface_vie==NULL)
	{
	  printf("Unable to load perso->V.surface_vie:%s\n",SDL_GetError());	
	}

         //chargement tableau d images de la vie du perso
        perso->V.tab_img[0]=IMG_Load("vie0.png");
	if(perso->V.tab_img[0]==NULL)
	{
	  printf("Unable to load image_vie,tab_img[0]:%s\n",SDL_GetError());	
	}
        perso->V.tab_img[1]=IMG_Load("vie1.png");
	if(perso->V.tab_img[1]==NULL)
	{
	  printf("Unable to load image_vie,tab_img[1]:%s\n",SDL_GetError());	
	}
        perso->V.tab_img[2]=IMG_Load("vie2.png");
	if(perso->V.tab_img[2]==NULL)
	{
	  printf("Unable to load image_vie,tab_img[2]:%s\n",SDL_GetError());	
	}
        perso->V.tab_img[3]=IMG_Load("vie3.png");
	if(perso->V.tab_img[3]==NULL)
	{
	  printf("Unable to load image_vie,tab_img[3]:%s\n",SDL_GetError());	
	}

//initialisation des autres champs
perso->score=0;
strcpy(perso->nom_joueur,"joueur1");
perso->V.val=3;//nombre de vie
//position perso
perso->pos_perso.x=500;
perso->pos_perso.y=300;

//position vie du perso
perso->V.pos_vie.x=250;
perso->V.pos_vie.y=5;
}

void afficher_perso(PERSONAGE perso,SDL_Surface *screen)
{
SDL_BlitSurface(perso.V.surface_vie,NULL,screen,&(perso.V.pos_vie));
SDL_BlitSurface(perso.surface_perso,NULL,screen, &perso.pos_perso);
}


void depacer_perso(PERSONAGE *perso,SDL_Event event)
{
 switch(event.type)
              {
               case SDL_KEYDOWN:
               
                  switch(event.key.keysym.sym)
                     {
                     case SDLK_UP:
                      perso->pos_perso.y -=10;
                       SDL_WaitEvent(&event);
                       break;
                     case SDLK_DOWN:
                       perso->pos_perso.y +=10;
                       SDL_WaitEvent(&event);
                       break;
                     case SDLK_LEFT:
                       perso->pos_perso.x -=10;
                       SDL_WaitEvent(&event);
                       break;
                     case SDLK_RIGHT:
                       perso->pos_perso.x +=10;
                       SDL_WaitEvent(&event);
                       break;
                    }
                break;
               case SDL_MOUSEBUTTONUP:

			if(event.button.button==SDL_BUTTON_LEFT)
		{
                    if(event.button.y < perso->pos_perso.y && event.button.x < perso->pos_perso.x )
                    {
                        while(perso->pos_perso.y > event.button.y)
                        {
                           perso->pos_perso.y-=10;
                        }
			while(perso->pos_perso.x > event.button.x)
                        {
                           perso->pos_perso.x-=10;
                        }			
                    }
//
                    if(event.button.x < perso->pos_perso.x && event.button.y > perso->pos_perso.y)
                    {
                       while(perso->pos_perso.x > event.button.x)
                        {
                           perso->pos_perso.x-=10;
                        }
 			while(perso->pos_perso.y < event.button.y)
                        {
                           perso->pos_perso.y+=10;
                        }
                    }
//
                    if(event.button.y < perso->pos_perso.y && event.button.x > perso->pos_perso.x)
                    {
                       while(perso->pos_perso.x < event.button.x)
                        {
                           perso->pos_perso.x+=10;
                        }
			while(perso->pos_perso.y < event.button.y)
                        {
                           perso->pos_perso.y+=10;
                        }			
                    }
//
                    if(event.button.x > perso->pos_perso.x && event.button.y > perso->pos_perso.y)
                    {
                       while(perso->pos_perso.x < event.button.x)
                        {
                           perso->pos_perso.x+=10;
                        }
			while(perso->pos_perso.y < event.button.y)
                        {
                           perso->pos_perso.y+=10;
                        }
                    }
		}//fin if choix du boutton

		break;
            }
}
