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


        current_position_in_string = recognize_double_and_count_it(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter);

        current_position_in_string = recognize_placeholder_symbol_and_count_it(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            &lexeme_counter);


        if (current_position_in_string == old_position_in_string) {
            return lexeme_counter;
        }
    }

}

void create_lexemes(const char *infix_notation_row, int length_without_terminator, Lexeme *lexemes, int lexemes_length) {
    const char *current_position_in_string = infix_notation_row;
    
    int lexemes_created = 0;
    // printf("create_lexemes(): lexemes created: %d\n", lexemes_created);
    // printf("create_lexemes(): lexemes length : %d\n", lexemes_length);
    const int show_everything = 0;
    //  chain of responsibility design pattern
    while (lexemes_created < lexemes_length) {
        // const char *old_position_in_string = current_position_in_string;

        // printf("create_lexemes(): lexemes created: %d\n", lexemes_created);

        current_position_in_string = recognize_subtract_symbol_and_create_three_lexemes_instead_of_one(
            current_position_in_string,
            length_without_terminator - (current_position_in_string - infix_notation_row),
            lexemes + lexemes_created + 0,
            lexemes + lexemes_created + 1,
            lexemes + lexemes_created + 2,
            lexemes_length,
            &lexemes_created);
        if (show_everything)
            printf("create_lexemes(): lexemes created: %d\n", lexemes_created);

        current_position_in_string = recognize_add_symbol_and_create_lexeme(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            lexemes + lexemes_created,
            &lexemes_created);
        if (show_everything)
            printf("create_lexemes(): lexemes created: %d\n", lexemes_created);


        current_position_in_string = recognize_multiply_symbol_and_create_lexeme(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            lexemes + lexemes_created,
            &lexemes_created);
        if (show_everything)
            printf("create_lexemes(): lexemes created: %d\n", lexemes_created);

        current_position_in_string = recognize_divide_symbol_and_create_lexeme(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            lexemes + lexemes_created,
            &lexemes_created);
        if (show_everything)
            printf("create_lexemes(): lexemes created: %d\n", lexemes_created);

        current_position_in_string = recognize_power_symbol_and_create_lexeme(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            lexemes + lexemes_created,
            &lexemes_created);
        if (show_everything)
            printf("create_lexemes(): lexemes created: %d\n", lexemes_created);


        current_position_in_string = recognize_opening_brace_and_create_lexeme(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            lexemes + lexemes_created,
            &lexemes_created);
        if (show_everything)
            printf("create_lexemes(): lexemes created: %d\n", lexemes_created);

        current_position_in_string = recognize_closing_brace_and_create_lexeme(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            lexemes + lexemes_created,
            &lexemes_created);
        if (show_everything)
            printf("create_lexemes(): lexemes created: %d\n", lexemes_created);


        current_position_in_string = recognize_sine_and_create_lexeme(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            lexemes + lexemes_created,
            &lexemes_created);
        if (show_everything)
            printf("create_lexemes(): lexemes created: %d\n", lexemes_created);

        current_position_in_string = recognize_cosine_and_create_lexeme(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            lexemes + lexemes_created,
            &lexemes_created);
        if (show_everything)
            printf("create_lexemes(): lexemes created: %d\n", lexemes_created);

        current_position_in_string = recognize_tangent_and_create_lexeme(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            lexemes + lexemes_created,
            &lexemes_created);
        if (show_everything)
            printf("create_lexemes(): lexemes created: %d\n", lexemes_created);

        current_position_in_string = recognize_cotangent_and_create_lexeme(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            lexemes + lexemes_created,
            &lexemes_created);
        if (show_everything)
            printf("create_lexemes(): lexemes created: %d\n", lexemes_created);

        current_position_in_string = recognize_square_root_and_create_lexeme(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            lexemes + lexemes_created,
            &lexemes_created);
        if (show_everything)
            printf("create_lexemes(): lexemes created: %d\n", lexemes_created);

        current_position_in_string = recognize_natural_logarithm_and_create_lexeme(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            lexemes + lexemes_created,
            &lexemes_created);
        if (show_everything)
            printf("create_lexemes(): lexemes created: %d\n", lexemes_created);


        current_position_in_string = recognize_double_and_create_lexeme(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            lexemes + lexemes_created,
            &lexemes_created);
        if (show_everything)
            printf("create_lexemes(): lexemes created: %d\n", lexemes_created);

        current_position_in_string = recognize_placeholder_symbol_and_create_lexeme(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row),
            lexemes + lexemes_created,
            &lexemes_created);
        if (show_everything)
            printf("create_lexemes(): lexemes created: %d\n", lexemes_created);

        // if (current_position_in_string == old_position_in_string) {
        //     printf("Creating lexemes is done!\n");
        //     printf("Lexemes created: %d\n", lexemes_created);
        //     // printf("lexeme counted: %d\n", lexemes_created);
        //     // return lexemes_created;
        //     break;
        // }
    }
    // printf("Creating lexemes is done!\n");
    // printf("Lexemes created: %d\n", lexemes_created);
}

void parse_to_lexemes_allocate(const char *infix_notation_row, int length_without_terminator, Lexeme **infix_notation_out, int *lexeme_list_length_out) {
    // printf("parse_to_lexemes_allocate():\n");
    // printf("%s\n", infix_notation_row);
    // printf("length = %d\n", length_without_terminator);

    // if (infix_notation_out)
    //     infix_notation_out = NULL;
    // *lexeme_list_length_out = 0;
   
    const int amount_of_lexemes = get_amount_of_lexemes(infix_notation_row, length_without_terminator);
    // printf("amount = %d\n", amount_of_lexemes);

    Lexeme *lexemes = malloc(amount_of_lexemes * sizeof(Lexeme));
    if (lexemes == NULL) {
        *lexeme_list_length_out = 0;
        *infix_notation_out = NULL;
        return;
    }

    create_lexemes(infix_notation_row, length_without_terminator, lexemes, amount_of_lexemes);

    // print_lexeme_array(lexemes, amount_of_lexemes);
    // printf("pointer to pointer = %p\n", infix_notation_out);
    *infix_notation_out = lexemes;
    *lexeme_list_length_out = amount_of_lexemes;
    // printf("pointer = %p\n", *infix_notation_out);
    // print_lexeme_array(*infix_notation_out, amount_of_lexemes);
    // *lexeme_list_length_out = amount_of_lexemes;
}