/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : teleport.cpp

* Purpose :

* Creation Date : 19-12-2011

* Last Modified : Fri 30 Dec 2011 11:28:14 PM EET

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
bool compare(const vector<int>& v1,const vector <int>& v2)
{
    if(v1[0]>v1[1] && v2[0]>v2[1]) 
        return v1[0] < v2[0] || (v1[0]==v2[0] && v1[1] < v2[1]);
    else 
        if(v1[0]>v1[1])
    {
        return false;
    }
    else 
        if(v2[0]>v2[1])
    {
        return true;
    }
    else
        return (v1[1] < v2[1] && v1[0]<=v2[0]) || (v1[1]==v2[1] && v1[0] <=v2[0]);

}
void fill_line(vector< vector< int > >::const_iterator abIt,
                            vector< int >& l1,vector< int >& l2)
{
    int i;
    int start = (*abIt)[0];
    int finish = (*abIt)[1];
    int inc=min(start,finish);
    vector< int >::iterator itl1,itl2;
    itl1=l1.begin()+1;
    itl2=l2.begin()+1;
    for(i=0;itl1!=l1.end() && itl2!=l2.end();itl1++,itl2++,i++)
    {
        if(i==inc)
        {
            (*itl2)=max(*itl1,*(itl2-1))+1;
        }
        else
        {
            (*itl2)=max(*itl1,*(itl2-1));
        }
    }
}
int solveMe(const vector< vector <int> >& AB,int top)
{
    vector< vector<int> >::const_iterator abIt;

    vector< vector<int> > dyn_line;
    dyn_line.reserve(2);
    dyn_line.push_back(vector<int>(top+1,0));
    dyn_line.push_back(vector<int>(top+1,0));

    //dyn_line[0].resize(top+1);
    //dyn_line[1].resize(top+1);

    int i;
    int j;

    for(i=0,j=1,abIt=AB.begin();abIt!=AB.end();abIt++)
    {
        fill_line(abIt,dyn_line[i],dyn_line[j]);
        if(i)
        {
            i=0;
            j=1;
        }
        else
        {
            i=1;
            j=0;
        }
    }
    return max(dyn_line[0].back(),dyn_line[1].back());

}

int main()
{
    int scientists=0;
    int nothing;
    int toplimit=0;
    vector< vector < int > > AB;

    nothing = scanf("%d",&scientists);

    AB.resize(scientists);
    
    vector< vector<int> >::iterator ABit;
    for(ABit=AB.begin();ABit!=AB.end();ABit++)
    {
        ABit->resize(2);
        nothing = scanf("%d %d",&(*ABit)[0],&(*ABit)[1]);
        toplimit=max((*ABit)[0],toplimit);
        toplimit=max((*ABit)[1],toplimit);
    }

    sort(AB.begin(),AB.end(),compare);
    printf("solved: %d\n",solveMe(AB,toplimit));


    exit(0);
}
