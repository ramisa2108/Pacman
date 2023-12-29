int check_level()
{
    int i,j;
    for(i=0; i<28; i++)
    {
        for(j=0; j<36; j++)
        {
            if(points[(i*20)+10][(j*20)+10]==1&&blocked[(i*20+10)][j*20+10]==0)
                return -1;
        }
    }

    for(i=0;i<4;i++)
    {
        if(has_energizer[energizer[i][0]][energizer[i][1]]==1)
            return -1;
    }
    if(first_fruit==1||second_fruit==1)
        return -1;
    return 0;
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
                ghost[i][0]=ghost_initial[i][0];
                ghost[i][1]=ghost_initial[i][1];
            }
            else
            {
                lives--;
                if(lives==0)
                {
                    update_highscore();
                    game_over=1;
                }
                pacman[0]=pacman_initial[0];
                pacman[1]=pacman_initial[1];
                for(j=0;j<4;j++)
                {
                    ghost[j][0]=ghost_initial[j][0];
                    ghost[j][1]=ghost_initial[j][1];
                }
                life_lost=1;
            }
            break;
        }
    }
}

