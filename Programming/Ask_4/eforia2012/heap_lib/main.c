/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : main.c

* Purpose :

* Creation Date : 13-03-2012

* Last Modified : Tue 13 Mar 2012 01:47:28 AM EET

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/

#include <stdlib.h>
#include <stdio.h>
#include "heap.h"


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

    return 0;
}

