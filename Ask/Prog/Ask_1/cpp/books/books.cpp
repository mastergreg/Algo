/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : books.cpp

 * Purpose :

 * Creation Date : 28-11-2011

 * Last Modified : Fri 02 Dec 2011 12:07:29 PM EET

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
    int maximum=0;
    vector<int> bookpages;
    cin >> books >> writers;
    bookpages.resize(books);
    for (i=0;i<books;i++)
    {
        cin >> bookpages.at(i);
    }
    maximum=*max_element(bookpages.begin(),bookpages.end());
    do
    {
        pivot++;
        ret = decide(bookpages,writers,pivot);
        if(ret>0)
        {
            ans = ret;
        }
        else
        {
            break;
        }
    }while(pivot<maximum);
    cout << ans << endl;


    return 0;
}
int decide(vector<int> bookpg,int writers,int pivot)
{
    int buf,i,j;
    j=0;
    int pages = bookpg.size();
    int max_pages=0;
    for(i=0;i<writers;i++)
    {
        buf=0;
        do
        {
            if (j>=pages)
            {
                return 0;
            }
            else
            {
                buf+=bookpg[j];
                j++;
            }
            max_pages = max(max_pages,buf);
        }while(buf<pivot);
    }
    return max_pages;

}
