/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : books.cpp

 * Purpose :

 * Creation Date : 28-11-2011

 * Last Modified : Fri 09 Dec 2011 12:23:08 PM EET

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
        ret = maxPages(bookpages,writers,pivot);
        if(ret >0 )
        {
            ans=ret;
            plow=pivot;
        }
        else
        {
            phigh=pivot;
        }
    }while((phigh-plow)>1);
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
        cout << "Writer " << i << endl;
        while(buf<pivot)
        {
            if (j==books && (i<(writers-1)))       //j exceeded vector size
            {
                cout << "my line " << "writers " << writers << " i "<<i<< " j " <<j << " buf "<< buf << " pivot " << pivot << endl;
                cout << "\tFAIL" << endl; //faulty here
                return 0;
            }
            buf+=bookpg[j];
            cout << "\t" <<pivot << " " << j << " buf " << buf<<endl;
            j++;
        }
        if(j>0)
        {
            buf-=bookpg[j-1];
            if(buf==0)
            {
                buf=bookpg[j-1];
            }
        }
        pages=pages>buf?pages:buf;
    }
    for(;j<books;buf+=bookpg[j++]){}
    cout << j << " " << books << endl;
    pages=pages>buf?pages:buf;
    return pages;
}
