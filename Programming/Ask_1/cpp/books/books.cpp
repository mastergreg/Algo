/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : books.cpp

 * Purpose :

 * Creation Date : 28-11-2011

 * Last Modified : Mon 12 Dec 2011 09:43:51 AM EET

 * Created By : Greg Liras <gregliras@gmail.com>

 _._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>


using namespace std;

static bool decide(int pivot);
static vector<int> bookpages;
static unsigned int books;
static unsigned int writers;

int main()
{
    unsigned int i;
    int pivot=0;
    int top=0;
    int maxelem;
    int phigh=0;
    int plow=0;
    cin >> books >> writers;
    bookpages.resize(books);
    for (i=0;i<books;i++)
        cin >> bookpages.at(i);
    top=accumulate(bookpages.begin(),bookpages.end(),0);
    maxelem=*(max_element(bookpages.begin(),bookpages.end()));
    phigh=top;
    plow=max((int)(top/books),maxelem);
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

bool decide(int pivot)
{
    unsigned int i=0;
    unsigned int j=0;
    int buf=0;
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
