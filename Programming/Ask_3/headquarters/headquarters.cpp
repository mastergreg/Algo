/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : headquarters.cpp

* Purpose :

* Creation Date : 29-01-2012

* Last Modified : Thu 02 Feb 2012 03:11:04 AM EET

* Created By : Greg Liras <gregliras@gmail.com>

_._._._._._._._._._._._._._._._._._._._._.*/

#define MODLIMIT 100000007

#include <cstdio>
#include <cstdlib>
#include <cmath>
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

void solvem(long long int **initial_matrix,long long int **answer, int N, int k)
{
    long long int **sup1,**sup2;
    sup1 = new long long int*[N];
    sup2 = new long long int*[N];
    unsigned int bit;
    for ( int i = 0 ; i < N ; i ++ )
    {
        sup1[i] = new long long int[N];
        copy(initial_matrix[i],initial_matrix[i]+N,sup1[i]);
        sup2[i] = new long long int[N];
    }
    k--;
    printf("k-1 = %d\n",k);
    for ( int i = 0 ; i < 32 ; i++)
    {
        bit = ( k & ( 1 << i ) ) >> i;
        if( bit )
        {
            printf("2^%d+\n",i);
            for( int j = 0 ; j < i ; j++)
            {
                multiply(sup1,sup1,sup2,N);
                swap(sup1,sup2);
            }
            for ( int i = 0 ; i < N ; i ++ )
            {
                for ( int j = 0 ; j < N ; j ++ )
                {
                    answer[i][j]+= sup1[i][j];
                    answer[i][j] %= MODLIMIT;
                }
            }

        }
    }
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
    //    mat3[i] = new long long int[N];
        fill(mat[i],mat[i]+N,0);
        fill(mat2[i],mat2[i]+N,0);
    //    fill(mat3[i],mat3[i]+N,0);
    }
    for ( int i = 0 ; i < M ; i++ )
    {
        nothing = scanf("%d %d",&a,&b);
        a--;
        b--;
        mat[a][b] = 1;
    //    mat2[a][b] = 1;
    }
    //for( int i = 0 ; i < log2k ; i++)
    //{
    //    multiply(mat2,mat2,mat3,N);
    //    swap(mat2,mat3);
    //}
    //printf("%d %d\n",(int) pow(2,log2k),k);
    //for ( int i = ( int ) pow(2,log2k); i < k-1 ; i++)
    //{
    //    multiply(mat,mat2,mat3,N);
    //    swap(mat2,mat3);
    //}
    solvem(mat,mat2,N,k);
    printf("%lld\n",mat2[s-1][t-1]);


    return 0;
}
