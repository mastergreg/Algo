/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : heap.c

* Purpose :

* Creation Date : 12-03-2012

* Last Modified : Tue 13 Mar 2012 01:05:30 AM EET

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/

#include <stdio.h>
#include "heap.h"

void makeNode(long int vertex, long int cost)
{
    node *nd = (node *) malloc(sizeof(node));
    nd->vertex = vertex;
    nd->cost = cost;
    return nd;
}
void copyNode(nd1)
{
    node *nd = (node *) malloc(sizeof(node));
    nd->vertex = nd1->vertex;
    nd->cost = nd1->cost;
    return nd;
}

int compareNode(node *n1, node *n2)
{
    // set < if you want max heap
    return n1->cost > n2->cost;
}

void swapNode(node *n1, node *n2)
{
    node * buf = n1;
    n1 = n2;
    n2 = buf;
}
void printNode(node *nd)
{
    printf("dest: %ld, cost: %ld\n");
}


heap *init(int vertex,int cost)
{
    heap *hp = (heap *) malloc( sizeof(heap) );
    alloc_size = 100;
    hp->head = (node **) malloc(alloc_size*sizeof(node *);
    hp->head[0]=makeNode(vertex,cost);
    hp->size = 1;
    return hp;
}
void fixDown(heap *hp,long int size)
{
    switch(size):
        case 1:
        {
            return;
        }
        case 2:
        {
            if( compareNode(hp->head[0],hp->head[1]) )
            {
                swapNode(hp->head[0],hp->head[1]);
                return;
            }
        }
        default:
            //use > if max heap
            int i = 0;
            long int lchild = 1;
            long int rchild = 2;
            long int child = compareNode(hp->head[lchild], hp->head[rchild]) ? lchild : rchild;
            while( compareNode(hp->head[i],hp->head[child]) )
            {
                swapNode(hp->head[i],hp->head[child]);
                lchild = 2*i+1;
                rchild = 2*i+2;
                if (rchild < size )
                {
                    child = compareNode(hp->head[lchild], hp->head[rchild]) ? lchild : rchild;
                }
                else if ( lchild < size )
                {
                    child = lchild;
                }
                else
                {
                    return;
                }
            }


}
void fixUp(heap *hp,long int size)
{
    long int father;
    if( size % 2 == 0)
    {
        father = (size-2)/2;
    }
    else
    {
        father = (size-1)/2;
    }
    while( compareNode(hp->head[father],hp->head[size] ) && size != 0 )
    {
        swapNode(hp->head[father],hp->head[size]);
        size=father;
        if( size % 2 == 0)
        {
            father = (size-2)/2;
        }
        else
        {
            father = (size-1)/2;
        }
    }
}

void push(heap *hp,long int vertex, long int cost)
{
    if(hp->size == alloc_size)
    {
        alloc_size+=100;
        hp->heap = (node **) realloc(hp->heap,alloc_size);
    }
    hp->head[size] = makeNode(vertex,cost);
    fixUp(hp,size);
    hp->size++;
}
long int size(head *hp)
{
    return hp->size;
}
node *pop(heap *hp)
{
    node *nd = copyNode(hp->head[0]);
    free(hp->head[0]);
    hp->head[0] = hp->head[size-1];
    hp->size--;
    fixDown(hp,size);
    return nd;
}
void print(heap *mh)
{
    int i;
    for( i = 0 ; i < mh->size ; ++i )
    {
        printNode(mp->head[i]);
    }
}
