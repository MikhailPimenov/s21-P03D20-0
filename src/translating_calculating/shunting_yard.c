#include <stdio.h>
#include <stdlib.h>

enum Lexeme_types {
    LT_OPERAND = 0,
    LT_ACTION = 1
};

typedef struct Lexeme {
    int data;
    int actual_type;
} Lexeme;


typedef Lexeme Type_t;


typedef struct Stack_node {
    struct Stack_node* previous;
    Type_t this;
} Stack_node;


void get_lexeme(const Lexeme *lexeme, int *operand_out, char *action_out);

void print_lexeme(const Lexeme *lexeme) {
    int operand = -1;
    char action = '\0';
    get_lexeme(lexeme, &operand, &action);
    if (lexeme->actual_type == LT_OPERAND) {
        printf("operand = %d\n", operand);
    } else {
        printf("action  = %c\n", action);
    }
}


Stack_node* init(Type_t element) {
    Stack_node *node = malloc(1 * sizeof(Stack_node));
    if (!node)
        return NULL;

    node->this = element;
    node->previous = NULL;
 
    return node;
}
void push(Stack_node** stack, Type_t element) {
    Stack_node *previous_node = *stack;
    
    *stack = init(element);
    if (!(*stack)) {
        return;
    }

    if (previous_node)
        (*stack)->previous = previous_node;
}
Type_t pop(Stack_node** stack) {
    // printf("pop():\n");
    // *is_pop_failed = 0;
    // if((*stack) == NULL) {
        // printf("Error: stack is empty!\n");
        // *is_pop_failed = 1;
        // return -1;
    // }
    const Type_t result_to_return = (*stack)->this;


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

Type_t top(Stack_node *stack) {
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
        // printf("%d\n", stack->this);
        print_lexeme(&(stack->this));
        stack = stack->previous;
    }
    printf("\n\n");
}




void get_lexeme(const Lexeme *lexeme, int *operand_out, char *action_out) {
    *operand_out = 0;
    *action_out = '\0';
    // *actual_type_out = lexeme->actual_type;
    
    
    //  expecting integer (number, operand)
    if (lexeme->actual_type == LT_OPERAND) {
        *operand_out = lexeme->data;
        return;
    } 
    
    //  expecting char (symbol, operator, action)
    const int *const pointer_to_int = &(lexeme->data);
    const char *const pointer_to_char = (char*)pointer_to_int;
    *action_out = *pointer_to_char;
    
    // *action_out = *((char*)(&(lexeme->data)));   // same in one line
}


void print_lexeme_array(const Lexeme *array, int length) {
    for (int index = 0; index < length; ++index) {
        // int actual_type = -1;
        // int operand = -1;
        // char action = '\0';
        // get_lexeme(lexemes + index, &operand, &action);
        // if (lexemes[index].actual_type == LT_OPERAND) {
        //     printf("operand = %d\n", operand);
        // }
        // if (lexemes[index].actual_type == LT_ACTION) {
        //     printf("action  = %c\n", action);
        // }
        print_lexeme(array + index);
            
    }
    printf("\n");
}

void visual_test_get_lexeme(void get_lexeme(const Lexeme*, int *, char *)){
    Lexeme lexemes[33];
    lexemes[0] = (Lexeme){.data = 56, .actual_type = LT_OPERAND};
    lexemes[1] = (Lexeme){.data = '-', .actual_type = LT_ACTION};
    lexemes[2] = (Lexeme){.data = 14, .actual_type = LT_OPERAND};
    lexemes[3] = (Lexeme){.data = 88, .actual_type = LT_OPERAND};
    lexemes[4] = (Lexeme){.data = '*', .actual_type = LT_ACTION};
    lexemes[5] = (Lexeme){.data = 1488, .actual_type = LT_OPERAND};
    lexemes[6] = (Lexeme){.data = '-', .actual_type = LT_ACTION};
    lexemes[7] = (Lexeme){.data = 228, .actual_type = LT_OPERAND};
    lexemes[8] = (Lexeme){.data = -99, .actual_type = LT_OPERAND};
    lexemes[9] = (Lexeme){.data = '/', .actual_type = LT_ACTION};
    lexemes[10] = (Lexeme){.data = '+', .actual_type = LT_ACTION};
    lexemes[11] = (Lexeme){.data = '/', .actual_type = LT_ACTION};
    lexemes[12] = (Lexeme){.data = -1, .actual_type = LT_OPERAND};
    lexemes[13] = (Lexeme){.data = -0, .actual_type = LT_OPERAND};
    lexemes[14] = (Lexeme){.data = 10, .actual_type = LT_OPERAND};
    lexemes[15] = (Lexeme){.data = -0, .actual_type = LT_OPERAND};
    lexemes[16] = (Lexeme){.data = 'm', .actual_type = LT_ACTION};
    lexemes[17] = (Lexeme){.data = 's', .actual_type = LT_ACTION};
    lexemes[18] = (Lexeme){.data = 't', .actual_type = LT_ACTION};
    lexemes[19] = (Lexeme){.data = 'g', .actual_type = LT_ACTION};
    lexemes[20] = (Lexeme){.data = -5, .actual_type = LT_OPERAND};
    lexemes[21] = (Lexeme){.data = 25, .actual_type = LT_OPERAND};
    lexemes[22] = (Lexeme){.data = -0, .actual_type = LT_OPERAND};
    lexemes[23] = (Lexeme){.data = 'm', .actual_type = LT_ACTION};
    lexemes[24] = (Lexeme){.data = 's', .actual_type = LT_ACTION};
    lexemes[25] = (Lexeme){.data = '(', .actual_type = LT_ACTION};
    lexemes[26] = (Lexeme){.data = -50, .actual_type = LT_OPERAND};
    lexemes[27] = (Lexeme){.data = 250, .actual_type = LT_OPERAND};
    lexemes[28] = (Lexeme){.data = -60, .actual_type = LT_OPERAND};
    lexemes[29] = (Lexeme){.data = 'l', .actual_type = LT_ACTION};
    lexemes[30] = (Lexeme){.data = 't', .actual_type = LT_ACTION};
    lexemes[31] = (Lexeme){.data = ')', .actual_type = LT_ACTION};
    lexemes[32] = (Lexeme){.data = 'g', .actual_type = LT_ACTION};
    
    const int length = 33;
    
    for (int index = 0; index < length; ++index) {
        int operand = -1;
        char action = '\0';
        get_lexeme(lexemes + index, &operand, &action);
        if (lexemes[index].actual_type == LT_OPERAND) {
            printf("operand = %d\n", operand);
        }
        if (lexemes[index].actual_type == LT_ACTION) {
            printf("action  = %c\n", action);
        }
        // print_lexeme(lexemes + index);
            
    }
}




int are_two_lexemes_equal(const Lexeme* first, const Lexeme* second) {
    return (first->actual_type == second->actual_type) && (first->data == second->data);
}

int are_equal(const Lexeme *first_array, const Lexeme *second_array, int length) {
    for (int index = 0; index < length; ++index) {
        if (!are_two_lexemes_equal(first_array + index, second_array + index))
            return 0;
    }
    return 1;
}


void test_shunting_yard(void (*shunting_yard_function)(const Lexeme *, int, Lexeme *, int*)) {
    // const char *case1 = "2 + 1";
    // const char *expected1 = "2 1 +";
    
    const int length1 = 3;
    Lexeme case1[3];
    case1[0] = (Lexeme){.data = 2, .actual_type = LT_OPERAND};
    case1[1] = (Lexeme){.data = '+', .actual_type = LT_ACTION};
    case1[2] = (Lexeme){.data = 1, .actual_type = LT_OPERAND};
    
    Lexeme expected1[3];
    expected1[0] = (Lexeme){.data = 2, .actual_type = LT_OPERAND};
    expected1[1] = (Lexeme){.data = 1, .actual_type = LT_OPERAND};
    expected1[2] = (Lexeme){.data = '+', .actual_type = LT_ACTION};
    
    Lexeme actual1[3];
    const int expected_length1 = 3;
    int actual_length1 = -1;
    shunting_yard_function(case1, length1, actual1, &actual_length1);
    printf("test # 1: ");
    if (expected_length1 == actual_length1 && are_equal(expected1, actual1, length1)) {
        printf("ok\n");
    } else {
        printf("FAILED\n");
    }
    
    // const char *case2 = "59 + 7 / 2";
    // const char *expected2 = "59 7 2 / +";
    
    
    const int length2 = 5;
    Lexeme case2[5];
    case2[0] = (Lexeme){.data = 59, .actual_type = LT_OPERAND};
    case2[1] = (Lexeme){.data = '+', .actual_type = LT_ACTION};
    case2[2] = (Lexeme){.data = 7, .actual_type = LT_OPERAND};
    case2[3] = (Lexeme){.data = '/', .actual_type = LT_ACTION};
    case2[4] = (Lexeme){.data = 2, .actual_type = LT_OPERAND};
    
    Lexeme expected2[5];
    expected2[0] = (Lexeme){.data = 59, .actual_type = LT_OPERAND};
    expected2[1] = (Lexeme){.data = 7, .actual_type = LT_OPERAND};
    expected2[2] = (Lexeme){.data = 2, .actual_type = LT_OPERAND};
    expected2[3] = (Lexeme){.data = '/', .actual_type = LT_ACTION};
    expected2[4] = (Lexeme){.data = '+', .actual_type = LT_ACTION};
    
    Lexeme actual2[5];
    const int expected_length2 = 5;
    int actual_length2 = -1;
    shunting_yard_function(case2, length2, actual2, &actual_length2);
    printf("test # 2: ");
    if (expected_length2 == actual_length2 && are_equal(expected2, actual2, length2)) {
        printf("ok\n");
    } else {
        printf("FAILED\n");
    }
    
    
    // const char *case3 = "( 5 + 7 ) / 2";
    // const char *expected3 = "5 7 + 2 /";
    
    {
    const int length3 = 7;
    Lexeme case3[7];
    case3[0] = (Lexeme){.data = '(', .actual_type = LT_ACTION};
    case3[1] = (Lexeme){.data = 5, .actual_type = LT_OPERAND};
    case3[2] = (Lexeme){.data = '+', .actual_type = LT_ACTION};
    case3[3] = (Lexeme){.data = 7, .actual_type = LT_OPERAND};
    case3[4] = (Lexeme){.data = ')', .actual_type = LT_ACTION};
    case3[5] = (Lexeme){.data = '/', .actual_type = LT_ACTION};
    case3[6] = (Lexeme){.data = 2, .actual_type = LT_OPERAND};
    
    Lexeme expected3[5];
    expected3[0] = (Lexeme){.data = 5, .actual_type = LT_OPERAND};
    expected3[1] = (Lexeme){.data = 7, .actual_type = LT_OPERAND};
    expected3[2] = (Lexeme){.data = '+', .actual_type = LT_ACTION};
    expected3[3] = (Lexeme){.data = 2, .actual_type = LT_OPERAND};
    expected3[4] = (Lexeme){.data = '/', .actual_type = LT_ACTION};


    Lexeme actual3[5];
    const int expected_length3 = 5;
    int actual_length3 = -1;
    shunting_yard_function(case3, length3, actual3, &actual_length3);
    printf("test # 3: ");
    if (expected_length3 == actual_length3 && are_equal(expected3, actual3, length3)) {
        printf("ok\n");
    } else {
        printf("FAILED\n");
    }
    }
    
    // const char *case4 = " 5 * 2 - 3";
    // const char *expected4 = "5 2 * 3 -";
    const int length4 = 5;
    Lexeme case4[5];
    case4[0] = (Lexeme){.data = 5, .actual_type = LT_OPERAND};
    case4[1] = (Lexeme){.data = '*', .actual_type = LT_ACTION};
    case4[2] = (Lexeme){.data = 2, .actual_type = LT_OPERAND};
    case4[3] = (Lexeme){.data = '-', .actual_type = LT_ACTION};
    case4[4] = (Lexeme){.data = 3, .actual_type = LT_OPERAND};

    
    Lexeme expected4[5];
    expected4[0] = (Lexeme){.data = 5, .actual_type = LT_OPERAND};
    expected4[1] = (Lexeme){.data = 2, .actual_type = LT_OPERAND};
    expected4[2] = (Lexeme){.data = '*', .actual_type = LT_ACTION};
    expected4[3] = (Lexeme){.data = 3, .actual_type = LT_OPERAND};
    expected4[4] = (Lexeme){.data = '-', .actual_type = LT_ACTION};
    
    Lexeme actual4[5];
    const int expected_length4 = 5;
    int actual_length4 = -1;
    shunting_yard_function(case4, length4, actual4, &actual_length4);
    printf("test # 4: ");
    if (expected_length4 == actual_length4 && are_equal(expected4, actual4, length4)) {
        printf("ok\n");
    } else {
        printf("FAILED\n");
    }
    
    
    
    
    
    // const char *case5 = " 5 * ( 2 - 3 )";
    // const char *expected5 = "5 2 3 - *";
    const int length5 = 7;
    Lexeme case5[7];
    case5[0] = (Lexeme){.data = 5, .actual_type = LT_OPERAND};
    case5[1] = (Lexeme){.data = '*', .actual_type = LT_ACTION};
    case5[2] = (Lexeme){.data = '(', .actual_type = LT_ACTION};
    case5[3] = (Lexeme){.data = 2, .actual_type = LT_OPERAND};
    case5[4] = (Lexeme){.data = '-', .actual_type = LT_ACTION};
    case5[5] = (Lexeme){.data = 3, .actual_type = LT_OPERAND};
    case5[6] = (Lexeme){.data = ')', .actual_type = LT_ACTION};
    
    Lexeme expected5[7];
    expected5[0] = (Lexeme){.data = 5, .actual_type = LT_OPERAND};
    expected5[1] = (Lexeme){.data = 2, .actual_type = LT_OPERAND};
    expected5[2] = (Lexeme){.data = 3, .actual_type = LT_OPERAND};
    expected5[3] = (Lexeme){.data = '-', .actual_type = LT_ACTION};
    expected5[4] = (Lexeme){.data = '*', .actual_type = LT_ACTION};
    
    
    Lexeme actual5[5];
    const int expected_length5 = 5;
    int actual_length5 = -1;
    shunting_yard_function(case5, length5, actual5, &actual_length5);
    printf("test # 5: ");
    if (expected_length5 == actual_length5 && are_equal(expected5, actual5, length5)) {
        printf("ok\n");
    } else {
        printf("FAILED\n");
    }
    
    
    
    // const char *case6 = " 5 * ( 2 - 3 )";
    // const char *expected6 = "5 2 3 - *";
    
    
}

int is_operand(const Lexeme* lexeme) {
    return lexeme->actual_type == LT_OPERAND;
}
int is_action(const Lexeme* lexeme) {
    return lexeme->actual_type == LT_ACTION;
}

int is_brace(const Lexeme* lexeme) {
    return lexeme->data == ')' && lexeme->data == '('; // may not work, check it
}

enum operator_precedence {
    OP_LOWEST = -1,
    OP_LOW = 0,
    OP_MEDIUM = 1,
    OP_HIGH = 2
};

int get_precenence(const Lexeme *lexeme) {
    int operand = -1;
    char action = '\0';
    get_lexeme(lexeme, &operand, &action);
    
    switch(action){
        case '(': return OP_LOWEST;
        case '+': return OP_LOW;
        case '-': return OP_LOW;
        case '*': return OP_MEDIUM;
        case '/': return OP_MEDIUM;
        case 's': return OP_HIGH;
        case 'c': return OP_HIGH;
        case 't': return OP_HIGH;
        case 'g': return OP_HIGH;
        case 'r': return OP_HIGH;
        case 'l': return OP_HIGH;
        default: return OP_LOWEST;
    };
}

int has_lower_precedence(const Lexeme *left, const Lexeme *right) {
    const int left_precedence = get_precenence(left);
    const int right_precedence = get_precenence(right);
    return left_precedence < right_precedence;
}

int has_top_higher_precedence(const Lexeme *top, const Lexeme *current_lexeme) {
    return has_lower_precedence(current_lexeme, top);
}
int is_opening_brace(const Lexeme *lexeme) {
    return lexeme->data == '(';   // may not work, check it
}
void shunting_yard(const Lexeme *infix_notation, int length, Lexeme *postfix_notation, int *length_out) {
    // print_lexeme_array(infix_notation, length);
    *length_out = length;
    int last_index_postfix_notation = 0;
    Stack_node *stack_for_actions = NULL;
    for (int index = 0; index < length; ++index) {
        const Lexeme current_lexeme = infix_notation[index];
        if (is_operand(&current_lexeme)) {
            postfix_notation[last_index_postfix_notation] = current_lexeme;
            ++last_index_postfix_notation;
            continue;
        }
        
        if (is_brace(&current_lexeme))
            --(*length_out);
    
        
        // if (!is_empty(stack_for_actions))
        
        if (!is_empty(stack_for_actions)) {
            const Lexeme action_on_the_top_of_the_stack = top(stack_for_actions);
            if (has_top_higher_precedence(&action_on_the_top_of_the_stack, &current_lexeme)) {
                postfix_notation[last_index_postfix_notation] = current_lexeme;
                ++last_index_postfix_notation;
                continue;
            }
        }
        push(&stack_for_actions, current_lexeme);
                
    }
    
    
    //  flushing what's left in stack into postfix_notation:
    while(!is_empty(stack_for_actions)) {
        const Lexeme lexeme_action = pop(&stack_for_actions);
        postfix_notation[last_index_postfix_notation] = lexeme_action;
        ++last_index_postfix_notation;
    }
    
    printf("input:\n");
    print_lexeme_array(infix_notation, length);
    printf("output:\n");
    print_lexeme_array(postfix_notation, *length_out);
}

int main() {
    // visual_test_get_lexeme(get_lexeme);
    printf("before test:\n");
    test_shunting_yard(shunting_yard);
    printf("after  test:\n");
/*
    Stack_node *stack = NULL;
    
    push(&stack, 1488);
    print_stack(stack);
    
    
    push(&stack, 228);
    print_stack(stack);
    

    push(&stack, 14);
    print_stack(stack);
    

    push(&stack, 88);
    print_stack(stack);
    
    
    
    int element = -1;
    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("from stack: %d\n", element);
        print_stack(stack);
    } else {
        printf("stack is empty, bitch!!!\n");
    }
    element = -1;
    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("from stack: %d\n", element);
        print_stack(stack);
    } else {
        printf("stack is empty, bitch!!!\n");
    }
    element = -1;
    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("from stack: %d\n", element);
        print_stack(stack);
    } else {
        printf("stack is empty, bitch!!!\n");
    }
    element = -1;
    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("from stack: %d\n", element);
        print_stack(stack);
    } else {
        printf("stack is empty, bitch!!!\n");
    }
    element = -1;
    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("from stack: %d\n", element);
        print_stack(stack);
    } else {
        printf("stack is empty, bitch!!!\n");
    }
    element = -1;
    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("from stack: %d\n", element);
        print_stack(stack);
    } else {
        printf("stack is empty, bitch!!!\n");
    }
    element = -1;
    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("from stack: %d\n", element);
        print_stack(stack);
    } else {
        printf("stack is empty, bitch!!!\n");
    }
    element = -1;
    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("from stack: %d\n", element);
        print_stack(stack);
    } else {
        printf("stack is empty, bitch!!!\n");
    }
    element = -1;
    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("from stack: %d\n", element);
        print_stack(stack);
    } else {
        printf("stack is empty, bitch!!!\n");
    }
    element = -1;
    if (!is_empty(stack)) {
        element = pop(&stack);
        printf("from stack: %d\n", element);
        print_stack(stack);
    } else {
        printf("stack is empty, bitch!!!\n");
    }
  
*/
    return 0;
}
