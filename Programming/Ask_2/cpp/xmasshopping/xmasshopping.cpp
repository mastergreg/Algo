/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : xmasshopping.cpp

* Purpose :

* Creation Date : 19-12-2011

* Last Modified : Mon 02 Jan 2012 09:40:59 PM EET

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/


#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;


inline
int manhatan(const vector<int>& v1,const vector<int>& v2)
{
    /* =========================== 
     * Calculate manthatan 
     * distance of two points
     * =========================== */
    return abs(v1[0]-v2[0])+abs(v1[1]-v2[1]);
}

int less(int n,vector< vector<int> >& shops)
{
    int next;
    int distances_i_next,distances_j_next;
    int **lessmatrix = new int*[n];
    for(int i=0;i<n;i++)
    {
        lessmatrix[i]=new int[n];
    }
    lessmatrix[n-1][n-1]=0;

    for(int i=n-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            next=min(n-1,max(i,j)+1);
            distances_i_next=manhatan(shops[next],shops[i]);
            distances_j_next=manhatan(shops[next],shops[j]);
            lessmatrix[i][j]= min(distances_i_next+lessmatrix[next][j],
                    distances_j_next+lessmatrix[next][i]);
        }

    }
    return lessmatrix[0][1];
}

int main(void)
{
    int n=0;
    int r=0;
    int c=0;
    int nothing;
    int i;
    vector< vector < int > > shops;
    //int **shops;
    /* ==== GET INPUT ==== */
    nothing = scanf("%d %d %d",&n,&r,&c);
    vector< vector < int > > lessmatrix(n+2,vector<int>(n+2,-1));
    lessmatrix[n-1][n-1]=0;
    shops.reserve(n+2);

    //nothing = scanf("%d %d",&s1[0],&s1[1]);
    //nothing = scanf("%d %d",&s2[0],&s2[1]);
    for (i=0;i<n+2;i++)
    {
        shops.push_back(vector <int> (2));
        nothing = scanf("%d %d",&shops[i][0],&shops[i][1]);
        //ugly ugliness of ugly
    }

    //printf("%d\n",solveMe(s1,s2,shops,prefix_manthatan_distance_sums));
    printf("%d\n",less(n+2,shops));
    //printf("%d\n",lesser(distances,shops));



}

