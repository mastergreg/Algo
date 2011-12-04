/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : vacation.cpp

* Purpose :

* Creation Date : 28-11-2011

* Last Modified : Thu 01 Dec 2011 10:28:52 PM EET

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/
#include "vacation.h"

using namespace std;
int main()
{
    unsigned int days,i;
    unsigned int j,temp_size;
    int min_temp;
    unsigned int max_days=0;
    vector<double> temperatures;
    deque<double> my_que;

    cin >> days >> min_temp;
	min_temp-=273;
    temperatures.resize(days);
    for (i=0;i<temperatures.size();i++)
    {
        cin >> temperatures[i];
    }
    for (i=0;i<temperatures.size();i++)
    {
        temperatures[i]-=273;
    }
    //end of data input
	temp_size = temperatures.size();

    for(i=0;i<days;i++)
    {
        for(j=0;j<temp_size;j+=2)
        {
            temperatures[j/2]=temperatures[j]+temperatures[j+1];
            if (temperatures[j/2]>=(double) min_temp*2*(i+1))
            {
                max_days = 2*(i+1);
            }
        }
		temp_size/=2;
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
