/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : books.cpp

 * Purpose :

 * Creation Date : 28-11-2011

 * Last Modified : Tue 06 Dec 2011 12:23:13 AM EET

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
        ret = decide(bookpages,writers,pivot);
        
        if(ret>0)
        {
            ans = ret;
            plow=pivot;
        }
        else
        {
            phigh=pivot;
        }
        cout << plow << " " << pivot << " " << phigh << endl;
    }while(pivot>0 && plow!=(phigh-1));
    cout << ans << endl;
    return 0;
}
int decide(vector<int> bookpg,int writers,int pivot)
{
    int buf,i,j;
    int books = bookpg.size();
    int max_pages=0;
    for(i=0,j=0;i<writers;i++)
    {
        buf=0;
        do
        {
            if (j==books)
            {
                return 0;
            }
            else
            {
                buf+=bookpg[j];
            }
            j++;
        }while(buf<pivot);
        max_pages = max(max_pages,buf);
    }
    while(j<books)
    {
        buf+=bookpg[j];
        j++;
    }
    max_pages = max(max_pages,buf);
    return max_pages;

}
