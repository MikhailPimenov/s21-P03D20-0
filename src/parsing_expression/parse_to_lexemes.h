#ifndef SRC_PARSING_EXPRESSION_PARSE_TO_LEXEMES_H_
#define SRC_PARSING_EXPRESSION_PARSE_TO_LEXEMES_H_

#include <stdlib.h>

#include "../data_structures/lexeme.h"
#include "../data_structures/stack.h"
#include "string_to_number_error_codes.h"
#include "string_to_double.h"
#include "recognize_lexemes.h"
#include "create_lexemes.h"
#include "expression_check_error_codes.h"
#include "check_expression_and_count_lexemes.h"




int check_expression_and_count_lexemes(const char *infix_notation_row, int length_without_terminator, int *amount_of_lexemes_out); 
void parse_to_lexemes_allocate(const char *infix_notation_row, int length, Lexeme **infix_notation_out, int *length_out);

#endif  //  SRC_PARSING_EXPRESSION_PARSE_TO_LEXEMES_H_
