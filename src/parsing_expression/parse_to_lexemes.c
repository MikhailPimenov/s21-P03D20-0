#include "parse_to_lexemes.h"


const char *recognize_sinlge_symbol(const char *infix_notation_row, int length_without_terminator, char symbol_to_recognize) {
    if (length_without_terminator < 1) 
        return infix_notation_row;

    if (infix_notation_row[0] != symbol_to_recognize)
        return infix_notation_row;

    printf("%c\n", symbol_to_recognize);
    return infix_notation_row + 1;
}

const char *recognize_placeholder_symbol(const char *infix_notation_row, int length_without_terminator) {
    return recognize_sinlge_symbol(infix_notation_row, length_without_terminator, 'x');
}

const char *recognize_opening_brace(const char *infix_notation_row, int length_without_terminator) {
    return recognize_sinlge_symbol(infix_notation_row, length_without_terminator, '(');
}
const char *recognize_closing_brace(const char *infix_notation_row, int length_without_terminator) {
    return recognize_sinlge_symbol(infix_notation_row, length_without_terminator, ')');    
}
const char *recognize_add_symbol(const char *infix_notation_row, int length_without_terminator) {
    return recognize_sinlge_symbol(infix_notation_row, length_without_terminator, '+');    
}
const char *recognize_subtract_symbol(const char *infix_notation_row, int length_without_terminator) {
    return recognize_sinlge_symbol(infix_notation_row, length_without_terminator, '-');    
}
const char *recognize_multiply_symbol(const char *infix_notation_row, int length_without_terminator) {
    return recognize_sinlge_symbol(infix_notation_row, length_without_terminator, '*');    
}
const char *recognize_divide_symbol(const char *infix_notation_row, int length_without_terminator) {
    return recognize_sinlge_symbol(infix_notation_row, length_without_terminator, '/');    
}
const char *recognize_power_symbol(const char *infix_notation_row, int length_without_terminator) {
    return recognize_sinlge_symbol(infix_notation_row, length_without_terminator, '^');    
}

const char *recognize_function(
    const char *infix_notation_row, 
    int length_without_terminator, 
    const char *function_name_as_string, 
    int function_name_length_without_terminator) {

    //  the end of infix_notation is closer than the end of possible function_name in it
    if (length_without_terminator < function_name_length_without_terminator + 1)
        return infix_notation_row;

    //  the symbols and their order in infix_notation are exactly the same as in possible function_name
    for (int index = 0; index < function_name_length_without_terminator; ++index) {
        if (infix_notation_row[index] != function_name_as_string[index])
            return infix_notation_row;
    }

    //  after function name there should be opening brace
    if (infix_notation_row[function_name_length_without_terminator] != '(')  //  could have used recognise_single_symbol function
        return infix_notation_row;
    

    printf("%s\n", function_name_as_string);

    //  returning pointer to the next position in infix_notation to recognise
    return infix_notation_row + function_name_length_without_terminator;
}
const char *recognize_sine(const char *infix_notation_row, int length_without_terminator) {
    return recognize_function(infix_notation_row, length_without_terminator, "sin", 3);
}
const char *recognize_cosine(const char *infix_notation_row, int length_without_terminator) {
    return recognize_function(infix_notation_row, length_without_terminator, "cos", 3);
}
const char *recognize_tangent(const char *infix_notation_row, int length_without_terminator) {
    return recognize_function(infix_notation_row, length_without_terminator, "tg", 2);
}
const char *recognize_cotangent(const char *infix_notation_row, int length_without_terminator) {
    return recognize_function(infix_notation_row, length_without_terminator, "ctg", 3);
}
const char *recognize_natural_logarithm(const char *infix_notation_row, int length_without_terminator) {
    return recognize_function(infix_notation_row, length_without_terminator, "ln", 2);
}
const char *recognize_square_root(const char *infix_notation_row, int length_without_terminator) {
    return recognize_function(infix_notation_row, length_without_terminator, "sqrt", 4);
}



// static int get_amount_of_lexemes(const char *infix_notation_row, int length_without_terminator) {
    // for (int index = 0; index < length_without_terminator; ++index) {

    // }
// }
const char *recognize_double(const char *infix_notation_row, int length_without_terminator) {
    double result = 0.0;
    int status = 1;

    const char *current_position_in_string = string_to_double(
        infix_notation_row, 
        length_without_terminator, 
        &result, 
        &status);

    if (status == CS_SUCCESSFUL_CONVERSION)
        printf("%lf\n", result); 

    return current_position_in_string;
}


void parse_to_lexemes_allocate(const char *infix_notation_row, int length_without_terminator, Lexeme **infix_notation_out, int *lexeme_list_length_out) {
    printf("parse_to_lexemes_allocate():\n");
    printf("%s\n", infix_notation_row);
    printf("length = %d\n", length_without_terminator);

    if (infix_notation_out)
        infix_notation_out = NULL;
    *lexeme_list_length_out = 0;
    // print_lexeme_array(infix_notation_row, *length_out);

    // int index = 0;
    const char *current_position_in_string = infix_notation_row;
    
    //  chain of responsibility design pattern
    while (1) {
        const char *old_position_in_string = current_position_in_string;

        current_position_in_string = recognize_add_symbol(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row));

        current_position_in_string = recognize_subtract_symbol(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row));

        current_position_in_string = recognize_multiply_symbol(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row));

        current_position_in_string = recognize_divide_symbol(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row));

        current_position_in_string = recognize_power_symbol(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row));


        current_position_in_string = recognize_opening_brace(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row));

        current_position_in_string = recognize_closing_brace(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row));


        current_position_in_string = recognize_sine(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row));

        current_position_in_string = recognize_cosine(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row));

        current_position_in_string = recognize_tangent(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row));

        current_position_in_string = recognize_cotangent(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row));

        current_position_in_string = recognize_square_root(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row));

        current_position_in_string = recognize_natural_logarithm(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row));



        current_position_in_string = recognize_double(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row));

        current_position_in_string = recognize_placeholder_symbol(
            current_position_in_string, 
            length_without_terminator - (current_position_in_string - infix_notation_row));


        if (current_position_in_string == old_position_in_string) {
            printf("Done!\n");
            break;
        }
    }

    // exit(-1);
    // for (int index = 0; index < length_without_terminator; ++)
}