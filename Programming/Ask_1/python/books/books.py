#!/usr/bin/python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : books.py
#
#* Purpose :
#
#* Creation Date : 12-12-2011
#
#* Last Modified : Mon 12 Dec 2011 02:59:13 PM EET
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/
import sys

bookpages=[]
books=0
writers=0
def decide(pivot):
    global writers,books
    j=0
    for i in range(writers):
        buf=0
        while(buf<=pivot):
            if(j==books):
                return True
            buf+=bookpages[j]
            j+=1
        if(i==writers-1):
            return False
        else:
            if(buf>bookpages[j-1]):
                buf-=bookpages[j-1]
                j-=1
    if (j<books-1):
        return False
    return True


stdinput = sys.stdin

def main():
    global writers,books
    ln = stdinput.readline().split()
    books=int(ln[0])
    writers=int(ln[1])
    for i in range(books):
        bookpages.append(int(stdinput.readline()))
    phigh = sum(bookpages)
    plow=max(phigh/books,max(bookpages))
    while(phigh-plow>1):
        pivot=(phigh+plow)/2
        if decide(pivot):
            phigh=pivot
        else:
            plow=pivot
    print plow,phigh





if __name__=="__main__":
  main()

