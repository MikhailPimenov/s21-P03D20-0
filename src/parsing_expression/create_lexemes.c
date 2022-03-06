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

    if (recognition_status != RS_RECOGNIZED) 
        return infix_notation_row;

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

const char *recognize_function_and_create_lexeme(
    const char *infix_notation_row, 
    int length_without_terminator, 
    const char *function_name_as_string, 
    int function_name_length_without_terminator,
    int *lexeme_counter_out
    ) {

    const int recognition_status = is_function_recognized(
                                            infix_notation_row, 
                                            length_without_terminator, 
                                            function_name_as_string, 
                                            function_name_length_without_terminator);

    if (recognition_status == RS_NOT_RECOGNIZED)
        return infix_notation_row;


    printf("%s\n", function_name_as_string);
    *lexeme_counter_out += 1;

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

    printf("%lf\n", result);
    *lexemes_created_out += 1; 

    return current_position_in_string;
}



const char *recognize_subtract_symbol_and_create_five_lexemes_instead_of_one(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out) {
    return recognize_sinlge_symbol_and_create_lexeme(infix_notation_row, length_without_terminator, '-', lexeme_out, lexemes_created_out);    
}