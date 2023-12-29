#include "mazedraw.h"
#include "variables.h"
#include "high_scores.h"
#include "check_functions.h"
#include "movements.h"
#include "savegame.h"
#include "screens.h"
#include "resume_game.h"
#include<windows.h>

void points_energizers();
void initialize_everything();
void level_up_func();
void compare();

void iDraw()
{
    iClear();
    if(paused_game==1)
    {
        paused_game_func();
    }
    else if(show_highscore==1)
    {
        show_highscore_func();
    }
     else if(instruction==1)
    {
        iShowBMP(0,0,"Images/instructions.bmp");
    }
    else if(no_saved_game==1)
    {
        no_saved_game();
    }
     else if(resume==1)
    {
        iShowBMP(0,0,"Images/background.bmp");
        resume_game_func();
    }
    else if(game_ended==1)
    {
        game_ended_func();
    }
    else if(start==1)
    {
        start_func();
    }
    else if(getting_name==1)
    {
        iShowBMP(0,0,"Images/background.bmp");
        iSetColor( 171, 235, 198);
        iText(7*20,25*20,"ENTER YOUR NAME:",GLUT_BITMAP_TIMES_ROMAN_24);
        iRectangle(8*20,20*20,10*20,3*20);
        iText(9*20,21*20,name,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(6*20+10,17*20,"MAXIMUM 10 LETTERS",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    else if(level_up==1)
    {
        iShowBMP(0,0,"Images/background.bmp");
        level_up_func();
    }
    else if(game_over==1)
    {
        iShowBMP(0,0,"Images/background.bmp");
        game_over_func();
    }

    else if(life_lost==1)
    {
        iShowBMP(0,0,"Images/background.bmp");
        life_lost_func();
    }

    else
    {
        int i,j;

        drawmaze();

        points_energizers();
        iSetColor( 241, 196, 15 );

        iShowBMP(pacman[0]-15,pacman[1]-15,"Images/pacman.bmp");

        if(frightened==0)
        {
            iShowBMP(ghost[0][0]-15,ghost[0][1]-10,"Images/red_ghost.bmp");
            iShowBMP(ghost[1][0]-15,ghost[1][1]-10,"Images/pink_ghost.bmp");
            iShowBMP(ghost[2][0]-15,ghost[2][1]-10,"Images/blue_ghost.bmp");
            iShowBMP(ghost[3][0]-15,ghost[3][1]-10,"Images/yellow_ghost.bmp");
        }
        else{
            for(i=0;i<4;i++)
            {
                iShowBMP(ghost[i][0]-20,ghost[i][1]-20,"Images/frightened_ghost.bmp");
            }
        }
        if(dots_eaten==70)
        {
            first_fruit=1;
        }
        if(dots_eaten==170)
        {
            second_fruit=1;
        }
        score_temp=score;
        j=1000;
        for(i=0;i<=3;i++)
        {
            scorestring[i]=score_temp/j+'0';
            score_temp%=j;
            j/=10;
        }
        iSetColor(255,255,255);
        iText(18*20,34*20,"SCORE: ",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(23*20,34*20,scorestring,GLUT_BITMAP_TIMES_ROMAN_24);
        levelchar[0]=level+'1';
        iText(10*20,34*20,"LEVEL:",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(14*20,34*20,levelchar,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(2*20,34*20,"LIVES:",GLUT_BITMAP_TIMES_ROMAN_24);
        lives_string[0]=lives+'0';
        iText(6*20,34*20,lives_string,GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,153,51);
        iText(20*20,2*20-5,"press p to pause the game", GLUT_BITMAP_HELVETICA_12);
        check_position();
    }
}

void iMouse(int button,int state,int mx,int my )
{
    if(paused_game==1)
    {
        if(mx>=6*20&&mx<=21*20&&my>=19*20+10&&my<=23*20)
        {
            paused_game=0;
            initialize_everything();
        }
        else if(mx>=6*20&&mx<=22*20&&my>=13*20+10&&my<=17*20)
        {
            save_game();
            exit(0);
        }
        else if(mx>=7*20&&mx<=21*20&&my>=7*20+10&&my<=11*20)
        {
            update_highscore();
            exit(0);
        }
    }
    else if(game_ended==1)
    {
        if(mx>=6*20&&mx<=20*20&&my>=18*20&&my<=21*20)
        {
            show_highscore=1;
        }
        else if(mx>=8*20&&mx<=18*20&&my>=13*20&&my<=16*20)
        {
            exit(0);
        }
    }
    else if(start==1)
    {
        if(mx>=8*20&&mx<=23*20&&my>=20*20+10&&my<=24*20)
        {

            getting_name=1;
            start=0;
        }
        else if(mx>=8*20&mx<=23*20&&my>=11*20+10&&my<=15*20+10)
        {
            show_highscore=1;
        }
        else if(mx>=8*20&&mx<=23*20&&my>=7*20+10&&my<=11*20)
        {
            instruction=1;
        }
        else if(mx>=8*20&&mx<=23*20&&my>=3*20+10&&my<=7*20)
        {
            exit(0);
        }
        else if(mx>=8*20&&mx<=23*20&&my>=16*20+10&&my<=20*20)
        {
            resume=1;
        }
    }
    else if(game_over==1)
    {
        if(mx>=8*20&&mx<=20*20&&my>=15*20&&my<=18*20)
        {
            game_over=0;
            life_lost=0;
            initialize_everything();
        }
        else if(mx>=8*20&&mx<=20*20&&my>=10*20&&my<=13*20)
        {
            show_highscore=1;
        }
        else if(mx>=8*20&&mx<=20*20&&my>=5*20&&my<=8*20)
        {
            initialize_everything();
            exit(0);
        }
    }
}
void iMouseMove(int mx,int my)
{

}
void iKeyboard(unsigned char key)
{
    if(show_highscore==1)
    {
        if(key=='\r')
            show_highscore=0;
    }
    else if(instruction==1)
    {
        if(key=='\r')
        {
            instruction=0;
        }
    }
    else if(start==1)
    {
        if(key=='\r')
        {
            if(pointer_center[0][1]==22*20)
            {
                getting_name=1;
                start=0;
            }
            else if(pointer_center[0][1]==18*20)
            {
                resume=1;
                start=0;

            }
            else if(pointer_center[0][1]==14*20)
            {
                show_highscore=1;

            }
            else if(pointer_center[0][1]==10*20)
            {
                instruction=1;

            }
            else if(pointer_center[0][1]==6*20)
            {
                exit(0);

            }
        }
    }
    else if(game_over==1)
    {
        if(pointer_center[1][1]==16.5*20)
        {

            game_over=0;
            life_lost=0;
            initialize_everything();
        }
        else if(pointer_center[1][1]==11.5*20)
        {
            show_highscore=1;
        }

        else if(pointer_center[1][1]==6.5*20)
        {
            initialize_everything();
            exit(0);

        }
    }
    else if(game_ended==1)
    {
        if(key=='\r')
        {
            if(pointer_center[2][1]==19.5*20)
            {
                show_highscore=1;
            }
            else if(pointer_center[2][1]==14.5*20)
            {
                exit(0);
            }
        }
    }
    else if(paused_game==1)
    {

        if(key=='\r')
        {
            if(pointer_center[3][1]==21*20)
            {
                paused_game=0;
                initialize_everything();


            }
            else if(pointer_center[3][1]==15*20)
            {
                save_game();
                exit(0);

            }
            else if(pointer_center[3][1]==9*20)
            {
                update_highscore();
                exit(0);

            }
        }
    }
    else if(resume==1)
    {
        if(key=='\r')
        {
            if(pointer_center[4][1]==24*20)
            {
                open_game=times[total_saved-1].filenum;
            }
            else if(pointer_center[4][1]==20*20)
            {
                open_game=times[total_saved-2].filenum;
            }
            else if(pointer_center[4][1]==16*20)
            {
                open_game=times[total_saved-3].filenum;
            }
            else if(pointer_center[4][1]==12*20)
            {
                open_game=times[total_saved-4].filenum;
            }
            else if(pointer_center[4][1]==8*20)
            {
                open_game=times[total_saved-5].filenum;
            }
            resumed();
        }
    }

    else if(getting_name==1)
    {
        if(key=='\r')
        {
            if(name_len==0)
            {
                iText(4*20,15*20,"NAME MUST CONTAIN AT LEAST 1 CHAR",GLUT_BITMAP_TIMES_ROMAN_24);

            }
            else
            {
                name[name_len]='\0';

                name_len=0;
                getting_name=0;
                initialize_everything();
            }
        }
        else
        {
            name[name_len]=key;
            name_len++;
            if(name_len>10)
            {
                name[name_len]='\0';
                name_len=0;
                getting_name=0;
            }

        }
    }
    if(level_up==1)
    {
        if(key=='\r')
            level_up=0;
    }
    if(life_lost==1)
    {
        if(key=='\r')
            life_lost=0;
    }
    if(getting_name==0)
    {
        if(key=='p')

        {
            paused_game=1;
        }
    }
    if(no_saved_game==1)
    {
        if(key=='\r')
        {
            resume=0;
            start=1;
            no_saved_game=0;
        }
    }
}

void iSpecialKeyboard(unsigned char key)
{
    if(start==1)
    {
        if(key==GLUT_KEY_DOWN&&pointer_center[0][1]!=6*20)
        {
            pointer_center[0][1]-=4*20;
        }
        else if(key==GLUT_KEY_UP&&pointer_center[0][1]!=22*20)
        {
            pointer_center[0][1]+=4*20;
        }
    }
    else if(game_over==1)
    {
        if(key==GLUT_KEY_DOWN&&pointer_center[1][1]!=6.5*20)
        {
            pointer_center[1][1]-=5*20;
        }
        else if(key==GLUT_KEY_UP&&pointer_center[1][1]!=16.5*20)
        {
            pointer_center[1][1]+=5*20;
        }
    }
    else if(game_ended==1)
    {
        if(key==GLUT_KEY_DOWN&&pointer_center[2][1]!=14.5*20)
        {
            pointer_center[2][1]-=5*20;
        }
        else if(key==GLUT_KEY_UP&&pointer_center[2][1]!=19.5*20)
        {
            pointer_center[2][1]+=5*20;
        }
    }
    else if(paused_game==1)
    {
        if(key==GLUT_KEY_DOWN&&pointer_center[3][1]!=9*20)
        {
            pointer_center[3][1]-=6*20;
        }
        else if(key==GLUT_KEY_UP&&pointer_center[3][1]!=21*20)
        {
            pointer_center[3][1]+=6*20;
        }
    }
    else if(resume==1)
    {
        if(key==GLUT_KEY_DOWN && pointer_center[4][1]!=24*20-(total_saved-1)*4*20)
        {
            pointer_center[4][1]-=4*20;
        }
        else if(key==GLUT_KEY_UP&&pointer_center[4][1]!=24*20)
        {
            pointer_center[4][1]+=4*20;
        }
    }

    if(life_lost==1)
    {
        if(key==GLUT_KEY_END)
        {
            update_highscore();
            exit(0);
        }
    }
    if(key==GLUT_KEY_DOWN)
    {

        if(blocked[pacman[0]][pacman[1]-20]==0)
        {
            pacman_last[0]=pacman[0];
            pacman_last[1]=pacman[1];
            pacman[1]=pacman[1]-20;

        }
            if(frightened==1)
            {
                frightened_steps++;
            }
            else if(scattered==1)
            {
                scattered_steps++;
            }
            else
            {
                chase_steps++;
            }

    }
    else if(key==GLUT_KEY_UP)
    {

        if(blocked[pacman[0]][pacman[1]+20]==0)
        {
            pacman_last[0]=pacman[0];
            pacman_last[1]=pacman[1];
            pacman[1]=pacman[1]+20;
        }
             if(frightened==1)
            {
                frightened_steps++;
            }
            else if(scattered==1)
            {
                scattered_steps++;
            }
            else
            {
                chase_steps++;
            }
    }
    else if(key==GLUT_KEY_LEFT)
    {
        if(blocked[pacman[0]-20][pacman[1]]==0)
        {
            pacman_last[0]=pacman[0];
            pacman_last[1]=pacman[1];
            pacman[0]=pacman[0]-20;}
             if(frightened==1)
            {
                frightened_steps++;
            }
            else if(scattered==1)
            {
                scattered_steps++;
            }
            else
            {
                chase_steps++;
            }
    }
    else if(key==GLUT_KEY_RIGHT)
    {
        if(blocked[pacman[0]+20][pacman[1]]==0)
        {
            pacman_last[0]=pacman[0];
            pacman_last[1]=pacman[1];
            pacman[0]=pacman[0]+20;
        }
             if(frightened==1)
            {
                frightened_steps++;
            }
            else if(scattered==1)
            {
                scattered_steps++;
            }
            else
            {
                chase_steps++;
            }
    }
    if(points[pacman[0]][pacman[1]]==1)
    {
        score++;
        dots_eaten++;
        points[pacman[0]][pacman[1]]=0;
    }
    if(first_fruit==1&&pacman[0]==fruit[0][0]&&pacman[1]==fruit[0][1])
    {
        first_fruit=0;
        score+=30;
    }
    else if(second_fruit==1&&pacman[0]==fruit[1][0]&&pacman[1]==fruit[1][1])
    {
        second_fruit=0;
        score+=30;
    }
    if(has_energizer[pacman[0]][pacman[1]]==1)
    {
        score+=20;
        int xx[4],yy[4];
        has_energizer[pacman[0]][pacman[1]]=0;
        frightened=1;
        for(int i=0;i<4;i++)
        {
            xx[i]=ghost[i][0]-ghost_last[i][0];
            yy[i]=ghost[i][1]-ghost_last[i][1];
            if(xx[i]==20&&yy[i]==0)
            {
                dir[i]=2;
            }
            else if(xx[i]==-20&&yy[i]==0)
            {
                dir[i]=3;
            }
            else if(xx[i]==0&&yy[i]==20)
            {
                dir[i]=1;
            }
            else
            {
                dir[i]=4;
            }
        }
        last=mode;
        mode=3;
        frightened_steps=0;
    }
    if(frightened_steps==frightened_steps_total[level]&&frightened==1)
    {
        frightened=0;
        mode=last;
        if(mode==1)
        {
            scattered=1;

        }
        else
        {
            chase=1;
        }
    }
    if(scattered_steps==scattered_steps_total[level]&&scattered==1)
    {
        changed++;
        mode=2;
        scattered=0;
        chase=1;
        chase_steps=0;
    }
    if(chase_steps==chase_steps_total[level]&&chase==1)
    {
        changed++;
        if(changed<total_changed[level]){
        mode=1;
        scattered=1;
        chase=0;
        scattered_steps=0;}
    }
    check=check_level();
    if(check==0)
    {
        level_up=1;
        level++;
        if(level==2)
        {
            update_highscore();
            game_ended=1;
        }
    }
}

void level_up_func()
{
    initialize_everything();
    iSetColor( 215, 189, 226);
    iText(8*20+10,20*20,"L  E  V  E  L  U  P  !  !",GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(133, 193, 233 );
    iText(6*20,15*20,"PRESS ENTER TO CONTINUE",GLUT_BITMAP_TIMES_ROMAN_24);
}

void initialize_everything()
{
    int i,j;
    for(i=0;i<4;i++)
    {
        ghost[i][0]=ghost_initial[i][0];
        ghost[i][1]=ghost_initial[i][1];
    }
    pacman[0]=pacman_initial[0];
    pacman[1]=pacman_initial[1];
    draw_points();
    dots_eaten=0;
    if(level_up!=1)
        score=0;
    scattered=1;
    chase=0;
    first_fruit=0;
    second_fruit=0;
    frightened=0;
    if(level_up!=1)
        lives=3;
    changed=0;
    scattered_steps=0;
    chase_steps=0;
    frightened_steps=0;
    pacman_last[0]=pacman[0];
    pacman_last[1]=pacman[1];
    mode='s';
    last='s';
    paused_game=0;
    getting_name=0;
    game_ended=0;
    life_lost=0;
    game_over=0;
    resume=0;
}

void points_energizers()
{
    iSetColor(255,229,204);
    int i,j;
    for(i=0; i<28; i++)
    {
        for(j=0; j<36; j++)
        {
            if(points[(i*20)+10][(j*20)+10]==1&&blocked[(i*20+10)][j*20+10]==0)
                iFilledCircle((i*20)+10,(j*20)+10,2.5);
        }
    }
    //drawing energizer now
    iSetColor(240,240,240);
    for(i=0;i<4;i++)
    {
        if(has_energizer[energizer[i][0]][energizer[i][1]]==1)
        iFilledCircle(energizer[i][0],energizer[i][1],10);
    }
    if(first_fruit==1)
    {
          iShowBMP(fruit[0][0]-20,fruit[0][1]-20,"Images/fruits.bmp");
    }
    else if(second_fruit==1)
    {
          iShowBMP(fruit[1][0]-20,fruit[1][1]-20,"Images/grape.bmp");
    }
}

int main()
{

    PlaySound(TEXT("Audios/game_music.wav"),NULL,SND_LOOP|SND_ASYNC);
    draw_points();
    //draw_points is in variables.h
    iSetTimer(300,ghost_movement);
    iInitialize(560,720,"maze");
    iDraw();
}

