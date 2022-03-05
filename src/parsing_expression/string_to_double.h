#ifndef SRC_PARSING_EXPRESSION_STRING_TO_DOUBLE_H_
#define SRC_PARSING_EXPRESSION_STRING_TO_DOUBLE_H_

#include <stdlib.h>
#include <stdio.h>
#include "string_to_int.h"

const char* string_to_double(const char* input, int length_of_the_rest_without_terminator, double *result, int *conversion_status);

#endif  //  SRC_PARSING_EXPRESSION_STRING_TO_DOUBLE_H_