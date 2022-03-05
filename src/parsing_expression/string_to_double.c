#include "string_to_double.h"


static int get_multiplier(int base, int amount_of_digits) {
    int multiplier = 1;
    for (int i = 0; i < amount_of_digits; ++i)
        multiplier *= base;

    return multiplier;
}

const char* string_to_double(const char* input, int length_of_the_rest_without_terminator, double *result, int *conversion_status) {
    const int sign = get_sign(input[0]);
    const int shift_because_of_sign = (sign == -1) ? 1 : 0;
    const char *input_shifted = input + shift_because_of_sign;

    int integer_part = 0;
    int integer_part_conversion_status = CS_FAILED_CONVERSION;
    const char *fraction_part_with_dot = string_to_int(
        input_shifted, 
        length_of_the_rest_without_terminator, 
        &integer_part, 
        &integer_part_conversion_status);


    if (integer_part_conversion_status != CS_SUCCESSFUL_CONVERSION) {
        *result = 0.0;
        *conversion_status = CS_FAILED_CONVERSION;
        return input;
    }

    *result = (double)integer_part;


    if (fraction_part_with_dot[0] != '.') {
        (*result) *= sign;
        *conversion_status = CS_SUCCESSFUL_CONVERSION;
        return fraction_part_with_dot;
    }


    const char *start_of_fraction_part = fraction_part_with_dot + 1;  //  moving after '.'
    const int length_of_the_rest_after_integer_part = length_of_the_rest_without_terminator - (start_of_fraction_part - input);
    int fraction_part = 0;
    int fraction_part_conversion_status = CS_FAILED_CONVERSION;
    const char *the_rest_of_the_input_string = string_to_int(
        start_of_fraction_part, 
        length_of_the_rest_after_integer_part,
        &fraction_part,
        &fraction_part_conversion_status);


    //  input string is not correct! That situation is not handled at all!
    if (fraction_part_conversion_status != CS_SUCCESSFUL_CONVERSION) {
        *conversion_status = CS_FAILED_CONVERSION;
        *result = 0.0;
        return input;
    }


    const int amount_of_digits_in_fraction_part = the_rest_of_the_input_string - start_of_fraction_part;
    static const int base = 10;
    const int multiplier = get_multiplier(base, amount_of_digits_in_fraction_part);


    (*result) += (double)fraction_part / (double)multiplier;
    (*result) *= sign;
    *conversion_status = CS_SUCCESSFUL_CONVERSION;

    return the_rest_of_the_input_string;
}