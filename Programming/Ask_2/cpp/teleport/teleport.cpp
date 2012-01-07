/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : teleport.cpp

 * Purpose :

 * Creation Date : 19-12-2011

 * Last Modified : Sat 07 Jan 2012 03:49:50 AM EET

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


int binary_insert(int key,int *array,int array_size)
{
    int low,high,pivot;
    low=0;
    high=array_size-1;
    pivot=(high+low)/2;

    while(high-low>1)
    {
        if(key<array[pivot])
            high=pivot;
        else
            low=pivot;
        pivot=(high+low)/2;
    }
    if(array[low]>key)
        array[low]=key;
    else if (array[high]>key)
        array[high]=key;
    else
        array[array_size++]=key;
    return array_size;
}

int llis(int *array,int array_size)
{
    int *stacks=new int[array_size];
    int stacks_size=1;
    stacks[0]=array[0];
    for(int i=1;i<array_size;i++)
        stacks_size = binary_insert(array[i],stacks,stacks_size);
    
    delete[] stacks;
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
    delete[] maki;

    return llis(x,scientists);
}

int main()
{
    /*
     * Variables
     */
    int scientists=0;
    int nothing;
    int **AB;

    nothing = scanf("%d",&scientists);
    AB=new int*[scientists];

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
