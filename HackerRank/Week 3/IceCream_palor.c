#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int cost;
    int index;
} Flavor;

int compareFlavors(const void* a, const void* b) {
    return ((Flavor*)a)->cost - ((Flavor*)b)->cost;
}

int* icecreamParlor(int m, int cost_count, int* cost, int* result_count) {
    *result_count = 2;
    int* result = malloc(2 * sizeof(int));
    Flavor* flavors = malloc(cost_count * sizeof(Flavor));
    for (int i = 0; i < cost_count; i++) {
        flavors[i].cost = cost[i];
        flavors[i].index = i + 1; 
    }
    qsort(flavors, cost_count, sizeof(Flavor), compareFlavors);
    int left = 0;
    int right = cost_count - 1;

    while (left < right) {
        int sum = flavors[left].cost + flavors[right].cost;
        if (sum == m) {
            result[0] = flavors[left].index;
            result[1] = flavors[right].index;
            if (result[0] > result[1]) {
                int temp = result[0];
                result[0] = result[1];
                result[1] = temp;
            }
            break;
        } else if (sum < m) {
            left++;
        } else { // sum > m
            right--;
        }
    }
    free(flavors);
    return result;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int m, n;
        scanf("%d", &m);
        scanf("%d", &n);
        int* cost = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &cost[i]);
        }
        int result_count;
        int* result = icecreamParlor(m, n, cost, &result_count);
        printf("%d %d\n", result[0], result[1]);
        free(cost);
        free(result);
    }
    
    return 0;
}
