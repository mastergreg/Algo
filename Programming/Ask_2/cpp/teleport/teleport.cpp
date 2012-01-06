/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : teleport.cpp

 * Purpose :

 * Creation Date : 19-12-2011

 * Last Modified : Fri 06 Jan 2012 02:57:37 AM EET

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
    list< pair<int , int> >::iterator it=alist.begin();
    prevs=it->first;
    preve=it->second;
    it++;
    for(;it!=alist.end();++it)
    {
        if((it->second > it->first && it->second > preve && it->first < prevs)
                || (it->second < it->first && it->second < preve && it->first > prevs))
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
bool collidesA(pair<int,int>& abelem,pair<int,int>& baelem)
{
    /*
     * [ -> ]       = abelem
     *    [ <- ]    = baelem
     */
    return (abelem.second > baelem.second && abelem.second < baelem.first);

}

inline
bool collidesB(pair<int,int>& abelem,pair<int,int>& baelem)
{
    /*
     *    [ -> ]    = abelem
     * [ <- ]       = baelem
     */
    return (abelem.first < baelem.first && abelem.second > baelem.first);
}

inline
bool collidesC(pair<int,int>& abelem,pair<int,int>& baelem)
{
    /*
     *    [ -> ]    = abelem
     * [    <-   ]  = baelem
     */
    return (abelem.first < baelem.second && abelem.second < baelem.first);
}

inline
bool collidesD(pair<int,int>& abelem,pair<int,int>& baelem)
{
    /*
     * [    ->    ] = abelem
     *    [ <- ]    = baelem
     */
    return (abelem.first > baelem.second && abelem.second > baelem.first);
}

inline
bool noCollision(pair<int,int>& abelem,pair<int,int>& baelem)
{
    /*                                    
     * [ -> ]         ||        [ -> ]      = abelem
     *        [ <- ]  || [ <- ]             = baelem
     */
    return (abelem.second <= baelem.second || abelem.first >= baelem.first);
}

int getMaxAB(list<pair<int,int> >& ablist,list<pair<int,int> >& balist)
{
    int ans=0;
    list<pair<int,int> >::reverse_iterator abit=ablist.rbegin();
    list<pair<int,int> >::reverse_iterator bait=balist.rbegin();
    int ba;
    int ab;
    while(noCollision(*abit,*bait) && abit!=ablist.rend() && bait!=balist.rend())
    {
        ans++;
        /*
         * increase the one 
         * which is on the left
         */
        if(abit->second <= bait->second)
        {
            abit++;
        }
        else
        {
            bait++;
        }
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

    for_each(ablist.begin(),ablist.end(),printEm);
    cout << endl;
    for_each(balist.begin(),balist.end(),printEm);
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
        if(buf0<buf1)
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

    sort(AB,AB+(++ABcnt),compare);
    sort(BA,BA+(++BAcnt),compare2);
    printf("solved: %d\n",solveMe(AB,ABcnt,BA,BAcnt));


    return 0;
}
