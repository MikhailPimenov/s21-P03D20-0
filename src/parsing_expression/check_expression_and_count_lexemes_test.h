#ifndef SRC_PARSING_EXPRESSION_CHECK_EXPRESSION_AND_COUNT_LEXEMES_TEST_H_
#define SRC_PARSING_EXPRESSION_CHECK_EXPRESSION_AND_COUNT_LEXEMES_TEST_H_

#include <stdio.h>
#include "parse_to_lexemes.h"
#include "expression_check_error_codes.h"

void check_expression_and_count_lexemes_test(int (*check_expression_and_count_lexemes_function)(const char*, int, int *));


#endif  //   SRC_PARSING_EXPRESSION_CHECK_EXPRESSION_AND_COUNT_LEXEMES_TEST_H_