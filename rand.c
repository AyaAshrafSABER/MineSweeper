
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void randG (int num_of_mines,int m,int n,char hidden_grid[m][n],int a[num_of_mines],int b[num_of_mines])
{
    int i, j;
    time_t t;
    /* Intializes random number generator */
    srand((unsigned) time(&t));

    /* Print (number of mine)  random numbers from 0 to m */
    for( i = 0 ; i <num_of_mines  ; i++ )
    {
        a[i]=rand()%(m) ;
    }
    for (j=0 ; j<num_of_mines ; j++)
    {
        b[j]=rand()%(n);
    }
    int k=0;
    while(k<num_of_mines)
    {
        switch(hidden_grid[a[k]][b[k]])
        {
        case'0':
        {
            hidden_grid[a[k]][b[k]]='*';
            k++;
        }
        break;
        case '*':
        {
          //  b[k]=rand()%(n);
            for (j=0; j<n;)
            {
                if ( hidden_grid[a[k]][b[k]]=='*') //it will not work in all conditions;
                {
                    b[k]=rand()%(n);
                    j=0;
                }
                else
                {
                    j++;

                }
            }
            hidden_grid[a[k]][b[k]]='*';
            k++;

        }

        }

    }

}
