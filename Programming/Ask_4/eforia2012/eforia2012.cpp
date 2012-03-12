/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : eforia2012.cpp

* Purpose :

*Creation Date : 12-03-2012

* Last Modified : Mon 12 Mar 2012 05:29:40 PM EET

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/

#include <cstdio>
#include <cstdlib>

#include <queue>

using namespace std;

struct cmpare
{
    bool operator()(int *a, int *b){ return a[1] < b[1];}
};
typedef priority_queue<int *,vector<int *>,cmpare> my_pr_q;

int shortest_path(int start, int stop, int nodes, my_pr_q* heaps);

int main(void)
{
    int start;
    int stop;
    int cost;
    int edges;
    int *edge;
    int nodes;
    int i,j;
    int wanted[2];
    long long sum;

    scanf( "%d %d", &nodes, &edges );
    //printf( "%d %d\n", nodes, edges );
    my_pr_q *heaps = new my_pr_q[nodes];
    for ( i = 0,sum=0 ; i < edges ; ++i )
    {
        scanf( "%d %d %d", &start, &stop, &cost );
        edge = new int[2];
        edge[0] = stop;
        edge[1] = cost;
        heaps[start-1].push(edge);
        edge = new int[2];
        edge[0] = start;
        edge[1] = cost;
        heaps[stop-1].push(edge);
        sum+=cost;
        
    }
    for ( i = 0, j = 0 ; i < nodes ; ++i )
    {
        if (heaps[i].size() % 2 == 1) 
        {
            wanted[j++]=i+1;
        }
    }
    printf("%lld\n",shortest_path(wanted[0],wanted[1],nodes,heaps)+sum);
    delete[] heaps;
    return 0;
}

int shortest_path(int start, int stop, int nodes, my_pr_q* heaps)
{
    int *costs = new int[nodes]; 
    fill(costs, costs+nodes,0);
    int current = start;
    int min_cost;
    int next = start;
    int *buf;
    int total;

    while( current != stop )
    {
        min_cost = 0;
        while( !heaps[current-1].empty() )
        {
            buf = heaps[current-1].top();
            heaps[current-1].pop();
            if ( !heaps[buf[0]-1].empty()) //den exei eksereunh8ei akoma
            {
                if ( costs[buf[0]-1] == 0 && buf[0] != start)
                {
                    costs[buf[0]-1] = costs[current-1]+buf[1];
                }
                else
                {
                    costs[buf[0]-1] = min(costs[buf[0]-1], costs[current-1]+buf[1]);
                }

                if (min_cost == 0)
                {
                    next = buf[0];
                    min_cost = costs[buf[0]-1];
                }
                else if ( min_cost > costs[buf[0]-1])
                {
                    min_cost = costs[buf[0]-1];
                    next = buf[0];
                }
            }
        }
        if (current == next)
        {
            current = stop;
        }
        else
        {
            current = next;
        }
    }
    total = costs[stop-1];
    delete[] costs;
    return total;
}

