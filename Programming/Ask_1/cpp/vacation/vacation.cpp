/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : vacation.cpp

* Purpose :

* Creation Date : 28-11-2011

* Last Modified : Thu 15 Dec 2011 05:24:18 PM EET

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/
#include <vector>
#include <cstdio>
#include <deque>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

int solve(vector<int> lefts,vector<int> rights,vector<int> sums);
int getlefts(vector<int>::iterator it,vector<int>::iterator sumsstart,int len);
int getrights(vector<int>::iterator it,vector<int>::reverse_iterator sumsstart,int len);

int main()
{
    unsigned int days=0;
    unsigned int i=0;
    int min_temp=0;
    int max_days=0;
    int cr=0;
    int cl=0;
    vector<int> temperatures;
    vector<int> lefts;
    vector<int> rights;


    //cin >> days >> min_temp;
    scanf("%d %d",&days,&min_temp);
    temperatures.resize(days);
    lefts.resize(days);
    rights.resize(days);

    scanf("%d",&temperatures[0]);
    //cin >> temperatures[0];
    temperatures[0]-=min_temp;
    for (i=1;i<days;i++)
    {
        //cin >> temperatures[i];
        scanf("%d",&temperatures[i]);
        temperatures[i]-=min_temp;
        temperatures[i]+=temperatures[i-1];
    }
    cl=getlefts(lefts.begin(),temperatures.begin(),temperatures.size());
    lefts.erase(lefts.begin()+cl,lefts.end());

    cr=getrights(rights.begin(),temperatures.rbegin(),temperatures.size());
    rights.erase(rights.begin()+cl,rights.end());

    max_days = solve(lefts,rights,temperatures);
    //cout << max_days << endl;
    printf("%d\n",max_days);
    return 0;
}

int solve(vector<int> lefts,vector<int> rights,vector<int> sums)
{
    int i=0;
    unsigned int j=0;
    unsigned int limiti;
    unsigned int limitj;
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

int getlefts(vector<int>::iterator it, vector<int>::iterator sumsstart,int sumslen)
{
    int i;
    int lim=sumslen;
    int curr=*sumsstart;
    *it=0;
    it++;
    sumsstart++;
    int c =1;
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

int getrights(vector<int>::iterator it, vector<int>::reverse_iterator sumsstart,int sumslen)
{
    int i;
    int lim=sumslen-1;
    int curr=0;
    int c =1;
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
