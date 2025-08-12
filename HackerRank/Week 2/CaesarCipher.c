#include <stdio.h>
#include <stdlib.h>

int main() {
    int len;
    scanf("%d", &len);
    char *input = (char *)malloc(sizeof(char) * (len + 1));
    scanf("%s", input);
    int rotationKey;
    scanf("%d", &rotationKey);
    for (int i = 0; i < len; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            input[i] = ((input[i] - 'a' + rotationKey) % 26) + 'a';
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] = ((input[i] - 'A' + rotationKey) % 26) + 'A';
        }
    }
    printf("%s\n", input);
    free(input);
    return 0;
}
