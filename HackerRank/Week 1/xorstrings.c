#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* strings_xor(const char* s, const char* t) {
    int len = strlen(s);
    char* res = (char*)malloc(sizeof(char) * (len + 1));
    if (res == NULL) {
        return NULL;
    }

    for (int i = 0; i < len; i++) {
        if (s[i] == t[i]) {
            res[i] = '0';
        } else {
            res[i] = '1';
        }
    }
    res[len] = '\0';
    return res;
}

int main() {
    char s[100];
    char t[100];

    scanf("%s", s);
    scanf("%s", t);

    char* result = strings_xor(s, t);
    if (result != NULL) {
        printf("%s\n", result);
        free(result);
    }

    return 0;
}
