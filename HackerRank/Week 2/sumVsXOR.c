#include <math.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    long n,sum1,sum2,count=0; 
    scanf("%ld",&n);
    while(n)
        {
        sum1+=n%2?0:1;
        n/=2;
    }
    count=pow(2,sum1);
    printf("%ld",count);
    return 0;
}
