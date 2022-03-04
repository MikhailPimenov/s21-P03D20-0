#include "string_to_int.h"




int is_symbol_numeric(char symbol) {
    static const int ascii_code_of_first_numeric = 48;
    static const int ascii_code_of_last_numeric = 57;
    
    return ascii_code_of_first_numeric <= symbol && symbol <= ascii_code_of_last_numeric;
}

int get_amount_of_digits_in_number(const char *input, int length) {
    int amount_of_digits = 0;
    while(amount_of_digits < length && is_symbol_numeric(input[amount_of_digits])) 
        ++amount_of_digits;
        
    return amount_of_digits;
}

int get_int_from_numeric_char(char symbol) {
    static const int ascii_shift = 48;
    return (int)symbol - ascii_shift;
}

int get_sign(char first_symbol, int *shift_because_of_sign) {
    if (first_symbol == '-'){
        *shift_because_of_sign = 1;
        return -1;
    }
    *shift_because_of_sign = 0;
    return 1;
}

const char* string_to_int(const char* input, int length_of_the_rest_without_terminator, int *result, int *conversion_status) {
    static const int base = 10;
    int shift_because_of_sign = 0;
    const int sign = get_sign(input[0], &shift_because_of_sign);
    const char* input_shifted = input + shift_because_of_sign;

    const int length = get_amount_of_digits_in_number(input_shifted, length_of_the_rest_without_terminator);
    if (length == 0) {
        *conversion_status = CS_FAILED_CONVERSION;
        *result = -1;
    }
    int index = length - 1;
    
    
    int sum = 0;
    int multiplier = 1;
    
    while (index > -1) {
        const int digit = get_int_from_numeric_char(input_shifted[index]);
        sum += (digit * multiplier);
        multiplier *= base;
        
        --index;
    }

    *result = sum * sign;
    *conversion_status = CS_SUCCESSFUL_CONVERSION;
    return input_shifted + length;
}