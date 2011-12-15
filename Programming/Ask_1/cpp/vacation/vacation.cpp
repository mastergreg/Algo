/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : vacation.cpp

* Purpose :

* Creation Date : 28-11-2011

* Last Modified : Thu 15 Dec 2011 04:25:11 PM EET

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

long long int solve(vector<long long int> lefts,vector<long long int> rights,vector<long long int> sums);
long long int getlefts(vector<long long int>::iterator it,vector<long long int>::iterator sumsstart,long long int len);
long long int getrights(vector<long long int>::iterator it,vector<long long int>::reverse_iterator sumsstart,long long int len);

int main()
{
    unsigned long long int days=0;
    unsigned long long int i=0;
    long long int min_temp=0;
    long long int max_days=0;
    long long int cr=0;
    long long int cl=0;
    vector<long long int> temperatures;
    vector<long long int> lefts;
    vector<long long int> rights;


    cin >> days >> min_temp;
    temperatures.resize(days);
    lefts.resize(days);
    rights.resize(days);

    cin >> temperatures[0];
    temperatures[0]-=min_temp;
    for (i=1;i<days;i++)
    {
        cin >> temperatures[i];
        temperatures[i]-=min_temp;
        temperatures[i]+=temperatures[i-1];
    }
    cl=getlefts(lefts.begin(),temperatures.begin(),temperatures.size());
    lefts.erase(lefts.begin()+cl,lefts.end());

    cr=getrights(rights.begin(),temperatures.rbegin(),temperatures.size());
    rights.erase(rights.begin()+cl,rights.end());

    max_days = solve(lefts,rights,temperatures);
    cout << max_days << endl;
    return 0;
}

long long int solve(vector<long long int> lefts,vector<long long int> rights,vector<long long int> sums)
{
    long long int i=0;
    unsigned long long int j=0;
    unsigned long long int limiti;
    unsigned long long int limitj;
    long long int buf=0;
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

long long int getlefts(vector<long long int>::iterator it, vector<long long int>::iterator sumsstart,long long int sumslen)
{
    long long int i;
    long long int lim=sumslen;
    long long int curr=*sumsstart;
    *it=0;
    it++;
    sumsstart++;
    long long int c =1;
    for(i=1;i<lim;i++,sumsstart++)
    {
        if(*sumsstart<curr)
        {
            curr=*sumsstart;
            (*it)=i;
            it++;
            c++;
        }
    }
    return c;
}

long long int getrights(vector<long long int>::iterator it, vector<long long int>::reverse_iterator sumsstart,long long int sumslen)
{
    long long int i;
    long long int lim=sumslen-1;
    long long int curr=0;
    long long int c =1;
    *it=lim;
    it++;
    curr=*sumsstart;
    sumsstart++;
    for(i=lim-1;i>=0;i--,sumsstart++)
    {
        if(*sumsstart>curr)
        {
            curr=*sumsstart;
            *it=i;
            it++;
            c++;
        }
    }
    return c;
}
