#ifndef SRC_PARSING_EXPRESSION_CHECK_EXPRESSION_AND_COUNT_LEXEMES_H_
#define SRC_PARSING_EXPRESSION_CHECK_EXPRESSION_AND_COUNT_LEXEMES_H_

#define LEXEME_T_

#include "../data_structures/lexeme.h"
#include "../data_structures/stack.h"
#include "expression_check_error_codes.h"
#include "recognize_lexemes.h"


int check_expression_and_count_lexemes(const char *infix_notation_row, int length_without_terminator, int *amount_of_lexemes_out);

#endif  //  SRC_PARSING_EXPRESSION_CHECK_EXPRESSION_AND_COUNT_LEXEMES_H_