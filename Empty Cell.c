void emptyCell(int m,int n, char a[m][n], char b[m][n], int i,int j)     //a is the player grid
{
    // b is a hidden grid



    int k,l;

    for (k=i-1; k<=i+1&&k<m;)
    {
        if(k<0)
        {
            k++;
        }
        else{

        for (l=j-1 ; l<=j+1 &&   l<n ; )
        {
            if(l<0)
            {
                l++;
            }

            else
            {
                if(a[k][l]=='X')
                {
                    a[k][l]=b[k][l];
                     if(b[k][l]==' ')
                {
                    emptyCell(m,n,a,b,k,l);

                }
                }

               l++;

            }


        }
        k++;
        }
    }


}
