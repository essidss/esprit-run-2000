#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

//#define W1 170
//#define H1 309
//#define W2 347
//#define H2 169

typedef struct 
{
SDL_Rect pos_vie ;  
int val ;
SDL_Surface *tab_img[4];
SDL_Surface *surface_vie; 
}vie;

typedef struct
{
int score;
vie V;
char nom_joueur[30];
SDL_Rect pos_perso;
SDL_Surface *tab_img[5];// ajouter les images 
SDL_Surface *surface_perso;// image qui sera modifiee dans la fonction animer
}PERSONAGE;


int collision_trigo(SDL_Rect pos_perso,SDL_Rect pos_enemi);
void init_perso(PERSONAGE *perso);
void afficher_perso(PERSONAGE perso,SDL_Surface *screen);
void depacer_perso(PERSONAGE *perso,SDL_Event event);
#endif /* FONCTIONS_H_ */
