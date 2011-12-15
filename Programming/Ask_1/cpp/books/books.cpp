/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : books.cpp

 * Purpose :

 * Creation Date : 28-11-2011

 * Last Modified : Thu 15 Dec 2011 04:24:23 PM EET

 * Created By : Greg Liras <gregliras@gmail.com>

 _._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>


using namespace std;

static bool decide(long long int pivot);
static vector<long long int> bookpages;
static unsigned long long int books;
static unsigned long long int writers;

int main()
{
    unsigned long long int i;
    long long int pivot=0;
    long long int top=0;
    long long int maxelem;
    long long int phigh=0;
    long long int plow=0;
    cin >> books >> writers;
    bookpages.resize(books);
    for (i=0;i<books;i++)
        cin >> bookpages.at(i);
    top=accumulate(bookpages.begin(),bookpages.end(),0);
    maxelem=*(max_element(bookpages.begin(),bookpages.end()));
    phigh=top;
    plow=max((long long int)(top/books),maxelem);
    do
    {
        pivot=(phigh+plow)/2;
        if(decide(pivot))
            phigh=pivot;
        else
            plow=pivot;
    }while((phigh-plow)>1);
    if(decide(plow))
        cout << plow << endl;
    else
        cout << phigh << endl;
    return 0;
}

bool decide(long long int pivot)
{
    unsigned long long int i=0;
    unsigned long long int j=0;
    long long int buf=0;
    for (i=0,j=0;i<writers;i++)
    {
        buf=0;
        while(buf<=pivot)
        {
            if(j==books)
                return true;
            buf+=bookpages.at(j);
            j++;
        }
        if(i==writers-1)
            return false;
        else
            if(buf>bookpages.at(j-1))
                buf-=bookpages.at(--j);
    }
    if (j<books-1)
        return false;
    return true;
}
