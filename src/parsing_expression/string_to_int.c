#include "string_to_int.h"


static int __is_symbol_numeric(char symbol) {
    static const int ascii_code_of_first_numeric = 48;
    static const int ascii_code_of_last_numeric = 57;
    
    return ascii_code_of_first_numeric <= symbol && symbol <= ascii_code_of_last_numeric;
}

static int __get_amount_of_digits_in_number(const char *input, int length) {
    int amount_of_digits = 0;
    while(amount_of_digits < length && __is_symbol_numeric(input[amount_of_digits])) 
        ++amount_of_digits;
        
    return amount_of_digits;
}

static int __get_int_from_numeric_char(char symbol) {
    static const int ascii_shift = 48;
    return (int)symbol - ascii_shift;
}

int get_sign(char first_symbol) {
    return ((first_symbol == '-') ? (-1) : 1);
}

const char* string_to_int(const char* input, int length_of_the_rest_without_terminator, int *result, int *conversion_status) {
    static const int base = 10;
    const int sign = get_sign(input[0]);
    const int shift_because_of_sign = (sign == -1) ? 1 : 0;
    const char* input_shifted = input + shift_because_of_sign;

    const int length = __get_amount_of_digits_in_number(input_shifted, length_of_the_rest_without_terminator);
    if (length == 0) {
        *conversion_status = CS_FAILED_CONVERSION;
        *result = 0;
        return input;
    }
    int index = length - 1;
    
    
    int sum = 0;
    int multiplier = 1;
    
    while (index > -1) {
        const int digit = __get_int_from_numeric_char(input_shifted[index]);
        sum += (digit * multiplier);
        multiplier *= base;
        
        --index;
    }

    *result = sum * sign;
    *conversion_status = CS_SUCCESSFUL_CONVERSION;
    return input_shifted + length;
}