#include "stack.h"

Stack_node *init(Type_t element) {
    Stack_node *node = malloc(1 * sizeof(Stack_node));
    if (!node)
        return NULL;

    node->this = element;
    node->previous = NULL;

    return node;
}
void push(Stack_node **stack, Type_t element) {
    Stack_node *previous_node = *stack;

    *stack = init(element);
    if (!(*stack)) {
        return;
    }

    if (previous_node)
        (*stack)->previous = previous_node;
}
Type_t pop(Stack_node **stack) {
    const Type_t result_to_return = (*stack)->this;

    Stack_node *node_to_free = *stack;
    if ((*stack)->previous) {
        *stack = (*stack)->previous;
    } else {
        *stack = NULL;
    }

    if (node_to_free) {
        free(node_to_free);
        node_to_free = NULL;
    }
    return result_to_return;
}

int is_empty(Stack_node *stack) {
    return stack == NULL;
}

Type_t top(Stack_node *stack) {
    return stack->this;
}

void destroy(Stack_node **stack) {
    while (*stack) {
        Stack_node *node_to_free = *stack;
        *stack = (*stack)->previous;
        free(node_to_free);
    }
}

void print_stack(Stack_node *stack) {
    printf("------Top of the stack:---------\n");
    while (stack) {        
        #if defined(LEXEME_T_)
        printf("         ");
        print_lexeme_with_endline_and_type(&(stack->this));
        #elif defined(OPERAND_T_)
        printf("         %lf\n", stack->this);
        #else
        printf("         %c\n", stack->this);  //  default type
        #endif //  LEXEME_T_

        stack = stack->previous;
    }
    printf("------bottom of the stack-------\n");
}