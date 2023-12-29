#include<stdlib.h>
#include<stdio.h>

void resumed()
{

    FILE *save;
    char line[80];
    save=fopen(filenames[open_game],"r");
    drawmaze();
    fscanf(save,"%d",&filenum);
    fscanf(save,"%d",&day);
    fscanf(save,"%d",&month);
    fscanf(save,"%d",&year);
    fscanf(save,"%d",&hour);
    fscanf(save,"%d",&minute);
    fscanf(save,"%d",&second);
    fscanf(save,"%d",&mode);
    fscanf(save,"%d",&last);
    fscanf(save,"%d",&dir[0]);
    fscanf(save,"%d",&dir[1]);
    fscanf(save,"%d",&dir[2]);
    fscanf(save,"%d",&dir[3]);
    fscanf(save,"%d",&level);
    fscanf(save,"%d",&lives);
    fscanf(save,"%d",&dots_eaten);
    fscanf(save,"%d",&score);
    fscanf(save,"%d",&first_fruit);
    fscanf(save,"%d",&second_fruit);
    fscanf(save,"%d",&has_energizer[energizer[0][0]][energizer[0][1]]);
    fscanf(save,"%d",&has_energizer[energizer[1][0]][energizer[1][1]]);
    fscanf(save,"%d",&has_energizer[energizer[2][0]][energizer[2][1]]);
    fscanf(save,"%d",&has_energizer[energizer[3][0]][energizer[3][1]]);
    fscanf(save,"%d",&changed);
    fscanf(save,"%d",&scattered_steps);
    fscanf(save,"%d",&chase_steps);
    fscanf(save,"%d",&frightened_steps);
    fscanf(save,"%d",&scattered);
    fscanf(save,"%d",&chase);
    fscanf(save,"%d",&frightened);
    int i,j;
    drawmaze();
    for(i=0; i<28; i++)
    {
        for(j=0; j<36; j++)
        {
            if(blocked[(i*20+10)][j*20+10]==0)
               {
                   fscanf(save,"%d",&points[(i*20)+10][(j*20)+10]);
               }

        }
    }

    fscanf(save,"%d",&pacman[0]);
    fscanf(save,"%d",&pacman[1]);
    fscanf(save,"%d",&pacman_last[0]);
    fscanf(save,"%d",&pacman_last[1]);
    for(i=0;i<4;i++)
    {
        for(j=0;j<2;j++)
        {
            fscanf(save,"%d",&ghost[i][j]);
        }
    }
     for(i=0;i<4;i++)
    {
        for(j=0;j<2;j++)
        {
            fscanf(save,"%d",&ghost_last[i][j]);
        }
    }
    fscanf(save,"%d",&t);
    fscanf(save,"%s",name);
    fclose(save);
    save=fopen(filenames[open_game],"w");
    fclose(save);
    resume=0;
    start=0;

}
