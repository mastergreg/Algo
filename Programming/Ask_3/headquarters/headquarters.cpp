/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : headquarters.cpp

* Purpose :

* Creation Date : 29-01-2012

* Last Modified : Thu 02 Feb 2012 11:09:12 AM EET

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/

#define MODLIMIT 100000007

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;



void multiply(unsigned long long int **mat0,unsigned long long int **mat2,unsigned long long int **mat3,int N)
{
    unsigned long long int buf;
    for ( int i=0 ; i < N ; ++i )
    {
        for ( int j = 0 ; j < N ; ++j )
        {
            buf = 0;
            for( int k = 0 ; k < N ; k ++)
                buf += mat0[i][k]*mat2[k][j];
            mat3[i][j] = buf % MODLIMIT;
        }
    }
}

void solvem(unsigned long long int **initial_matrix, int N, int k,int s,int t)
{
    //ans is initialized to 0
    //using two more matrices for mul
    //and ans as the accumulator
    unsigned long long int **sup1,**sup2,**ans;
    sup1 = new unsigned long long int*[N];
    sup2 = new unsigned long long int*[N];
    ans = new unsigned long long int*[N];
    unsigned int bit;
    for ( int i = 0 ; i < N ; i ++ )
    {
        sup1[i] = new unsigned long long int[N];
        ans[i] = new unsigned long long int[N];
        copy(initial_matrix[i],initial_matrix[i]+N,sup1[i]);
        sup2[i] = new unsigned long long int[N];
    }
    k--;
    //we need to move k-1 times ( right? )
    for ( int i = 0 , j = 0 ; i < 32 ; ++i)
    {
        bit = ( k & ( 1 << i ) ) >> i;
        //using binary representation of k
        //to calculate the powers of 2 that
        //k consists of
        if( bit )
        {
            //calculating A^(2^i)
            for( ; j < i ; ++j )
            {
                //A*=A, i times
                multiply(sup1,sup1,sup2,N);
                swap(sup1,sup2);
            }
            if ( j == 0 )
                for ( int l = 0 ; l < N ; ++l )
                    for ( int m = 0 ; m < N ; ++m )
                        ans[l][m] = sup1[l][m];
            else
            {
                multiply(ans,sup1,sup2,N);
                swap(sup2,ans);
            }
        }
    }
    printf("%llu\n",ans[s-1][t-1]);
    delete [] sup1;
    delete [] sup2;
}



int main()
{
    int k,N,M,s,t,a,b;
    unsigned long long int **mat;
    int log2k;
    int nothing;

    nothing = scanf("%d %d %d %d %d",&k,&N,&M,&s,&t);

    log2k= (int) log2(k);
    mat = new unsigned long long int*[N];
    //adjacency matrix [from][to]
    for( int i = 0 ; i < N ; i ++)
    {
        mat[i] = new unsigned long long int[N];
        fill(mat[i],mat[i]+N,0);
    }
    for ( int i = 0 ; i < M ; ++i )
    {
        nothing = scanf("%d %d",&a,&b);
        a--;
        b--;
        mat[a][b] = 1;
    }
    solvem(mat,N,k,s,t);
    return 0;
}
