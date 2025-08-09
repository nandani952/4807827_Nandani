#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n, q;
    char** n_array = NULL;
    char** q_array = NULL;
    scanf("%d", &n);
    n_array = (char**)malloc(n * sizeof(char*));
    if (n_array == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        char s[21]; 
        scanf("%s", s);
        n_array[i] = (char*)malloc(strlen(s) + 1); 
        if (n_array[i] == NULL) {
            return 1;
        }
        strcpy(n_array[i], s);
    }

    scanf("%d", &q);
    q_array = (char**)malloc(q * sizeof(char*));
    if (q_array == NULL) {
        return 1;
    }

    for (int i = 0; i < q; i++) {
        int occurs = 0;
        char s[21];
        scanf("%s", s);
        for (int j = 0; j < n; j++) {
            if (strcmp(s, n_array[j]) == 0) {
                occurs++;
            }
        }
        printf("%d\n", occurs);
    }

    for (int i = 0; i < n; i++) {
        free(n_array[i]);
    }
    free(n_array);
    return 0;
}
