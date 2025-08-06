#include <stdio.h>
int main(){
    int arr[5];
    for(int i=0;i<=4;i++){
        scanf("%d",&arr[i]);
    }
    int sum=0;
    int sum2=0;
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
   for(int i=0;i<=3;i++){
        sum+=arr[i];
    }
    for(int i=1;i<=4;i++){
        sum2+=arr[i];
    }
    printf("%d %d",sum,sum2);
}
