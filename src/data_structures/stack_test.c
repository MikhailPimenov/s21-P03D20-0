#include "stack_test.h"


char get_random_action() {
    static const int amount_of_actions = 14;
    static const char actions[14] = {
        '+', 
        '-', 
        '*', 
        '/', 
        's', 
        'c', 
        't', 
        'g', 
        'r',
        'l',
        'p',
        '(',
        ')',
        'm'
        };
    const int random_index = rand() % amount_of_actions;
    return actions[random_index];
}

char get_random_operand() {
    const int integer_part    = rand() % 1000;
    const int fractional_part = rand() % 100;
    const int sign = 1 - 2 * rand() % 2;

    return ((double)integer_part + (double)fractional_part) * (double)sign;
}



#if defined(ACTION_T_)
static char get_element_for_testing() {  
    return get_random_action();
}
static void print_element(char element) {
    printf("%c\n", element);
}

#elif defined(OPERAND_T_)
static double get_element_for_testing() {
    return get_random_operand();
}
static void print_element(double element) {
    printf("%lf\n", element);
}
#else



static Lexeme get_element_for_testing() {
    Lexeme lexeme;

    if (rand() % 2) {
        const double operand = get_random_operand();
        set_lexeme(&lexeme, LT_OPERAND, operand, '\0');
        return lexeme;
    }

    const char action = get_random_action();
    set_lexeme(&lexeme, LT_ACTION, 0.0, action);

    return lexeme;
}

static void print_element(Lexeme lexeme) {
    print_lexeme_with_endline_and_type(&lexeme);
}

#endif // ACTION_



void stack_test_visual() {
    printf("stack_test_visual():\n");

    srand(0u);
    
    Stack_node *stack = NULL;
    print_stack(stack);
 
    Type_t element = get_element_for_testing();
    printf("Adding: ");
    print_element(element);
    push(&stack, element);
    print_stack(stack);

    element = get_element_for_testing();
    printf("Adding: ");
    print_element(element);
    push(&stack, element);
    print_stack(stack);

    element = get_element_for_testing();
    printf("Adding: ");
    print_element(element);
    push(&stack, element);
    print_stack(stack);

    element = get_element_for_testing();
    printf("Adding: ");
    print_element(element);
    push(&stack, element);
    print_stack(stack);

    element = get_element_for_testing();
    printf("Adding: ");
    print_element(element);
    push(&stack, element);
    print_stack(stack);

    element = get_element_for_testing();
    printf("Adding: ");
    print_element(element);
    push(&stack, element);
    print_stack(stack);

    element = get_element_for_testing();
    printf("Adding: ");
    print_element(element);
    push(&stack, element);
    print_stack(stack);

    element = get_element_for_testing();
    printf("Adding: ");
    print_element(element);
    push(&stack, element);
    print_stack(stack);

    element = get_element_for_testing();
    printf("Adding: ");
    print_element(element);
    push(&stack, element);
    print_stack(stack);

    element = get_element_for_testing();
    printf("Adding: ");
    print_element(element);
    push(&stack, element);
    print_stack(stack);

    element = get_element_for_testing();
    printf("Adding: ");
    print_element(element);
    push(&stack, element);
    print_stack(stack);

    element = get_element_for_testing();
    printf("Adding: ");
    print_element(element);
    push(&stack, element);
    print_stack(stack);

    element = get_element_for_testing();
    printf("Adding: ");
    print_element(element);
    push(&stack, element);
    print_stack(stack);

    element = get_element_for_testing();
    printf("Adding: ");
    print_element(element);
    push(&stack, element);
    print_stack(stack);

    element = get_element_for_testing();
    printf("Adding: ");
    print_element(element);
    push(&stack, element);
    print_stack(stack);

    element = get_element_for_testing();
    printf("Adding: ");
    print_element(element);
    push(&stack, element);
    print_stack(stack);

    element = get_element_for_testing();
    printf("Adding: ");
    print_element(element);
    push(&stack, element);
    print_stack(stack);

    element = get_element_for_testing();
    printf("Adding: ");
    print_element(element);
    push(&stack, element);
    print_stack(stack);

    element = get_element_for_testing();
    printf("Adding: ");
    print_element(element);
    push(&stack, element);
    print_stack(stack);

    element = get_element_for_testing();
    printf("Adding: ");
    print_element(element);
    push(&stack, element);
    print_stack(stack);

    element = get_element_for_testing();
    printf("Adding: ");
    print_element(element);
    push(&stack, element);
    print_stack(stack);

    element = get_element_for_testing();
    printf("Adding: ");
    print_element(element);
    push(&stack, element);
    print_stack(stack);

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("Popped from stack: ");
        print_element(element);
        print_stack(stack);
    } else {
        printf("Stack is empty. Nothing to pop.\n");
    }

}