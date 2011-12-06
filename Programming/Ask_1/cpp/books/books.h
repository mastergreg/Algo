/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : books.h

* Purpose :

* Creation Date : 28-11-2011

* Last Modified : Tue 06 Dec 2011 09:39:24 PM EET

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/
#ifndef BOOKS_H
#define BOOKS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
bool decide(std::vector<int> bookpages,int writers,int pivot);
int maxPages(std::vector<int> bookpages,int writers,int pivot);
#endif
