#include "menu.h"





int temps(int , char )

{

    SDL_Event event;

    SDL_Surface *ecran=NULL, *personnage=NULL;

    SDL_Rect positionpersonnage;

    int continuer=1, tempsPrecedent=0, tempsActuel=0, versLaDroite=1,
     versLaGauche=1, versLeHaut=1, versLeBas=1, activerpersonnage=1;



    SDL_Init(SDL_INIT_VIDEO);

    SDL_WM_SetCaption("Gestion du temps en SDL", NULL);

    ecran=SDL_SetVideoMode(640,480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    personnage=SDL_LoadBMP("personnage.bmp");

    SDL_SetColorKey(personnage, SDL_SRCCOLORKEY, SDL_MapRGB(personnage->format, 0, 0, 255));



    positionpersonnage.x=(ecran->w/2)-(personnage->w/2);

    positionpersonnage.y=(ecran->h/2)-(personnage->h/2);



    SDL_EnableKeyRepeat(10, 10);



    while (continuer)

    {

        SDL_PollEvent(&event);



        switch (event.type)

        {

        case SDL_QUIT:

            continuer=0;

            break;

        case SDL_KEYDOWN:

            switch (event.key.keysym.sym)

            {

            case SDLK_p:

                activerpersonnage=0;

                break;

            }

        }



        if (activerpersonnage==1)

        {

           tempsActuel=SDL_GetTicks();



      if (tempsActuel-tempsPrecedent >10)

        {

            if (positionpersonnage.x==ecran->w - personnage->w)

            {

                versLaDroite=0;

                versLaGauche=1;

            }

            else if (positionpersonnage.x==0)

            {

                versLaGauche=0;

                versLaDroite=1;

            }

            if (versLaDroite)

            {

                positionpersonnage.x++;

            }

            else if (versLaGauche)

            {

                positionpersonnage.x--;

            }



            tempsPrecedent=tempsActuel;

        }

        else

        {

            SDL_Delay (10 - (tempsActuel-tempsPrecedent));

        }

        }





        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

        SDL_BlitSurface(personnage, NULL, ecran, &positionpersonnage);

        SDL_Flip(ecran);

    }



    SDL_FreeSurface(personnage);







    SDL_Quit();



    return EXIT_SUCCESS;

}


