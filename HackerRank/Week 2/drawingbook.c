#include <stdio.h>

int main() {
    int num, target;
    scanf("%d %d", &num, &target);
    int begin = target / 2;
    int fromEnd;
    if (num % 2 == 1) {
        fromEnd = (num - target) / 2;
    } else {
        fromEnd = (num - target + 1) / 2;
    }
    int result = (begin < fromEnd) ? begin : fromEnd;
    printf("%d", result);
    return 0;
}
