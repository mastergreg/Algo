/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : vacation.h

* Purpose :

* Creation Date : 28-11-2011

* Last Modified : Thu 08 Dec 2011 09:51:21 AM EET

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/
#ifndef VACATION_H
#define VACATION_H

#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>


class touple
{
    public:
        int sum;
        int index;
        touple(int s,int i);
};
int solve(std::vector<touple *> lefts,std::vector<touple *> rights);
std::vector<int> getSums(std::vector<int> temps);
std::vector<touple *> getlefts(std::vector<int> sums);
std::vector<touple *> getrights(std::vector<int> sums);
#endif
