/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : xmasshopping.cpp

* Purpose :

* Creation Date : 19-12-2011

* Last Modified : Tue 27 Dec 2011 11:40:39 PM EET

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/


#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    int n=0;
    int r=0;
    int c=0;
    int nothing;
    int i;
    vector< vector < int > > shops;
    vector< int > XY1(2,0);
    vector< int > XY2(2,0);




    nothing = scanf("%d %d %d",&n,&r,&c);
    shops.reserve(n);

    nothing = scanf("%d %d",&XY1[0],&XY1[1]);
    nothing = scanf("%d %d",&XY2[0],&XY2[1]);
    for (i=0;i<n;i++)
    {
        shops.push_back(vector <int> (2));
        nothing = scanf("%d %d",&shops[i][0],&shops[i][1]);
    }

}
