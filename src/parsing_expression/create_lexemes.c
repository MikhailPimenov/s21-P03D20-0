#include "create_lexemes.h"

static const char *recognize_sinlge_symbol_and_create_lexeme(
    const char *infix_notation_row, 
    int length_without_terminator, 
    char symbol_to_recognize,
    int not_operand_lexeme_type, 
    Lexeme *const lexeme_out,
    int *lexemes_created_out) {

    const int recognition_status = is_symbol_recognized(
        infix_notation_row,
        length_without_terminator,
        symbol_to_recognize
    );
    
    if (recognition_status != RS_RECOGNIZED) {
        return infix_notation_row;
    }

    *lexemes_created_out += 1;

    set_lexeme(lexeme_out, not_operand_lexeme_type, 0.0, symbol_to_recognize);
    return infix_notation_row + 1;
}

const char *recognize_placeholder_symbol_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out) {
    return recognize_sinlge_symbol_and_create_lexeme(infix_notation_row, length_without_terminator, 'x', LT_PLACEHOLDER, lexeme_out, lexemes_created_out);
}
const char *recognize_opening_brace_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out) {
    return recognize_sinlge_symbol_and_create_lexeme(infix_notation_row, length_without_terminator, '(', LT_BRACE, lexeme_out, lexemes_created_out);
}
const char *recognize_closing_brace_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out) {
    return recognize_sinlge_symbol_and_create_lexeme(infix_notation_row, length_without_terminator, ')', LT_BRACE, lexeme_out, lexemes_created_out);    
}
const char *recognize_add_symbol_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out) {
    return recognize_sinlge_symbol_and_create_lexeme(infix_notation_row, length_without_terminator, '+', LT_ACTION, lexeme_out, lexemes_created_out);    
}
const char *recognize_multiply_symbol_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out) {
    return recognize_sinlge_symbol_and_create_lexeme(infix_notation_row, length_without_terminator, '*', LT_ACTION, lexeme_out, lexemes_created_out);    
}
const char *recognize_divide_symbol_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out) {
    return recognize_sinlge_symbol_and_create_lexeme(infix_notation_row, length_without_terminator, '/', LT_ACTION, lexeme_out, lexemes_created_out);    
}
const char *recognize_power_symbol_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out) {
    return recognize_sinlge_symbol_and_create_lexeme(infix_notation_row, length_without_terminator, '^', LT_ACTION, lexeme_out, lexemes_created_out);    
}
int are_strings_equal(const char *left, const char *right, int length_without_terminator) {
    for (int index = 0; index < length_without_terminator; ++index) {
        int is_left_null  = (left  + index == NULL);
        int is_right_null = (right + index == NULL);

        if (is_left_null && is_right_null)
            return 1;

        if (!is_left_null && !is_right_null && left[index] != right[index])
            return 0;

    }
    return 1;
}
//  TODO: make this function available for the entire program!
char get_single_symbol_for_function(const char *function_name_as_string, int function_name_length_without_terminator) {
    if (are_strings_equal(function_name_as_string, "sin",  function_name_length_without_terminator))
        return 's';
    if (are_strings_equal(function_name_as_string, "cos",  function_name_length_without_terminator))
        return 'c';
    if (are_strings_equal(function_name_as_string, "tg",   function_name_length_without_terminator))
        return 't';
    if (are_strings_equal(function_name_as_string, "ctg",  function_name_length_without_terminator))
        return 'g';
    if (are_strings_equal(function_name_as_string, "sqrt", function_name_length_without_terminator))
        return 'r';
    if (are_strings_equal(function_name_as_string, "ln",   function_name_length_without_terminator))
        return 'l';
    
    //  function is not recognized
    return '\0';
}

static const char *recognize_function_and_create_lexeme(
    const char *infix_notation_row, 
    int length_without_terminator, 
    const char *function_name_as_string, 
    int function_name_length_without_terminator,
    Lexeme *const lexeme_out,
    int *lexeme_counter_out) {

    const int recognition_status = is_function_recognized(
                                            infix_notation_row, 
                                            length_without_terminator, 
                                            function_name_as_string, 
                                            function_name_length_without_terminator);

    if (recognition_status == RS_NOT_RECOGNIZED)
        return infix_notation_row;

    *lexeme_counter_out += 1;

    const char function_as_single_symbol = get_single_symbol_for_function(function_name_as_string, function_name_length_without_terminator);
    set_lexeme(lexeme_out, LT_ACTION, 0.0, function_as_single_symbol);

    //  returning pointer to the next position in infix_notation to recognise
    return infix_notation_row + function_name_length_without_terminator;
}

// TODO: replace everywhere "sin", 3, with struct, "tg", 2 and so on
const char *recognize_sine_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out) {
    return recognize_function_and_create_lexeme(infix_notation_row, length_without_terminator, "sin", 3, lexeme_out, lexemes_created_out);
}
const char *recognize_cosine_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out) {
    return recognize_function_and_create_lexeme(infix_notation_row, length_without_terminator, "cos", 3, lexeme_out, lexemes_created_out);
}
const char *recognize_tangent_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out) {
    return recognize_function_and_create_lexeme(infix_notation_row, length_without_terminator, "tg", 2, lexeme_out, lexemes_created_out);
}
const char *recognize_cotangent_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out) {
    return recognize_function_and_create_lexeme(infix_notation_row, length_without_terminator, "ctg", 3, lexeme_out, lexemes_created_out);
}
const char *recognize_natural_logarithm_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out) {
    return recognize_function_and_create_lexeme(infix_notation_row, length_without_terminator, "ln", 2, lexeme_out, lexemes_created_out);
}
const char *recognize_square_root_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out) {
    return recognize_function_and_create_lexeme(infix_notation_row, length_without_terminator, "sqrt", 4, lexeme_out, lexemes_created_out);
}

const char *recognize_double_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out) {
    double result = 0.0;
    int status = 1;

    const char *current_position_in_string = string_to_double(
        infix_notation_row, 
        length_without_terminator, 
        &result, 
        &status);

    if (status == CS_FAILED_CONVERSION)
        return infix_notation_row;

    set_lexeme(lexeme_out, LT_OPERAND, result, '\0');
    *lexemes_created_out += 1; 

    return current_position_in_string;
}



const char *recognize_subtract_symbol_and_create_several_lexemes_instead_of_one(
    const char *infix_notation_row,
    int length_without_terminator,
    Lexeme *const lexeme1_in_array_out,
    Lexeme *const lexeme2_in_array_out,
    Lexeme *const lexeme3_in_array_out,
    int lexemes_length,
    int *lexemes_created_out,
    int is_not_first) {

    const char symbol_to_recognize = '-';

    const int recognition_status = is_symbol_recognized(
        infix_notation_row,
        length_without_terminator,
        symbol_to_recognize
    );

    if (recognition_status != RS_RECOGNIZED) 
        return infix_notation_row;

    //  because "3-5" will be treated like "3+(-1)*5" and then converted to  3, '+', -1, '*', 5
    //  or "-(5+1)" will be treated like "(-1)*(5+1)" and then converted to -1, '*', '(',  5, '+', ')'
    const int amount_of_lexemes = is_not_first ? 3 : 2;


    // this error should be handled when calling this function, but not here
    if (*lexemes_created_out + amount_of_lexemes - 1 >= lexemes_length)
        return infix_notation_row;

    *lexemes_created_out += amount_of_lexemes;                   

    if (is_not_first)
        set_lexeme(lexeme1_in_array_out, LT_ACTION,   0.0,  '+');
    
    set_lexeme(lexeme2_in_array_out, LT_OPERAND, -1.0, '\0');
    set_lexeme(lexeme3_in_array_out, LT_ACTION,   0.0,  '*');

    return infix_notation_row + 1;
}

const char *recognize_subtract_symbol_and_create_three_lexemes_instead_of_one(
    const char *infix_notation_row,
    int length_without_terminator,
    Lexeme *const lexeme1_in_array_out,
    Lexeme *const lexeme2_in_array_out,
    Lexeme *const lexeme3_in_array_out,
    int lexemes_length,
    int *lexemes_created_out) {

    const int is_not_first = 1;
    return recognize_subtract_symbol_and_create_several_lexemes_instead_of_one(
        infix_notation_row,
        length_without_terminator,
        lexeme1_in_array_out,
        lexeme2_in_array_out,
        lexeme3_in_array_out,
        lexemes_length,
        lexemes_created_out,
        is_not_first);
}

const char *recognize_first_subtract_symbol_and_create_two_lexemes_instead_of_one(
    const char *infix_notation_row,
    int length_without_terminator,
    Lexeme *const lexeme1_in_array_out,
    Lexeme *const lexeme2_in_array_out,
    int lexemes_length,
    int *lexemes_created_out) {

    const int is_not_first = 0;
    return recognize_subtract_symbol_and_create_several_lexemes_instead_of_one(
        infix_notation_row,
        length_without_terminator,
        NULL,
        lexeme1_in_array_out,
        lexeme2_in_array_out,
        lexemes_length,
        lexemes_created_out,
        is_not_first);
}

const char *recognize_first_add_symbol_and_not_create_lexeme(const char *infix_notation_row, int length_without_terminator) {
    const int recognition_status = is_symbol_recognized(
        infix_notation_row,
        length_without_terminator,
        '+'
    );
    
    if (recognition_status != RS_RECOGNIZED) {
        return infix_notation_row;
    }

    return infix_notation_row + 1;
}

void create_lexemes(const char *infix_notation_row, int length_without_terminator, Lexeme *lexemes, int lexemes_length) {
    const char *current_position_in_string = infix_notation_row;
    
    int lexemes_created = 0;
    // printf("create_lexemes(): lexemes created: %d\n", lexemes_created);
    // printf("create_lexemes(): lexemes length : %d\n", lexemes_length);
    const int show_everything = 0;


    current_position_in_string = recognize_first_subtract_symbol_and_create_two_lexemes_instead_of_one(
        current_position_in_string,
        length_without_terminator - (current_position_in_string - infix_notation_row),
        lexemes + lexemes_created + 0,
        lexemes + lexemes_created + 1,
        lexemes_length,
        &lexemes_created);
    
    current_position_in_string = recognize_first_add_symbol_and_not_create_lexeme(
        current_position_in_string,
        length_without_terminator - (current_position_in_string - infix_notation_row));

    if (show_everything)
        printf("create_lexemes(): lexemes created: %d\n", lexemes_created);


    //  chain of responsibility design pattern
    while (lexemes_created < lexemes_length) {
        const char *old_position_in_string = current_position_in_string;

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

        if (current_position_in_string == old_position_in_string) {
            printf("Creating lexemes is done!\n");
            printf("Lexemes created: %d\n", lexemes_created);
            // printf("lexeme counted: %d\n", lexemes_created);
            // return lexemes_created;
            break;
        }
    }
    // printf("Creating lexemes is done!\n");
    // printf("Lexemes created: %d\n", lexemes_created);
}