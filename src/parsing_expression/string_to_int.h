#ifndef SRC_PARSING_EXPRESSION_STRING_TO_INT_H_
#define SRC_PARSING_EXPRESSION_STRING_TO_INT_H_

#include <stdlib.h>
#include "string_to_number_error_codes.h"


int get_sign(char first_symbol);
const char* string_to_int(const char* input, int length_of_the_rest_without_terminator, int *result, int *conversion_status);

#endif  //  SRC_PARSING_EXPRESSION_STRING_TO_INT_H_