#include <stdio.h>
#include <stdlib.h>

void minimumBribes(int q_count, int* q) {
    int bribes = 0;
    for (int i = q_count - 1; i >= 0; i--) {
        if (q[i] - (i + 1) > 2) {
            printf("Too chaotic\n");
            return;
        }
        for (int j = (q[i] - 2 > 0 ? q[i] - 2 : 0); j < i; j++) {
            if (q[j] > q[i]) {
                bribes++;
            }
        }
    }
    printf("%d\n", bribes);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int* q = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &q[i]);
        }
        minimumBribes(n, q);
        free(q);
    }
    return 0;
}
