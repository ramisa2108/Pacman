void update_highscore()
{
    FILE *fp;
    fp=fopen("highscore.txt","r+");

    int i=0,j,c=-1,temp_highscore;
    char temp_name[20];
    if(fp != NULL){
    fseek(fp,0,SEEK_END);
    int sz=ftell(fp);
    if(sz!=0){
        fseek(fp,0,SEEK_SET);
    while(!(feof(fp)))
    {
        if(feof(fp)) break;
        fscanf(fp,"%s %d ",temp_name,&temp_highscore);
        if(c==-1&&score>temp_highscore)
        {
            strcpy(highscore_names[i],name);
            highscores[i]=score;
            i++;
            c=1;
        }
        if(temp_highscore){
        strcpy(highscore_names[i],temp_name);
        highscores[i]=temp_highscore;
        i++;
        }
    }
    }

    }
    if(c==-1&&i<5)
    {
        highscores[i]=score;
        strcpy(highscore_names[i],name);
        i++;

    }
    fclose(fp);
    fp=fopen("highscore.txt","w");
    for(j=0;j<min(5,i);j++)
    {
        fprintf(fp,"%s %d",highscore_names[j],highscores[j]);
        if(j!=min(5,i))
            fprintf(fp,"\n");
    }
    fclose(fp);




}

void show_highscore_func()
{
    iShowBMP(0,0,"high scores.bmp");
    iSetColor(198, 198, 221);
//    iRectangle(7*20,29*20,13*20,3*20);
//    iRectangle(7*20-5,29*20-5,13*20+10,3*20+10);
//    iText(8*20,30*20,"H I G H    S C O R E S",GLUT_BITMAP_TIMES_ROMAN_24);
//    iSetColor(69, 179, 157);
    iRectangle(4*20,27*20-6*60-20,18*20,6*60+20);
    iRectangle(4*20+5,27*20-6*60-15,18*20-10,6*60+20-10);
//    iSetColor(  112, 197, 200);
    int i,j=0,k;
    FILE *fp;
    fp=fopen("highscore.txt","r");
    while(!(feof(fp)))
    {
        if(feof(fp))
            break;
        fscanf(fp,"%s %d",highscore_names[j],&highscores[j]);
        if(highscores[j]==0) break;
        hstemp=highscores[j];
        k=1000;
        for(i=0;i<=3;i++)
        {
            hs_string[i]=hstemp/k+'0';
            hstemp%=k;
            k/=10;
        }
        iText(6*20,(26*20-(j+1)*60),highscore_names[j],GLUT_BITMAP_TIMES_ROMAN_24);
        iText(16*20,(26*20-(j+1)*60),hs_string,GLUT_BITMAP_TIMES_ROMAN_24);
        j++;
        if(j==5) break;

    }
    if(j==0)
    {
        iText(6*20+10,26*20-3*60,"NO HIGHSCORES YET",GLUT_BITMAP_TIMES_ROMAN_24);
    }

    fclose(fp);
//    iSetColor(69, 179, 157);
//    iText(6*20-10,26*20-7*60,"PRESS ENTER TO RETURN",GLUT_BITMAP_TIMES_ROMAN_24);
}
