#include "parse_to_lexemes.h"


int get_amount_of_lexemes(const char *infix_notation_row, int length_without_terminator) {
    const char *current_position_in_string = infix_notation_row;
    
    int lexeme_counter = 0;
    //  chain of responsibility design pattern
    while (1) {
        const char *old_position_in_string = current_position_in_string;

        current_position_in_string = recognize_add_symbol_and_count_it(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter);

        current_position_in_string = recognize_subtract_symbol_and_count_it(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter);

        current_position_in_string = recognize_multiply_symbol_and_count_it(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter);

        current_position_in_string = recognize_divide_symbol_and_count_it(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter);

        current_position_in_string = recognize_power_symbol_and_count_it(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter);


        current_position_in_string = recognize_opening_brace_and_count_it(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter);

        current_position_in_string = recognize_closing_brace_and_count_it(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter);


        current_position_in_string = recognize_sine_and_count_it(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter);

        current_position_in_string = recognize_cosine_and_count_it(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter);

        current_position_in_string = recognize_tangent_and_count_it(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter);

        current_position_in_string = recognize_cotangent_and_count_it(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter);

        current_position_in_string = recognize_square_root_and_count_it(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter);

        current_position_in_string = recognize_natural_logarithm_and_count_it(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter);


        current_position_in_string = recognize_double_and_create_lexeme(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter);

        current_position_in_string = recognize_placeholder_symbol_and_count_it(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter);


        if (current_position_in_string == old_position_in_string) {
            printf("Done!\n");
            printf("lexeme counted: %d\n", lexeme_counter);
            return lexeme_counter;
        }
    }

}

void create_lexemes(const char *infix_notation_row, int length_without_terminator, Lexeme *lexemes, int lexemes_length) {
    const char *current_position_in_string = infix_notation_row;
    
    int lexeme_counter = 0;
    //  chain of responsibility design pattern
    while (1) {
        const char *old_position_in_string = current_position_in_string;

        current_position_in_string = recognize_add_symbol_and_create_lexeme(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter);

        current_position_in_string = recognize_subtract_symbol_and_create_lexeme(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter);

        current_position_in_string = recognize_multiply_symbol_and_create_lexeme(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter);

        current_position_in_string = recognize_divide_symbol_and_create_lexeme(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter);

        current_position_in_string = recognize_power_symbol_and_create_lexeme(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter);


        current_position_in_string = recognize_opening_brace_and_create_lexeme(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter);

        current_position_in_string = recognize_closing_brace_and_create_lexeme(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter);


        current_position_in_string = recognize_sine_and_create_lexeme(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter);

        current_position_in_string = recognize_cosine_and_create_lexeme(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter);

        current_position_in_string = recognize_tangent_and_create_lexeme(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter);

        current_position_in_string = recognize_cotangent_and_create_lexeme(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter);

        current_position_in_string = recognize_square_root_and_create_lexeme(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter);

        current_position_in_string = recognize_natural_logarithm_and_create_lexeme(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter);


        current_position_in_string = recognize_double_and_create_lexeme(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter);

        current_position_in_string = recognize_placeholder_symbol_and_create_lexeme(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter);


        if (current_position_in_string == old_position_in_string) {
            printf("Done!\n");
            printf("lexeme counted: %d\n", lexeme_counter);
            return lexeme_counter;
        }
    }
}

void parse_to_lexemes_allocate(const char *infix_notation_row, int length_without_terminator, Lexeme **infix_notation_out, int *lexeme_list_length_out) {
    printf("parse_to_lexemes_allocate():\n");
    printf("%s\n", infix_notation_row);
    printf("length = %d\n", length_without_terminator);

    if (infix_notation_out)
        infix_notation_out = NULL;
    *lexeme_list_length_out = 0;
   
    const int amount_of_lexemes = get_amount_of_lexemes(infix_notation_row, length_without_terminator);
    printf("amount = %d\n", amount_of_lexemes);

    // Lexeme *lexemes = malloc(amount_of_lexemes * sizeof(Lexeme));
    // if (lexemes == NULL) {
    //     *lexeme_list_length_out = 0;
    //     *infix_notation_out = NULL;
    //     return;
    // }

    // create_lexemes(infix_notation_row, length_without_terminator, lexemes, amount_of_lexemes);
}