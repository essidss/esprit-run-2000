#ifndef TACHES_H_INCLUDED
#define TACHES_H_INCLUDED
typedef struct
{
SDL_Rect pos_enemi;
SDL_Surface *tab_image[5];// ajouter les images
SDL_Surface *surface_enemi;// animimation enemi
}ENEMI;

void init_enemi(ENEMI *enemi);
void afficher_enemi(ENEMI enemi,SDL_Surface *screen);
int collision_boundingbox(SDL_Rect pos_perso,SDL_Rect pos_enemi);

#endif // TACHES_H_INCLUDED
