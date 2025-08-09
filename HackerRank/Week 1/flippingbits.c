#include <stdio.h>

unsigned int flipBits(unsigned int a) {
    return a ^ 4294967295;
}
int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        unsigned int a;
        if (scanf("%u", &a) != 1) {
            return 1;
        }
        unsigned int res = flipBits(a);
        printf("%u\n", res);
    }
    return 0;
}
