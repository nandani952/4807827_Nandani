#include <stdio.h>

int main() {
    int n, d, m, ans = 0;
    int a[105], s[105] = {0};

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s[i] = s[i-1] + a[i];
    }
    
    scanf("%d %d", &d, &m);

    for (int i = m; i <= n; i++) {
        if (s[i] - s[i - m] == d) {
            ans++;
        }
    }
    
    printf("%d\n", ans);

    return 0;
}
