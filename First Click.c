#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>
#include "start game.h"
#include "Actions.h"
#include "save.h"
#include "Empty Cell.h"
#include "Number.h"
#include "rand.h"
#include "draw the grid.h"

void first_click(int m , int n ,char hidden_grid[][n],char grid[][n],int num_of_mines,int mine_raw_p[],int mine_col_p[],int* mov,double* t ,int * flags,int*quest)
{
    int x,y; //the coordinaqts
    //2 function
    int i,j ;
    int flag=0; //to check if the player opens the cell ;
    char operation,xc[30],yc[30];


    while (flag==0)
    {
        time_t start=time(0);

       printf("Enter the coordinates: \n");
    printf("X=");
    scanf(" %s",xc);
    if (strlen(xc)<3){
            x=todigit(xc);
    }
    else{

         printf("\nInvalid coordinates.\nPlease keep in mind that:\n");
        printf("0<=X<%d\n",m);
        while(getchar()!='\n');
       first_click(m,n,hidden_grid,grid,num_of_mines,mine_raw_p,mine_col_p,&(*mov),&(*t),&(*flags),&(*quest));
       return;
    }


    printf("\nY=");

    scanf(" %s",yc);
    if (strlen(yc)<3){
            y=todigit(yc);
    }
    else{
         printf("\nInvalid coordinates.\nPlease keep in mind that:\n");
        printf("0<=Y<%d\n",n);
        while(getchar()!='\n');

first_click(m,n,hidden_grid,grid,num_of_mines,mine_raw_p,mine_col_p,&(*mov),&(*t),&(*flags),&(*quest));
       return;
    }
        printf("Enter Operation : ");
        scanf(" %c",&operation);



        if ( x<m  && y < n && x >=0 && y>=0)
        {
            if (operation == 'O'|| operation == 'o')
            {
                *mov=*mov+1;
                flag=1;
                if (hidden_grid[x][y]!='*')
                {
                    if(grid[x][y]=='F')
                    {
                        *flags=*flags+1;
                    }
                    if(grid[x][y]=='?')
                    {
                        *quest=*quest-1;
                    }
                    grid[x][y]=hidden_grid[x][y];

                    if (hidden_grid[x][y]==' ')
                    {

                        emptyCell(m ,n, grid, hidden_grid,x ,y);//a is the player grid

                    }
                }
                else
                {
                    while ( hidden_grid[x][y]=='*')
                    {
                        for (i=0 ; i<m ; i++)
                        {
                            for (j=0 ; j<n; j++)
                            {
                                hidden_grid[i][j]='0';
                            }
                        }


                        randG(num_of_mines,m,n,hidden_grid,mine_raw_p,mine_col_p);
                        number_in_cell(num_of_mines,m,n,hidden_grid,mine_raw_p,mine_col_p);
                    }
                    if(grid[x][y]=='F')
                    {
                        *flags=*flags+1;
                    }
                    if(grid[x][y]=='?')
                    {
                        *quest=*quest-1;
                    }

                    grid[x][y]=hidden_grid[x][y];

                    if (hidden_grid[x][y]==' ')
                    {

                        emptyCell(m ,n, grid, hidden_grid,x ,y);//a is the player grid

                    }

                }
                *t=*t+difftime(time(0),start);
            }
            else if (operation=='f' || operation=='F')
            {
                if(grid[x][y]=='?')
                    {
                        *quest=*quest-1;
                    }

                grid[x][y]='F';
                *mov=*mov+1;
                *flags=*flags-1;
                system("cls");
                *t=*t+difftime(time(0),start);
                 printf("time %d:%d  moves:%d\n",(int)*t/60,(int)*t%60,*mov);
                draw_grid(m,n,grid);

            }
            else if (operation== 'q')
            {
                if(grid[x][y]=='F')
                {
                    *flags=*flags+1;
                }

                grid[x][y]='?';
                *quest=*quest+1;
                *mov=*mov+1;
                system("cls");
                *t=*t+difftime(time(0),start);
                 printf("time %d:%d  moves:%d\n",(int)*t/60,(int)*t%60,*mov);
                draw_grid(m,n,grid);

            }

            else if (operation =='r' || operation =='R') //remove flags or question mark
            {
                if(grid[x][y]=='F')
                {
                    *flags=*flags+1;
                }
                if(grid[x][y]=='?')
                    {
                        *quest=*quest-1;
                    }

                *t=*t+difftime(time(0),start);
                grid [x][y]='X';
                *mov=*mov+1;

                system("cls");

                 printf("time %d:%d  moves:%d\n",(int)*t/60,(int)*t%60,*mov);
                draw_grid(m,n,grid);

            }
            else if (operation=='n'||operation=='N'){
                *mov=*mov+1;

            }
            else if (operation == 's')// save game
                {  flag =1;
                    pause ( m , n , hidden_grid, grid, *mov,*t,num_of_mines,mine_raw_p,mine_col_p,*flags,*quest);
                }



            else
            {
                printf ("error\n");
            }
        }
        else
        {
                *mov=*mov+1;
            printf ("\nInvalid coordinate\n");
            getchar();
            while('\n'!=getchar())
            {
                getchar();
            }
        }

    }
    system("cls");
  printf("time %d:%d  moves:%d mines: %d\n",(int)*t/60,(int)*t%60,*mov,*flags);
    draw_grid(m,n,grid);
   GameLoop(m,n,hidden_grid,grid ,&(*mov),&(*t),num_of_mines, mine_raw_p,mine_col_p,&(*flags),&*quest);



}
