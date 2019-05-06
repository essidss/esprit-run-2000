#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
#include <SDL/SDL.h>
#include "defs.h"

/**
* @struct background
* @brief struct for background
*/

struct Background{
	SDL_Surface *backgroundImg;/*!<Surface*/
	SDL_Surface *backgroundCollide;/*!<Surface*/
	SDL_Rect backgroundPos;/*!<Rectangle*/
};
typedef struct Background Background;


/**
* @struct vie
* @brief struct for vie
*/
typedef struct 
{
SDL_Rect pos_vie ; /*!<Rectangle*/ 
int val ;/*!<Int*/
SDL_Surface *tab_img[4];/*!<Surface*/
SDL_Surface *surface_vie; /*!<Surface*/
}vie;


/**
* @struct PERSONAGE
* @brief struct for PERSONAGE
*/
typedef struct
{
int score;/*!<Int*/
vie V;/*!<Vie*/
char nom_joueur[30];/*!<Char*/

SDL_Rect pos_perso;/*!<Rectangle*/
SDL_Surface *tab_img[5];/*!<Surface*/   // ajouter les images 
SDL_Surface *surface_perso;/*!<Surface*/ // image qui sera modifiee dans la fonction animer


int moving;/*!<Int*/   //1 if moving and 0 else
int direction;/*!<Int*/  // 0 right 1 left 2 up 3 down
float Mass;/*!<Float*/  

float acceleration;/*!<Float*/
float velocity;/*!<Float*/  //VITESSE

}PERSONAGE;

//background

int loadBackground(Background *Backg);
void initBackground(Background *Backg);
void freeBackground(Background *Backg);
void blitBackground(Background*Backg,SDL_Surface *screen);

//personnage

int loadPersoImages(PERSONAGE *P);
void initPerso(PERSONAGE *P);
void movePerso(PERSONAGE *P,Background *B,Uint32 dt);
void freePerso(PERSONAGE *P);
void afficher_perso(PERSONAGE perso,SDL_Surface *screen);
//void depacer_perso_clavier(PERSONAGE *perso,SDL_Event event);
//void depacer_perso_souris(PERSONAGE *perso,SDL_Event event,SDL_Surface *screen);

//jouer
int jouer(SDL_Surface * screen);

//colision trigo
int collision_trigo(SDL_Rect pos_perso,SDL_Rect pos_enemi);

#endif
