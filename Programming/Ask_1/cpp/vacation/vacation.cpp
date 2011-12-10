/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : vacation.cpp

* Purpose :

* Creation Date : 28-11-2011

* Last Modified : Sun 11 Dec 2011 01:44:37 AM EET

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

class touple
{
    public:
        int sum;
        int index;
        touple(int s,int i);
};
int solve(vector<touple *> lefts,vector<touple *> rights);
vector<touple *> getlefts(vector<int> sums);
vector<touple *> getrights(vector<int> sums);

touple::touple(int s,int i)
{
    sum=s;
    index=i;
}
int main()
{
    unsigned int days=0;
    unsigned int i=0;
    int min_temp=0;
    int max_days=0;
    vector<int> temperatures;
    vector<int> prefix_sums;
    vector<touple *> lefts;
    vector<touple *> rights;


    cin >> days >> min_temp;
    temperatures.resize(days);
    prefix_sums.resize(days);
    for (i=0;i<days;i++)
    {
        cin >> temperatures[i];
        temperatures[i]-=min_temp;
    }
    partial_sum(temperatures.begin(),temperatures.end(),prefix_sums.begin());
    lefts=getlefts(prefix_sums);
    rights=getrights(prefix_sums);
    max_days = solve(lefts,rights);
    max_days = min(max_days,(int)days);
    cout << max_days << endl;
    return 0;
}
int solve(vector<touple *> lefts,vector<touple *> rights)
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
        for(;i>=0;i--)
        {
            if(((rights[j]->sum)-(lefts[i]->sum))>0)
                buf=max(buf,(rights[j]->index)-(lefts[i]->index));
            else
                break;
        }
    }
    return buf;
}
vector<touple *> getlefts(vector<int> sums)
{
    vector<touple *> lefts;
    int i;
    int lim=sums.size();
    int curr=sums[0];
    lefts.push_back(new touple(0,-1));
    for(i=0;i<lim;i++)
    {
        if(sums[i]<curr)
        {
            curr=sums[i];
            lefts.push_back(new touple(sums[i],i));
        }
    }
    return lefts;
}
vector<touple *> getrights(vector<int> sums)
{
    vector<touple *> rights;
    int i;
    int lim=sums.size()-1;
    int curr=0;
    rights.push_back(new touple(sums[lim],lim+1));
    curr=sums[lim];
    for(i=lim-1;i>=0;i--)
    {
        if(sums[i]>curr)
        {
            curr=sums[i];
            rights.push_back(new touple(sums[i],i));
        }
    }
    return rights;
}
