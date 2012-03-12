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
    struct node * head;
    long int size;
    long int alloc_size;

};

typedef struct node node;
typedef struct heap heap;

node *makeNode(long int vertex, long int cost);
void printNode(long int vertex, long int cost);
int compareNode(const node *a,const node *b);

void init(heap * mh,long int vertex,long int cost);
void push(heap * mh,long int vertex,long int cost);
long int size(heap * mh);
node *pop(heap * mh);
void print(heap *mh);

#endif

