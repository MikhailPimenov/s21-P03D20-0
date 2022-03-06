#include "create_lexemes.h"

// int is_symbol_recognized(
//     const char *infix_notation_row, 
//     int length_without_terminator, 
//     char symbol_to_recognize) {

//     if (length_without_terminator < 1) 
//         return RS_NOT_RECOGNIZED;

//     if (infix_notation_row[0] != symbol_to_recognize)
//         return RS_NOT_RECOGNIZED;

//     return RS_RECOGNIZED;
// }

const char *recognize_sinlge_symbol_and_create_lexeme(
    const char *infix_notation_row, 
    int length_without_terminator, 
    char symbol_to_recognize, 
    Lexeme *const lexeme_out,
    int *lexemes_created_out) {

    const int recognition_status = is_symbol_recognized(
        infix_notation_row,
        length_without_terminator,
        symbol_to_recognize
    );
    
    if (recognition_status != RS_RECOGNIZED) {
        // printf("%c is not recognized, bitch\n", symbol_to_recognize);
        return infix_notation_row;
    }

    printf("%c\n", symbol_to_recognize);
    *lexemes_created_out += 1;


    if (symbol_to_recognize == 'x') {
        set_lexeme(lexeme_out, LT_OPERAND_PLACEHOLDER, 0.0, '\0');  
        return infix_notation_row + 1;
    }

    set_lexeme(lexeme_out, LT_ACTION, 0.0, symbol_to_recognize);

    // TODO: YOU ENDED HERE!! TRYING TO FIGURE OUT, HOW TO CREATE 5 LEXEMES INSDEAT OF ONE!!!

    // if (symbol_to_recognize == '-')
        // *lexeme_counter_out += 4;   //  because "3-5" will be treated like "3+(-1)*5" and then converted to  3, '+', '(', -1, ')', '*', 5

    return infix_notation_row + 1;
}

const char *recognize_placeholder_symbol_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out) {
    return recognize_sinlge_symbol_and_create_lexeme(infix_notation_row, length_without_terminator, 'x', lexeme_out, lexemes_created_out);
}

const char *recognize_opening_brace_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out) {
    return recognize_sinlge_symbol_and_create_lexeme(infix_notation_row, length_without_terminator, '(', lexeme_out, lexemes_created_out);
}
const char *recognize_closing_brace_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out) {
    return recognize_sinlge_symbol_and_create_lexeme(infix_notation_row, length_without_terminator, ')', lexeme_out, lexemes_created_out);    
}
const char *recognize_add_symbol_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out) {
    printf("trying to recognize '+'\n");
    printf("current first symbol is %c\n", infix_notation_row[0]);
    return recognize_sinlge_symbol_and_create_lexeme(infix_notation_row, length_without_terminator, '+', lexeme_out, lexemes_created_out);    
}

const char *recognize_multiply_symbol_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out) {
    return recognize_sinlge_symbol_and_create_lexeme(infix_notation_row, length_without_terminator, '*', lexeme_out, lexemes_created_out);    
}
const char *recognize_divide_symbol_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out) {
    return recognize_sinlge_symbol_and_create_lexeme(infix_notation_row, length_without_terminator, '/', lexeme_out, lexemes_created_out);    
}
const char *recognize_power_symbol_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out) {
    return recognize_sinlge_symbol_and_create_lexeme(infix_notation_row, length_without_terminator, '^', lexeme_out, lexemes_created_out);    
}



// int is_function_recognized(
//     const char *infix_notation_row, 
//     int length_without_terminator, 
//     const char *function_name_as_string, 
//     int function_name_length_without_terminator) {

//     //  the end of infix_notation is closer than the end of possible function_name in it
//     if (length_without_terminator < function_name_length_without_terminator + 1)
//         return RS_NOT_RECOGNIZED;

//     //  the symbols and their order in infix_notation are exactly the same as in possible function_name
//     for (int index = 0; index < function_name_length_without_terminator; ++index)
//         if (infix_notation_row[index] != function_name_as_string[index])
//             return RS_NOT_RECOGNIZED;

//     //  after function name there should be opening brace
//     if (infix_notation_row[function_name_length_without_terminator] != '(')  //  could have used recognise_single_symbol function
//         return RS_NOT_RECOGNIZED;
    
//     return RS_RECOGNIZED;
// }

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
    if (are_strings_equal(function_name_as_string, "sin", function_name_length_without_terminator))
        return 's';
    if (are_strings_equal(function_name_as_string, "cos", function_name_length_without_terminator))
        return 'c';
    if (are_strings_equal(function_name_as_string, "tg", function_name_length_without_terminator))
        return 't';
    if (are_strings_equal(function_name_as_string, "ctg", function_name_length_without_terminator))
        return 'g';
    if (are_strings_equal(function_name_as_string, "sqrt", function_name_length_without_terminator))
        return 'r';
    if (are_strings_equal(function_name_as_string, "ln", function_name_length_without_terminator))
        return 'l';
    
    //  function is not recognized
    return '\0';
}

const char *recognize_function_and_create_lexeme(
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


    printf("%s\n", function_name_as_string);
    *lexeme_counter_out += 1;

    const char function_as_single_symbol = get_single_symbol_for_function(function_name_as_string, function_name_length_without_terminator);
    set_lexeme(lexeme_out, LT_ACTION, 0.0, function_as_single_symbol);

    //  returning pointer to the next position in infix_notation to recognise
    return infix_notation_row + function_name_length_without_terminator;
}
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

    printf("double created: %lf\n", result);
    set_lexeme(lexeme_out, LT_OPERAND, result, '\0');
    *lexemes_created_out += 1; 


    if (current_position_in_string == infix_notation_row)
        printf("double(): position is not changed!\n");

    return current_position_in_string;
}



const char *recognize_subtract_symbol_and_create_three_lexemes_instead_of_one(
    const char *infix_notation_row, 
    int length_without_terminator, 
    Lexeme *const lexeme1_in_array_out, 
    Lexeme *const lexeme2_in_array_out, 
    Lexeme *const lexeme3_in_array_out, 
    int lexemes_length,
    int *lexemes_created_out) {

    const char symbol_to_recognize = '-';

    const int recognition_status = is_symbol_recognized(
        infix_notation_row,
        length_without_terminator,
        symbol_to_recognize
    );

    if (recognition_status != RS_RECOGNIZED) 
        return infix_notation_row;

    // this error should be handled when calling this function, but not here
    if (*lexemes_created_out + 2 >= lexemes_length) {
        printf("already created = %d, lexemes_length = %d\n", *lexemes_created_out, lexemes_length);
        printf("Error: not enough memory to create three lexemes for '-'.\n");
        return infix_notation_row;
    }

    printf("symbol '-' is recognized and created three lexemes\n");
    
    *lexemes_created_out += 3;                   //  because "3-5" will be treated like "3+(-1)*5" and then converted to  3, '+', -1, '*', 5


    set_lexeme(lexeme1_in_array_out, LT_ACTION,   0.0,  '+');
    set_lexeme(lexeme2_in_array_out, LT_OPERAND, -1.0, '\0');
    set_lexeme(lexeme3_in_array_out, LT_ACTION,   0.0,  '*');


    return infix_notation_row + 1;
}