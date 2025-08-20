// Queue using 2 stacks 

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int top;
    int capacity;
} Stack;

void init_stack(Stack* s, int capacity) {
    s->data = (int*)malloc(sizeof(int) * capacity);
    s->top = -1;
    s->capacity = capacity;
}

void free_stack(Stack* s) {
    free(s->data);
}

int is_empty(Stack* s) {
    return s->top == -1;
}

int is_full(Stack* s) {
    return s->top == s->capacity - 1;
}

void push(Stack* s, int value) {
    if (is_full(s)) {
        s->capacity *= 2;
        s->data = (int*)realloc(s->data, sizeof(int) * s->capacity);
    }
    s->data[++(s->top)] = value;
}

int pop(Stack* s) {
    if (is_empty(s)) {
        return -1; 
    }
    return s->data[(s->top)--];
}

int peek(Stack* s) {
    if (is_empty(s)) {
        return -1; 
    }
    return s->data[s->top];
}

void transfer_stacks(Stack* from, Stack* to) {
    while (!is_empty(from)) {
        push(to, pop(from));
    }
}

int main() {
    int q;
    scanf("%d", &q);

    int capacity = 10000;
    Stack stack_enqueue;
    Stack stack_dequeue;

    init_stack(&stack_enqueue, capacity);
    init_stack(&stack_dequeue, capacity);

    for (int i = 0; i < q; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int x;
            scanf("%d", &x);
            push(&stack_enqueue, x);
        } else if (type == 2) {
            if (is_empty(&stack_dequeue)) {
                transfer_stacks(&stack_enqueue, &stack_dequeue);
            }
            if (!is_empty(&stack_dequeue)) {
                pop(&stack_dequeue);
            }
        } else if (type == 3) {
            if (is_empty(&stack_dequeue)) {
                transfer_stacks(&stack_enqueue, &stack_dequeue);
            }
            if (!is_empty(&stack_dequeue)) {
                printf("%d\n", peek(&stack_dequeue));
            }
        }
    }

    free_stack(&stack_enqueue);
    free_stack(&stack_dequeue);

    return 0;
}
