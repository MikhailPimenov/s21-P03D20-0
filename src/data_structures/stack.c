#include "stack.h"


Stack_node* init(int element) {
    Stack_node *node = malloc(1 * sizeof(Stack_node));
    if (!node)
        return NULL;

    node->this = element;
    node->previous = NULL;
 
    return node;
}
void push(Stack_node** stack, int element) {
    Stack_node *previous_node = *stack;
    
    *stack = init(element);
    if (!(*stack)) {
        return;
    }

    (*stack)->previous = previous_node;
}
int pop(Stack_node** stack) {
    // printf("pop():\n");
    // *is_pop_failed = 0;
    if((*stack) == NULL) {
        printf("Error: stack is empty!\n");
        // *is_pop_failed = 1;
        return -1;
    }
    const int result_to_return = (*stack)->this;


    Stack_node* node_to_free = *stack;
    // printf("in pop():\n");
    if ((*stack)->previous) {
        *stack = (*stack)->previous;
        if (node_to_free)
            free(node_to_free);
    } else {
        *stack = NULL;
    }

    return result_to_return;
}

int is_empty(Stack_node *stack) {
    return stack == NULL;
}

int top(Stack_node *stack) {
    return stack->this;
}

void destroy(Stack_node** stack) {
    while (*stack) {
        Stack_node* node_to_free = *stack;
        *stack = (*stack)->previous;
        free(node_to_free);
    }
}

void print_stack(Stack_node* stack) {
    printf("Stack:\n");
    while(stack) {
        printf("%d\n", stack->this);
        stack = stack->previous;
    }
    printf("\n\n");
}

