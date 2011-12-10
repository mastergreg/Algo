/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : books.cpp

 * Purpose :

 * Creation Date : 28-11-2011

 * Last Modified : Sat 10 Dec 2011 05:17:12 PM EET

 * Created By : Greg Liras <gregliras@gmail.com>

 _._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>


using namespace std;

bool decide(vector<int> bookpages,unsigned int writers,int pivot);

int main()
{
    unsigned int books=0;
    unsigned int writers=0;
    unsigned int i;
    int pivot=0;
    int top=0;
    int maxelem;
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
    maxelem=*(max_element(bookpages.begin(),bookpages.end()));
    phigh=top;
    plow=max((int)(top/books),maxelem);
    do
    {
        pivot=(phigh+plow)/2;
        if(decide(bookpages,writers,pivot))
        {
            phigh=pivot;
        }
        else
        {
            plow=pivot;
        }
    }while((phigh-plow)>1);
    if(decide(bookpages,writers,plow))
    {
        cout << plow << endl;
    }
    else
    {
        cout << phigh << endl;
    }
    return 0;
}

bool decide(vector<int> books,unsigned int writers, int pivot)
{
    unsigned int i=0;
    unsigned int j=0;
    int buf=0;
    for (i=0,j=0;i<writers;i++)
    {
        buf=0;
        while(buf<=pivot)
        {
            if(j==books.size())
            {
                return true;
            }
            buf+=books[j];
            j++;
        }
        if(i==writers-1)
        {
            return false;
        }
        else
        {
            if(buf>books[j-1])
            {
                buf-=books[j-1];
                j--;
            }
        }
    }
    if (j<books.size()-1)
    {
        return false;
    }
    cout << writers << " " << j << " ";
    return true;
}
