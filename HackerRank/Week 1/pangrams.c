#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
    char s[1001]; 
    if (fgets(s, sizeof(s), stdin) == NULL) {
        return 1; 
    }
    
    int len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
        len--;
    }
    if (len < 26) {
        printf("not pangram\n");
        return 0;
    }

    int arr[26] = {0};

    for (int i = 0; i < len; i++) {
        if (isalpha(s[i])) {
            arr[toupper(s[i]) - 'A']++;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (arr[i] == 0) {
            printf("not pangram\n");
            return 0;
        }
    }

    printf("pangram\n");

    return 0;
}
