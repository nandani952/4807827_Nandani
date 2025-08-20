#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char** data;
    int top;
    int capacity;
} StringStack;

void init_stack(StringStack* s, int capacity) {
    s->data = (char**)malloc(sizeof(char*) * capacity);
    s->top = -1;
    s->capacity = capacity;
}

void free_stack(StringStack* s) {
    while (s->top >= 0) {
        free(s->data[s->top--]);
    }
    free(s->data);
}

bool is_empty(StringStack* s) {
    return s->top == -1;
}

void push(StringStack* s, char* str) {
    if (s->top == s->capacity - 1) {
        s->capacity *= 2;
        s->data = (char**)realloc(s->data, sizeof(char*) * s->capacity);
    }
    s->data[++(s->top)] = strdup(str);
}

char* pop(StringStack* s) {
    if (is_empty(s)) {
        return NULL;
    }
    return s->data[(s->top)--];
}

int main() {
    int Q;
    scanf("%d", &Q);

    char* s = (char*)malloc(sizeof(char) * 1000001);
    s[0] = '\0';
    int s_len = 0;

    StringStack history_stack;
    init_stack(&history_stack, 1000);

    for (int i = 0; i < Q; ++i) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            char w[1000001];
            scanf("%s", w);
            push(&history_stack, s);
            s_len += strlen(w);
            s = (char*)realloc(s, sizeof(char) * (s_len + 1));
            strcat(s, w);
        } else if (type == 2) {
            int k;
            scanf("%d", &k);
            if (s_len >= k) {
                push(&history_stack, s);
                s_len -= k;
                s[s_len] = '\0';
                s = (char*)realloc(s, sizeof(char) * (s_len + 1));
            }
        } else if (type == 3) {
            int k;
            scanf("%d", &k);
            if (k > 0 && k <= s_len) {
                printf("%c\n", s[k - 1]);
            }
        } else if (type == 4) {
            if (!is_empty(&history_stack)) {
                free(s);
                s = pop(&history_stack);
                s_len = strlen(s);
            }
        }
    }
    
    free(s);
    free_stack(&history_stack);

    return 0;
}
