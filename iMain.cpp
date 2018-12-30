#include "mazedraw.h"
#include "variables.h"

void points_energizers();
void check_position();
void initialize_everything();
void game_over_func();
void life_komse_func();
void start_func();
void iDraw()
{
    iClear();
    if(start==1)
    {
        start_func();
    }
    else if(game_over==1)
    {
        game_over_func();
    }

    else if(life_komse==1)
    {
        life_komse_func();
    }
    else{
    int i,j;
    //Show grid:
//    iSetColor(0,120,0);
//
//    for(i=0;i<800;i+=20)
//    {
//        iLine(0,i,800,i);
//    }
//    for(i=0;i<800;i+=20)
//    {
//        iLine(i,0,i,800);
//
//    }
    drawmaze();
    points_energizers();
    iSetColor( 241, 196, 15 );
//    iFilledCircle(pacman[0],pacman[1],12.5);
    iShowBMP(pacman[0]-15,pacman[1]-15,"pacman.bmp");
//    for(i=0;i<4;i++){
//    iSetColor(ghost_color[i][0],ghost_color[i][1],ghost_color[i][2]);
//    iFilledCircle(ghost[i][0],ghost[i][1],12.5);
//    }
    if(frightened==0){
    iShowBMP(ghost[0][0]-15,ghost[0][1]-10,"red ghost.bmp");
    iShowBMP(ghost[1][0]-15,ghost[1][1]-10,"pink ghost.bmp");
    iShowBMP(ghost[2][0]-15,ghost[2][1]-10,"blue ghost.bmp");
    iShowBMP(ghost[3][0]-15,ghost[3][1]-10,"yellow ghost.bmp");
    }
    else{
        for(i=0;i<4;i++)
        {
            iShowBMP(ghost[i][0]-20,ghost[i][1]-20,"frightenedghost.bmp");
        }
    }
        if(dots_eaten==70)
        {
            firstfruit=1;
        }
        if(dots_eaten==170)
        {
            secondfruit=1;
        }
        if(frightened==1)
        {
            iText(270,410,"frightened");
        }
        else if(chase==1&&frightened==0)
        {
            iText(270,400,"Chase");
        }
        else if(scattered==1&&frightened==0){
            iText(270,400,"scattered");
        }

        scoretemp=score;
        j=1000;
        for(i=0;i<=3;i++)
        {
            scorestring[i]=scoretemp/j+'0';
            scoretemp%=j;
            j/=10;
        }
        iSetColor(255,255,255);
        iText(17*20,34*20,"SCORE: ",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(22*20,34*20,scorestring,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(2*20,34*20,"LIVES:",GLUT_BITMAP_TIMES_ROMAN_24);
        lifes_string[0]=lifes+'0';
        iText(6*20,34*20,lifes_string,GLUT_BITMAP_TIMES_ROMAN_24);
        check_position();
    }

}

void iMouse(int button,int state,int mx,int my )
{
    if(start==1)
    {
        if(mx>=12*20&&mx<=27*20&&my>=20*20&&my<=24*20)
        {
            start=0;
        }
        else if(mx>=12*20&mx<=27*20&&my>=15*20+10&&my<=19*20+10)
        {
            //high score
        }
        else if(mx>=1*20&&mx<=16*20&&my>=9*20&&my<=13*20)
        {
            //instructions
        }
        else if(mx>=3*20&&mx<=14*20&&my>=4*20&&my<=8*20)
        {
            exit(0);
        }
    }
    else if(game_over==1)
    {
        if(mx>=8*20&&mx<=20*20&&my>=20*20&&my<=23*20)
        {
            game_over=0;
            life_komse=0;
            initialize_everything();
        }
        else if(mx>=8*20&&mx<=20*20&&my>=15*20&&my<=18*20)
        {
            //high score
        }
        else if(mx>=8*20&&mx<=20*20&&my>=10*20&&my<=13*20)
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
    if(life_komse==1)
    {
        if(key=='\r')
            life_komse=0;
    }

}
void iSpecialKeyboard(unsigned char key)
{
    if(life_komse==1)
    {
        if(key==GLUT_KEY_END)
            exit(0);
    }



    if(key==GLUT_KEY_DOWN)
    {

        if(blocked[pacman[0]][pacman[1]-20]==0)
        {
            pacmanlast[0]=pacman[0];
            pacmanlast[1]=pacman[1];
            pacman[1]=pacman[1]-20;

        }
        if(mode=='s')
            {
                scattered_steps++;
            }
            else if(mode=='c')
            {
                chase_steps++;
            }
            else
            {
                frightened_steps++;
            }
    }
    else if(key==GLUT_KEY_UP)
    {

        if(blocked[pacman[0]][pacman[1]+20]==0)
        {
            pacmanlast[0]=pacman[0];
            pacmanlast[1]=pacman[1];
            pacman[1]=pacman[1]+20;
        }
            if(mode=='s')
            {
                scattered_steps++;
            }
            else if(mode=='c')
            {
                chase_steps++;
            }
            else
            {
                frightened_steps++;
            }

    }
    else if(key==GLUT_KEY_LEFT)
    {

        if(blocked[pacman[0]-20][pacman[1]]==0)
        {
            pacmanlast[0]=pacman[0];
            pacmanlast[1]=pacman[1];
            pacman[0]=pacman[0]-20;}
            if(mode=='s')
            {
                scattered_steps++;
            }
            else if(mode=='c')
            {
                chase_steps++;
            }
            else
            {
                frightened_steps++;
            }

    }
    else if(key==GLUT_KEY_RIGHT)
    {

        if(blocked[pacman[0]+20][pacman[1]]==0)
        {
            pacmanlast[0]=pacman[0];
            pacmanlast[1]=pacman[1];
            pacman[0]=pacman[0]+20;
        }
            if(mode=='s')
            {
                scattered_steps++;
            }
            else if(mode=='c')
            {
                chase_steps++;
            }
            else
            {
                frightened_steps++;
            }

    }
    if(points[pacman[0]][pacman[1]]==1)
    {
        score++;
        dots_eaten++;
        points[pacman[0]][pacman[1]]=0;
    }
    if(pacman[0]==fruit[0][0]&&pacman[1]==fruit[0][1])
        {
            firstfruit=0;
            score+=30;
        }
    else if(pacman[0]==fruit[1][0]&&pacman[1]==fruit[1][1])
        {
            secondfruit=0;
            score+=30;
        }
    if(energizer_ase[pacman[0]][pacman[1]]==1)
    {
        score+=20;
        int xx[4],yy[4];
        energizer_ase[pacman[0]][pacman[1]]=0;
        frightened=1;
        for(int i=0;i<4;i++)
        {
            xx[i]=ghost[i][0]-ghost_last[i][1];
            yy[i]=ghost[i][1]-ghost_last[i][1];
            if(xx[i]==20&&yy[i]==0)
            {
                dir[i]='r';
            }
            else if(xx[i]==-20&&yy[i]==0)
            {
                dir[i]='l';
            }
            else if(xx[i]==0&&yy[i]==20)
            {
                dir[i]='u';
            }
            else
            {
                dir[i]='d';
            }
        }
        last=mode;
        mode='f';
        frightened_steps=0;
    }
    if(frightened_steps==30&&mode=='f')
    {
        frightened=0;
        mode=last;
        if(mode=='s')
        {
            scattered=1;

        }
        else
        {
            chase=1;
        }
    }
    if(scattered_steps==40&&mode=='s')
    {
        changed++;
        mode='c';
        scattered=0;
        chase=1;
        chase_steps=0;
    }
    if(chase_steps==40&&mode=='c')
    {
        changed++;
        if(changed<5){
        mode='s';
        scattered=1;
        chase=0;
        scattered_steps=0;}
    }







}
void start_func()
{

      iShowBMP(0,0,"menubar.bmp");
      iSetColor(198,198,221);
      iRectangle(12*20,15*20+10,15*20,4*20);
      iRectangle(12*20,20*20,15*20,4*20);
      iRectangle(1*20,9*20,15*20,4*20);
      iRectangle(3*20,4*20,11*20,4*20);

}
void life_komse_func()
{
        iSetColor(241, 196, 15 );
        iText(10*20,24*20,"You just lost one life",GLUT_BITMAP_HELVETICA_18);
        iText(9*20,22*20,"Press enter to continue ",GLUT_BITMAP_HELVETICA_18);
        iText(11*20,20*20,"and end to exit",GLUT_BITMAP_HELVETICA_18);

}
void game_over_func()
{
        iSetColor(255,255,255);
        iRectangle(4*20,25*20,20*20,5*20);
        iText(9*20,27*20,"G A M E  O V E R",GLUT_BITMAP_TIMES_ROMAN_24);
        iRectangle(8*20,20*20,12*20,3*20);
        iText(10*20,21*20,"N E W G A M E ",GLUT_BITMAP_TIMES_ROMAN_24);
        iRectangle(8*20,15*20,12*20,3*20);
        iText(9*20,16*20,"H I G H S C O R E S",GLUT_BITMAP_TIMES_ROMAN_24);
        iRectangle(8*20,10*20,12*20,3*20);
        iText(12*20,11*20," Q U I T",GLUT_BITMAP_TIMES_ROMAN_24);
}
void initialize_everything()
{
    int i,j;
    for(i=0;i<4;i++)
    {
        ghost[i][0]=ghostinitial[i][0];
        ghost[i][1]=ghostinitial[i][1];
    }
    pacman[0]=pacmaninitial[0];
    pacman[1]=pacmaninitial[1];
    drawpoints();
    dots_eaten=0;
    score=0;
    scattered=1;
    chase=0;
    frightened=0;
    lifes=3;
    changed=0;
    scattered_steps=0;
    chase_steps=0;
    frightened_steps=0;
    pacmanlast[0]=pacman[0];
    pacmanlast[1]=pacman[1];
    mode='s';
    last='s';
}
void check_position()
{
    int i,j;
    for(i=0;i<4;i++)
    {
        if(ghost[i][0]==pacman[0]&&ghost[i][1]==pacman[1])
        {
            if(frightened==1)
            {
                score+=50;
                ghost[i][0]=ghostinitial[i][0];
                ghost[i][1]=ghostinitial[i][1];
            }
            else
            {
                lifes--;
                if(lifes==0)
                    game_over=1;
                pacman[0]=pacmaninitial[0];
                pacman[1]=pacmaninitial[1];
                for(j=0;j<4;j++)
                {
                    ghost[j][0]=ghostinitial[j][0];
                    ghost[j][1]=ghostinitial[j][1];
                }
                life_komse=1;
            }
            break;
        }
    }
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
        if(energizer_ase[energizer[i][0]][energizer[i][1]]==1)
        iFilledCircle(energizer[i][0],energizer[i][1],10);
    }
    if(firstfruit==1)
    {
          iShowBMP(fruit[0][0]-20,fruit[0][1]-20,"fruits.bmp");
    }
    else if(secondfruit==1)
    {
          iShowBMP(fruit[1][0]-20,fruit[1][1]-20,"fruits.bmp");
    }


}
void move_ghost()
{
    int i,j,u,d,r,l,mini,dx,dy;
    if(frightened==0){
    for(i=0;i<4;i++)
    {
        mini=1000000;
        dx=0;
        dy=0;
        if(blocked[ghost[i][0]+20][ghost[i][1]]==0&&(ghost_last[i][0]-ghost[i][0])!=20)
        {
            r=(ghost[i][0]+20-target[i][0])*(ghost[i][0]+20-target[i][0])+(ghost[i][1]-target[i][1])*(ghost[i][1]-target[i][1]);
            if(mini>r)
            {
                mini=r;
                dx=20;
                dy=0;
            }
        }
        if(blocked[ghost[i][0]-20][ghost[i][1]]==0&&(ghost_last[i][0]-ghost[i][0])!=-20)
        {
            l=(ghost[i][0]-20-target[i][0])*(ghost[i][0]-20-target[i][0])+(ghost[i][1]-target[i][1])*(ghost[i][1]-target[i][1]);
            if(mini>l)
            {
                mini=l;
                dx=-20;
                dy=0;
            }
        }
        if(blocked[ghost[i][0]][ghost[i][1]+20]==0&&(ghost_last[i][1]-ghost[i][1])!=20)
        {
            u=(ghost[i][0]-target[i][0])*(ghost[i][0]-target[i][0])+(ghost[i][1]+20-target[i][1])*(ghost[i][1]+20-target[i][1]);
            if(mini>u)
            {
                mini=u;
                dx=0;
                dy=20;
            }

        }
        if(blocked[ghost[i][0]][ghost[i][1]-20]==0&&(ghost_last[i][1]-ghost[i][1])!=-20)
        {
            d=(ghost[i][0]-target[i][0])*(ghost[i][0]-target[i][0])+(ghost[i][1]-20-target[i][1])*(ghost[i][1]-20-target[i][1]);
            if(mini>d)
            {
                mini=d;
                dx=0;
                dy=-20;

            }
        }
        ghost_last[i][0]=ghost[i][0];
        ghost_last[i][1]=ghost[i][1];
        ghost[i][0]+=dx;
        ghost[i][1]+=dy;
    }
    }
    else if(frightened==1&&t%3==0)
    {
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(dir[i]==direction[j])
                {
                    dx=diff[j][0];
                    dy=diff[j][1];
                    break;
                }
            }
            while(blocked[ghost[i][0]+dx][ghost[i][1]+dy]==1)
            {
                j++;
                j%=4;
                dir[i]=direction[j];
                dx=diff[j][0];
                dy=diff[j][1];
            }
            ghost_last[i][0]=ghost[i][0];
            ghost_last[i][1]=ghost[i][1];
            ghost[i][0]+=dx;
            ghost[i][1]+=dy;


        }
    }



}
void ghost_movement()
{
    if(life_komse==1||start==1) return ;
    t++;
    int i,j,k,x1,x2,y1,y2;
    if(frightened==0)
    {
        if(scattered==1)
        { iSetColor(0,255,0);
    for(i=0;i<=28;i++)
    {
        iLine(20*i,0,20*i,720);
    }
    for(i=0;i<=36;i++)
    {
        iLine(0,20*i,560,20*i);
    }
            for(i=0;i<4;i++)
            {
                target[i][0]=scattered_target[i][0];
                target[i][1]=scattered_target[i][1];
            }
        }
        else if(chase==1){

            target[0][0]=pacman[0];
            target[0][1]=pacman[1];
            x1=pacmanlast[0];
            x2=pacman[0];
            y1=pacmanlast[1];
            y2=pacman[1];
            target[1][0]=x2+2*(x2-x1);
            target[1][1]=y2+2*(y2-y1);
            x1=ghost[0][0];
            x2=target[1][0];
            y1=ghost[0][1];
            y2=target[1][1];
            target[2][0]=x2+(x2-x1);
            target[2][1]=y2+(y2-y1);
            x1=pacman[0];
            y1=pacman[1];
            x2=ghost[3][0];
            y2=ghost[3][1];
            if(((x2-x1)*(x2-x1)+(y2-y2)*(y2-y1))>=22500)
            {
                target[3][0]=pacman[0];
                target[3][1]=pacman[1];
            }
            else{

                target[3][0]=scattered_target[3][0];
                target[3][1]=scattered_target[3][1];
            }
        }
    }
     move_ghost();
}

int main()
{

    drawpoints();
    iSetTimer(300,ghost_movement);
    iInitialize(560,720,"maze");
    iDraw();
}
