#ifndef SRC_STACK_H_
#define SRC_STACK_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack_node {
    struct Stack_node* previous;
    int this;
} Stack_node;

Stack_node* init(int element);
void push(Stack_node** stack, int element);
// int pop(Stack_node** stack, int *is_pop_failed);
int pop(Stack_node** stack);
int is_empty(Stack_node *stack);
void destroy(Stack_node** stack);
void print_stack(Stack_node* stack);

#endif //  SRC_STACK_H_
