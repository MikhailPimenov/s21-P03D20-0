#ifndef SRC_STACK_H_
#define SRC_STACK_H_

#include <stdio.h>
#include <stdlib.h>

#include "lexeme.h"

// typedef struct Stack_node {
//     struct Stack_node* previous;
//     int this;
// } Stack_node;

// Stack_node* init(int element);
// void push(Stack_node** stack, int element);
// // int pop(Stack_node** stack, int *is_pop_failed);
// int pop(Stack_node** stack);
// int is_empty(Stack_node *stack);
// void destroy(Stack_node** stack);
// void print_stack(Stack_node* stack);

typedef Lexeme Type_t;

typedef struct Stack_node {
    struct Stack_node* previous;
    Type_t this;
} Stack_node;

Stack_node* init(Type_t element);
void push(Stack_node** stack, Type_t element);
// int pop(Stack_node** stack, int *is_pop_failed);
int pop(Stack_node** stack);
int is_empty(Stack_node *stack);
void destroy(Stack_node** stack);
void print_stack(Stack_node* stack);

#endif //  SRC_STACK_H_
