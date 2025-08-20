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
char** split_string(char*);

int parse_int(char*);

// Stack implementation
typedef struct {
    int* data;
    int top;
    int capacity;
} IntStack;

void init_stack(IntStack* s, int capacity) {
    s->data = (int*)malloc(sizeof(int) * capacity);
    s->top = -1;
    s->capacity = capacity;
}

void free_stack(IntStack* s) {
    if (s->data) {
        free(s->data);
    }
}

bool is_empty(IntStack* s) {
    return s->top == -1;
}

void push(IntStack* s, int value) {
    if (s->top == s->capacity - 1) {
        s->capacity *= 2;
        s->data = (int*)realloc(s->data, sizeof(int) * s->capacity);
    }
    s->data[++(s->top)] = value;
}

int pop(IntStack* s) {
    if (is_empty(s)) {
        return -1;
    }
    return s->data[(s->top)--];
}

// Sieve to generate primes
void sieve_of_eratosthenes(int limit, int* primes, int* prime_count) {
    bool* is_prime = (bool*)malloc(sizeof(bool) * (limit + 1));
    memset(is_prime, true, sizeof(bool) * (limit + 1));
    is_prime[0] = is_prime[1] = false;

    for (int p = 2; p * p <= limit; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                is_prime[i] = false;
            }
        }
    }

    *prime_count = 0;
    for (int p = 2; p <= limit; p++) {
        if (is_prime[p]) {
            primes[(*prime_count)++] = p;
        }
    }
    free(is_prime);
}

int* waiter(int number_count, int* number, int q, int* result_count) {
    // Generate primes
    int prime_limit = 20000;
    int* primes = (int*)malloc(sizeof(int) * prime_limit);
    int prime_count;
    sieve_of_eratosthenes(prime_limit, primes, &prime_count);

    // Stacks for current and next iteration
    IntStack stack_a, stack_b;
    init_stack(&stack_a, number_count);
    init_stack(&stack_b, number_count);

    // Initial stack A contains the input numbers
    for (int i = 0; i < number_count; i++) {
        push(&stack_a, number[i]);
    }
    
    // Result array
    int* result = (int*)malloc(sizeof(int) * number_count);
    *result_count = 0;
    
    // Pointers to current and next stack
    IntStack* current = &stack_a;
    IntStack* next = &stack_b;
    IntStack* temp;

    // Iterations
    for (int i = 0; i < q; i++) {
        int prime = primes[i];
        IntStack b_temp;
        init_stack(&b_temp, number_count);
        
        while (!is_empty(current)) {
            int num = pop(current);
            if (num % prime == 0) {
                push(&b_temp, num);
            } else {
                push(next, num);
            }
        }

        while (!is_empty(&b_temp)) {
            result[(*result_count)++] = pop(&b_temp);
        }
        
        free_stack(&b_temp);

        // Swap pointers for next iteration
        temp = current;
        current = next;
        next = temp;
        // Make sure the next stack is empty
        next->top = -1;
    }
    
    // Add remaining items from the last "current" stack
    while (!is_empty(current)) {
        result[(*result_count)++] = pop(current);
    }

    free_stack(&stack_a);
    free_stack(&stack_b);
    free(primes);
    
    return result;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** first_multiple_input = split_string(rtrim(readline()));

    int n = parse_int(*(first_multiple_input + 0));

    int q = parse_int(*(first_multiple_input + 1));

    char** number_temp = split_string(rtrim(readline()));

    int* number = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int number_item = parse_int(*(number_temp + i));

        *(number + i) = number_item;
    }

    int result_count;
    int* result = waiter(n, number, q, &result_count);

    for (int i = 0; i < result_count; i++) {
        fprintf(fptr, "%d", *(result + i));

        if (i != result_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

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

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
