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
        if(energizer_ase[energizer[i][0]][energizer[i][1]]==1)
            return -1;
    }
    if(firstfruit==1||secondfruit==1)
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
                ghost[i][0]=ghostinitial[i][0];
                ghost[i][1]=ghostinitial[i][1];
            }
            else
            {
                lifes--;
                if(lifes==0)
                {
                    update_highscore();
                    game_over=1;
                }
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

