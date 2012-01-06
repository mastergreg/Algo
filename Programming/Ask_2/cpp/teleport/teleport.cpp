/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : teleport.cpp

 * Purpose :

 * Creation Date : 19-12-2011

 * Last Modified : Fri 06 Jan 2012 04:53:11 PM EET

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

inline
bool overlaps(pair<int,int>& current,int prevs,int preve)
{
    /*
     *     [ -> ]    ||     [ <- ]
     *   [   ->   ]  ||   [   <-   ]
     *
     *   Checking among same "type" of pairs
     *   (either rights or lefts)
     */
    return (current.second > current.first && current.second > preve && current.first < prevs) \
                || (current.second < current.first && current.second < preve && current.first > prevs);
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
        if(overlaps(*it,prevs,preve))
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
bool collidesA(pair<int,int>& rights_elem,pair<int,int>& lefts_elem)
{
    /*
     * [ -> ]       = rights_elem
     *    [ <- ]    = lefts_elem
     */
    return (rights_elem.second > lefts_elem.second && \
            rights_elem.second < lefts_elem.first);

}

inline
bool collidesB(pair<int,int>& rights_elem,pair<int,int>& lefts_elem)
{
    /*
     *    [ -> ]    = rights_elem
     * [ <- ]       = lefts_elem
     */
    return (rights_elem.first < lefts_elem.first && \
            rights_elem.second > lefts_elem.first);
}

inline
bool collidesC(pair<int,int>& rights_elem,pair<int,int>& lefts_elem)
{
    /*
     *    [ -> ]    = rights_elem
     * [    <-   ]  = lefts_elem
     */
    return (rights_elem.first > lefts_elem.second && \
            rights_elem.second < lefts_elem.first);
}

inline
bool collidesD(pair<int,int>& rights_elem,pair<int,int>& lefts_elem)
{
    /*
     * [    ->    ] = rights_elem
     *    [ <- ]    = lefts_elem
     */
    return (rights_elem.first > lefts_elem.second && \
            rights_elem.second > lefts_elem.first);
}

inline
bool noCollision(pair<int,int>& rights_elem,pair<int,int>& lefts_elem)
{
    /*                                    
     * [ -> ]         ||        [ -> ]      = rights_elem
     *        [ <- ]  || [ <- ]             = lefts_elem
     */
    return (rights_elem.second <= lefts_elem.second || \
            rights_elem.first >= lefts_elem.first);
}

int getMaxAB(list<pair<int,int> >& rights_list,list<pair<int,int> >& lefts_list)
{
    int ans=0;
    list<pair<int,int> >::reverse_iterator rights_iter=rights_list.rbegin();
    list<pair<int,int> >::reverse_iterator lefts_iter=lefts_list.rbegin();
    list<pair<int,int> >::reverse_iterator k,m;
    int cr;
    int cl;
    while(rights_iter++ != rights_list.rend() && lefts_iter++ != lefts_list.rend())
    {
        /*
         * first sanity check then collisions
         * '&&' will shortcircuit if any iterator is out of bounds
         */
        while(rights_iter!=rights_list.rend() && lefts_iter!=lefts_list.rend() && \
                noCollision(*rights_iter,*lefts_iter))
        {
            ans++;
            /*
             * increase the one 
             * which is on the left
             */
            if(rights_iter->second <= lefts_iter->second)
            {
                rights_iter++;
                cout << "increase right" << endl;
            }
            else
            {
                lefts_iter++;
                cout << "increase left" << endl;
            }
        }
        cl=0; 
        /*
         * How many times lefts_iter collides
         */
        cr=0;
        /*
         * How many times rights_iter collides
         */
        k=lefts_iter;
        k++;
        m=rights_iter;
        m++;

        /*
         * Check for type A collisions
         */

        if(collidesA(*rights_iter,*lefts_iter))
        {
            while(k != lefts_list.rend() && collidesA(*rights_iter,*k))
            {
                k++;
                cr++;
            }
            while(m != rights_list.rend() && collidesA(*m,*lefts_iter))
            {
                m++;
                cl++;
            }
            ans++;
            /*
             * Pick the one with the least collisions
             */
            if(cl>cr)
            {
                rights_iter++;
                lefts_iter=k;
            }
            else
            {
                lefts_iter++;
                rights_iter=m;
            }
        }

        /*
         * Check for type B collisions
         */

        else if(collidesB(*rights_iter,*lefts_iter))
        {
            /*
             * adding some sanity checking
             */
            while(k != lefts_list.rend() && collidesB(*rights_iter,*k))
            {
                k++;
                cr++;
            }
            while(m != rights_list.rend() && collidesB(*m,*lefts_iter))
            {
                m++;
                cl++;
            }
            ans++;
            if(cl>cr)
            {
                rights_iter++;
                lefts_iter=k;
            }
            else
            {
                lefts_iter++;
                rights_iter=m;
            }
        }
        /*
         * Check for type C collisions
         */
        else if(collidesC(*rights_iter,*lefts_iter))
        {
            while(k != lefts_list.rend() && collidesC(*rights_iter,*k))
            {
                k++;
                cr++;
            }
            while(m != rights_list.rend() && collidesC(*m,*lefts_iter))
            {
                m++;
                cl++;
            }
            ans++;
            /*
             * Pick the one with the least collisions
             */
            if(cl>cr)
            {
                rights_iter++;
                lefts_iter=k;
            }
            }
            else
            {
                lefts_iter++;
                rights_iter=m;
            }
        }
    }

    return ans;
}

int mergeEm(list<pair<int,int> >& rights_list,list<pair<int,int> >& lefts_list)
{
    int ans;
    ans=max(rights_list.size(),lefts_list.size());
    ans=getMaxAB(rights_list,lefts_list);
    return ans;
}

void printEm(pair<int,int> & p)
{
    cout << p.first << "\t" << p.second << endl;
}
int solveMe(int **rights,int rightscnt,int ** lefts,int leftscnt)
{
    /*
     * Main solving function
     */
    list< pair <int , int> > rights_list; 
    list< pair <int , int> > lefts_list; 
    for(int i=0;i<rightscnt;i++)
        rights_list.push_back(pair<int,int>(rights[i][0],rights[i][1]));
    for(int i=0;i<leftscnt;i++)
        lefts_list.push_back(pair<int,int>(lefts[i][0],lefts[i][1]));
    clean_overlapping(rights_list);
    clean_overlapping(lefts_list);
    //copy(rights,rights+rightscnt,rights_list);

    for_each(rights_list.begin(),rights_list.end(),printEm);
    cout << endl;
    for_each(lefts_list.begin(),lefts_list.end(),printEm);
    return mergeEm(rights_list,lefts_list);
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
