#include "main.h"


int main ( int argc, char** argv )
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface *screen=NULL;
    SDL_Surface *background=NULL;
    buttons b;
    screen=SDL_SetVideoMode (800,600,0,SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Esprit Run 2000",NULL);//titre de la fenetre
    SDL_WarpMouse(screen->w / 2, screen->h / 2);
    SDL_EnableKeyRepeat(100,100);
    background =SDL_LoadBMP("menu.bmp");
    SDL_Rect background_pos;
    SDL_Rect pxy,pxin,pxset,pxexit;
    SDL_Event event;
    background_pos.x=0;
    background_pos.y=0;
    pxy.x=328;
    pxy.y=443;

    pxin.x=328;
    pxin.y=481;

    pxset.x=328;
    pxset.y=519;

    pxexit.x=328;
    pxexit.y=557;
    int pp=2,op=0,ex=0,ins=0,t;
    int done=1;
    int motion=330;
    b.play[0]=SDL_LoadBMP("play0.bmp");
    b.play[1]=SDL_LoadBMP("play1.bmp");
    b.play[2]=SDL_LoadBMP("play2.bmp");
    b.instructions[0]=SDL_LoadBMP("instructions0.bmp");
    b.instructions[1]=SDL_LoadBMP("instructions1.bmp");
    b.instructions[2]=SDL_LoadBMP("instructions2.bmp");
    b.setting[0]=SDL_LoadBMP("setting0.bmp");
    b.setting[1]=SDL_LoadBMP("setting1.bmp");
    b.setting[2]=SDL_LoadBMP("setting2.bmp");
    b.exit[0]=SDL_LoadBMP("exit0.bmp");
    b.exit[1]=SDL_LoadBMP("exit1.bmp");
    b.exit[2]=SDL_LoadBMP("exit2.bmp");

while (done!=0)
    {
        SDL_BlitSurface(background,NULL,screen,NULL);
        SDL_BlitSurface(b.play[pp],NULL,screen,&pxy);
        SDL_BlitSurface(b.instructions[ins],NULL,screen,&pxin);
        SDL_BlitSurface(b.setting[op],NULL,screen,&pxset);
        SDL_BlitSurface(b.exit[ex],NULL,screen,&pxexit);
        SDL_Flip(screen);
        t=0;
        if (SDL_WaitEvent(&event))
        {
            switch(event.type)
            {
            case SDL_QUIT :
                if (quit(screen)==1)
                    done=0;
                break;
            case SDL_KEYDOWN:

                switch(event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                   if (quit(screen)==1)
                        done=0;
                    break;
                case SDLK_UP:
                    if (pp==1 && t==0)
                    {
                        ex=1;
                        pp=0;
                        op=0;
                        ins=0;
                        t=1;
                    }
                    else if(ins==1 && t==0)
                    {
                        pp=1;
                        op=0;
                        ex=0;
                        ins=0;
                        t=1;
                    }
                    else if (op==1 && t==0)
                    {
                        ins=1;
                        ex=0;
                        pp=0;
                        op=0;
                        t=1;
                    }
                    else if (ex==1 && t==0)
                    {
                        op=1;
                        ex=0;
                        pp=0;
                        ins=0;
                        t=0;
                    }
                    break;
                case SDLK_DOWN:
                    if (pp==1 && t==0)
                    {
                        ins=1;
                        ex=0;
                        op=0;
                        pp=0;
                        t=1;
                    }
                    else if(ins==1 && t==0)
                    {
                        pp=0;
                        op=1;
                        ex=0;
                        ins=0;
                        t=1;
                    }
                    else if (op==1 && t==0)
                    {
                        ex=1;
                        pp=0;
                        ins=0;
                        op=0;
                        t=1;
                    }
                    else if (ex==1 && t==0)
                    {
                        pp=1;
                        op=0;
                        ins=0;
                        ex=0;
                        t=1;
                    }
                    break;
                case SDLK_RETURN:
                    if (pp==1)
                    {
                        SDL_BlitSurface(b.play[2],NULL,screen,&pxy);
                        SDL_Flip(screen);
                        //SDL_Delay(200);
                        //return NEW_GAME;
                    }
                    else if (ins==1)
                    {
                         SDL_BlitSurface(b.instructions[2],NULL,screen,&pxin);
                        SDL_Flip(screen);
                      instructions(screen);
                       ins=0;

                        //SDL_Delay(200);

                        //return OPTION;
                    }
                    else if (op==1)
                    {
                        SDL_BlitSurface(b.setting[2],NULL,screen,&pxset);
                        SDL_Flip(screen);
                        //SDL_Delay(200);
                        option(screen);
                    }
                    else if (ex==1)
                    {
                        SDL_BlitSurface(b.exit[2],NULL,screen,&pxexit);
                        SDL_Flip(screen);
                    if (quit(screen)==1)
                            done=0;
                        //SDL_Delay(200);
                    }
                    break;
                }
                break;
            case SDL_MOUSEMOTION:
                ex=0;
                pp=0;
                op=0;
                t=0;
                if ((event.motion.x>motion)&&(event.motion.y>motion+117)&&(event.motion.x<motion+131)&&(event.motion.y<motion+145) && (t==0) && (pp==0))
                {
                    pp=1;
                    ex=0;
                    ins=0;
                    op=0;
                    t=1;
                }
                else if ((event.motion.x>motion)&&(event.motion.y>motion+155)&&(event.motion.x<motion+152)&&(event.motion.y<motion+183) &&(t==0)&& (ins==0))
                {
                    ex=0;
                    pp=0;
                    ins=1;
                    op=0;
                    t=1;
                }
                else if ((event.motion.x>motion)&&(event.motion.y>motion+193)&&(event.motion.x<motion+190)&&(event.motion.y<motion+221)&&(t==0)&& (op==0))
                {
                    ex=0;
                    pp=0;
                    ins=0;
                    op=1;
                    t=1;
                }
                else if ((event.motion.x>motion)&&(event.motion.y>motion+231)&&(event.motion.x<motion+228)&&(event.motion.y<motion+259)&&(t==0)&& (ex==0))
                {
                    ex=1;
                    pp=0;
                    ins=0;
                    op=0;
                    t=1;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button==SDL_BUTTON_LEFT)
                {
                    if ((event.motion.x>motion) && (event.motion.y>motion+117) && (event.motion.x<motion+131) && (event.motion.y<motion+145)&&(pp==1))
                    {
                        pp=2;
                        //SDL_Delay (200);
                        //play(screen);
                        //return NEW_GAME;
                    }
                    else if ((event.motion.x>motion) && (event.motion.y>motion+155) && (event.motion.x<motion+152) && (event.motion.y<motion+183)&&(ins==1))
                    {

                        SDL_BlitSurface(b.instructions[2],NULL,screen,&pxin);
                        SDL_Flip(screen);
                        instructions(screen);
                       //ins=0;



                        //SDL_Delay (200);
                        //return OPTION;
                    }
                    else if ((event.motion.x>motion) && (event.motion.y>523) && (event.motion.x<520) && (event.motion.y<551)&&(op==1))
                    {
                        op=2;
                        option(screen);
                        //SDL_Delay (200);
                        //return OPTION;
                    }
                    else if (ex==1)
                    {
                        SDL_BlitSurface(b.exit[2],NULL,screen,&pxexit);
                        SDL_Flip(screen);
                        //SDL_Delay (200);
                        if (quit(screen)==1)
                            done=0;

                    }
                }
                break;
            }
        }
    }
    SDL_FreeSurface(background);
    SDL_FreeSurface(b.play[2]);
    SDL_FreeSurface(b.setting[2]);
    SDL_FreeSurface(b.exit[2]);
    SDL_FreeSurface(b.instructions[2]);
    SDL_Quit();
    return 0 ;
    }
void cleanmenu(SDL_Surface *background)
{
    buttons b;
    SDL_FreeSurface(background);
    SDL_FreeSurface(b.play[2]);
    SDL_FreeSurface(b.setting[2]);
    SDL_FreeSurface(b.exit[2]);
    SDL_FreeSurface(b.instructions[2]);

}
