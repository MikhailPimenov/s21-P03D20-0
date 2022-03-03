#include "calculate_reverse_polish_notation.h"

enum error_codes {
    E_SUCCESS = 0,
    E_ZERO_DIVISION_ERROR = 1,
    E_EMPTY_STACK_ERROR = 2,
    E_INVALID_REVERSE_POLISH_NOTATION_ERROR = 3,
    E_UNKNOWN_ACTION_ERROR = 4,
    E_NEGATIVE_ARGUMENT_FOR_LOGARITHM_ERROR = 5,
    E_NEGATIVE_ARGUMENT_FOR_SQRT_ERROR = 6
};

int add(double left_operand, double right_operand, double *result) {
    *result = left_operand + right_operand; 

    return E_SUCCESS;
}
int subtract(double left_operand, double right_operand, double *result) {
    *result = left_operand - right_operand; 

    return E_SUCCESS;
}

int multiply(double left_operand, double right_operand, double *result) {
    *result = left_operand * right_operand; 

    return E_SUCCESS;
}

int divide(double left_operand, double right_operand, double *result) {
    if (are_double_equal(right_operand, 0.0, 1e-12))
        return E_ZERO_DIVISION_ERROR;
    
    *result = left_operand / right_operand; 

    return E_SUCCESS;
}
int minus(double single_operand, double *result_out) {
    *result_out = (-1.0) * single_operand;
    return E_SUCCESS;
}
int sine(double single_operand, double *result_out) {
    *result_out = sin(single_operand);
    return E_SUCCESS;
}
int cosine(double single_operand, double *result_out) {
    *result_out = cos(single_operand);
    return E_SUCCESS;
}

int tangent(double single_operand, double *result_out) {
    const double pi_constant = acos(-1.0);
    if (are_double_equal(single_operand, pi_constant / 2.0, 1e-12)) {
        return E_ZERO_DIVISION_ERROR;
    }

    *result_out = tan(single_operand);
    return E_SUCCESS;
}

int cotangent(double single_operand, double *result_out) {
    if (are_double_equal(single_operand, 0.0, 1e-12)) {
        return E_ZERO_DIVISION_ERROR;
    }

    *result_out = tan(single_operand);
    return E_SUCCESS;
}

int natural_logarithm(double single_operand, double *result_out) {
    if (single_operand < 1e-12) {
        return E_NEGATIVE_ARGUMENT_FOR_LOGARITHM_ERROR;
    }

    *result_out = log(single_operand);
    return E_SUCCESS;
}
int square_root(double single_operand, double *result_out) {
    if (single_operand < 1e-12) {
        return E_NEGATIVE_ARGUMENT_FOR_SQRT_ERROR;
    }

    *result_out = sqrt(single_operand);
    return E_SUCCESS;
}

int take_two_operands_calculate_and_push_result(Stack_node **stack, int (*function_with_two_operands)(double, double, double *)) {
    double right_operand = 0.0;
    char right_action    = '\0';

    double left_operand  = 0.0;
    char left_action     = '\0';

    
    if (is_empty(*stack)) {
        printf("Stack is empty. Nothing to pop.\n");
        return E_EMPTY_STACK_ERROR;
    }

    const Lexeme right = pop(stack);
    get_lexeme(&right, &right_operand, &right_action);
    
    // if (right_operand_should_not_be_zero && are_double_equal(right_operand, 0.0, 1e-12)) {
    //     printf("Zero-division error!\n");
    //     return E_ZERO_DIVISION_ERROR;
    // }

    if (is_empty(*stack)) {
        printf("Stack is empty. Nothing to pop.\n");
        return 0;
    }

    const Lexeme left = pop(stack);
    get_lexeme(&left, &left_operand, &left_action);

    double result_operand = 0.0;
    const int status = function_with_two_operands(left_operand, right_operand, &result_operand);
    if (status != E_SUCCESS) {
        return status;
    }

    Lexeme result_lexeme;
    set_lexeme(&result_lexeme, LT_OPERAND, result_operand, '\0');
    push(stack, result_lexeme);

    return E_SUCCESS;
}

int take_single_operand_calculate_and_push_result(Stack_node **stack, int (*function_with_single_operand)(double, double*)) {
    double single_operand = 0.0;
    char action_dummy    = '\0';

    if (is_empty(*stack)) {
        printf("Stack is empty. Nothing to pop.\n");
        return E_EMPTY_STACK_ERROR;
    }

    const Lexeme single = pop(stack);
    get_lexeme(&single, &single_operand, &action_dummy);
    
    double result_operand = 0.0;
    const int status = function_with_single_operand(single_operand, &result_operand);
    if (status != E_SUCCESS) {
        return status;
    }

    Lexeme result_lexeme;
    set_lexeme(&result_lexeme, LT_OPERAND, result_operand, '\0');
    push(stack, result_lexeme);

    return E_SUCCESS;
}




int calculate_reversed_polish_notation(const Lexeme *const postfix_notation, int length, double *result_out) {
    Stack_node *stack = NULL;

    for (int index = 0; index < length; ++index) {
        const Lexeme current_lexeme = postfix_notation[index];

        if (is_operand(&current_lexeme)) {
            push(&stack, current_lexeme);
            continue;
        }

        char current_action    = '\0';
        double current_operand = 0.0;  //  no need in that
        get_lexeme(&current_lexeme, &current_operand, &current_action);
        
        switch (current_action) {
        case '+': {
            const int status = take_two_operands_calculate_and_push_result(&stack, add);
            if (status == E_EMPTY_STACK_ERROR) {
                return E_INVALID_REVERSE_POLISH_NOTATION_ERROR;
            }
            if (status != E_SUCCESS) {
                return status;
            }
            continue;
        }
        case '-': {
            const int status = take_two_operands_calculate_and_push_result(&stack, subtract);
            if (status == E_EMPTY_STACK_ERROR) {
                return E_INVALID_REVERSE_POLISH_NOTATION_ERROR;
            }
            if (status != E_SUCCESS) {
                return status;
            }
            continue;
        }
        case '*': {
            const int status = take_two_operands_calculate_and_push_result(&stack, multiply);
            if (status == E_EMPTY_STACK_ERROR) {
                return E_INVALID_REVERSE_POLISH_NOTATION_ERROR;
            }
            if (status != E_SUCCESS) {
                return status;
            }
            continue;
        }
        case '/': {
            const int status = take_two_operands_calculate_and_push_result(&stack, divide);
            if (status == E_EMPTY_STACK_ERROR) {
                return E_INVALID_REVERSE_POLISH_NOTATION_ERROR;
            }
            if (status != E_SUCCESS) {
                return status;
            }
            continue;
        }

        case 'm': {
            const int status = take_single_operand_calculate_and_push_result(&stack, minus);
            if (status == E_EMPTY_STACK_ERROR) {
                return E_INVALID_REVERSE_POLISH_NOTATION_ERROR;
            }
            if (status != E_SUCCESS) {
                return status;
            }
            continue;
        }

        case 's': {
            const int status = take_single_operand_calculate_and_push_result(&stack, sine);
            if (status == E_EMPTY_STACK_ERROR) {
                return E_INVALID_REVERSE_POLISH_NOTATION_ERROR;
            }
            if (status != E_SUCCESS) {
                return status;
            }
            continue;
        }

        case 'c': {
            const int status = take_single_operand_calculate_and_push_result(&stack, cosine);
            if (status == E_EMPTY_STACK_ERROR) {
                return E_INVALID_REVERSE_POLISH_NOTATION_ERROR;
            }
            if (status != E_SUCCESS) {
                return status;
            }
            continue;
        }

        case 't': {
            const int status = take_single_operand_calculate_and_push_result(&stack, tangent);
            if (status == E_EMPTY_STACK_ERROR) {
                return E_INVALID_REVERSE_POLISH_NOTATION_ERROR;
            }
            if (status != E_SUCCESS) {
                return status;
            }
            continue;
        }

        case 'g': {
            const int status = take_single_operand_calculate_and_push_result(&stack, cotangent);
            if (status == E_EMPTY_STACK_ERROR) {
                return E_INVALID_REVERSE_POLISH_NOTATION_ERROR;
            }
            if (status != E_SUCCESS) {
                return status;
            }
            continue;
        }

        case 'r': {
            const int status = take_single_operand_calculate_and_push_result(&stack, square_root);
            if (status == E_EMPTY_STACK_ERROR) {
                return E_INVALID_REVERSE_POLISH_NOTATION_ERROR;
            }
            if (status != E_SUCCESS) {
                return status;
            }
            continue;
        }

        default:
            printf("COCKSUCKER!\n");
            return E_UNKNOWN_ACTION_ERROR;
        }
    }

    char action_dummy;
    const Lexeme result_lexeme = pop(&stack);
    get_lexeme(&result_lexeme, result_out, &action_dummy);

    if (!is_empty(stack)) {
        return E_INVALID_REVERSE_POLISH_NOTATION_ERROR;
    }

    return E_SUCCESS;
}