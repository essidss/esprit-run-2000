#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

void initialiser(SDL_Surface *screen,buttons but)
{
    //normal buttons
    but.button[1]=SDL_LoadBMP("play0.bmp");
    but.button[2]=SDL_LoadBMP("instructions0.bmp");
    but.button[3]=SDL_LoadBMP("setting0.bmp");
    but.button[4]=SDL_LoadBMP("exit0.bmp");
    but.button[5]=SDL_LoadBMP("back.bmp");
    but.button[6]=SDL_LoadBMP("yes.bmp");
    but.button[7]=SDL_LoadBMP("no.bmp");
    //selected buttons
    but.button_select[1]=SDL_LoadBMP("play1.bmp");
    but.button_select[2]=SDL_LoadBMP("instructions1.bmp");
    but.button_select[3]=SDL_LoadBMP("setting1.bmp");
    but.button_select[4]=SDL_LoadBMP("exit1.bmp");
    but.button_select[5]=SDL_LoadBMP("backselected.bmp");
    but.button_select[6]=SDL_LoadBMP("yes selected.bmp");
    but.button_select[7]=SDL_LoadBMP("no selected.bmp");
    //clicked buttons
    but.button_clicked[1]=SDL_LoadBMP("play2.bmp");
    but.button_clicked[1]=SDL_LoadBMP("instructions2.bmp");
    but.button_clicked[1]=SDL_LoadBMP("setting2.bmp");
    but.button_clicked[1]=SDL_LoadBMP("exit2.bmp");
    but.button_clicked[1]=SDL_LoadBMP("backclicked.bmp");
    but.button_clicked[1]=SDL_LoadBMP("yes clicked.bmp");
    but.button_clicked[1]=SDL_LoadBMP("no clicked.bmp");
    //playbutton postions
    but.posbutton[1].x=328;
    but.posbutton[1].y=443;
    //instruction postions
    but.posbutton[2].x=328;
    but.posbutton[2].y=481;
    //settings postions
    but.posbutton[3].x=328;
    but.posbutton[3].y=519;
    //exit postions
    but.posbutton[4].x=328;
    but.posbutton[4].y=557;
    //backbutton postions
    but.posbutton[5].x=570;
    but.posbutton[5].y=450;
    //yes button postions
    but.posbutton[6].x=50;
    but.posbutton[6].y=450;
    //no button postions
    but.posbutton[7].x=570;
    but.posbutton[7].y=450;
    }
/*void objects (SDL_Surface * screen)
{
    SDL_Surface *object;
    SDL_Rect posobj;

    int done=1;
    posobj.x=0;
    posobj.y=0;

    //object=SDL_LoadBMP("object.bmp");
    while(done!=0)
    {
        SDL_BlitSurface(object,NULL,screen,&posobj);
        SDL_Flip(screen);
    }
    SDL_FreeSurface(object);
}*/
void enigmes (SDL_Surface * screen)
{
    SDL_Surface *enigme;
    SDL_Rect posenig;

    int done=1;
    posenig.x=0;
    posenig.y=0;

    enigme=SDL_LoadBMP("enigmes.bmp");
    while (done!=0)
    {
        SDL_BlitSurface(enigme,NULL,screen,&posenig);
        SDL_Flip(screen);
    }
    SDL_FreeSurface(enigme);
}
void instructionss (SDL_Surface *screen)
{
    SDL_Surface *bg,*backbutton[3],*instructionsbutton;
    SDL_Rect pos,posback;
    SDL_Event event;
    int done=1,n=1;
    pos.x=125;
    pos.y=200;

    posback.x=570;
    posback.y=450;

    bg=SDL_LoadBMP("menu.bmp");
    backbutton[0]=SDL_LoadBMP("instructions.bmp");
    backbutton[1]=SDL_LoadBMP("back.bmp");
    backbutton[2]=SDL_LoadBMP("backselected.bmp");
    backbutton[3]=SDL_LoadBMP("backclicked.bmp");
    while (done!=0)
    {
        SDL_BlitSurface(backbutton[0],NULL,screen,&pos);
        SDL_BlitSurface(backbutton[n],NULL,screen,&posback);
        SDL_Flip(screen);
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_KEYDOWN:

            switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                done=0;
                break;
            }
            case SDL_MOUSEMOTION:
                if ((event.motion.x>570) && (event.motion.y>450) && (event.motion.x<735) && (event.motion.y<500))
                {
                    n=2;
                }else
                {
                    n=1;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                if ((event.motion.x>570) && (event.motion.y>450) && (event.motion.x<735) && (event.motion.y<500))
                {
                    SDL_BlitSurface(backbutton[3],NULL,screen,&posback);
                    SDL_Flip(screen);
                    SDL_Delay(50);
                    done=0;
                    //return 1;
                    //SDL_FreeSurface(backbutton[1]);
                   // SDL_FreeSurface(backbutton[2]);
                }
                break;
    }

}
SDL_FreeSurface(backbutton[n]);
}
int quit (SDL_Surface *screen)
{
    SDL_Surface *bg,*exit[7],*exitback;
    int n=6,t,done=1;;
    SDL_Rect pos,posyes,posno;
    SDL_Event event;
    pos.x=130;
    pos.y=200;

    posyes.x=50;
    posyes.y=450;

    posno.x=570;
    posno.y=450;

    bg=SDL_LoadBMP("menu.bmp");
    exit[6]=SDL_LoadBMP("exit.bmp");
    exit[0]=SDL_LoadBMP("yes.bmp");
    exit[1]=SDL_LoadBMP("no.bmp");
    exit[2]=SDL_LoadBMP("yes selected.bmp");
    exit[3]=SDL_LoadBMP("no selected.bmp");
    exit[4]=SDL_LoadBMP("yes clicked.bmp");
    exit[5]=SDL_LoadBMP("no clicked.bmp");
    while(done!=0)
    {
        SDL_BlitSurface(bg,NULL,screen,NULL);
        //SDL_BlitSurface(exitback,NULL,screen,&pos);
        if (n==2)
        {
            SDL_BlitSurface(exit[6],NULL,screen,&pos);
            SDL_BlitSurface(exit[n],NULL,screen,&posyes);
            SDL_BlitSurface(exit[1],NULL,screen,&posno);
            SDL_Flip(screen);
        }
        else if (n==3)
        {
            SDL_BlitSurface(exit[6],NULL,screen,&pos);
            SDL_BlitSurface(exit[n],NULL,screen,&posno);
            SDL_BlitSurface(exit[0],NULL,screen,&posyes);
            SDL_Flip(screen);
        }
        else
        {
            SDL_BlitSurface(exit[6],NULL,screen,&pos);
            SDL_BlitSurface(exit[0],NULL,screen,&posyes);
            SDL_BlitSurface(exit[1],NULL,screen,&posno);
            SDL_Flip(screen);
        }
        SDL_WaitEvent(&event);
        t=0;
        switch(event.type)
        {
        case SDL_KEYDOWN:


            switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                done=0;
                break;
            case SDLK_LEFT:

                if (n==2 && t==0)
                {
                    n++;
                    t=1;
                }
                else if (n==3 && t==0)
                {
                    n--;
                    t=1;
                }
                break;
            case SDLK_RIGHT:
                if (n==2 && t==0)
                {
                    n++;
                    t=1;
                }
                else if (n==3 && t==0)
                {
                    n--;
                    t=1;
                }
                break;
            case SDLK_RETURN:
                if (n==2)
                {
                    SDL_BlitSurface(exit[4],NULL,screen,&posyes);
                    SDL_Flip(screen);
                    //SDL_Delay (200);
                    SDL_FreeSurface(bg);
                    SDL_FreeSurface(exit[n]);
                    return 1;
                }
                else if (n==3)
                {
                    SDL_BlitSurface(exit[5],NULL,screen,&posno);
                    SDL_Flip(screen);
                    //SDL_Delay (200);
                    SDL_FreeSurface(bg);
                    SDL_FreeSurface(exit[n]);
                    return 0;
                }
                break;
            }
            break;
        case SDL_MOUSEMOTION:
            n=6;
            //printf("%d,%d\n",event.motion.x,event.motion.y);
            if ((event.motion.x>50) && (event.motion.y>450) && (event.motion.x<208) && (event.motion.y<500))
            {
                n=2;
            }
            else if ((event.motion.x>570) && (event.motion.y>450) && (event.motion.x<735) && (event.motion.y<500))
            {
                n=3;
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            if ((event.motion.x>50) && (event.motion.y>450) && (event.motion.x<208) && (event.motion.y<500))
            {
                SDL_BlitSurface(exit[4],NULL,screen,&posyes);
                SDL_Flip(screen);
                //SDL_Delay (200);
                return 1;
            }
            else if ((event.motion.x>570) && (event.motion.y>450) && (event.motion.x<735) && (event.motion.y<500) )
            {
                SDL_BlitSurface(exit[5],NULL,screen,&posno);
                SDL_Flip(screen);
                SDL_Delay (50);
                return 0;
            }
            break;
        }
    }

}
void menu (SDL_Surface *screen)
{
    SDL_Surface *background=NULL;
    background =SDL_LoadBMP("menu.bmp");
    SDL_Rect background_pos;
    background_pos.x=0;
    background_pos.y=0;
    SDL_Surface *play[3],*instructions[3],*setting[3],*exit[3];
    SDL_Rect pos;
    SDL_Rect pxy,pxin,pxset,pxexit;
    pos.x=0;
    pos.y=0;
    pxy.x=328;
    pxy.y=443;

    pxin.x=328;
    pxin.y=481;

    pxset.x=328;
    pxset.y=519;

    pxexit.x=328;
    pxexit.y=557;
    SDL_Event event;
    int pp=1,op=0,ex=0,ins=0,t,s,save;
    play[0]=SDL_LoadBMP("play0.bmp");
    play[1]=SDL_LoadBMP("play1.bmp");
    play[2]=SDL_LoadBMP("play2.bmp");
    instructions[0]=SDL_LoadBMP("instructions0.bmp");
    instructions[1]=SDL_LoadBMP("instructions1.bmp");
    instructions[2]=SDL_LoadBMP("instructions2.bmp");

    setting[0]=SDL_LoadBMP("setting0.bmp");
    setting[1]=SDL_LoadBMP("setting1.bmp");
    setting[2]=SDL_LoadBMP("setting2.bmp");
    exit[0]=SDL_LoadBMP("exit0.bmp");
    exit[1]=SDL_LoadBMP("exit1.bmp");
    exit[2]=SDL_LoadBMP("play2.bmp");

    int done=1;
    while (done!=0)
    {
        SDL_BlitSurface(background,NULL,screen,&pos);
        SDL_BlitSurface(play[pp],NULL,screen,&pxy);
        SDL_BlitSurface(instructions[ins],NULL,screen,&pxin);
        SDL_BlitSurface(setting[op],NULL,screen,&pxset);
        SDL_BlitSurface(exit[ex],NULL,screen,&pxexit);
        SDL_Flip(screen);
        t=0;
        s=0;
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
                        SDL_BlitSurface(play[2],NULL,screen,&pxy);
                        SDL_Flip(screen);
                        //SDL_Delay(200);
                        //return NEW_GAME;
                    }
                    else if (ins==1)
                    {
                         SDL_BlitSurface(instructions[2],NULL,screen,&pxin);
                        SDL_Flip(screen);
                       instructionss(screen);
                       ins=0;

                        //SDL_Delay(200);

                        //return OPTION;
                    }
                    else if (op==1)
                    {
                        SDL_BlitSurface(setting[2],NULL,screen,&pxset);
                        SDL_Flip(screen);
                        //SDL_Delay(200);
                    }
                    else if (ex==1)
                    {
                        SDL_BlitSurface(exit[2],NULL,screen,&pxexit);
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
                if ((event.motion.x>330)&&(event.motion.y>447)&&(event.motion.x<461)&&(event.motion.y<475) && (t==0) && (pp==0))
                {
                    pp=1;
                    ex=0;
                    ins=0;
                    op=0;
                    t=1;
                }
                else if ((event.motion.x>330)&&(event.motion.y>485)&&(event.motion.x<482)&&(event.motion.y<513) &&(t==0)&& (ins==0))
                {
                    ex=0;
                    pp=0;
                    ins=1;
                    op=0;
                    t=1;
                }
                else if ((event.motion.x>330)&&(event.motion.y>523)&&(event.motion.x<520)&&(event.motion.y<551)&&(t==0)&& (op==0))
                {
                    ex=0;
                    pp=0;
                    ins=0;
                    op=1;
                    t=1;
                }
                else if ((event.motion.x>330)&&(event.motion.y>561)&&(event.motion.x<558)&&(event.motion.y<589)&&(t==0)&& (ex==0))
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
                    if ((event.motion.x>330) && (event.motion.y>447) && (event.motion.x<461) && (event.motion.y<475)&&(pp==1))
                    {
                        pp=2;
                        //SDL_Delay (200);
                        //play(screen);
                        //return NEW_GAME;
                    }
                    else if ((event.motion.x>330) && (event.motion.y>485) && (event.motion.x<482) && (event.motion.y<513)&&(ins==1))
                    {

                        SDL_BlitSurface(instructions[2],NULL,screen,&pxin);
                        SDL_Flip(screen);
                       instructionss(screen);
                       ins=0;



                        //SDL_Delay (200);
                        //return OPTION;
                    }
                    else if ((event.motion.x>330) && (event.motion.y>523) && (event.motion.x<520) && (event.motion.y<551)&&(op==1))
                    {
                        op=2;
                        //SDL_Delay (200);
                        //return OPTION;
                    }
                    else if (ex==1)
                    {
                        SDL_BlitSurface(exit[2],NULL,screen,&pos);
                        SDL_Flip(screen);
                        //SDL_Delay (200);
                        if (quit(screen)==1)
                            done= 0;
                    }
                }
                break;
            }
        }
    }
    SDL_FreeSurface(background);
    SDL_FreeSurface(play[2]);
    SDL_FreeSurface(setting[2]);
    SDL_FreeSurface(exit[2]);
    SDL_FreeSurface(play[0]);
    SDL_FreeSurface(play[1]);
    SDL_FreeSurface(setting[0]);
    SDL_FreeSurface(setting[1]);
    SDL_FreeSurface(instructions[0]);
    SDL_FreeSurface(exit[0]);
    SDL_FreeSurface(exit[1]);
}

int main ( int argc, char** argv )
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface *screen=NULL;
    screen=SDL_SetVideoMode (800,600,0,SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Esprit Run 2000",NULL);//titre de la fenetre
    SDL_WarpMouse(screen->w / 2, screen->h / 2);
    SDL_EnableKeyRepeat(100,100);
    menu(screen);
    SDL_Quit();
    return 0 ;
}
