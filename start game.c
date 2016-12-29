#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "draw the grid.h"
#include "Win Lose.h"
#include "menu.h"
#include "rand.h"
#include "Number.h"
#include "Order.h"
#include "Actions.h"
#include "First Click.h"

void start_game()
{
    system("cls");//to remove the start menu
    printf("Enter the dimensions for the grid: ");

    int m,n;
    char str1[30],str2[30];
    scanf(" %s",str1);
    if (strlen(str1)<3){
            m=todigit(str1);
    }
    else{
            while(getchar()!='\n');
            start_game();
       return;
    }
    scanf(" %s",str2);
    if (strlen(str2)<3){
            n=todigit(str2);
    }
    else{


        while(getchar()!='\n');
       start_game();
       return;
    }



    if(m>=2&&n>=2){
    char grid[m][n];
    int i,j;

    for (i=0 ; i<m ; i++)
    {
        for (j=0 ; j<n ; j++)
        {
            grid[i][j]='X';
        }
    }
    int moves=0;
    int questMark=0; //to calculate the moves from the beginnig of the the game
    draw_grid(m,n,grid);
    int num_of_mines=1+(m*n)/10;

    printf("number of mines:%d\n",num_of_mines);
    char hidden_grid[m][n] ;
    for (i=0 ; i<m ; i++)
    {
        for (j=0 ; j<n; j++)
        {
            hidden_grid[i][j]='0';
        }
    }
    int mine_raw_p[num_of_mines],mine_col_p[num_of_mines]; // the two array contain the places that contain tne mine on it

    randG(num_of_mines,m,n,hidden_grid,mine_raw_p,mine_col_p);
    number_in_cell(num_of_mines,m,n,hidden_grid,mine_raw_p,mine_col_p );
    double q=0;
    int flags=num_of_mines;

    first_click(m,n,hidden_grid,grid,num_of_mines,mine_raw_p,mine_col_p,&moves,&q,&flags,&questMark);
    }
    else{


        printf("Invalid!\n");
        while(getchar()!='\n');
        start_game();
    }
}
void  GameLoop (int m ,int n ,char hidden_grid [][n] ,char grid[][n] ,int* mov,double* w,int mines,int raw[],int col[],int *f,int* quest){
  int b=0;
    int c=0;
    double t=*w;
    int score=0;
    int moves =*mov;
    int flags=*f;


    while(!b)
{    if(!c){

time_t start=time(0);
while(getchar()!='\n');
 operations(m,n,grid,hidden_grid,&c,&moves,t,mines,raw,col,&flags,&(*quest));
 system("cls");
 t=t+difftime(time(0),start);

printf("\n Time: %d:%d moves: %d mines: %d QuestionMarks: %d\n",(int)t/60,(int)t%60,moves,flags,*quest);


draw_grid(m,n,grid);


b=winC(m,n,grid,hidden_grid);



}
else
{
    break;
}
}
if(b)
{
  score=(power(m,4)*power(n,4))/(t*moves);
  printf("Score= %d\n",score);
  player_score(score);
}
menu();
}
