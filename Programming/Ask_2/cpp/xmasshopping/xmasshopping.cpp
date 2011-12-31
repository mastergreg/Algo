/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : xmasshopping.cpp

* Purpose :

* Creation Date : 19-12-2011

* Last Modified : Sat 31 Dec 2011 04:18:31 AM EET

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

int totdist(int i,int j,const vector<int>& prefix_sum_dists)
{
    int tdist=0;
    tdist = prefix_sum_dists.at(j)-prefix_sum_dists.at(i);
    return tdist;
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
int totalCost(int total_dist,int input_cost,int start,int finish,const vector<int>& prefix_sum_mh_dists)
{
    return total_dist-(prefix_sum_mh_dists[start]-prefix_sum_mh_dists[start-1])-(prefix_sum_mh_dists[finish]-prefix_sum_mh_dists[finish+1])+input_cost;
}
int solveMe(const vector<int>& s1,const vector<int>& s2,const vector< vector<int> >& shops,const vector<int>& p_sum_mdists)
{
    int total_dist=manhatan(s2,shops[0])+p_sum_mdists.back();
    vector<int> line1(shops.size()+1,0);
    vector<int> line2(shops.size()+1);
    line1[0]=total_dist;
    return total_dist;

}

int main(void)
{
    int n=0;
    int r=0;
    int c=0;
    int nothing;
    int i;
    vector< vector < int > > shops;
    vector< int > s1(2,0);
    vector< int > s2(2,0);
    vector< int > mdists;
    vector< int > prefix_manthatan_distance_sums;




    nothing = scanf("%d %d %d",&n,&r,&c);
    shops.reserve(n);
    mdists.resize(n);
    prefix_manthatan_distance_sums.resize(n+1);
    prefix_manthatan_distance_sums[0]=0;

    nothing = scanf("%d %d",&s1[0],&s1[1]);
    nothing = scanf("%d %d",&s2[0],&s2[1]);
    for (i=0;i<n;i++)
    {
        shops.push_back(vector <int> (2));
        nothing = scanf("%d %d",&shops[i][0],&shops[i][1]);
    }
    gen_mdists(shops,mdists);
    partial_sum(mdists.begin(),mdists.end(),prefix_manthatan_distance_sums.begin()+1);

    printf("%d\n",solveMe(s1,s2,shops,prefix_manthatan_distance_sums));



}

