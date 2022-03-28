#ifndef SRC_STACK_H_
#define SRC_STACK_H_

#include <stdio.h>
#include <stdlib.h>

#include "lexeme.h"

#if defined(ACTION_T_)
typedef char Type_t;
#elif defined(OPERAND_T_)
typedef double Type_t;
#else
typedef Lexeme Type_t;  //  default type
#endif //  LEXEME_T


typedef struct Stack_node {
    struct Stack_node *previous;
    Type_t this;
} Stack_node;

Stack_node *init(Type_t element);
void push(Stack_node **stack, Type_t element);
Type_t pop(Stack_node **stack);
Type_t top(Stack_node *stack);
int is_empty(Stack_node *stack);
void destroy(Stack_node **stack);
void print_stack(Stack_node *stack);

#endif //  SRC_STACK_H_
