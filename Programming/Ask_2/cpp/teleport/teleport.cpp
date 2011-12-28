/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : teleport.cpp

* Purpose :

* Creation Date : 19-12-2011

* Last Modified : Tue 27 Dec 2011 07:52:26 PM EET

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(vector<int> v1,vector <int> v2)
{
    return v1[0] < v2[0] || (v1[0]==v2[0] && v1[1] < v2[1]);
}
bool compare2(vector<int> v1,vector <int> v2)
{
    return v1[1] < v2[1] || (v1[1]==v2[1] && v1[0] < v2[0]);
}
bool incomp(vector<int> v1, vector<int> v2)
{
    return v2[1]<v1[1] && v2[0] > v1[0];
}
bool compatible(vector<int> v1, vector<int> v2)
{
    return v2[1]>=v1[1] || v2[0] <= v1[0];
}
int main()
{
    int scientists=0;
    int i;
    int nothing;
    vector< vector < int > > AB;
    vector< vector < int > > ABcopy;
    //get how many are there

    nothing = scanf("%d",&scientists);

    AB.reserve(scientists);
    ABcopy.resize(scientists);

    for (i=0;i<scientists;i++)
    {
        AB.push_back(vector <int> (2));
        nothing = scanf("%d %d",&AB[i][0],&AB[i][1]);
    }


    for (i=0;i<scientists;i++)
    {
        printf("%d %d\n",AB[i][0],AB[i][1]);
    }
    copy(AB.begin(),AB.end(),ABcopy.begin());
    sort(AB.begin(),AB.end(),compare);
    sort(ABcopy.begin(),ABcopy.end(),compare2);
    printf("\n");
    for (i=0;i<scientists;i++)
    {
        printf("%d %d \t\t %d %d\n",AB[i][0],AB[i][1],ABcopy[i][0],ABcopy[i][1]);
    }


    

}
