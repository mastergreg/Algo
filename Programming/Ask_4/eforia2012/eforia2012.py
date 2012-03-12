#!/bin/env python
#/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
#
#* File Name : eforia2012.py
#
#* Purpose :
#
#* Creation Date : 12-03-2012
#
#* Last Modified : Mon 12 Mar 2012 04:50:36 PM EET
#
#* Created By : Greg Liras <gregliras@gmail.com>
#
#_._._._._._._._._._._._._._._._._._._._._.*/

import sys
from itertools import *

graph={}

def main():
    f = sys.stdin
    (nodes,edges) = tuple(map(int,f.readline().split()))
    for i in xrange(1,nodes+1):
        graph[i]=0
    for i in imap(lambda x: map(int,x.split()),f.readlines()):
        graph[i[0]] +=1
        graph[i[1]] +=1
    for i in xrange(1,nodes+1):
        print i,graph[i]


if __name__=="__main__":
    main()

