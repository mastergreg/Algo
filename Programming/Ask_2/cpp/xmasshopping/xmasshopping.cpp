/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : xmasshopping.cpp

* Purpose :

* Creation Date : 19-12-2011

* Last Modified : Mon 02 Jan 2012 06:13:05 PM EET

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/


#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

/* needs to be ancestor matrix */
struct node
{
    int index;
    int father;
    int cost;
};

int manhatan(const vector<int>& v1,const vector<int>& v2)
{
    /* =========================== 
     * Calculate manthatan 
     * distance of two points
     * =========================== */
    return abs(v1[0]-v2[0])+abs(v1[1]-v2[1]);
}

void fill_line(int j,vector<int>& line1,vector<int>& line2,vector< vector<int> >& distances,vector< vector<int> >& shops) 
{
    int i;
    int prev;
    for (i=2;i<line2.size();i++)
    {
        /* ===============================
         * I need the previous 
         * consecutive node of i,j
         * which will be either i=1 or j-1
         * =============================== */
        prev=min(i,j)-1;
        if(distances[prev][i]==-1)
        {
            distances[prev][i]=manhatan(shops[prev],shops[i]);
        }
        if(distances[prev][j]==-1)
        {
            distances[prev][j]=manhatan(shops[prev],shops[j]);
        }
        line2[i]=min(distances[prev][i]+line2[prev],distances[prev][j]+line1[prev]);
    }

}

int lesser(vector< vector<int> >& distances,vector< vector<int> >& shops)
{
    int i,j,z;
    bool flag=true;
    int n = shops.size();
    vector< vector<int> > lines(n,vector<int>(n,0));
    
    for(i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            distances[i][j]=manhatan(shops[i],shops[j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            //lines[i][j]=min(distances[i-1]
        }
    }


}

int less(int i ,int j ,vector< vector<int> >& distances,vector< vector<int> >& shops,vector< vector<int> >& lessmatrix)
{
    int next;
    if(j==shops.size()-1 || i==shops.size()-1)
    {
        return 0;
    }
    next=max(i,j)+1;
    if(distances[i][next]==-1)
    {
        distances[i][next]=manhatan(shops[next],shops[i]);
    }
    if(distances[j][next]==-1)
    {
        distances[j][next]=manhatan(shops[next],shops[j]);
    }
    if(lessmatrix[i][j]==-1)
    {
        lessmatrix[i][j]= min(distances[i][next]+less(next,j,distances,shops,lessmatrix),
                distances[j][next]+less(next,i,distances,shops,lessmatrix));
    }
    return lessmatrix[i][j];
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
    s1=shops[0];
    s2=shops[1];
    /* ==== GET INPUT ==== */
    //generate_all_distances(shops,distances);
    //gen_mdists(shops,mdists);
    
    /* ==== prefix_sums of manhatan distances ==== */
    //partial_sum(mdists.begin(),mdists.end(),prefix_manthatan_distance_sums.begin()+1);

    //printf("%d\n",solveMe(s1,s2,shops,prefix_manthatan_distance_sums));
    printf("%d\n",less(0,1,distances,shops,lessmatrix));
    //printf("%d\n",lesser(distances,shops));



}

