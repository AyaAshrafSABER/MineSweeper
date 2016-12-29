#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <time.h>
void loseOp(int m,int n,char a[m][n],char b[m][n])
{
    int i,j;
    for(i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
        {
            switch (a[i][j])
            {
                case 'F':{if(b[i][j]=='*')
                {
                    a[i][j]='*';
                }
                else{
                    a[i][j]='_';
                } break;}
                case '?':{if (b[i][j]=='*')
                {
                    a[i][j]='M';
                }
                else{
                    a[i][j]=b[i][j];
                } break;}
                case 'X':{if (b[i][j]=='*')
                {
                    a[i][j]='M';
                }
                else{
                    a[i][j]=b[i][j];
                }
                break;}
                case '*':a[i][j]='M'; break;


            }
        }
    }
}


int winC(int m,int n,char a[m][n],char b[m][n])
{
    int i,j;
    int flag=0;

    for(i=0; i<m;i++)

    {
        for(j=0; j<n; j++)
        {
            switch(b[i][j])
            {
                case '*': if(a[i][j]=='F')
                {
                    flag=1;
                }
                else{
                    flag=0;

                }
                break;
                default: {if(a[i][j]!='F'&&a[i][j]!='X')
                {
                    flag=1;
                }
                else{
                    flag=0;
                }}

            }
            if(flag==0)
            {
                i=m;
                break;

            }
        }
    }



    return flag;

}


int loseC(int m,int n,char a[m][n],char b[m][n],int i,int j,int x)
{
    if(a[i][j]=='*'&&!x)
    {
        printf("Game Over!");
        Sleep(2000);
        a[i][j]='!';
        loseOp(m,n,a,b);
        return 1;

    }
    else if(x)
    {
         printf("Game Over!");
        Sleep(2000);
        loseOp(m,n,a,b);
        return 1;
    }
    else return 0;


}
