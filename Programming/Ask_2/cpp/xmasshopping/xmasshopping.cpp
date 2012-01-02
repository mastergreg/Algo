/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : xmasshopping.cpp

* Purpose :

* Creation Date : 19-12-2011

* Last Modified : Mon 02 Jan 2012 02:16:23 PM EET

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
    /* =========================== 
     * Calculate manthatan 
     * distance of two points
     * =========================== */
    return abs(v1[0]-v2[0])+abs(v1[1]-v2[1]);
}

inline void fill_layer_item(int z,vector< vector<int> >&layer1,vector< vector<int> >& layer2,vector< vector<int> >& distances,vector< vector<int> >& shops)
{
    unsigned int i,j;

    printf("\nlevel %d \n",z-1);
    for(i=0;i<layer2.size()-2;i++)
    {
        if(distances[i][z]==-1)
        {
            distances[i][z]=manhatan(shops[i],shops[z]);
        }
        for(j=i+1;j<layer2.size()-1;j++)
        {
            if(distances[j][z]==-1)
            {
                distances[j][z]=manhatan(shops[j],shops[z]);
            }
            layer2[i][j]= layer1[i][j]+min(distances[i][z],distances[j][z]);
        }
    }
    for(i=0;i<layer2.size();i++)
    {
        for(j=0;j<layer2.size();j++)
        {
            printf("%d\t",layer2[i][j]);
        }
        printf("\n");
    }

    //printf("a:%d p:%d t:%d %d %d %d %d\n",above,prev,top,i,j,z,layer2[i][j]);
}

int lesser(vector< vector<int> >& distances,vector< vector<int> >& shops)
{
    int i,j,z;
    bool flag=true;
    int n = shops.size();
    vector< vector<int> > layer1(n,vector<int>(n,0));
    vector< vector<int> > layer2(n,vector<int>(n,0));
    for (i=0;i<n;i++)
    {
        distances[0][i]=manhatan(shops[0],shops[i]);
        layer1[0][i]=distances[0][i];
        layer2[0][i]=distances[0][i];
    }
    for (i=0;i<n;i++)
    {
        distances[1][i]=manhatan(shops[1],shops[i]);
        layer1[1][i]=distances[1][i];
        layer2[1][i]=distances[1][i];
    }


    for(z=n-1;z>1;z--)
    {
        if(flag)
        {
            fill_layer_item(z,layer1,layer2,distances,shops);
        }
        else
        {
            fill_layer_item(z,layer2,layer1,distances,shops);
        }
        flag=!flag;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",layer1[i][j]);
        }
        printf("\n");
    }
    return min(layer1.back().back(),layer2.back().back());
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
    /* ==== GET INPUT ==== */
    nothing = scanf("%d %d %d",&n,&r,&c);
    vector< vector < int > > distances(n+2,vector<int>(n+2,-1));
    shops.reserve(n+2);

    //nothing = scanf("%d %d",&s1[0],&s1[1]);
    //nothing = scanf("%d %d",&s2[0],&s2[1]);
    for (i=0;i<n+2;i++)
    {
        shops.push_back(vector <int> (2));
        nothing = scanf("%d %d",&shops[i][0],&shops[i][1]);
        //ugly ugliness of ugly
    }
    s1=shops[0];
    s2=shops[1];
    /* ==== GET INPUT ==== */
    //generate_all_distances(shops,distances);
    //gen_mdists(shops,mdists);
    /* ==== prefix_sums of manhatan distances ==== */
    //partial_sum(mdists.begin(),mdists.end(),prefix_manthatan_distance_sums.begin()+1);

    //printf("%d\n",solveMe(s1,s2,shops,prefix_manthatan_distance_sums));
    printf("%d\n",lesser(distances,shops));



}

