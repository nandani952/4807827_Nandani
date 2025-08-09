#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int diagonalDifference(int** arr, int n) {
    int s1 = 0;
    int s2 = 0;
    for (int i = 0; i < n; i++) {
        s1 += arr[i][i];
        s2 += arr[i][n - i - 1];
    }
    return abs(s1 - s2);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    int** arr = (int**)malloc(n * sizeof(int*));
    if (arr == NULL) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = (int*)malloc(n * sizeof(int));
        if (arr[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(arr[j]);
            }
            free(arr);
            return 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &arr[i][j]) != 1) {
                for (int k = 0; k < n; k++) {
                    free(arr[k]);
                }
                free(arr);
                return 1;
            }
        }
    }
    int result = diagonalDifference(arr, n);

    printf("%d\n", result);
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
