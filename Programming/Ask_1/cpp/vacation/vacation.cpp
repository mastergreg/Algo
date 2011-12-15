/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : vacation.cpp

* Purpose :

* Creation Date : 28-11-2011

* Last Modified : Thu 15 Dec 2011 02:24:18 PM EET

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

int solve(vector<int> lefts,vector<int> rights,vector<int> sums);
int getlefts(vector<int>::iterator it,vector<int> sums);
int getrights(vector<int>::iterator it,vector<int> sums);

int main()
{
    unsigned int days=0;
    unsigned int i=0;
    int min_temp=0;
    int max_days=0;
    int cr=0;
    int cl=0;
    vector<int> temperatures;
    vector<int> prefix_sums;
    vector<int> lefts;
    vector<int> rights;


    cin >> days >> min_temp;
    temperatures.resize(days);
    prefix_sums.resize(days);
    lefts.resize(days);
    rights.resize(days);

    cin >> temperatures[0];
    temperatures[0]-=min_temp;
    prefix_sums[0]=temperatures[0];
    for (i=1;i<days;i++)
    {
        cin >> temperatures[i];
        temperatures[i]-=min_temp;
        prefix_sums[i]=prefix_sums[i-1]+temperatures[i];
    }
    //partial_sum(temperatures.begin(),temperatures.end(),prefix_sums.begin());
    cl=getlefts(lefts.begin(),prefix_sums);
    lefts.erase(lefts.begin()+cl,lefts.end());
    //lefts.resize(cr);

    cr=getrights(rights.begin(),prefix_sums);
    rights.erase(rights.begin()+cl,rights.end());
    //rights.resize(cr);
    max_days = solve(lefts,rights,prefix_sums);
    max_days = min(max_days,(int)days);
    cout << max_days << endl;
    return 0;
}
int solve(vector<int> lefts,vector<int> rights,vector<int> sums)
{
    int i=0;
    unsigned int j=0;
    unsigned int limiti=0;
    unsigned int limitj=0;
    int buf=0;
    limiti = lefts.size();
    limitj = rights.size();
    for(i=limiti-1,j=0;j<limitj;j++)
    {
        if(sums[rights[j]]>=0)
        {
            buf=max(buf,rights[j]+1);
        }
        for(;i>=0;i--)
        {
            if((sums[rights[j]]-sums[lefts[i]])>=0)
                buf=max(buf,rights[j]-lefts[i]);
            else
                break;
        }
    }
    return buf;
}
int getlefts(vector<int>::iterator it, vector<int> sums)
{
    int i;
    int lim=sums.size();
    int curr=sums[0];
    *it=0;
    it++;
    int c =1;
    for(i=1;i<lim;i++)
    {
        if(sums[i]<curr)
        {
            curr=sums[i];
            (*it)=i;
            it++;
            c++;
        }
    }
    return c;
}
int getrights(vector<int>::iterator it, vector<int> sums)
{
    int i;
    int lim=sums.size()-1;
    int curr=0;
    int c =1;
    *it=lim;
    it++;
    curr=sums[lim];
    for(i=lim-1;i>=0;i--)
    {
        if(sums[i]>curr)
        {
            curr=sums[i];
            *it=i;
            it++;
            c++;
        }
    }
    return c;
}
