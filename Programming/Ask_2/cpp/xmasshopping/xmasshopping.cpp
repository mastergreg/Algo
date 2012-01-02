/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : xmasshopping.cpp

* Purpose :

* Creation Date : 19-12-2011

* Last Modified : Tue 03 Jan 2012 12:16:35 AM EET

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/


#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <numeric>
#include <ostream>
#include <iterator>
#include <iostream>
using namespace std;


inline
int manhatan(const int *v1,const int *v2)
{
    /* =========================== 
     * Calculate manthatan 
     * distance of two points
     * =========================== */
    return abs( v1[0] - v2[0] ) + abs( v1[1] - v2[1] );
}

int solveMe(int n,int **shops)
{
    int next;
    int distances_i_next;
    int distances_j_next;
    int *current_line = new int[n];
    int *prev_line = new int[n];
    prev_line[n-1] = 0;

    for(int i = n-2 , next = n-1 ; i >= 0 ; i-- , next--)
    {
        distances_i_next = manhatan( shops[next] , shops[i] );
        for(int j = i-1 ; j >= 0 ; j--)
        {
            distances_j_next = manhatan( shops[next] , shops[j] );
            current_line[j] = min( distances_i_next + prev_line[j],
                                    distances_j_next + prev_line[i] );
        }
        swap( current_line , prev_line );
    }
    return current_line[0];
}

int main(void)
{
    int n = 0;
    int r = 0;
    int c = 0;
    int nothing;
    int **shops;
    /* ==== GET INPUT ==== */
    nothing = scanf("%d %d %d" , &n , &r , &c);
    n += 2;

    shops = new int*[n];
    for (int i = 0 ; i < n ; i++)
    {
        shops[i] = new int[2];
        nothing = scanf("%d %d" , &shops[i][0] , &shops[i][1]);
    }
    printf( "%d\n" , solveMe( n , shops ) );
    return 0;
}

