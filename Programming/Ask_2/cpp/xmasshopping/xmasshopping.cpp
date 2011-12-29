/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : xmasshopping.cpp

* Purpose :

* Creation Date : 19-12-2011

* Last Modified : Thu 29 Dec 2011 12:34:02 AM EET

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/


#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int manhatan(const vector<int>& v1,const vector<int>& v2)
{
    return abs(v1[0]-v2[0])+abs(v1[1]-v2[1]);
}

int next(vector<int>& v1,vector<int>& v2,vector<int> dest)
{
    int m1 = manhatan(v1,dest);
    int m2 = manhatan(v2,dest);
    if(m1<m2)
    {
        v1[0]=dest[0];
        v1[1]=dest[1];
        return m1;
    }
    else
    {
        v2[0]=dest[0];
        v2[1]=dest[1];
        return m2;
    }
}
int totdist(int i,int j,const vector<int>& mdists)
{
    int tdist=0;
    tdist = accumulate(mdists.begin()+i,mdists.begin()+j,0);
    return tdist;
}

int previous(   vector< vector < int > >::iterator it1,
                vector< vector < int > >::iterator it2,
                vector< vector < int > >::iterator dest)
{
    int m1 = manhatan(*it1,*dest);
    int m2 = manhatan(*it2,*dest);
    if(m2<m1)
    {
        return m2;
    }
    else
    {
        return m1;
    }
}
void gen_mdists(const vector< vector<int> >& shops,vector<int>& mdists)
{
    vector< vector<int> >::const_iterator itsh=shops.begin()+1;
    vector<int>::iterator itmd=mdists.begin();
    (*itmd)=0;
    itmd++;
    for(;itsh!=shops.end();itsh++,itmd++)
    {
        (*itmd)=manhatan(*(itsh-1),*itsh);
    }
    
}


int main(void)
{
    int n=0;
    int r=0;
    int c=0;
    int nothing;
    int i;
    int total_dist=0;
    vector< vector < int > > shops;
    vector< int > XY1(2,0);
    vector< int > XY2(2,0);
    vector< int > mdists;




    nothing = scanf("%d %d %d",&n,&r,&c);
    shops.reserve(n);
    mdists.resize(n);

    nothing = scanf("%d %d",&XY1[0],&XY1[1]);
    nothing = scanf("%d %d",&XY2[0],&XY2[1]);
    for (i=0;i<n;i++)
    {
        shops.push_back(vector <int> (2));
        nothing = scanf("%d %d",&shops[i][0],&shops[i][1]);
    }
    gen_mdists(shops,mdists);
    vector< vector<int> >::iterator shop;
    for (shop=shops.begin(); shop!=shops.end(); shop++)
    {
        printf("%d (%d,%d) (%d,%d)\n",total_dist,XY1[0],XY1[1],XY2[0],XY1[1]);
        total_dist+=next(XY1,XY2,*shop);

    }
    printf("%d\n",total_dist);
    printf("%d\n",totdist(0,n,mdists));


}

