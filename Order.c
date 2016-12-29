#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#define MAX_LEN 150

struct arr{
char user_name[MAX_LEN];
int id;
};
void player_score(int score )
{
          int i=0, j=0;
     char player_name[MAX_LEN];
    printf("Enter your name :");
    player_name[0]=getchar();
    gets(player_name);
    for(i = 0; player_name[i] != '\0'; i++)
    {
        player_name[i] = toupper(player_name[i]);
    }

     struct arr players[MAX_LEN];
     char other_player[MAX_LEN];
     int flage=1;
     //////////////////////////////////////
     FILE * order;
     FILE * ftemp;
    order= fopen("score.txt","r");
    ftemp =fopen("temp.txt","w");
     if (ftemp==NULL)
    {
        printf("this file is not exit");
        exit(0);
    }
     if (order==NULL)
    {
        printf("this file is not exit");
        exit(0);
    }
    /////////////////////////////////////
    while (fgets(other_player,150,order)!=NULL){
            for (i=0 ;i<strlen(other_player);){
                if (other_player[i]!=':'){
                    players[j].user_name[i]=other_player[i];
                        i++;

                }
                else {
                    players[j].user_name[i]='\0';
                      i++;
                        break;

            }
            }

            players[j].id=0;
            for (;i<strlen(other_player)&&other_player[i]!='\n';){
            players[j].id=players[j].id*10+(int)(other_player[i]-'0');
                    i++;
                    }
        if (strcmp(players[j].user_name,player_name)==0){
            players[j].id+=score;
            printf("your new score is %d\n",players[j].id);
            flage =0;
                    }
              j++;

    }
       if (flage==1){
       players[j].id=score;
       strcpy( players[j].user_name,player_name);
       }
       int sizeofarr=j+1;
       int temp; //using for swapping
       char nam[MAX_LEN];//using for swapping

   ////////////////////////////////////////////////////////////////// sorting to the structure
   for (i=0;i<sizeofarr;i++){
    for (j=0;j<sizeofarr-i;j++){
        if (players[j].id<players[j+1].id){
            //swapping in the structure
            temp=players[j].id;
            strcpy(nam, players[j].user_name);
            players[j].id=players[j+1].id;
            strcpy(players[j].user_name,players[j+1].user_name);
            players[j+1].id=temp;
            strcpy(players[j+1].user_name,nam);
        }
    }
   }



    ///////////////////////////////////////////////////put the sorting structure in the temp file
   for (i=0 ;i<sizeofarr-1;i++){
    fprintf(ftemp,"%s:%d\n",players[i].user_name,players[i].id);
    }

    ///////////////////////////////////////////////////
    fclose(ftemp);
    fclose(order);
   remove("score.txt");
   rename("temp.txt","score.txt");



}
