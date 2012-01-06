/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : teleport.cpp

 * Purpose :

 * Creation Date : 19-12-2011

 * Last Modified : Sat 07 Jan 2012 12:51:56 AM EET

 * Created By : Greg Liras <gregliras@gmail.com>

 _._._._._._._._._._._._._._._._._._._._._.*/

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <list>
#include <algorithm>
#include <utility>
#include <set>
#include <iostream>
#include <ostream>
#include <iterator>

using namespace std;

int solveMe(int **pairs,int scientists)
{
    int *maki = new int[scientists];
    int *makend;
    
    for(int i=0;i<scientists;i++)
        maki[i]=pairs[i][1];

    sort(maki,maki+scientists);
    makend = unique(maki,maki+scientists);

    cout << "maki" << endl;
    copy(maki,makend,ostream_iterator<int>(cout,"\n"));
    cout << "maki" << endl;
    return 0;

}

int main()
{
    /*
     * Variables
     */
    int scientists=0;
    int nothing;
    int toplimit=0;
    int **AB;
    int ABcnt=-1;
    int **BA;
    int BAcnt=-1;
    int buf0,buf1;

    nothing = scanf("%d",&scientists);
    AB=new int*[scientists];
    BA=new int*[scientists];

    /*
     * Get input
     */
    for(int i=0;i<scientists;i++)
    {
        AB[i]=new int[2];
        nothing = scanf("%d %d",AB[i],AB[i]+1);
    }
    printf("%d\n",solveMe(AB,scientists));


    return 0;
}
