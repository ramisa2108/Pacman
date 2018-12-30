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
    if(resume==1||paused_game==1||life_komse==1||start==1||level_up==1||getting_name==1||show_highscore==1)
        return ;
    t++;
    int i,j,k,x1,x2,y1,y2;
    if(frightened==0)
    {
        if(scattered==1)
        { iSetColor(0,255,0);
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

