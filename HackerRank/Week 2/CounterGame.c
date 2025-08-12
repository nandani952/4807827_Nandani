#include <stdio.h>
#include <stdint.h> 
#include <string.h>

int is_power_of_two(uint64_t n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}
uint64_t get_next_lower_power_of_two(uint64_t n) {
    uint64_t p = 1;
    while (p <= n) {
        p <<= 1;
    }
    return p >> 1;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        uint64_t n;
        scanf("%llu", &n);
        int moves = 0;
        while (n > 1) {
            if (is_power_of_two(n)) {
                n /= 2;
            } else {
                uint64_t next_lower_power = get_next_lower_power_of_two(n);
                n -= next_lower_power;
            }
            moves++;
        }
        if (moves % 2 == 1) {
            printf("Louise\n");
        } else {
            printf("Richard\n");
        }
    }

    return 0;
}
