#include "check_expression_and_count_lexemes.h"


void push_to_stack(Stack_node **stack, char element) {
    Lexeme lexeme;
    set_lexeme(&lexeme, LT_BRACE, 0.0, element);
    push(stack, lexeme);
}
char pop_from_stack(Stack_node **stack) {
    const Lexeme lexeme = pop(stack);
    double operand = 0.0;
    char action = '\0';
    get_lexeme(&lexeme, &operand, &action);

    return action;
}
int check_brace_sequence(const char *brace_sequence, int length_without_terminator) {
    static const char opening_brace = '(';
    static const char closing_brace = ')';

    Stack_node *stack = NULL;

    int result = EC_EXPRESSION_IS_CORRECT;
    for (int index = 0; index < length_without_terminator; ++index) {
        const char symbol = brace_sequence[index];
        if (symbol != opening_brace && symbol != closing_brace)
            continue;

        if (symbol == opening_brace) {
            push_to_stack(&stack, symbol);
            continue;    
        }

        if (is_empty(stack)) {
            result = EC_EXPRESSION_IS_NOT_CORRECT;
            break;
        }

        pop_from_stack(&stack);
    }

    if (!is_empty(stack))
        result = EC_EXPRESSION_IS_NOT_CORRECT;

    destroy(&stack);

    return result;
}

// typedef struct Recognized_lexeme_types {
//     int is_unary_action_recognized    = 0;
//     int is_binary_action_recognized   = 0;
//     int is_brace_recognized           = 0;
//     int is_operand_recognized         = 0;
//     int is_previous_an_binary_action  = 0;
//     int is_previous_an_unary_action   = 0;
//     int is_previous_an_operand        = 0;
//     int is_previous_an_brace          = 0;
//     int is_first_lexeme               = 1; 
// } Recognized_lexeme_types;

int check_expression_and_count_lexemes(const char *infix_notation_row, int length_without_terminator, int *amount_of_lexemes_out) {

    const int status_check_brace_sequence = check_brace_sequence(infix_notation_row, length_without_terminator);
    if (status_check_brace_sequence == EC_EXPRESSION_IS_NOT_CORRECT)
        return EC_EXPRESSION_IS_NOT_CORRECT; 

    const char *current_position_in_string = infix_notation_row;
    *amount_of_lexemes_out = -1;

    int lexeme_counter                = 0;
    int is_unary_action_recognized    = 0;
    int is_binary_action_recognized   = 0;
    int is_brace_recognized           = 0;
    int is_operand_recognized         = 0;
    int is_previous_an_binary_action  = 0;
    int is_previous_an_unary_action   = 0;
    int is_previous_an_operand        = 0;
    int is_previous_an_brace          = 0;
    int is_first_lexeme               = 1; 
   
    if (is_previous_an_brace){
        ;
    }


    current_position_in_string = recognize_first_add_symbol_and_count_it(
        current_position_in_string,
        length_without_terminator,
        &lexeme_counter,
        &is_binary_action_recognized);

    if (is_binary_action_recognized) {
        is_previous_an_operand       = 0;
        is_previous_an_unary_action  = 0;
        is_previous_an_binary_action = 1;
        is_previous_an_brace         = 0;
        is_binary_action_recognized  = 0;
    }


    current_position_in_string = recognize_first_subtract_symbol_and_count_it(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter,
            &is_binary_action_recognized);

    if (is_binary_action_recognized && is_previous_an_binary_action) {
            // printf("return #0\n");
        return EC_EXPRESSION_IS_NOT_CORRECT;    
    }

    if (is_binary_action_recognized) {
        is_previous_an_operand       = 0;
        is_previous_an_unary_action  = 0;
        is_previous_an_binary_action = 1;
        is_previous_an_brace         = 0;
        is_binary_action_recognized  = 0;
    }


    //  chain of responsibility design pattern
    while (1) {
        const char *old_position_in_string = current_position_in_string;

        current_position_in_string = recognize_add_symbol_and_count_it(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter,
            &is_binary_action_recognized);

        if (is_binary_action_recognized && is_previous_an_binary_action) {
            // printf("return #1\n");
            return EC_EXPRESSION_IS_NOT_CORRECT;    
        }

        if (is_binary_action_recognized) {
            is_previous_an_operand       = 0;
            is_previous_an_unary_action  = 0;
            is_previous_an_binary_action = 1;
            is_previous_an_brace         = 0;
            is_binary_action_recognized  = 0;
        }

        current_position_in_string = recognize_subtract_symbol_and_count_it(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter,
            &is_binary_action_recognized);

        if (is_binary_action_recognized && is_previous_an_binary_action) {
            // printf("return #2\n");
            return EC_EXPRESSION_IS_NOT_CORRECT;    
        }

        if (is_binary_action_recognized) {
            is_previous_an_operand       = 0;
            is_previous_an_unary_action  = 0;
            is_previous_an_binary_action = 1;
            is_previous_an_brace         = 0;
            is_binary_action_recognized  = 0;
        }

        current_position_in_string = recognize_multiply_symbol_and_count_it(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter,
            &is_binary_action_recognized);

        if (is_binary_action_recognized && (is_previous_an_binary_action || is_first_lexeme)) {
            // printf("return #3\n");
            return EC_EXPRESSION_IS_NOT_CORRECT; 
        }

        if (is_binary_action_recognized) {
            is_previous_an_operand       = 0;
            is_previous_an_unary_action  = 0;
            is_previous_an_binary_action = 1;
            is_previous_an_brace         = 0;
            is_binary_action_recognized  = 0;
        }

        current_position_in_string = recognize_divide_symbol_and_count_it(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter,
            &is_binary_action_recognized);

        if (is_binary_action_recognized && (is_previous_an_binary_action || is_first_lexeme)) {
            // printf("return #4\n");
            return EC_EXPRESSION_IS_NOT_CORRECT;    
        }   

        if (is_binary_action_recognized) {
            is_previous_an_operand       = 0;
            is_previous_an_unary_action  = 0;
            is_previous_an_binary_action = 1;
            is_previous_an_brace         = 0;
            is_binary_action_recognized  = 0;
        }

        current_position_in_string = recognize_power_symbol_and_count_it(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter,
            &is_binary_action_recognized);

        if (is_binary_action_recognized && (is_previous_an_binary_action || is_first_lexeme)) {
            // printf("return #5\n");
            return EC_EXPRESSION_IS_NOT_CORRECT;    
        }    

        if (is_binary_action_recognized) {
            is_previous_an_operand       = 0;
            is_previous_an_unary_action  = 0;
            is_previous_an_binary_action = 1;
            is_previous_an_brace         = 0;
            is_binary_action_recognized  = 0;
        }

        current_position_in_string = recognize_sine_and_count_it(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter,
            &is_unary_action_recognized);

        if (is_unary_action_recognized && is_previous_an_unary_action) {
            // printf("return #6\n");
            return EC_EXPRESSION_IS_NOT_CORRECT;    
        }    

        if (is_unary_action_recognized) {
            is_previous_an_operand        = 0;
            is_previous_an_unary_action   = 1;
            is_previous_an_binary_action  = 0;
            is_previous_an_brace          = 0;
            is_unary_action_recognized    = 0;
        }

        current_position_in_string = recognize_cosine_and_count_it(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter,
            &is_binary_action_recognized);

        if (is_unary_action_recognized && is_previous_an_unary_action) {
            // printf("return #7\n");
            return EC_EXPRESSION_IS_NOT_CORRECT;    
        }    

        if (is_unary_action_recognized) {
            is_previous_an_operand        = 0;
            is_previous_an_unary_action   = 1;
            is_previous_an_binary_action  = 0;
            is_previous_an_brace          = 0;
            is_unary_action_recognized    = 0;
        }

        current_position_in_string = recognize_tangent_and_count_it(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter,
            &is_binary_action_recognized);

        if (is_unary_action_recognized && is_previous_an_unary_action) {
            // printf("return #8\n");
            return EC_EXPRESSION_IS_NOT_CORRECT;    
        }    

        if (is_unary_action_recognized) {
            is_previous_an_operand        = 0;
            is_previous_an_unary_action   = 1;
            is_previous_an_binary_action  = 0;
            is_previous_an_brace          = 0;
            is_unary_action_recognized    = 0;
        }

        current_position_in_string = recognize_cotangent_and_count_it(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter,
            &is_binary_action_recognized);

        if (is_unary_action_recognized && is_previous_an_unary_action) {
            // printf("return #9\n");
            return EC_EXPRESSION_IS_NOT_CORRECT;    
        }    

        if (is_unary_action_recognized) {
            is_previous_an_operand        = 0;
            is_previous_an_unary_action   = 1;
            is_previous_an_binary_action  = 0;
            is_previous_an_brace          = 0;
            is_unary_action_recognized    = 0;
        }

        current_position_in_string = recognize_square_root_and_count_it(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter,
            &is_binary_action_recognized);

        if (is_unary_action_recognized && is_previous_an_unary_action) {
            // printf("return #10\n");
            return EC_EXPRESSION_IS_NOT_CORRECT;    
        }    

        if (is_unary_action_recognized) {
            is_previous_an_operand        = 0;
            is_previous_an_unary_action   = 1;
            is_previous_an_binary_action  = 0;
            is_previous_an_brace          = 0;
            is_unary_action_recognized    = 0;
        }

        current_position_in_string = recognize_natural_logarithm_and_count_it(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter,
            &is_binary_action_recognized);

        if (is_unary_action_recognized && is_previous_an_unary_action) {
            // printf("return #11\n");
            return EC_EXPRESSION_IS_NOT_CORRECT;    
        }    

        if (is_unary_action_recognized) {
            is_previous_an_operand        = 0;
            is_previous_an_unary_action   = 1;
            is_previous_an_binary_action  = 0;
            is_previous_an_brace          = 0;
            is_unary_action_recognized    = 0;
        }

        current_position_in_string = recognize_opening_brace_and_count_it(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter,
            &is_brace_recognized);

        if (is_brace_recognized) {
            is_previous_an_operand        = 0;
            is_previous_an_unary_action   = 0;
            is_previous_an_binary_action  = 0;
            is_previous_an_brace          = 1;
            is_brace_recognized           = 0;
        }

        current_position_in_string = recognize_closing_brace_and_count_it(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter,
            &is_brace_recognized);

        if (is_brace_recognized) {
            is_previous_an_operand        = 0;
            is_previous_an_unary_action   = 0;
            is_previous_an_binary_action  = 0;
            is_previous_an_brace          = 1;
            is_brace_recognized           = 0;
        }


        current_position_in_string = recognize_double_and_count_it(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter,
            &is_operand_recognized);

        if (is_operand_recognized && is_previous_an_operand) {
            // printf("return double\n");
            return EC_EXPRESSION_IS_NOT_CORRECT;
        }

        if (is_operand_recognized) {
            is_previous_an_operand        = 1;
            is_previous_an_unary_action   = 0;
            is_previous_an_binary_action  = 0;
            is_previous_an_brace          = 0;
            is_operand_recognized         = 0;

            is_first_lexeme               = 0;
        }


        current_position_in_string = recognize_placeholder_symbol_and_count_it(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter,
            &is_operand_recognized);

        if (is_operand_recognized && is_previous_an_operand) { 
            // printf("return operand\n");
            return EC_EXPRESSION_IS_NOT_CORRECT;
        }

        if (is_operand_recognized) {
            is_previous_an_operand        = 1;
            is_previous_an_unary_action   = 0;
            is_previous_an_binary_action  = 0;
            is_previous_an_brace          = 0;
            is_operand_recognized         = 0;

            is_first_lexeme               = 0; 
        }

        if (current_position_in_string == old_position_in_string) {
            break;
        }
    }
    
    if (current_position_in_string - infix_notation_row < length_without_terminator) {
        // printf("return break\n");
        return EC_EXPRESSION_IS_NOT_CORRECT;
    }
    // printf("Congratulations! String is correct.\n");
    *amount_of_lexemes_out = lexeme_counter;
    return EC_EXPRESSION_IS_CORRECT;
}