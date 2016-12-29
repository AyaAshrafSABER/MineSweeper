#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>
#include "draw the grid.h"
#include "Win Lose.h"
#include "rand.h"
#include "save.h"
#include "Number.h"
#include "Empty Cell.h"
#include "OpeningOpenCell.h"

int todigit(char str[100])
{
    int i,num=0;
    for (i=0 ; i<strlen(str);i++){
    if (str[i]>='0'&&str[i]<='9'){
    num= num*10+(int)(str[i]-'0');
     }
     else{num=-1;break;}
    }
    return num;
}
int power(int m,int k)
{
    int i;
    int sum=1;
    for(i=0; i<k; i++)
    {
        sum=sum*m;
    }
    return sum;
}

char lowerUpper(char s)
{
    char d;
    if(isupper(s))
    {
        s=tolower(s);
        d=s;
    }
    else{
        d=s;
    }
    return d;
}

void cellWithFlag(int m,int n,char a[m][n],char b[m][n],int i,int j,int* p,int* mov,double t,int mines, int raw[],int col[],int* flags,int* quest)
{
    char operation;

    printf("Enter the operation: \n");
    scanf(" %c",&operation);
    operation=lowerUpper(operation);
    switch(operation)
    {
    case'n':
        while(getchar()!='\n');
        operations(m,n,a,b,&(*p),&(*mov),t,mines,raw,col,&(*flags),&(*quest));
        break;
    case 'q':
        a[i][j]='?';
        *mov=*mov+1;
        *quest=*quest+1;
       *flags=*flags+1;
        break;
    case 'o':
    {
        a[i][j]=b[i][j];
         *flags=*flags+1;
        *mov=*mov+1;
      //  *mines=*mines+1;
        if (a[i][j]==' ')
        {

            emptyCell(m,n, a, b,i,j);  //a is the player grid

        }
        else
        {
            if(b[i][j]=='*')
            {

                *p=loseC(m,n,a,b,i,j,0);
            }


        }

        break;
    }
    case 'r':
        a[i][j]='X';
        *mov=*mov+1;
       *flags=*flags+1;
        break;
    case 's':
        pause(m,n,b,b,*mov,t,mines,raw,col,*flags,*quest); break;

    default :
    {
        system("cls");
        printf("Invalid Operation!");

        draw_grid(m,n,a);
        cellWithFlag(m,n,a,b,i,j,&(*p),&(*mov),t,mines,raw,col,&(*flags),&(*quest));
    }
    }

}
void cellUnopened(int m,int n,char a[m][n],char b[m][n],int i,int j,int* p,int* mov,double t,int mines,int raw[],int col[],int *flags,int* quest)
{

    char operation;
    printf("Enter the operation: \n");
    scanf(" %c",&operation);
    operation=lowerUpper(operation);
    switch(operation)
    {
    case 'n':
        while(getchar()!='\n');
        operations(m,n,a,b,&(*p),&(*mov),t,mines,raw,col,&(*flags),&(*quest));
        break;
    case 'f':
        a[i][j]='F';
        *mov=*mov+1;
      *flags=*flags-1;
        break;
    case 'q':
        a[i][j]='?';
        *quest=*quest+1;
        *mov=*mov+1;
        break;
    case 'o':
    {
        a[i][j]=b[i][j];
        *mov=*mov+1;
        if (a[i][j]==' ')
        {

            emptyCell(m,n, a, b,i,j);  //a is the player grid

        }
        else
        {
            if(b[i][j]=='*')
            {

            *p=loseC(m,n,a,b,i,j,0);
            }

        }


        break;
    }
    case 's':pause(m,n,b,a,*mov,t,mines,raw,col,*flags,*quest);

    break;
    default :
    {
        printf("Invalid Operation!\n");
        printf("Kindly follow the following instructions. \n");
        printf("To enter new coordinates press N\nTo put a question mark press Q\nTo open the cell press O\nTo put a flag press F\n");
        cellUnopened(m,n,a,b,i,j,&(*p),&(*mov),t,mines,raw,col,&(*flags),&(*quest));
    }
    }

}

void cellWithQuestion(int m,int n,char a[m][n],char b[m][n],int i,int j,int* p,int* mov,double t,int mines,int raw[],int col[],int *flags,int* quest)
{
    printf("Note that the choosen cell contains a Question mark ,Kindly Follow the following Instructions : \n");
    char operation;
    printf("To enter new coordinates press N\nTo put a Flag mark press F\nTo open the cell press O\n to remove the Question mark press R\n");
    printf("Enter the operation: \n");
    scanf(" %c",&operation);
    operation=lowerUpper(operation);
    switch(operation)
    {
    case'n':
    {
        while(getchar()!='\n');
        operations(m,n,a,b,&(*p),&(*mov),t,mines,raw,col,&(*flags),&(*quest));
        break;
    }
    case 'f':
    {
        a[i][j]='F';
        *flags=*flags-1;
        *quest=*quest-1;
        *mov=*mov+1;
      //  *mines=*mines-1;
        break;
    }
    case 'o':
    {
        a[i][j]=b[i][j];
        *mov=*mov+1;
        *quest=*quest-1;
        if (a[i][j]==' ')
        {

            emptyCell(m,n, a, b,i,j);  //a is the player grid

        }
        else
        {
            if(b[i][j]=='*')
            {

                *p=loseC(m,n,a,b,i,j,0);
            }


        }


        break;
    }
    case 'r':
    {
        a[i][j]='X';
        *quest=*quest-1;
        *mov=*mov+1;
        break;
    }
    case 's':pause(m,n,b,a,*mov,t,mines,raw,col,*flags,*quest);
    break;
    default :
    {
        printf("Invalid Operation!");
        cellWithQuestion(m,n,a,b,i,j,&(*p),&(*mov),t,mines,raw,col,&(*flags),&(*quest));
    }
    }

}

void operations(int m,int n,char a[m][n],char b[m][n],int *p,int* mov,double t,int mines ,int raw[], int col[], int *flags,int* quest)
{


   int x,y;
    char xc[m],yc[n];



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
       operations(m,n,a,b,&(*p),&(*mov),t,mines,raw,col,&(*flags),&(*quest));
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

       operations(m,n,a,b,&(*p),&(*mov),t,mines,raw,col,&(*flags),&(*quest));
       return;
    }



    if(x<m&&y<n&&x>=0&&x>=0)
    {
        char ans;


        switch(a[x][y])
        {

        case 'X':
        {
            cellUnopened(m,n,a,b,x,y,&(*p),&(*mov),t,mines,raw,col,&(*flags),&(*quest));
            break;
        }
        case 'F':
        {
            cellWithFlag(m,n,a,b,x,y,&(*p),&(*mov),t,mines,raw,col,&(*flags),&(*quest));
            break;
        }
        case '?':
        {
            cellWithQuestion(m,n,a,b,x,y,&(*p),&(*mov),t,mines,raw,col,&(*flags),&(*quest));
            break;
        }

        case ' ':{printf("The choosen cell is already opened.Do you want to save the game ?(s for YES)Enter any char for NO.\n");
        scanf(" %c",&ans);
        lowerUpper(ans);
        switch(ans)
        {


            case 's': pause(m,n,b,a,*mov,t,mines,raw,col,*flags,*quest); break;
            default :operations(m,n,a,b,&(*p),&(*mov),t,mines,raw,col,&(*flags),&(*quest)); break;
            }
        }break;

        default: {printf("Do you want to save the game ?(s for YES)Enter any char for NO.\n");
        scanf(" %c",&ans);
        lowerUpper(ans);
        switch(ans)
        {
            case 's':pause(m,n,b,a,*mov,t,mines,raw,col,*flags,*quest);break;
            default :
                  openingOpenCell(m,n,a,b,x,y,&(*p),&(*mov));
        }
        }

        system("cls");
        draw_grid(m,n,a);

        }






        }



    else
    {
        printf("\nInvalid coordinates.\nPlease keep in mind that:\n");
        printf("0<=X<%d && 0<=Y<%d\nPress ENTER to continue..\n",m,n);

        while(getchar()!='\n');
        operations(m,n,a,b,&(*p),&(*mov),t,mines,raw,col,&(*flags),&(*quest));
    }
}

