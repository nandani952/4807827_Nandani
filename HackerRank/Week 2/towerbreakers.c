#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int num, height;
        scanf("%d %d", &num, &height);
        if (height == 1 || num % 2 == 0) {
            printf("2\n");
        } else {
            printf("1\n");
        }
    }
    return 0;
}
