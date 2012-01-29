/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : headquarters.cpp

* Purpose :

* Creation Date : 29-01-2012

* Last Modified : Sun 29 Jan 2012 11:59:38 PM EET

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/


#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;


bool cmp(const int *a,const int *b)
{
    return a[1]<b[1];

}

bool cnt(const int *a,int b)
{
    return a[1]==b;
}

int main()
{
    int k,N,M,s,t;
    int **G;
    int **OCC;
    //G is sorted so that there are groups
    //that end to the same node
    //OCC should have the starting addreses of each group
    int a,b;

    scanf("%d %d %d %d %d",&k,&N,&M,&s,&t);
    G = new int*[M];
    OCC = new int*[N];

    for ( int i = 0 ; i < M ; i++ )
    {
        G[i] = new int[2];
        scanf("%d %d",&a,&b);
        G[i][0] = a-1;
        G[i][1] = b-1;
    }

    sort(G,G+M,cmp);

    for (int j = 0 , i = 0 ; j < M && i < N ; j++)
    {
        a = G[j][1];
        if( i == a )
        {
            OCC[i++]=G[j];
        }
        else if ( i < a )
        {
            for( ; i<a ; i++)
            {
                OCC[i] = NULL;
            }
            OCC[i++]=G[j];
        }
        else
        {
            continue;
        }
    }





    return 0;
}
