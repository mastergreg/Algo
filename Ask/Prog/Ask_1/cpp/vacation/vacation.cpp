/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : vacation.cpp

* Purpose :

* Creation Date : 28-11-2011

* Last Modified : Tue 29 Nov 2011 02:27:39 PM EET

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
    vector<double> buf;

    cin >> days >> min_temp;
    temperatures.resize(days);
    for (i=0;i<days;i++)
    {
        cin >> temperatures[i];
    }
    for(i=0;i<days;i++)
    {
        temperatures=next_temps(temperatures,i+1);
        cout << temperatures.size() << endl;
        for(j=0;j<temperatures.size();j++)
        {
            if (temperatures[j]>=min_temp)
            {
                max_days = max(max_days,i+1);
                break;
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
