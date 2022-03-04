#ifndef SRC_PARSING_EXPRESSION_STRING_TO_INT_H_
#define SRC_PARSING_EXPRESSION_STRING_TO_INT_H_

#include <stdlib.h>

enum conversion_status_codes {
    CS_SUCCESSFUL_CONVERSION = 0,
    CS_FAILED_CONVERSION = 1
};


const char* string_to_int(const char* input, int length_of_the_rest_without_terminator, int *result, int *conversion_status);

#endif  //  SRC_PARSING_EXPRESSION_STRING_TO_INT_H_