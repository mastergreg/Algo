/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : vacation.cpp

* Purpose :

* Creation Date : 28-11-2011

* Last Modified : Wed 07 Dec 2011 10:37:00 PM EET

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/
#include "vacation.h"

using namespace std;
touple::touple(int s,int i)
{
    sum=s;
    index=i;
}
int main()
{
    unsigned int days=0;
    unsigned int i=0;
    unsigned int j=0;
    unsigned int limiti=0;
    unsigned int limitj=0;
    int buf;
    int min_temp=0;
    int max_days=0;
    vector<int> temperatures;
    vector<int> prefix_sums;
    vector<touple *> lefts;
    vector<touple *> rights;


    cin >> days >> min_temp;
    temperatures.resize(days);
    for (i=0;i<days;i++)
    {
        cin >> temperatures[i];
        temperatures[i]-=min_temp;
    }
    prefix_sums = getSums(temperatures);
    lefts=getlefts(prefix_sums);
    rights=getrights(prefix_sums);
    limiti = lefts.size();
    limitj = rights.size();
    for(i=0,j=0;j<limitj;j++)
    {
        for(;i<limiti;i++)
        {
            if(((rights[j]->sum)-(lefts[i]->sum))>0)
            {
                buf=(rights[j]->index)-(lefts[i]->index)+1;
                max_days=max(max_days,buf);
            }
            else
            {
                break;
            }
        }
    }


    cout << max_days << endl;
    return 0;
}
vector<int> getSums(vector<int> temps)
{
    vector<int> sums;
    int i;
    int lim=temps.size();
    sums.resize(lim);
    sums[0]=temps[0];
    for(i=1;i<lim;i++)
    {
        sums[i]=sums[i-1]+temps[i];
    }
    return sums;
}
vector<touple *> getlefts(vector<int> sums)
{
    vector<touple *> lefts;
    lefts.push_back(new touple(0,0));
    int i;
    int lim=sums.size();
    int curr;
    for(i=0;i<lim;i++)
    {
        if(sums[i]>curr)
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
    rights.push_back(new touple(sums[lim],lim));
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
