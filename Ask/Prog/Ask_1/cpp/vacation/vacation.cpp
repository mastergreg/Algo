/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : vacation.cpp

* Purpose :

* Creation Date : 28-11-2011

* Last Modified : Tue 29 Nov 2011 11:06:14 PM EET

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/
#include "vacation.h"

using namespace std;
int main()
{
    unsigned int days,i;
    unsigned int j;
    int min_temp;
    unsigned int max_days=0;
    vector<double> temperatures;
    deque<double> my_que;

    cin >> days >> min_temp;
    temperatures.resize(days);
    my_que.resize(days);
    for (i=0;i<days;i++)
    {
        cin >> temperatures[i];
        my_que[i] = temperatures[i];
    }
    //end of data input

    for(i=0;i<days;i++)
    {
        my_que.push_front(0);
        my_que.pop_back();
        for(j=0;j<days;j++)
        {
            temperatures[j]+=my_que[j];
            if (temperatures[j]>=min_temp*(i+2))
            {
                max_days = i+2;
            }
        }
    }
    cout << max_days << endl;
    return 0;
}

vector<double> next_temps(vector<double> temps,int level)
{
    unsigned int i=0;
    vector<double> ntemp;
    ntemp.resize(temps.size()-1);
    for(i=0;i<ntemp.size();i++)
    {
        ntemp[i]=(temps[i]*level+temps[i+1])/double(level+1);
    }
    return ntemp;
}
