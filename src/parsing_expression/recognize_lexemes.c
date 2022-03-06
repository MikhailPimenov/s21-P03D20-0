#include "recognize_lexemes.h"

int is_symbol_recognized(
    const char *infix_notation_row, 
    int length_without_terminator, 
    char symbol_to_recognize) {

    if (length_without_terminator < 1) {
        // printf("%c is not recognized because of lack of length, bitch\n", symbol_to_recognize);
        return RS_NOT_RECOGNIZED;
        
    }

    if (infix_notation_row[0] != symbol_to_recognize) {
        // printf("%c is not recognized because you are shit, bitch\n", symbol_to_recognize);
        return RS_NOT_RECOGNIZED;
    }

    return RS_RECOGNIZED;
}

const char *recognize_sinlge_symbol_and_count_it(
    const char *infix_notation_row, 
    int length_without_terminator, 
    char symbol_to_recognize, 
    int *lexeme_counter_out) {

    const int recognition_status = is_symbol_recognized(
        infix_notation_row,
        length_without_terminator,
        symbol_to_recognize
    );

    if (recognition_status != RS_RECOGNIZED) 
        return infix_notation_row;

    printf("%c\n", symbol_to_recognize);
    *lexeme_counter_out += 1;
    
    if (symbol_to_recognize == '-')
        *lexeme_counter_out += 2;   //  because "3-5" will be treated like "3+(-1)*5" and then converted to  3, '+', -1, '*', 5

    return infix_notation_row + 1;
}

const char *recognize_placeholder_symbol_and_count_it(const char *infix_notation_row, int length_without_terminator, int *lexeme_counter_out) {
    return recognize_sinlge_symbol_and_count_it(infix_notation_row, length_without_terminator, 'x', lexeme_counter_out);
}
const char *recognize_opening_brace_and_count_it(const char *infix_notation_row, int length_without_terminator, int *lexeme_counter_out) {
    return recognize_sinlge_symbol_and_count_it(infix_notation_row, length_without_terminator, '(', lexeme_counter_out);
}
const char *recognize_closing_brace_and_count_it(const char *infix_notation_row, int length_without_terminator, int *lexeme_counter_out) {
    return recognize_sinlge_symbol_and_count_it(infix_notation_row, length_without_terminator, ')', lexeme_counter_out);    
}
const char *recognize_add_symbol_and_count_it(const char *infix_notation_row, int length_without_terminator, int *lexeme_counter_out) {
    return recognize_sinlge_symbol_and_count_it(infix_notation_row, length_without_terminator, '+', lexeme_counter_out);    
}
const char *recognize_subtract_symbol_and_count_it(const char *infix_notation_row, int length_without_terminator, int *lexeme_counter_out) {
    return recognize_sinlge_symbol_and_count_it(infix_notation_row, length_without_terminator, '-', lexeme_counter_out);    
}
const char *recognize_multiply_symbol_and_count_it(const char *infix_notation_row, int length_without_terminator, int *lexeme_counter_out) {
    return recognize_sinlge_symbol_and_count_it(infix_notation_row, length_without_terminator, '*', lexeme_counter_out);    
}
const char *recognize_divide_symbol_and_count_it(const char *infix_notation_row, int length_without_terminator, int *lexeme_counter_out) {
    return recognize_sinlge_symbol_and_count_it(infix_notation_row, length_without_terminator, '/', lexeme_counter_out);    
}
const char *recognize_power_symbol_and_count_it(const char *infix_notation_row, int length_without_terminator, int *lexeme_counter_out) {
    return recognize_sinlge_symbol_and_count_it(infix_notation_row, length_without_terminator, '^', lexeme_counter_out);    
}



int is_function_recognized(
    const char *infix_notation_row, 
    int length_without_terminator, 
    const char *function_name_as_string, 
    int function_name_length_without_terminator) {

    //  the end of infix_notation is closer than the end of possible function_name in it
    if (length_without_terminator < function_name_length_without_terminator + 1)
        return RS_NOT_RECOGNIZED;

    //  the symbols and their order in infix_notation are exactly the same as in possible function_name
    for (int index = 0; index < function_name_length_without_terminator; ++index)
        if (infix_notation_row[index] != function_name_as_string[index])
            return RS_NOT_RECOGNIZED;

    //  after function name there should be opening brace
    if (infix_notation_row[function_name_length_without_terminator] != '(')  //  could have used recognise_single_symbol function
        return RS_NOT_RECOGNIZED;
    
    return RS_RECOGNIZED;
}

const char *recognize_function_and_count_it(
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
const char *recognize_sine_and_count_it(const char *infix_notation_row, int length_without_terminator, int *lexeme_counter_out) {
    return recognize_function_and_count_it(infix_notation_row, length_without_terminator, "sin", 3, lexeme_counter_out);
}
const char *recognize_cosine_and_count_it(const char *infix_notation_row, int length_without_terminator, int *lexeme_counter_out) {
    return recognize_function_and_count_it(infix_notation_row, length_without_terminator, "cos", 3, lexeme_counter_out);
}
const char *recognize_tangent_and_count_it(const char *infix_notation_row, int length_without_terminator, int *lexeme_counter_out) {
    return recognize_function_and_count_it(infix_notation_row, length_without_terminator, "tg", 2, lexeme_counter_out);
}
const char *recognize_cotangent_and_count_it(const char *infix_notation_row, int length_without_terminator, int *lexeme_counter_out) {
    return recognize_function_and_count_it(infix_notation_row, length_without_terminator, "ctg", 3, lexeme_counter_out);
}
const char *recognize_natural_logarithm_and_count_it(const char *infix_notation_row, int length_without_terminator, int *lexeme_counter_out) {
    return recognize_function_and_count_it(infix_notation_row, length_without_terminator, "ln", 2, lexeme_counter_out);
}
const char *recognize_square_root_and_count_it(const char *infix_notation_row, int length_without_terminator, int *lexeme_counter_out) {
    return recognize_function_and_count_it(infix_notation_row, length_without_terminator, "sqrt", 4, lexeme_counter_out);
}



const char *recognize_double_and_count_it(const char *infix_notation_row, int length_without_terminator, int *lexeme_counter_out) {
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
    *lexeme_counter_out += 1; 

    return current_position_in_string;
}