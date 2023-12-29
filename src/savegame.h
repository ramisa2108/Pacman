#include<bits/stdc++.h>
using namespace std;

bool compare(struct Times &a,struct Times &b)
{
    if(a.year==b.year)
    {
        if(a.month==b.month)
        {
            if(a.day==b.day)
            {
                if(a.hour==b.hour)
                {
                    if(a.minute==b.minute)
                    {
                        return a.second<b.second;
                    }
                    return a.minute<b.minute;
                }
                return a.hour<b.hour;
            }
            return a.day<b.day;
        }
        return a.month<b.month;
    }
    return a.year<b.year;
}
void save_game()
{
    FILE *saved;
    int i,j,sz;
    for(i=0;i<5;i++)
    {
        saved=fopen(filenames[i],"r");
        if(saved==NULL) break;
        fseek(saved,0,SEEK_END);
        sz=ftell(saved);
        if(sz==0) break;
        fseek(saved,0,SEEK_SET);
        fscanf(saved,"%d",&times[i].filenum);
        fscanf(saved,"%d",&times[i].day);
        fscanf(saved,"%d",&times[i].month);
        fscanf(saved,"%d",&times[i].year);
        fscanf(saved,"%d",&times[i].hour);
        fscanf(saved,"%d",&times[i].minute);
        fscanf(saved,"%d",&times[i].second);
        fclose(saved);

    }
    if(i<5) {saved=fopen(filenames[i],"w");
        fprintf(saved,"%d\n",i);}
    else
    {
        sort(times,times+5,compare);
        saved=fopen(filenames[times[0].filenum],"w");
        fprintf(saved,"%d\n",times[0].filenum);

    }
     time_t current;
            struct tm *ltime;
            time(&current);
            ltime=localtime(&current);
            hour=ltime->tm_hour;
            minute=ltime->tm_min;
            second=ltime->tm_sec;
            day=ltime->tm_mday;
            month=ltime->tm_mon;
            year=ltime->tm_year;
    fprintf(saved,"%d %d %d %d %d %d\n",day,month,year,hour,minute,second);
    fprintf(saved,"%d %d %d %d %d %d ",mode,last,dir[0],dir[1],dir[2],dir[3]);
    fprintf(saved,"%d\n",level);
    fprintf(saved,"%d\n",lives);
    fprintf(saved,"%d\n",dots_eaten);
    fprintf(saved,"%d\n",score);
    fprintf(saved,"%d\n",first_fruit);
    fprintf(saved,"%d\n",second_fruit);
    fprintf(saved,"%d\n%d\n%d\n%d\n",has_energizer[energizer[0][0]][energizer[0][1]],has_energizer[energizer[1][0]][energizer[1][1]],
            has_energizer[energizer[2][0]][energizer[2][1]],has_energizer[energizer[3][0]][energizer[3][1]]);
    fprintf(saved,"%d\n",changed);
    fprintf(saved,"%d\n",scattered_steps);
    fprintf(saved,"%d\n",chase_steps);
    fprintf(saved,"%d\n",frightened_steps);
    fprintf(saved,"%d\n",scattered);
    fprintf(saved,"%d\n",chase);
    fprintf(saved,"%d\n",frightened);
   // fprintf(saved,"points");
    for(i=0; i<28; i++)
    {
        for(j=0; j<36; j++)
        {
            if(points[(i*20)+10][(j*20)+10]==1&&blocked[(i*20+10)][j*20+10]==0)
               fprintf(saved," 1");
            if(points[(i*20)+10][(j*20)+10]==0&&blocked[(i*20+10)][j*20+10]==0)
                fprintf(saved," 0");
        }
    }

    fprintf(saved,"\n");
    fprintf(saved,"%d %d\n",pacman[0],pacman[1]);
    fprintf(saved,"%d %d\n",pacman_last[0],pacman_last[1]);
    fprintf(saved,"%d %d %d %d %d %d %d %d\n",ghost[0][0],ghost[0][1],ghost[1][0],ghost[1][1],ghost[2][0],ghost[2][1],
                                      ghost[3][0],ghost[3][1]);
    fprintf(saved,"%d %d %d %d %d %d %d %d\n",ghost_last[0][0],ghost_last[0][1],ghost_last[1][0],ghost_last[1][1],
            ghost_last[2][0],ghost_last[2][1],ghost_last[3][0],ghost_last[3][1]);
    fprintf(saved,"%d\n",t);
    fprintf(saved,"%s",name);



    fclose(saved);

}
