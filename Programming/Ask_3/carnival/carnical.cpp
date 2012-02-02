/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : carnical.cpp

* Purpose :

* Creation Date : 29-01-2012

* Last Modified : Thu 02 Feb 2012 04:30:47 PM EET

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/

#include <cstdio>
#include <cstdlib>
#include <algorithm>


bool cmp(int *v1,int *v2)
{
    return v1[2] < v2[2]
}
int main()
{

    int V,E;


    scanf("%d %d\n",&V,&E);
    int **edges = new int*[E];
    //edges[i] = | n1 | n2 | w | used
    for( int i = 0 ; i < E ; ++i )
    {
        edges[i] = new int[4];
        scanf("%d %d %d\n",&edges[i][0],&edges[i][1],&edges[i][2]);
        edges[i][3]=0;
    }
    sort(edges,edges+E,cmp);
    //run kruskal
    //calculate mst
    





    return 0;
}
