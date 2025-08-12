#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int arr[101];
    for(int i=0;i<101;i++){
        arr[i]=0;
    }
    for(int i=0;i<n;i++){
        int j;
        scanf("%d",&j);
        arr[j] += 1;
    }
    int tot=0;
    for(int i=0;i<101;i++){
        if(arr[i]> 1){
            if(arr[i] % 2 == 0) tot += (arr[i] / 2);
            else tot += ((arr[i]-1) / 2);
        }
    }
    printf("%d",tot);
    return 0;
}
