/*!
* @file fonctions.c
* @brief Testing Program
* @author axel
* @version 1.0
* @date Apr 24, 2019
* Testing program related to the characters
*
 */
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include "math.h"
#include "defs.h"
#include "fonctions.h"

/**
* @brief to initialise the characters
* @param *perso  the PERSONAGE
* @return nothing
*/ 


void initPerso(PERSONAGE *perso)
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


//initialisation des autres champs
perso->score=0;
strcpy(perso->nom_joueur,"joueur1");
perso->V.val=3;//nombre de vie
//position perso
perso->pos_perso.x=SCREEN_W/2;
perso->pos_perso.y=SCREEN_H/+10;

//position vie du perso
perso->V.pos_vie.x=250;
perso->V.pos_vie.y=5;

// mobilite du personnage
perso->velocity=0; //velocity=0
perso->acceleration=0;
perso->moving=0;
}

/**
* @brief to frre the characters
* @param *p the PERSONAGE
* @return nothing
*/ 

void freePerso(PERSONAGE *P)
{
	int i;
	for(i=0; i<4; i++)
		SDL_FreeSurface(P->tab_img[i]);
}

/**
* @brief to load the characters pictures
* @param *perso the Personage
* @return int 
*/ 

int loadPersoImages(PERSONAGE *perso)
{
//chargement tableau d images du perso
        perso->tab_img[0] = IMG_Load("detective.png");
	if(perso->tab_img[0]==NULL)
	{
	  printf("Unable to load tab_img[0]:%s\n",SDL_GetError());
	return (-1);	 
	}

        perso->tab_img[1] = IMG_Load("detective.png");
	if(perso->tab_img[1]==NULL)
	{
	  printf("Unable to load tab_img[1]:%s\n",SDL_GetError());
	return (-1);	  
	}

        perso->tab_img[2] = IMG_Load("detective.png");
	if(perso->tab_img[2]==NULL)
	{
	  printf("Unable to load tab_img[2]:%s\n",SDL_GetError());
	return (-1);	
	}

        perso->tab_img[3] = IMG_Load("detective.png");
	if(perso->tab_img[3]==NULL)
	{
	  printf("Unable to load tab_img[3]:%s\n",SDL_GetError());	
	return (-1);
        }

        perso->tab_img[4] = IMG_Load("detective.png");
	if(perso->tab_img[4]==NULL)
	{
	  printf("Unable to load tab_img[4]:%s\n",SDL_GetError());	
	return (-1);
        }
//VIE
        
         //chargement surface vie du perso
        perso->V.surface_vie=IMG_Load("vie0.png");
	if(perso->V.surface_vie==NULL)
	{
	  printf("Unable to load perso->V.surface_vie:%s\n",SDL_GetError());	
	return (-1);
        } 

         //chargement tableau d images de la vie du perso
        perso->V.tab_img[0]=IMG_Load("vie0.png");
	if(perso->V.tab_img[0]==NULL)
	{
	  printf("Unable to load image_vie,tab_img[0]:%s\n",SDL_GetError());	
	return (-1);
        }

        perso->V.tab_img[1]=IMG_Load("vie1.png");
	if(perso->V.tab_img[1]==NULL)
	{
	  printf("Unable to load image_vie,tab_img[1]:%s\n",SDL_GetError());	
	return (-1);
        }

        perso->V.tab_img[2]=IMG_Load("vie2.png");
	if(perso->V.tab_img[2]==NULL)
	{
	  printf("Unable to load image_vie,tab_img[2]:%s\n",SDL_GetError());	
	return (-1);
        }

        perso->V.tab_img[3]=IMG_Load("vie3.png");
	if(perso->V.tab_img[3]==NULL)
	{
	  printf("Unable to load image_vie,tab_img[3]:%s\n",SDL_GetError());	
	return (-1);
        }
return (0);
}

/**
* @brief to move the characters
* @param *P the PERSONAGE
* @param b the background
* @param dt the Uint32
* @return nothing
*/ 

void movePerso(PERSONAGE *P,Background *B,Uint32 dt)
{
Uint32 t=SDL_GetTicks();
if(P->direction==2)//cas personnage immobile -> saut vertical 
 {
printf("cos(alpha)=%f\n",cos(alpha));
printf("P->velocity1=%2.f\n",P->velocity);
printf("P->pos_perso.x1=%d\n",P->pos_perso.x);
printf("P->pos_perso.y1=%d\n",P->pos_perso.y);
 P->pos_perso.x=(P->velocity)*cos(alpha)*t + P->pos_perso.x;
 P->pos_perso.y=-g/(2*pow(P->velocity,2)*pow(cos(alpha),2))*pow(P->pos_perso.x,2) + tan(alpha)*P->pos_perso.x + P->pos_perso.y;
printf("P->pos_perso.x2=%d\n",P->pos_perso.x);
printf("P->pos_perso.y2=%d\n",P->pos_perso.y);
 }

B->backgroundPos.x=B->backgroundPos.x + 0.5*(P->acceleration)*(dt*dt) + (P->velocity)*dt;//velocity line

}


/**
* @brief to load the background Backg.
* @param *Backg the background
* @return int 
*/ 

int loadBackground(Background *Backg)
{
	// load background
	Backg->backgroundImg = SDL_LoadBMP("background.bmp");
	if (Backg->backgroundImg == NULL) {
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return (-1);
	}

	Backg->backgroundCollide = SDL_LoadBMP("background.bmp");
	if (Backg->backgroundCollide == NULL) {
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return (-1);
	}
	return (0);
}


/**
* @brief to initialise the background Backg.
* @param *Backg the background
* @return nothing
*/

void initBackground(Background *Backg)
{
	Backg->backgroundPos.x=0;
	Backg->backgroundPos.y=0;
	Backg->backgroundPos.w=SCREEN_W;
	Backg->backgroundPos.h=SCREEN_H;
}


/**
* @brief to show the background b.
* @param screen the screen
* @param b the background
* @return nothing
*/ 
void blitBackground(Background*Backg,SDL_Surface *screen)
{

	if(Backg->backgroundPos.x>Backg->backgroundImg->w-SCREEN_W)
		Backg->backgroundPos.x=0;
	if(Backg->backgroundPos.x<0)
		Backg->backgroundPos.x=Backg->backgroundImg->w-SCREEN_W;
	SDL_BlitSurface(Backg->backgroundImg, &(Backg->backgroundPos), screen,NULL); 

}

/**
* @brief to free the background b.
* @param b the background
* @return nothing
*/ 

void freeBackground(Background *Backg)
{
	SDL_FreeSurface(Backg->backgroundImg);
}


/**
* @brief to play the game
* @param screen the screen
* @return int
*/ 

int jouer(SDL_Surface * screen)
{
	int done = 0;
	int i=0,t;
	Uint32 t_prev, dt=0; //time variables

        double v_y =v_saut;
	
	PERSONAGE perso;
	Background Backg;
	//Text txt;
	
	SDL_Event event;
	int keysHeld[323] = {0}; // everything will be initialized to false
	
	//TTF_Font *police = NULL;

	if(loadPersoImages(&perso) == -1) {
		printf("Erreuer Chargement Voiture Images\n");
		return(-1);

	}

	if(loadBackground(&Backg) == -1) {
		printf("Erreuer Chargement Background Images\n");
		return(-1);
	}


	initBackground(&Backg);
	initPerso(&perso);

	// program Game loop
	SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);


	while(!done) {

                  t_prev=SDL_GetTicks();////

		SDL_PollEvent(&event) ;
               
			// check for messages
			switch (event.type) 
                        {
				// exit if the window is closed
			case SDL_QUIT:
				done = 1;
				break;
			case SDL_KEYDOWN:
				perso.moving=1; //lets move
				keysHeld[event.key.keysym.sym] = 1;
				break;
			case SDL_KEYUP:
				keysHeld[event.key.keysym.sym] = 0;
				break;
                        }
			// exit if ESCAPE is pressed ou fin switch
			if (keysHeld[SDLK_ESCAPE])   
				done = 1;
			else if(keysHeld[SDLK_RIGHT]) {
                                perso.acceleration=0.05;
				perso.velocity+=0.01;
				perso.direction=0;//right direction
				movePerso(&perso,&Backg,dt);
				i++;
			}
			else if(keysHeld[SDLK_LEFT]) {
                                perso.acceleration=0.05;
				perso.velocity-=0.01;
				perso.direction=1;//right direction
				movePerso(&perso,&Backg,dt);
				i++;
			}
			else if(keysHeld[SDLK_UP]) {
				perso.direction=2;//UP direction
				movePerso(&perso,&Backg,dt);
				i++;
                               /*if(dt>2)
                               {
				t=1;
				perso.pos_perso.x+=v_x;
				perso.pos_perso.y+=v_y;
                               //evolution de vla vitesse verticale
				v_y+=v_grav;
			       }
				if(t==1)
				{
				   if(perso.pos_perso.y > 100)
					{
					perso.pos_perso.y=100;
					t=0;
					}
				}*/
			}
			else if (perso.moving==1&&perso.direction==0){
                                perso.acceleration=0.001;
                                if(perso.velocity > 0)
				perso.velocity-=0.05;
				perso.direction=0;//right direction
				movePerso(&perso,&Backg,dt);
				i++;
			}
			else if (perso.moving==1&&perso.direction==1){
                                perso.acceleration=0.001;
				if(perso.velocity <= 0)
				perso.velocity+=0.05;
				perso.direction=1;//left direction
				movePerso(&perso,&Backg,dt);
				i++;
			}

                   if (perso.velocity == 0 )
                         perso.moving=0;//pour ne pas avoir de vitesse negative
		 
                        if(!perso.moving)
			i=0;//mise a l etat initiale du personage
                        else
		         i=i%4;
		//Blit the bachground and perso to the backbuffer
		blitBackground(&Backg,screen);
		afficher_perso(perso,screen);
		
		//if(car.direction == 0)
			   //SDL_BlitSurface(perso.tab_img[i],NULL,screen,&perso.pos_perso);
			
		//displayText(police,&txt,screen,car,Backg,0);
		
		SDL_Flip(screen);
		
	   dt=SDL_GetTicks()-t_prev;
    if(1000/FPS > dt)
      {
         SDL_Delay(1000/FPS-dt);
             }//fin if	
		
	}// end of  loop

	                // free loaded bitmap

	freePerso(&perso);
	freeBackground(&Backg);
	//TTF_CloseFont(police);
	return(0);
}

/**
* @brief to show the characters perso.
* @param screen the screen
* @param *perso the characters
* @return nothing
*/ 
void afficher_perso(PERSONAGE perso,SDL_Surface *screen)
{
SDL_BlitSurface(perso.V.surface_vie,NULL,screen,&(perso.V.pos_vie));
SDL_BlitSurface(perso.surface_perso,NULL,screen, &perso.pos_perso);
}


