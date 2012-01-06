/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : teleport.cpp

 * Purpose :

 * Creation Date : 19-12-2011

 * Last Modified : Sat 07 Jan 2012 12:13:49 AM EET

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

int getMaxAB(list<pair<int,int> >& rights_list,list<pair<int,int> >& lefts_list)
{
    return 0;
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
void mergeTheListsIntoMakis(list< pair<int , int> >& rights_list,
                            list< pair<int , int> >& lefts_list,
                            vector<int>& maki)
{
    list< pair<int,int> >::iterator rit=rights_list.begin();
    list< pair<int,int> >::iterator lit=lefts_list.begin();

    int current_right_end;
    int current_left_end;
    while(rit!=rights_list.end() && lit!=lefts_list.end())
    {
        current_right_end=rit->second;
        current_left_end=lit->second;
        if(current_right_end>current_left_end)
        {
            if(maki.back()!=current_right_end)
            {
                maki.push_back(current_right_end);
            }
            rit++;

        }
        else
        {
            if(maki.back()!=current_left_end)
            {
                maki.push_back(current_left_end);
            }
            lit++;
        }
    }
    /*
     * Will only get in one of the following
     */
    while(rit!=rights_list.end())
    {
        if(maki.back()!=current_right_end)
        {
            maki.push_back(current_right_end);
        }
        rit++;
    }
    while(lit!=lefts_list.end())
    {
        if(maki.back()!=current_left_end)
        {
            maki.push_back(current_left_end);
        }
        lit++;
    }
}

int solveMe(int **rights,int rightscnt,int ** lefts,int leftscnt)
{
    /*
     * Main solving function
     */
    list< pair <int , int> > rights_list; 
    list< pair <int , int> > lefts_list; 
    vector<int> maki;
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

    maki.reserve(rights_list.size()+lefts_list.size());


    mergeTheListsIntoMakis(rights_list,lefts_list,maki);

    

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
