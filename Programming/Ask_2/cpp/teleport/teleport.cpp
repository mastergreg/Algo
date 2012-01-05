/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : teleport.cpp

 * Purpose :

 * Creation Date : 19-12-2011

 * Last Modified : Thu 05 Jan 2012 09:39:52 PM EET

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
    return !( (v1[0] < v2[0] )  || (v1[0]==v2[0] && v1[1] < v2[1]));
}

bool compare2(const int *v1,const int *v2)
{
    return !( (v1[1] < v2[1] ) || (v1[1]==v2[1] && v1[0] < v2[0]));
}

void clean_overlapping(list< pair < int , int > >& alist)
{
    /*
     * compare each element
     * with the ending of the previous one
     * and remove those that overlap
     */
    int prevs=0;
    int preve=0;
    for(list< pair<int , int> >::iterator it=alist.begin();it!=alist.end();++it)
    {
        if(it->second > preve && it->first < prevs)
        {
            /*
             * This is not safe
             * need to implement it better
             * but it's fine for now.
             */
            alist.erase(it);
            it--;
            continue;
        }
        preve=it->second;
        prevs=it->first;
    }
}

inline
bool collides(pair<int,int>& abelem,pair<int,int>& baelem)
{
    /*
     * [ -> ]       ||       [ -> ]
     *    [ <- ]    ||    [ <- ]
     */
    return abelem.first < baelem.second || abelem.second > baelem.first;
}

int getMaxAB(list<pair<int,int> >& ablist,list<pair<int,int> >& balist)
{
    int ans=0;
    list<pair<int,int> >::reverse_iterator bait;
    list<pair<int,int> >::iterator abit;
    int ba;
    int ab;
    for(ba=balist.size(),ab=0,bait=balist.rbegin(),abit=ablist.begin();
            bait!=balist.rend();bait++,ba--)
    {
        for(;abit!=ablist.end();abit++,ab++)
        {
            if(collides(*abit,*bait))
            {
                break;
            }

        }
        ans = max(ans,ab+ba);
    }
    return ans;
}

int mergeEm(list<pair<int,int> >& ablist,list<pair<int,int> >& balist)
{
    int ans;
    ans=max(ablist.size(),balist.size());
    ans=max(ans,getMaxAB(ablist,balist));
    return ans;
}

void printEm(pair<int,int> & p)
{
    cout << p.first << "\t" << p.second << endl;
}
int solveMe(int **ab,int abcnt,int ** ba,int bacnt)
{
    /*
     * Main solving function
     */
    list< pair <int , int> > ablist; 
    list< pair <int , int> > balist; 
    for(int i=0;i<abcnt;i++)
        ablist.push_back(pair<int,int>(ab[i][0],ab[i][1]));
    for(int i=0;i<bacnt;i++)
        balist.push_back(pair<int,int>(ba[i][0],ba[i][1]));
    clean_overlapping(ablist);
    clean_overlapping(balist);
    //copy(ab,ab+abcnt,ablist);

    //for_each(ablist.begin(),ablist.end(),printEm);
    //cout << endl;
    //for_each(balist.begin(),balist.end(),printEm);
    return mergeEm(ablist,balist);
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

    sort(AB,AB+(++ABcnt),compare2);
    sort(BA,BA+(++BAcnt),compare);
    printf("solved: %d\n",solveMe(AB,ABcnt,BA,BAcnt));


    return 0;
}
