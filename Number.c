void number_in_cell (int num_of_mine,int m,int n, char a[m][n] , int raw[num_of_mine],int col[num_of_mine])
{
    int i , j ;
    for (i=0 ; i<num_of_mine ; i++)
    {
        if (a[raw[i]-1][col[i]-1]!='*' && raw[i]>0 &&col[i]>0)
        {
            a[raw[i]-1][col[i]-1] ++;
        }

    }
    for (i=0 ; i<num_of_mine ; i++)
    {


        if(a[raw[i]][col[i]-1]!='*' &&col[i]>0)
        {
            a[raw[i]][col[i]-1] ++ ;
        }

    }
    for (i=0 ; i<num_of_mine ; i++)
    {

        if (a[raw[i]+1][col[i]-1]!='*'&& col[i]>0 && raw[i]+1<m)
        {
            a[raw[i]+1][col[i]-1] ++ ;

        }

    }
    for (i=0 ; i<num_of_mine ; i++)
    {

        if (a[raw[i]-1][col[i]]!='*' && raw[i]>0)
        {
            a[raw[i]-1][col[i]]++;


        }
    }
        for (i=0 ; i<num_of_mine ; i++)
        {

            if (a[raw[i]+1][col[i]]!='*' && raw[i]+1<m)
            {
                a[raw[i]+1][col[i]]++ ;
            }

        }
        for (i=0 ; i<num_of_mine ; i++)
        {


            if (a[raw[i]-1][col[i]+1]!='*' && raw[i]>0 &&col[i]+1<n )
            {
                a[raw[i]-1][col[i]+1]++;
            }

        }
        for (i=0 ; i<num_of_mine ; i++)
        {

            if (a[raw[i]][col[i]+1]!='*' &&col[i]+1<n)
            {
                a[raw[i]][col[i]+1]++;
            }

        }
        for (i=0 ; i<num_of_mine ; i++)
        {

            if (a[raw[i]+1][col[i]+1]!='*'&&col[i]+1<n && raw[i]+1<m)
            {
                a[raw[i]+1][col[i]+1]++;
            }

        }
 for (i=0 ; i<m ;i++){
    for (j=0 ; j<n ; j++){
        if (a[i][j]=='0'){
            a[i][j]=' ';
        }
    }
 }

    }
