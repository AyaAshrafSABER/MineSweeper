#include <stdio.h>

void draw_grid(int m,int n,char grid[][n])
{

    int i,j;
    if (n<10 && m<10) //when the gird < 10*10
    {
        printf("  MINESWEEPER\n");
        printf("  %d",0);
        for (j=2 ; j<=n ; j++)
        {
            printf(" %d",j-1);
        }
        printf("\n");
        for (i=0 ; i<m ; i++)
        {
            printf("%d ",i);
            for (j=0 ; j<n ; j++)
            {

                printf("%c ",grid[i][j]);
            }
            printf("\n");
        }
    }

   else // when the grid is bigger than 10*10
    {
        printf("  MINESWEEPER\n");
        printf("    %d",0);
        for (j=2 ; j<=n; j++)

        {   if (j<11){
            printf("   %d",j-1);

        }
            else if (j<50){
            printf("  %d",j-1);
            }

        }
        printf("\n");
        for (i=0 ; i<m ; i++)
        {   if (i<10){
            printf("%d   ",i);
        }
        else if (i<50){
            printf("%d  ",i);
        }
            for (j=0 ; j<n ; j++)
            {
                printf("%c   ",grid[i][j]);

            }

            printf("\n");
        }
    }

    printf("\t\tActions\t\t\n(o) to open.\t\t(q) to put a question mark.\n(f) to put a flag.\t(r) to remove flag or question mark.\n\t(X,Y,s) to save the game.\n");

}
