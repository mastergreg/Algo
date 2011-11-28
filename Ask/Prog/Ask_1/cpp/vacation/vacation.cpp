/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : vacation.cpp

* Purpose :

* Creation Date : 28-11-2011

* Last Modified : Mon 28 Nov 2011 07:45:43 PM EET

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/
#include "vacation.h"

using namespace std;
int main()
{
    unsigned int days,i;
    int min_temp;
    int max_days=0;
    int current_days=0;
    cin >> days >> min_temp;
    vector<int> temperatures;
    temperatures.resize(days);
    for (i=0;i<days;i++)
    {
        cin >> temperatures[i];
    }
    for (i=0;i<days;i++)
    {
        if(temperatures[i]>=min_temp)
        {
            current_days++;
        }
        else
        {
            max_days = max(current_days,max_days);
            current_days = 0;
        }
    }
    cout << max_days << endl;
    return 0;
}
