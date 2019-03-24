#ifndef FONCTIONS_H_
#define FONCTIONS_H_
typedef struct
{
int score;
int vie;
char nom_joueur[30];
SDL_Rect pos_perso;
}PERSONAGE;

void init_perso(PERSONAGE *perso,SDL_Surface *personages[]);
int afficher_perso(SDL_Surface *personages[],SDL_Surface *Surface_perso,SDL_Surface * screen);
void deplacement_perso(SDL_Surface *personages[],SDL_Surface * screen,SDL_Surface *Surface_perso);
int collision_trigo(SDL_Rect pos_perso,SDL_Rect pos_enemi);
#endif /* FONCTIONS_H_ */
