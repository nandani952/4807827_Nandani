#include <stdio.h>
#include <stdlib.h>

#define TOP_OF_RANGE 100

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        return 1; 
    }
    int* counts = (int*)calloc(TOP_OF_RANGE, sizeof(int));
    if (counts == NULL) {
        return 1; 
    }
    for (int i = 0; i < n; i++) {
        int tmp;
        if (scanf("%d", &tmp) != 1) {
            free(counts);
            return 1; 
        }
        if (tmp >= 0 && tmp < TOP_OF_RANGE) {
            counts[tmp]++;
        }
    }
    for (int i = 0; i < TOP_OF_RANGE; i++) {
        printf("%d ", counts[i]);
    }
    printf("\n");
    free(counts);

    return 0;
}
