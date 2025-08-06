#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
int main()
{
    int n,arr[100],temp;
    float minus = 0,zeros = 0,plus = 0;
    scanf("%d",&n);
    for(temp=0;temp<n;temp++)
    {
        scanf("%d",& arr[temp]);
        if(arr[temp] > 0)
        {
            plus++;    
        }
        else if(arr[temp] == 0)
        {
            zeros++;    
        }
        else
        {
            minus++;    
        }
        
    }
    printf("%.6f\n %.6f\n %.6f",plus/n,minus/n, zeros/n);    
    return 0;
}
