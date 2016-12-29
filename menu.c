#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "draw the grid.h"
#include "Win Lose.h"
#include "Order.h"
#include "rand.h"
#include "save.h"
#include "Number.h"
#include "Empty Cell.h"
#include "OpeningOpenCell.h"
#include "Actions.h"
#include "First Click.h"
#include "start game.h"
void  menu ()
{
    printf("(1)START NEW GAME\t  (2)CONTINUE \n\t*\t\t\t*\n\t  *\t\t      *\n\t    *\t\t    *\n\t\t TNE MENU\n\t\t    *\n\t\t    *\n\t\t    *\n\n\t  (3)SHOW TNE PLAYER ORDER\n\n");
    printf("ENTER YOUR CHOICE : ");
    int path;
    int flag=1;
    while (flag==1)
    {
        scanf( "%d",&path);

        switch (path)
        {
        case 1 : //start the game
            start_game();
            flag=0;


            break;
        case 2 : //load last save game
        {
            int m,n;
            int moves;
            double time;
            int num_of_mine,quest;
            int i,j;
            int f; //num of flag
            FILE *load ;
            load=fopen("saved game.txt","r");
            if (load == NULL)
            {
                printf("Error opening file!\n");
                exit(1);
            }
            if (fscanf(load, "%d%d%d%lf%d%d%d", &m ,&n, &moves ,&time,&num_of_mine,&f,&quest) < 8);
            fclose(load);
            char hidden_grid[m][n];
            char grid[m][n];
            int raw[num_of_mine],col[num_of_mine];
//read the hidden grid
            FILE*hidden;
            hidden=fopen("HIDDEN.txt","r");
            if (hidden == NULL)
            {
                printf("Error opening file!\n");
                exit(1);
            }
            for (i=0 ; i<n; i++)
            {
                for (j=0; j<m; j++)
                {
                    fscanf(hidden," %c",&hidden_grid[i][j]);
                }

            }
            fclose(hidden);
            FILE*player_grid;
            player_grid=fopen("GRID.txt","r");
            if (player_grid == NULL)
            {
                printf("Error opening file!\n");
                exit(1);
            }
            for (i=0 ; i<n; i++)
            {
                for (j=0; j<m; j++)
                {
                    fscanf(player_grid," %c",&grid[i][j]);
                }
            }
            fclose(player_grid);
            FILE*RAW_MIN;
            RAW_MIN=fopen("RAW.txt","r");
            if (RAW_MIN == NULL)
            {
                printf("Error opening file!\n");
                exit(1);
            }
            for (i=0 ; i<num_of_mine; i++)
            {
                fscanf(RAW_MIN,"%d",&raw[i]);
            }
            fclose(RAW_MIN);
            FILE*COL_MIN;
            COL_MIN=fopen("COL.txt","r");
            if (COL_MIN== NULL)
            {
                printf("Error opening file!\n");
                exit(1);
            }
            for (i=0 ; i<num_of_mine; i++)
            {
                fscanf(RAW_MIN,"%d",&col[i]);
            }
            fclose(COL_MIN);
            int check=0;
            for (i=0 ; i<m ; i++)
            {
                for (j=0 ; j<n ; j++)
                {
                    if (hidden_grid[i][j]=='0')
                    {
                        hidden_grid[i][j]=' ';
                    }
                    if (grid[i][j]=='0')
                    {
                        grid[i][j]=' ';
                        check=1;

                    }
                }
            }
            for (i=0 ; i<m ; i++)
            {
                for (j=0 ; j<n ; j++)
                {
                    if (check==1 ||(grid[i][j]>=1&&grid[i][j]<=9))
                    {
                        system("cls");
                        printf("\n Time %d:%d moves: %d\n",(int)time/60,(int)time%60,moves);
                        draw_grid(m,n,grid);
                        GameLoop(m,n,hidden_grid,grid,&moves,&time,num_of_mine,raw,col,&f,&quest);
                        flag=0;
                        break;
                    }
                    else
                    {
                        system("cls");
                        printf("\n Time %d:%d moves: %d\n",(int)time/60,(int)time%60,moves);
                        draw_grid(m,n,grid);
                        first_click(m,n,hidden_grid,grid,num_of_mine,raw,col,&moves,&time,&f,&quest);
                        flag=0;
                        break;
                    }

                }
                break;
            }


            break;

        }
        case 3 :// to open tne player score sheet
        {
            system("cls");
            char player[100];
            int i=1;
            FILE*plsc;
            plsc=fopen("score.txt","r");
            if (plsc==NULL)
            {
                exit(0) ;
            }

            while ( fgets(player,100,plsc)!=NULL)
            {
                printf("%d-%s",i,player);
                i++;
            }
            fclose(plsc);
            flag=0;
            menu();

            break;
        }
        case 4:system("cls");
            exit(1); break;
        default:
            printf("Invalid\n");
            printf("ENTER YOUR CHOICE : ");

        }
    }
}
