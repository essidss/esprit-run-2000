#include "menu.h"
void gameOver(){

SDL_BlitSurface(gameOverSurface,NULL,ecran,NULL);
SDL_Flip(ecran);
SDL_Delay(5000);/* 5 secondes */

}
int vieandscore(int score)
{ if(score>=0){
    switch (niveau){
   case 1 ;
       if (reponse==1){
         score=score+15;
                        }
       else{score=score-15;}
      }break;
   case 2 ;
       if (reponse==1){
         score=score+20;
                        }
       else{score=score-20;}
      }break;

   case 3 ;
       if (reponse==1){
         score=score+25;
                        }
       else{score=score-25;}
      }break;

 }
else
{
 gameOver();
continuer = false;

  }
return score;

}
