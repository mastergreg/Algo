/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : headquarters.cpp

* Purpose :

* Creation Date : 29-01-2012

* Last Modified : Thu 02 Feb 2012 10:22:29 AM EET

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



void multiply(long long int **mat0,long long int **mat2,long long int **mat3,int N)
{
    long long int buf;
    for ( int i=0 ; i < N ; i++ )
    {
        for ( int j = 0 ; j < N ; j++ )
        {
            buf = 0;
            for( int k = 0 ; k < N ; k ++)
            {
                buf += mat0[i][k]*mat2[k][j];
            }
            mat3[i][j] = buf % MODLIMIT;
        }
    }
}

void solvem(long long int **initial_matrix,long long int **answer, int N, int k,int s,int t)
{
    //ans is initialized to 0
    //using two more matrices for mul
    //and ans as the accumulator
    long long int **sup1,**sup2,**ans2;
    sup1 = new long long int*[N];
    sup2 = new long long int*[N];
    ans2 = new long long int*[N];
    unsigned int bit;
    for ( int i = 0 ; i < N ; i ++ )
    {
        sup1[i] = new long long int[N];
        ans2[i] = new long long int[N];
        //for ( int j = 0 ; j < N ; j ++ )
        //{
        //    sup[i][j] = initial_matrix[i][j];

        //}
        copy(initial_matrix[i],initial_matrix[i]+N,sup1[i]);
        sup2[i] = new long long int[N];
    }
    k--;
    //we need to move k-1 times ( right? )
    //printf("k-1 = %d\n",k);
    for ( int i = 0 , j = 0 ; i < 32 ; i++)
    {
        bit = ( k & ( 1 << i ) ) >> i;
        //using binary representation of k
        //to calculate the powers of 2 that
        //k consists of
        if( bit )
        {
            //printf("calculating A^(2^%d)\n",i);
            for( ; j < i ; j++ )
            {
                //A*=A, i times
                multiply(sup1,sup1,sup2,N);
                swap(sup1,sup2);
            }
            //printf("calculated, multipling with answer\n");
            if ( j == 0 )
            {
                for ( int l = 0 ; l < N ; l++ )
                    for ( int m = 0 ; m < N ; m++ )
                    {
                        answer[l][m] = sup1[l][m];
                    }
            }
            else
            {
                multiply(answer,sup1,ans2,N);
                swap(ans2,answer);
            }
        }
    }
    printf("%llu\n",answer[s-1][t-1]);
    delete [] sup1;
    delete [] sup2;

}



int main()
{
    int k,N,M,s,t,a,b;
    long long int **mat;
    long long int **mat2;
    //long long int **mat3;
    int log2k;
    int nothing;

    nothing = scanf("%d %d %d %d %d",&k,&N,&M,&s,&t);

    log2k= (int) log2(k);
    mat = new long long int*[N];
    mat2 = new long long int*[N];
    //mat3 = new long long int*[N];
    //adjacency matrix [from][to]
    for( int i = 0 ; i < N ; i ++)
    {
        mat[i] = new long long int[N];
        mat2[i] = new long long int[N];
        fill(mat[i],mat[i]+N,0);
        fill(mat2[i],mat2[i]+N,1);
    }
    for ( int i = 0 ; i < M ; i++ )
    {
        nothing = scanf("%d %d",&a,&b);
        a--;
        b--;
        mat[a][b] = 1;
    }
    solvem(mat,mat2,N,k,s,t);


    return 0;
}
