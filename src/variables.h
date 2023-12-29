int game_ended,paused_game,resume,no_saved_game,instruction,show_highscore,getting_name,name_len,level=0,level_up=0,
scattered=1,chase,frightened,switchmode,fright,switched,t=0,start=1,
pacman[2]={270,190},ghost[4][2]={270,430,270,370,230,370,310,370},hstemp,
pacman_initial[2]={270,190},ghost_initial[4][2]={270,430,270,370,230,370,310,370},
first_fruit=0,second_fruit=0,check,pacman_last[2]={270,190},scattered_target[4][2]={24*20+10,34*20+10,3*20+10,34*20+10,24*20+10,1,3*20+10,1},
power[4],high_scores[10],score,lives=3,dots_eaten=0,score_temp,life_lost,game_over,
points[1000][1000],energizer[4][2]={20+10,180+10,20+10,580+10,520+10,180+10,520+10,580+10},
ghost_color[4][3]={255,0,0,245, 183, 177,174, 214, 241, 230, 126, 34 },
ghost_last[4][2]={270,430,270,370,230,370,310,370},target[4][2],total_changed[2]={2,1},
has_energizer[1000][1000],fruit[2][2]={8*20+10,3*20+10,20*20+10,31*20+10},
frightened_steps,scattered_steps,chase_steps,changed,diff[4][2]={0,20,20,0,-20,0,0,-20},
scattered_steps_total[2]={25,15},chase_steps_total[2]={50,60},frightened_steps_total[2]={30,20};
char time_hr[4],time_min[4],time_sec[4],time_mon[4],time_day[4],time_yr[4],levelchar[1],highscore_names[10][20],name[20],hs_string[6],lives_string[1],scorestring[6],filenames[6][12]={"Saved Games/game_1.txt","Saved Games/game_2.txt","Saved Games/game_3.txt","Saved Games/game_4.txt","Saved Games/game_5.txt"},file[12];
int mode=1,last=1,direction[4]={1,2,3,4,},dir[4],pointer_center[5][2]={7*20,22*20,7*20,16.5*20,5*20,19.5*20,5*20,21*20,3*20,24*20};
int hour,minute,second,month,day,year,filenum,total_saved,open_game;
struct Times{
    int hour,minute,second,month,day,year,filenum;
    char names[20];

} times[6];
void draw_points()
{
    int i,j;
    for(i=0; i<28; i++)
    {
        for(j=0; j<36; j++)
        {
            if(blocked[(i*20)+1][(j*20)+1]==0)
            {
                points[(i*20)+10][(j*20)+10]=1;
            }

        }
    }
    for(j=13; j<24; j++)
    {
        for(i=7; i<21; i++)
        {
            points[(i*20)+10][j*20+10]=0;
        }
    }
    for(i=0;i<4;i++)
    {
        has_energizer[energizer[i][0]][energizer[i][1]]=1;
    }
}


