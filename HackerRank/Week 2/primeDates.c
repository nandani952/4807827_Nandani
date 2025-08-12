#include <stdio.h>
#include <stdbool.h>

int m[13];
void updateLeapYear(int y) {
    if (y % 400 == 0) {
        m[2] = 29;
    } else if (y % 100 == 0) {
        m[2] = 28;
    } else if (y % 4 == 0) {
        m[2] = 29;
    } else {
        m[2] = 28;
    }
}

void storeMonth() {
    m[1] = 31;
    m[2] = 28;
    m[3] = 31;
    m[4] = 30;
    m[5] = 31;
    m[6] = 30;
    m[7] = 31;
    m[8] = 31;
    m[9] = 30;
    m[10] = 31;
    m[11] = 30;
    m[12] = 31;
}
int findLuckyDates(int d1, int m1, int y1, int d2, int m2, int y2) {
    int r = 0;
    while (true) {
        long long x = d1;
        x = x * 100 + m1;
        x = x * 10000 + y1;
        if (x % 4 == 0 || x % 7 == 0) {
            r++;
        }
        if (d1 == d2 && m1 == m2 && y1 == y2) {
            break;
        }
        updateLeapYear(y1);
        d1++;
        if (d1 > m[m1]) {
            m1++;
            d1 = 1;
            if (m1 > 12) {
                y1++;
                m1 = 1;
            }
        }
    }
    return r;
}
int main() {
    int d1, m1, y1;
    int d2, m2, y2;
    scanf("%d-%d-%d %d-%d-%d", &d1, &m1, &y1, &d2, &m2, &y2);
    storeMonth();
    int result = findLuckyDates(d1, m1, y1, d2, m2, y2);
    printf("%d\n", result);
    return 0;
}
