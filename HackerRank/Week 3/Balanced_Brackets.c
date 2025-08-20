#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);

// A simple stack implementation using a dynamic array
typedef struct {
    char* data;
    int top;
    int capacity;
} CharStack;

void init_stack(CharStack* s, int capacity) {
    s->data = (char*)malloc(sizeof(char) * capacity);
    s->top = -1;
    s->capacity = capacity;
}

void free_stack(CharStack* s) {
    free(s->data);
}

bool is_empty(CharStack* s) {
    return s->top == -1;
}

bool is_full(CharStack* s) {
    return s->top == s->capacity - 1;
}

void push(CharStack* s, char value) {
    if (is_full(s)) {
        s->capacity *= 2;
        s->data = (char*)realloc(s->data, sizeof(char) * s->capacity);
    }
    s->data[++(s->top)] = value;
}

char pop(CharStack* s) {
    if (is_empty(s)) {
        return '\0'; 
    }
    return s->data[(s->top)--];
}

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
char* isBalanced(char* s) {
    int len = strlen(s);
    if (len % 2 != 0) {
        return "NO";
    }

    CharStack stack;
    init_stack(&stack, len);

    for (int i = 0; i < len; i++) {
        char current = s[i];
        if (current == '(' || current == '{' || current == '[') {
            push(&stack, current);
        } else {
            if (is_empty(&stack)) {
                free_stack(&stack);
                return "NO";
            }
            char top = pop(&stack);
            if ((current == ')' && top != '(') ||
                (current == '}' && top != '{') ||
                (current == ']' && top != '[')) {
                free_stack(&stack);
                return "NO";
            }
        }
    }

    bool is_balanced = is_empty(&stack);
    free_stack(&stack);

    return is_balanced ? "YES" : "NO";
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int t = parse_int(ltrim(rtrim(readline())));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        char* s = readline();

        char* result = isBalanced(s);

        fprintf(fptr, "%s\n", result);
    }

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';
            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
