#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int** arr = (int**)malloc(sizeof(int*) * n);
    int* sizes = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        sizes[i] = 0;
        arr[i] = (int*)malloc(sizeof(int));
    }

    int last = 0;

    for (int i = 0; i < q; i++) {
        int queryType, x, y;
        scanf("%d %d %d", &queryType, &x, &y);
        int idx = (x ^ last) % n;
        if (queryType == 1) {
            sizes[idx]++;
            arr[idx] = (int*)realloc(arr[idx], sizeof(int) * sizes[idx]);
            arr[idx][sizes[idx] - 1] = y;

        } else if (queryType == 2) {
            int elementIndex = y % sizes[idx];
            last = arr[idx][elementIndex];
            printf("%d\n", last);
        }
    }
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
    free(sizes);

    return 0;
}
