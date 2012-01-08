/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : xmasshopping.cpp

* Purpose :

* Creation Date : 19-12-2011

* Last Modified : Sun 08 Jan 2012 07:00:01 PM EET

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
inline
int manhatan(const int *v1,const int j,const int k)
{
    /* =========================== 
     * Calculate manthatan 
     * distance of two points
     * =========================== */
    return abs( v1[0] - j ) + abs( v1[1] - k );
}

inline
int solveMe(int R,int C,int n,int **shops)
{
    int next;
    int distances_i_next;
    int distances_j_next;
    int result;
    int **current_layer = new int*[R+1];
    int **prev_layer = new int*[R+1];
    for(int i=0;i<=R;i++)
    {
        current_layer[i]=new int[C+1];
        prev_layer[i]=new int[C+1];
        fill(prev_layer[i],prev_layer[i]+C+1,0);
    }
    vector< vector<bool> > shopfield(R+1,vector<bool>(C+1,false));
    for(int i = 0 ; i < n ; i++)
    {
        shopfield[shops[i][0]][shops[i][1]]=true;
    }

    for(int i = n-2 , next = n-1 ; i >= 0 ; i-- , next--)
    {
        distances_i_next = manhatan( shops[next] , shops[i] );
        for(int j = R ; j > 0 ; j--)
        {
            for(int k = C ; k > 0 ; k--)
            {
                if(shopfield[j][k])
                {
                    distances_j_next = manhatan( shops[next] , j ,k );
                    current_layer[j][k] = min( distances_i_next + prev_layer[j][k],
                            distances_j_next + prev_layer[shops[i][0]][shops[i][1]] );
                }
            }
        }
        swap( current_layer, prev_layer );
    }

    result = current_layer[shops[0][0]][shops[0][1]];

    delete[] current_layer;
    delete[] prev_layer;
    return result;
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
    printf( "%d\n" , solveMe(r,c, n , shops ) );
    return 0;
}

