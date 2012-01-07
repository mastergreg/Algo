/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : teleport.cpp

 * Purpose :

 * Creation Date : 19-12-2011

 * Last Modified : Sat 07 Jan 2012 03:11:59 AM EET

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

bool comp(const int *a,const int *b)
{
    return a[0]<b[0] || (a[0]==b[0] && a[1]<b[1]);
}

int compare(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}


int binary_search(int key,int *array,int array_size)
{
}
int binary_insert(int key,int *stacks,int stacks_size)
{
/*
 * This will return the new stacks_size
 * and edit the appropriate stack to have the key
 */

    for(int i=0;i<stacks_size;i++)
    {
        /*
         * Should be implemented with binary search
         */
        if(key<stacks[i])
        {
            stacks[i]=key;
            return stacks_size;
        }
    }
    stacks[stacks_size]=key;
    return stacks_size+1;

}

int llis(int *array,int array_size)
{
    int *stacks=new int[array_size];
    int stacks_size=0;
    for(int i=0;i<array_size;i++)
    {
        stacks_size = binary_insert(array[i],stacks,stacks_size);
    }

    return stacks_size;
}


int solveMe(int **pairs,int scientists)
{
    int *x = new int[scientists];
    int *maki = new int[scientists];
    int *makend;
    int makisize;
    
    for(int i=0;i<scientists;i++)
        maki[i]=pairs[i][1];

    sort(maki,maki+scientists);
    sort(pairs,pairs+scientists,comp);
    makend = unique(maki,maki+scientists);
    makisize=makend-maki;


    for (int i = 0; i < scientists; i++)
    {
        x[i] = (int*) bsearch(pairs[i]+1, maki, makisize, sizeof(int), compare) \
               - maki;
    }
    return llis(x,scientists);

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
