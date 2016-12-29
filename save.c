#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <time.h>

void pause(int m, int n ,char hidden_grid[][n], char grid[][n],int moves ,double t ,int num_of_min ,int raw[],int col[],int flags,int quest)
{
    int i , j ;
    for (i=0 ; i<m ;i++){
    for (j=0 ; j<n ; j++){
        if (hidden_grid[i][j]==' '){
            hidden_grid[i][j]='0';
        }
        if (grid[i][j]==' '){
            grid[i][j]='0';
        }
    }
    }

    FILE *load ;
    load=fopen("saved game.txt","w");
    /* print integers */
    fprintf(load, "%d %d %d %lf %d %d %d\n",m,n,moves,t,num_of_min,flags,quest);
    fclose(load);

    FILE *hidden;
    /* printing  matrix chatacters */
    hidden=fopen("HIDDEN.txt","w");
    for (i=0; i<m ; i++)
    {
        for (j=0 ; j<n ; j++)
        {
            fprintf(hidden,"%c ",hidden_grid[i][j]);
        }
    }
    fclose(hidden);

    FILE*player_grid;
    player_grid=fopen("GRID.txt","w");
    for (i=0; i<m ; i++)
    {
        for (j=0 ; j<n ; j++)
        {
            fprintf(player_grid ,"%c ",grid[i][j]);

        }

    }
    fclose(player_grid);
    FILE*RAW_MIN;
    RAW_MIN=fopen("RAW.txt","w");
    for (i=0 ;i<num_of_min;i++){
        fprintf(RAW_MIN,"%d ",raw[i]);
    }
    fclose(RAW_MIN);
        FILE*COL_MIN;
    COL_MIN=fopen("COL.txt","w");
    for (i=0 ;i<num_of_min;i++){
        fprintf(RAW_MIN,"%d ",col[i]);
    }
    fclose(COL_MIN);
    exit(0);
}

