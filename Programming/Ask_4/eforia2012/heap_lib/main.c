/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : main.c

* Purpose :

* Creation Date : 13-03-2012

* Last Modified : Tue 13 Mar 2012 01:33:55 AM EET

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/

#include <stdlib.h>
#include <stdio.h>

/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : heap.h

* Purpose :

* Creation Date : 12-03-2012

* Last Modified : Tue 13 Mar 2012 01:07:56 AM EET

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/

#ifndef HEAP_H
#define HEAP_H

struct node {
    long int vertex;
    long int cost;
};

struct heap {
    struct node ** head;
    long int size;
    long int alloc_size;

};

typedef struct node node;
typedef struct heap heap;

node *makeNode(long int vertex, long int cost);
void printNode(long int vertex, long int cost);
int compareNode(const node *a,const node *b);

heap *init(long int vertex,long int cost);
void push(heap * mh,long int vertex,long int cost);
long int size(heap * mh);
node *pop(heap * mh);
void print(heap *mh);

#endif





int main(void)
{
    heap *hp;

    hp = init(11,11);

    push(hp,5,5);
    push(hp,4,4);
    push(hp,3,3);
    push(hp,8,8);
    push(hp,1,1);
    push(hp,9,9);

    print(hp);

    printf("++\n");
    pop(hp);
    print(hp);
    printf("++\n");
    pop(hp);
    print(hp);
    printf("++\n");
    pop(hp);
    print(hp);
    printf("++\n");

}

node * makeNode(long int vertex, long int cost)
{
    node *nd = (node *) malloc(sizeof(node));
    nd->vertex = vertex;
    nd->cost = cost;
    return nd;
}
node * copyNode(node *nd1)
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
    long int buf = n1->vertex;
    n1->vertex = n2->vertex;
    n2->vertex = buf;
    buf = n1->cost;
    n1->cost = n2->cost;
    n2->cost = buf;
}
void printNode(node *nd)
{
    printf("dest: %ld, cost: %ld\n",nd->vertex,nd->cost);
}


heap *init(long int vertex,long int cost)
{
    heap *hp = (heap *) malloc( sizeof(heap) );
    hp->alloc_size = 100;
    hp->head = (node **) malloc((hp->alloc_size)*sizeof(node *));
    hp->head[0]=makeNode(vertex,cost);
    hp->size = 1;
    return hp;
}
void fixDown(heap *hp,long int size)
{
    switch(size)
    {
        case 0:
            return;
        case 1:
            return;
        case 2:
        {
            if( compareNode(hp->head[0],hp->head[1]) )
            {
                swapNode(hp->head[0],hp->head[1]);
            }
            return;
        }
        default:
            int i = 0;
            long int lchild = 1;
            long int rchild = 2;
            long int child = compareNode(hp->head[lchild], hp->head[rchild]) ? rchild : lchild;
            while( compareNode(hp->head[i],hp->head[child]) )
            {
                swapNode(hp->head[i],hp->head[child]);
                lchild = 2*i+1;
                rchild = 2*i+2;
                if (rchild < size )
                {
                    child = compareNode(hp->head[lchild], hp->head[rchild]) ? rchild : lchild;
                }
                else if ( lchild < size )
                {
                    child = lchild;
                }
                else
                {
                    return;
                }
                i++;
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
    while( father >= 0 && compareNode(hp->head[father],hp->head[size] ) )
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
    if(hp->size == hp->alloc_size)
    {
        hp->alloc_size+=100;
        hp->head = (node **) realloc(hp->head,hp->alloc_size);
    }
    hp->head[hp->size] = makeNode(vertex,cost);
    fixUp(hp,hp->size);
    hp->size++;
}
long int size(heap *hp)
{
    return hp->size;
}
node *pop(heap *hp)
{
    node *nd = copyNode(hp->head[0]);
    free(hp->head[0]);
    hp->size--;
    hp->head[0] = hp->head[hp->size];
    fixDown(hp,hp->size);
    return nd;
}
void print(heap *mh)
{
    int i;
    for( i = 0 ; i < mh->size ; ++i )
    {
        printNode(mh->head[i]);
    }
}

