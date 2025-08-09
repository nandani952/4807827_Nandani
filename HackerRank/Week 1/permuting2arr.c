#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main() {

    int T;
    int dummy;
    dummy=scanf("%d",&T);
    
    int N;
    int K;
    
    int i;
    for(i=0; i<T; i++)
    {
        dummy=scanf("%d",&N);
        int A[N];
        int B[N];
        
        dummy=scanf("%d",&K);
        
        int j;
        for(j=0; j<N; j++)
        {
            dummy=scanf("%d",A+j);
        }
        for(j=0; j<N; j++)
        {
            dummy=scanf("%d",B+j);
        }
        qsort (A, N, sizeof(int), compare);
        qsort (B, N, sizeof(int), compare);
        
        int k;
        int isPossible = 1;
               
        for (k=0; k<N; k++)
        {
            if ((isPossible == 1) && (A[k]+B[N-1-k] < K))
                isPossible = 0;
        }
        
        if (isPossible == 1)
            printf("YES\n");
        else
            printf("NO\n");
        
    }
    return 0;
}
