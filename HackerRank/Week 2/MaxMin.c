#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare_integers(const void *a, const void *b) {
    int int_a = *((int *)a);
    int int_b = *((int *)b);
    if (int_a < int_b) return -1;
    if (int_a > int_b) return 1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    int k;
    scanf("%d", &k);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), compare_integers);
    int min_unfairness = INT_MAX;
    for (int i = 0; i <= n - k; i++) {
        int current_unfairness = arr[i + k - 1] - arr[i];

        if (current_unfairness < min_unfairness) {
            min_unfairness = current_unfairness;
        }
    }
    printf("%d\n", min_unfairness);
    return 0;
}
