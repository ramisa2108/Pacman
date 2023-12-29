#include<stdio.h>
#include "iGraphics.h"

int verx[30],very[30],verwidth[30],verlength[30],vern,horx[30],hory[30],horwidth[30],horlength[30],horn;
int blocked[1000][1000];
void coordinates();
void blockedtiles();

void drawmaze()
{
    coordinates();
    blockedtiles();
    int i;
    iSetColor(0,153,76);
    iFilledRectangle(0,30,560,20);
    iFilledRectangle(0,30,10,32*20);
    iFilledRectangle(0,32*20+10,560,20);
    iFilledRectangle(540+10,30,20,32*20);
    for(i=0;i<vern;i++)
    {
         iSetColor(0,153,76);
         iFilledRectangle(verx[i]+10,very[i]+10,verwidth[i]-20,verlength[i]-20);
         if(verlength[i]>=60&&verwidth[i]>=60)
        {
            iSetColor(0,51,51);
            iFilledRectangle(verx[i]+20,very[i]+20,verwidth[i]-40,verlength[i]-40);


        }
    }
    for(i=0;i<horn;i++)
    {
        iSetColor(0,153,76);
        iFilledRectangle(horx[i]+10,hory[i]+10,horwidth[i]-20,horlength[i]-20);
        if(horlength[i]>=60&&horwidth[i]>=60)
        {
            iSetColor(0,51,51);
            iFilledRectangle(horx[i]+20,hory[i]+20,horwidth[i]-40,horlength[i]-40);


        }
    }
}


void coordinates()
{
    FILE *ver,*hor;
    ver=fopen("Maze Coordinates/vertical.txt","r");
    hor=fopen("Maze Coordinates/horizontal.txt","r");
    vern=14;
    horn=25;
    int i;
    for(i=0;i<vern;i++)
    {
        fscanf(ver,"%d",&verx[i]);
        verx[i]*=20;
    }
    for(i=0;i<vern;i++)
    {
        fscanf(ver,"%d",&very[i]);
        very[i]*=20;
    }
    for(i=0;i<vern;i++)
    {
        fscanf(ver,"%d",&verwidth[i]);
        verwidth[i]*=20;
    }
    for(i=0;i<vern;i++)
    {
        fscanf(ver,"%d",&verlength[i]);
        verlength[i]*=20;
    }
    for(i=0;i<horn;i++)
    {
        fscanf(hor,"%d",&horx[i]);
        horx[i]*=20;
    }
    for(i=0;i<horn;i++)
    {
        fscanf(hor,"%d",&hory[i]);
        hory[i]*=20;
    }
    for(i=0;i<horn;i++)
    {
        fscanf(hor,"%d",&horwidth[i]);
        horwidth[i]*=20;
    }
    for(i=0;i<horn;i++)
    {
        fscanf(hor,"%d",&horlength[i]);
        horlength[i]*=20;
    }
    fclose(ver);
    fclose(hor);
}

void blockedtiles()
{
    int i,j,k;
    for(i=0;i<vern;i++)
    {
        for(j=verx[i];j<=verx[i]+verwidth[i];j++)
        {
            for(k=very[i];k<=very[i]+verlength[i];k++)
            {
                blocked[j][k]=1;
            }
        }

    }
    for(i=0;i<horn;i++)
    {
        for(j=horx[i];j<=horx[i]+horwidth[i];j++)
        {
            for(k=hory[i];k<=hory[i]+horlength[i];k++)
            {
                blocked[j][k]=1;
            }
        }
    }
    for(i=0;i<560;i++)
    {
        for(j=0;j<40;j++)
        {
            blocked[i][j]=1;
        }
        for(j=719;j>=660;j--)
        {
            blocked[i][j]=1;
        }
    }
    for(j=0;j<720;j++)
    {
        for(i=0;i<20;i++)
        {
            blocked[i][j]=1;
        }
        for(i=559;i>=540;i--)
        {
            blocked[i][j]=1;
        }
    }
}



