/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : books.cpp

 * Purpose :

 * Creation Date : 28-11-2011

 * Last Modified : Tue 06 Dec 2011 09:45:38 PM EET

 * Created By : Greg Liras <gregliras@gmail.com>

 _._._._._._._._._._._._._._._._._._._._._.*/
#include "books.h"
using namespace std;
int main()
{
    unsigned int books=0;
    unsigned int writers=0;
    unsigned int i;
    int pivot=0;
    int ans=0;
    int ret=0;
    int top=0;
    int phigh=0;
    int plow=0;
    vector<int> bookpages;
    cin >> books >> writers;
    bookpages.resize(books);
    for (i=0;i<books;i++)
    {
        cin >> bookpages.at(i);
    }
    top=accumulate(bookpages.begin(),bookpages.end(),0);
    phigh=top;
    do
    {
        pivot=(phigh+plow)/2;
        if(decide(bookpages,writers,pivot))
        {
            //you can get at least pivot
            //books to all writters
            //lets test for more
            plow=pivot-1;
            ret = maxPages(bookpages,writers,pivot);
            if (ans==ret)
            {
                break;
            }
            ans = ans>ret?ans:ret;
        }
        else
        {
            //cannot get at least pivot
            //lets try less
            phigh=pivot+1;
        }
    }while(phigh-plow>2);
    cout << ans << endl;
    return 0;
}
int maxPages(vector<int> bookpg,int writers,int pivot)
{
    int buf,i,j;
    int books = bookpg.size();
    int pages=0;
    //start from j=0 and j++ until all
    //writers have at least pivot books
    for(i=0,j=0;i<writers;i++)
    {
        buf=0;
        do
        {
            if (j==books)       //j exceeded vector size
            {                   //so there can be no solution
                return 0;
            }
            else
            {
                buf+=bookpg[j];
            }
            j++;
        }while(buf<pivot);
        pages=pages>buf?pages:buf;
    }
    while(j<books)
    {
        buf+=bookpg[j++];
    }
    pages=pages>buf?pages:buf;
    return pages;

}
bool decide(vector<int> bookpg,int writers,int pivot)
{
    int buf,i,j;
    int books = bookpg.size();
    //start from j=0 and j++ until all
    //writers have at least pivot books
    for(i=0,j=0;i<writers;i++)
    {
        buf=0;
        do
        {
            if (j==books)       //j exceeded vector size
            {                   //so there can be no solution
                cout << "exceeded array size" << endl;
                return false;
            }
            else
            {
                buf+=bookpg[j];
            }
            j++;
        }while(buf<pivot);
    }
    return true;

}
