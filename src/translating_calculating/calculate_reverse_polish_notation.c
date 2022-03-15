#include "calculate_reverse_polish_notation.h"

static int __add(double left_operand, double right_operand, double *result) {
    *result = left_operand + right_operand; 

    return C_SUCCESS;
}
static int __subtract(double left_operand, double right_operand, double *result) {
    *result = left_operand - right_operand; 

    return C_SUCCESS;
}
static int __multiply(double left_operand, double right_operand, double *result) {
    *result = left_operand * right_operand; 

    return C_SUCCESS;
}
static int __divide(double left_operand, double right_operand, double *result) {
    if (are_double_equal(right_operand, 0.0, 1e-12))
        return C_ZERO_DIVISION_ERROR;
    
    *result = left_operand / right_operand; 

    return C_SUCCESS;
}
static int __sine(double single_operand, double *result_out) {
    *result_out = sin(single_operand);
    return C_SUCCESS;
}
static int __cosine(double single_operand, double *result_out) {
    *result_out = cos(single_operand);
    return C_SUCCESS;
}
static int __tangent(double single_operand, double *result_out) {
    const double pi_constant = acos(-1.0);
    if (are_double_equal(single_operand, pi_constant / 2.0, 1e-12)) {
        return C_ZERO_DIVISION_ERROR;
    }

    *result_out = tan(single_operand);
    return C_SUCCESS;
}
static int __cotangent(double single_operand, double *result_out) {
    if (are_double_equal(single_operand, 0.0, 1e-12)) {
        return C_ZERO_DIVISION_ERROR;
    }

    *result_out = tan(single_operand);
    return C_SUCCESS;
}
static int __square_root(double single_operand, double *result_out) {
    if (single_operand < 1e-12) {
        return C_NEGATIVE_ARGUMENT_FOR_SQRT_ERROR;
    }

    *result_out = sqrt(single_operand);
    return C_SUCCESS;
}
static int __take_two_operands_calculate_and_push_result(Stack_node **stack, int (*function_with_two_operands)(double, double, double *)) {
    double right_operand = 0.0;
    char right_action    = '\0';

    double left_operand  = 0.0;
    char left_action     = '\0';

    
    if (is_empty(*stack)) {
        printf("Stack is empty. Nothing to pop.\n");
        return C_EMPTY_STACK_ERROR;
    }

    const Lexeme right = pop(stack);
    get_lexeme(&right, &right_operand, &right_action);
    
    if (is_empty(*stack)) {
        printf("Stack is empty. Nothing to pop.\n");
        return 0;
    }

    const Lexeme left = pop(stack);
    get_lexeme(&left, &left_operand, &left_action);

    double result_operand = 0.0;
    const int status = function_with_two_operands(left_operand, right_operand, &result_operand);
    if (status != C_SUCCESS) {
        return status;
    }

    Lexeme result_lexeme;
    set_lexeme(&result_lexeme, LT_OPERAND, result_operand, '\0');
    push(stack, result_lexeme);

    return C_SUCCESS;
}
static int __take_single_operand_calculate_and_push_result(Stack_node **stack, int (*function_with_single_operand)(double, double*)) {
    double single_operand = 0.0;
    char action_dummy    = '\0';

    if (is_empty(*stack)) {
        printf("Stack is empty. Nothing to pop.\n");
        return C_EMPTY_STACK_ERROR;
    }

    const Lexeme single = pop(stack);
    get_lexeme(&single, &single_operand, &action_dummy);
    
    double result_operand = 0.0;
    const int status = function_with_single_operand(single_operand, &result_operand);
    if (status != C_SUCCESS) {
        return status;
    }

    Lexeme result_lexeme;
    set_lexeme(&result_lexeme, LT_OPERAND, result_operand, '\0');
    push(stack, result_lexeme);

    return C_SUCCESS;
}

int calculate_reversed_polish_notation(const Lexeme *const postfix_notation, int length, double *result_out) {
    Stack_node *stack = NULL;

    for (int index = 0; index < length; ++index) {
        const Lexeme current_lexeme = postfix_notation[index];

        if (is_operand_or_operand_placeholder(&current_lexeme)) {
            push(&stack, current_lexeme);
            continue;
        }

        char current_action    = '\0';
        double current_operand = 0.0;  //  no need in that
        get_lexeme(&current_lexeme, &current_operand, &current_action);
        
        switch (current_action) {
            case '+': {
                const int status = __take_two_operands_calculate_and_push_result(&stack, __add);
                if (status == C_EMPTY_STACK_ERROR) {
                    return C_INVALID_REVERSE_POLISH_NOTATION_ERROR;
                }
                if (status != C_SUCCESS) {
                    return status;
                }
                continue;
            }
            case '-': {
                const int status = __take_two_operands_calculate_and_push_result(&stack, __subtract);
                if (status == C_EMPTY_STACK_ERROR) {
                    return C_INVALID_REVERSE_POLISH_NOTATION_ERROR;
                }
                if (status != C_SUCCESS) {
                    return status;
                }
                continue;
            }
            case '*': {
                const int status = __take_two_operands_calculate_and_push_result(&stack, __multiply);
                if (status == C_EMPTY_STACK_ERROR) {
                    return C_INVALID_REVERSE_POLISH_NOTATION_ERROR;
                }
                if (status != C_SUCCESS) {
                    return status;
                }
                continue;
            }
            case '/': {
                const int status = __take_two_operands_calculate_and_push_result(&stack, __divide);
                if (status == C_EMPTY_STACK_ERROR) {
                    return C_INVALID_REVERSE_POLISH_NOTATION_ERROR;
                }
                if (status != C_SUCCESS) {
                    return status;
                }
                continue;
            }

            case 's': {
                const int status = __take_single_operand_calculate_and_push_result(&stack, __sine);
                if (status == C_EMPTY_STACK_ERROR) {
                    return C_INVALID_REVERSE_POLISH_NOTATION_ERROR;
                }
                if (status != C_SUCCESS) {
                    return status;
                }
                continue;
            }

            case 'c': {
                const int status = __take_single_operand_calculate_and_push_result(&stack, __cosine);
                if (status == C_EMPTY_STACK_ERROR) {
                    return C_INVALID_REVERSE_POLISH_NOTATION_ERROR;
                }
                if (status != C_SUCCESS) {
                    return status;
                }
                continue;
            }

            case 't': {
                const int status = __take_single_operand_calculate_and_push_result(&stack, __tangent);
                if (status == C_EMPTY_STACK_ERROR) {
                    return C_INVALID_REVERSE_POLISH_NOTATION_ERROR;
                }
                if (status != C_SUCCESS) {
                    return status;
                }
                continue;
            }

            case 'g': {
                const int status = __take_single_operand_calculate_and_push_result(&stack, __cotangent);
                if (status == C_EMPTY_STACK_ERROR) {
                    return C_INVALID_REVERSE_POLISH_NOTATION_ERROR;
                }
                if (status != C_SUCCESS) {
                    return status;
                }
                continue;
            }

            case 'r': {
                const int status = __take_single_operand_calculate_and_push_result(&stack, __square_root);
                if (status == C_EMPTY_STACK_ERROR) {
                    return C_INVALID_REVERSE_POLISH_NOTATION_ERROR;
                }
                if (status != C_SUCCESS) {
                    return status;
                }
                continue;
            }

            default:
                // printf("calculate_rpn(): default:\n");
                return C_UNKNOWN_ACTION_ERROR;
        }
    }

    char action_dummy;
    const Lexeme result_lexeme = pop(&stack);
    get_lexeme(&result_lexeme, result_out, &action_dummy);

    if (!is_empty(stack)) {
        return C_INVALID_REVERSE_POLISH_NOTATION_ERROR;
    }

    return C_SUCCESS;
}