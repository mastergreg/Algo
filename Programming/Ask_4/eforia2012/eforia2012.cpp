/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : eforia2012.cpp

* Purpose :

*Creation Date : 12-03-2012

* Last Modified : Mon 12 Mar 2012 05:46:56 PM EET

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/

#include <cstdio>
#include <cstdlib>

#include <queue>

#define BSIZE 1<<15

char buffer[BSIZE];
long bpos = 0L, bsize = 0L;

long readLong()
{
	long d = 0L, x = 0L;
	char c;

	while (1)  {
		if (bpos >= bsize) {
			bpos = 0;
			if (feof(stdin)) return x;
			bsize = fread(buffer, 1, BSIZE, stdin);
		}
		c = buffer[bpos++];
		if (c >= '0' && c <= '9') { x = x*10 + (c-'0'); d = 1; }
		else if (d == 1) return x;
	}
	return -1;
}

using namespace std;

struct cmpare
{
    bool operator()(long *a, long *b){ return a[1] < b[1];}
};
typedef priority_queue<long *,vector<long *>,cmpare> my_pr_q;

long shortest_path(long start, long stop, long nodes, my_pr_q* heaps);

int main(void)
{
    long start;
    long stop;
    long cost;
    long edges;
    long *edge;
    long nodes;
    long i,j;
    long wanted[2];
    long long sum;

    nodes = readLong();
    edges = readLong();
    //scanf( "%ld %ld", &nodes, &edges );
    //printf( "%d %d\n", nodes, edges );
    my_pr_q *heaps = new my_pr_q[nodes];
    for ( i = 0,sum=0 ; i < edges ; ++i )
    {
        start = readLong();
        stop = readLong();
        cost = readLong();
        //scanf( "%d %d %d", &start, &stop, &cost );
        edge = new long[2];
        edge[0] = stop;
        edge[1] = cost;
        heaps[start-1].push(edge);
        edge = new long[2];
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

long shortest_path(long start, long stop, long nodes, my_pr_q* heaps)
{
    long *costs = new long[nodes]; 
    fill(costs, costs+nodes,0);
    long current = start;
    long min_cost;
    long next = start;
    long *buf;
    long total;

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

