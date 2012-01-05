/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : teleport.cpp

 * Purpose :

 * Creation Date : 19-12-2011

 * Last Modified : Thu 05 Jan 2012 03:54:20 AM EET

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
bool compare(const int *v1,const int *v2)
{
    return !(v1[0] < v2[0] && v1[1] < v2[1]  || (v1[0]==v2[0] && v1[1] < v2[1]));
}
bool compare2(const int *v1,const int *v2)
{
    return !(v1[1] < v2[1] || (v1[1]==v2[1] && v1[0] < v2[0]));
}
void clean_overlapping(list< pair < int , int > >& alist)
{
    int prevs=0;
    int preve=0;
    for(list< pair<int , int> >::iterator it=alist.begin();it!=alist.end();++it)
    {
        if(it->second<preve)
        {
            alist.remove(*it);
            continue;
        }
        preve=it->second;
    }


}
int solveMe(int **ab,int abcnt,int ** ba,int bacnt)
{

    list< pair <int , int> > ablist; 
    list< pair <int , int> > balist; 
    for(int i=0;i<abcnt;i++)
        ablist.push_back(pair<int,int>(ab[i][0],ab[i][1]));
    for(int i=0;i<bacnt;i++)
        balist.push_back(pair<int,int>(ba[i][0],ba[i][1]));
    clean_overlapping(ablist);
    clean_overlapping(balist);

    //copy(ab,ab+abcnt,ablist);
    return 0;
}
int main()
{
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


    for(int i=0;i<scientists;i++)
    {
        nothing = scanf("%d %d",&buf0,&buf1);
        if(buf0>buf1)
        {
            AB[++ABcnt]=new int[2];
            AB[ABcnt][0]=buf0;
            AB[ABcnt][1]=buf1;
        }
        else
        {
            BA[++BAcnt]=new int[2];
            BA[BAcnt][0]=buf0;
            BA[BAcnt][1]=buf1;
        }
        toplimit=max(buf0,toplimit);
        toplimit=max(buf1,toplimit);
    }

    sort(AB,AB+ABcnt,compare);
    for (int i=0;i<ABcnt;i++)
    {
        printf("%d\t>\t%d\n",AB[i][0],AB[i][1]);
    }
    sort(BA,BA+BAcnt,compare2);
    for (int i=0;i<BAcnt;i++)
    {
        printf("%d\t<\t%d\n",BA[i][0],BA[i][1]);
    }
    printf("solved: %d\n",solveMe(AB,ABcnt,BA,BAcnt));


    return 0;
}
