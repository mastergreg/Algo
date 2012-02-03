/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : carnical.cpp

* Purpose :

* Creation Date : 29-01-2012

* Last Modified : Fri 03 Feb 2012 03:53:52 AM EET

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/

#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

bool cmp(int *v1,int *v2)
{
    return v1[2] < v2[2];
}


int find(int x,int **parents)
{
    //need to implement cost addition to parents
    //if( x != parents[x][0] )
    //    parents[x][0] = find(parents[x][0],parents);
    //return parents[x][0];
    while ( x != parents[x][0] )
    {
        x = parents[x][0];
    }
    return x;
}
void unite(int x,int y,int cost,int **parents)
{
    if (y == x ) 
    {
        return;
    }
    int k = find(y,parents);
    parents[k][0] = x;
    //parents[y][1] = max(parents[y][1],cost);
    parents[k][1] = max(parents[k][1],cost);
    parents[x][1] = max(parents[x][1],cost);
}


bool nofindset(int x, int y, int **parents)
{
    return (find(x,parents) != find(y,parents));
}


long long int kruskal(int **edges,int **parents,int V, int E)
{
    int found = 0 ;
    int i=0;
    long long int cost=0;
    while(found < V-1 && i < E)
    {
        if ( nofindset(edges[i][0],edges[i][1],parents) )
        {
            unite(edges[i][0],edges[i][1],edges[i][2],parents);
            edges[i][3] = 1;
            cost+=edges[i][2];
            found++;
        }
        i++;
    }
    return cost;
}

int get_max_cost(int i,int **parents)
{
}
long long int snd_mst(int **edges,int **parents, int E)
{
    unsigned long long int max_c,min_c;
    max_c=0;
    min_c=-1;
    for ( int i = 1 ; i < E ; ++i )
    {
        if ( edges[i][3] == 0 )
        {
            //printf("edge[%d] %d -> %d unused, weight %d\n",i,edges[i][0],edges[i][1], edges[i][2]);
            
            max_c = max(parents[edges[i][0]][1], parents[edges[i][1]][1]);
            //printf("%d %d %d\n",parents[edges[i][0]][2], parents[edges[i][1]][2],max_c);
            min_c = min(min_c,edges[i][2] - max_c);
        }
    }
    return (long long int) min_c;

}
int main()
{

    int V,E;


    scanf("%d %d\n",&V,&E);
    int **edges = new int*[E];
    int a,b,c;
    int **parents = new int*[V];
    //edges[i] = | n1 | n2 | w | used
    //parents | father | size | cost? //
    for( int i = 0 ; i < V ; ++i )
    {
        parents[i] = new int[2];
        parents[i][0] = i;
        parents[i][1] = 0;

    }
    for( int i = 0 ; i < E ; ++i )
    {
        edges[i] = new int[4];
        scanf("%d %d %d\n",&a,&b,&c);
        edges[i][0] = a-1;
        edges[i][1] = b-1;
        edges[i][2] = c;
        edges[i][3] = 0;
    }
    sort(edges,edges+E,cmp);
    //run kruskal
    //calculate mst
    long long int mst = kruskal(edges,parents,V,E);
    long long int smstdiff = snd_mst(edges,parents,E);

    printf("%lld %lld\n",mst,mst+smstdiff);
    





    return 0;
}
