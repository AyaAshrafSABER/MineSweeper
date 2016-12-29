void openingOpenCell(int m,int n,char a[m][n],char b[m][n],int i,int j,int *p,int* mov)
{
    int k,l,num=0;
    int mine=0;
    int s=b[i][j]-48;



    for(k=i-1; k<m&&k<=i+1;)
    {
        if(k<0)
        {
            k++;
        }
        else{
        for(l=j-1; l<n&&l<=j+1;)
        {
            if(l<0)
            {
                l++;
            }
            else{


            if(a[k][l]=='F')
            {
                num++;
                }


                l++;

                }
        }

    k++;
        }
}
if(s==num)
{


*mov=*mov+1;

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
                if(a[k][l]==' ')
                {
                    emptyCell(m,n,a,b,k,l);

                }
                else{
                if(a[k][l]=='*')
                {

                    mine++;

                }
                }

                }

               l++;

            }


        }
        k++;}
    }
    if(mine!=0)
                {
                   *p=loseC(m,n,a,b,k,l,1);
                }
}

}
